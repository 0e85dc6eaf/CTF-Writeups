#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

void *xrealloc(void *old, size_t size);
void *xmalloc(size_t size);
void *xcalloc(size_t count, size_t size);

typedef struct data_table* db_t;
typedef int64_t data_t;
typedef data_t (*aggregation_fn)(data_t accum, data_t current);

typedef struct data_table db;
typedef struct data_table_chain dbchain;

typedef int32_t ymon_t;
typedef uint8_t day_t;

struct data_table {
    size_t months;
    size_t size;
    ymon_t start_month;
    dbchain **table;
};

struct data_table_chain {
    data_t *data;
    day_t day;
    size_t capacity;
    size_t size;
    dbchain *next;
};

int get_year(ymon_t y) {
    return y / 12;
}

int get_month(ymon_t y) {
    return y % 12;
}

ymon_t make_ymon(int year, int month) {
    return year * 12 + month;
}

db_t db_new() {
    db* D = xmalloc(sizeof(db));
    D->months = 24;
    D->size = 0;
    D->table = xcalloc(D->months, sizeof(dbchain *));
    D->start_month = 0;
    return D;
}

ssize_t get_chain_index(db_t D, ymon_t y) {
    return y - D->start_month;
}

dbchain *chain_head(db_t D, ymon_t y) {
    ssize_t offset = get_chain_index(D, y);
    if (offset < 0 || offset >= D->months) return NULL;
    return D->table[offset];
}

dbchain *chain_get(db_t D, ymon_t y, day_t day) {
    dbchain *ch = chain_head(D, y);
    while (ch != NULL) {
        if (ch->day == day) {
            return ch;
        }
        ch = ch->next;
    }
    return NULL;
}

dbchain *chain_add(db_t D, ymon_t y, day_t day) {
    if (D->size == 0) {
        D->start_month = y - D->months / 2;
    }

    ssize_t offset = get_chain_index(D, y);
    if (offset < 0 || offset >= D->months) {
        size_t old_months = D->months;
        ymon_t start_month = D->start_month;
        dbchain **old_table = D->table;

        size_t size_increase = D->months / 2;
        size_t base_offset;
        if (offset < 0) {
            size_increase -= offset;
            base_offset = size_increase;
        } else {
            size_increase += offset;
            base_offset = 0;
        }

        D->months = old_months + size_increase;
        D->table = xcalloc(D->months, sizeof(dbchain *));
        D->start_month = start_month - base_offset;

        memcpy(D->table + base_offset, old_table, old_months * sizeof(dbchain *));
        offset += base_offset;

        free(old_table);
    }

    dbchain *ch = xmalloc(sizeof(dbchain));
    ch->capacity = 10;
    ch->size = 0;
    ch->data = xmalloc(ch->capacity * sizeof(data_t));
    ch->day = day;
    ch->next = D->table[offset];
    D->table[offset] = ch;

    D->size++;

    return ch;
}

void chain_append(dbchain *ch, data_t data_value) {
    if (ch->size == ch->capacity) {
        ch->capacity = ch->capacity * 2;
        ch->data = xrealloc(ch->data, ch->capacity * sizeof(data_t));
    }
    ch->data[ch->size] = data_value;
    ch->size++;
}

void db_add(db_t D, struct tm* when, data_t data_value) {
    ymon_t ymon = make_ymon(when->tm_year, when->tm_mon);
    day_t day = when->tm_mday;
    dbchain *ch = chain_get(D, ymon, day);
    if (ch == NULL) {
        ch = chain_add(D, ymon, day);
    }
    chain_append(ch, data_value);
}

void db_rem(db_t D, struct tm* when) {
    ymon_t ymon = make_ymon(when->tm_year, when->tm_mon);
    day_t day = when->tm_mday;

    dbchain *ch = chain_head(D, ymon);
    dbchain *prev = NULL;
    while (ch != NULL && ch->day != day) {
        prev = ch;
        ch = ch->next;
    }
    if (ch != NULL) {
        if (prev != NULL) prev->next = ch->next;
        ch->size = 0;
        free(ch->data);
        free(ch);
    }
    D->size--;
}

data_t db_aggregate_month(db_t D, struct tm* when, aggregation_fn fn) {
    dbchain *ch = chain_head(D, make_ymon(when->tm_year, when->tm_mon));
    size_t i = 0;

    data_t agg = 0;

    while (ch != NULL) {
        if (ch->size > 0) {
            agg = ch->data[0];
            i = 1;
            break;
        }
        ch = ch->next;
    }

    while (ch != NULL) {
        while (i < ch->size) {
            agg = fn(agg, ch->data[i]);
            i++;
        }

        ch = ch->next;
        i = 0;
    }

    return agg;
}

data_t product(data_t a, data_t b) {
    return a * b;
}

data_t sum(data_t a, data_t b) {
    return a + b;
}

data_t min(data_t a, data_t b) {
    return b < a ? b : a;
}

data_t max(data_t a, data_t b) {
    return b > a ? b : a;
}

data_t xor(data_t a, data_t b) {
    return a ^ b;
}

#define BUFSIZE 40

char *readline() {
    char *balloc = xmalloc(BUFSIZE);
    char *buf = fgets(balloc, BUFSIZE, stdin);
    if (buf == NULL) {
        free(balloc);
        return NULL;
    } else {
        return buf;
    }
}

aggregation_fn get_aggregation_fn(char aggregation_type) {
    switch (aggregation_type) {
        case '+': return &sum;
        case '*': return &product;
        case 'M': return &max;
        case 'm': return &min;
        case 'x': return &xor;
        default:  return NULL;
    }
}

void *xrealloc(void *old, size_t size) {
    void *ptr = realloc(old, size);
    if (ptr == NULL) {
        perror("xrealloc");
        exit(1);
    }
    return ptr;
}

void *xmalloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        perror("xmalloc");
        exit(1);
    }
    return ptr;
}

void *xcalloc(size_t count, size_t size) {
    void *ptr = calloc(count, size);
    if (ptr == NULL) {
        perror("xcalloc");
        exit(1);
    }
    return ptr;
}

bool check_month(struct tm* when) {
    return 0 <= when->tm_mon && when->tm_mon < 12;
}

bool check_day(struct tm* when) {
    return 1 <= when->tm_mday && when->tm_mday <= 31;
}

#define COMMENT_COUNT 10

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    
    db_t D = db_new();

    char *comments[COMMENT_COUNT];
    size_t comment_index = 0;

    for (char *line_buffer = readline(); line_buffer != NULL; line_buffer = readline()) {
        size_t line_length = strlen(line_buffer);
        if (line_length == 0) {
            continue;
        }
        struct tm when;
        data_t item;
        int matched;
        char aggregation_type;

        switch (line_buffer[0]) {
            case '#': {
                if (comment_index >= COMMENT_COUNT) break;
                size_t start = 1;
                while (start < line_length && line_buffer[start] == ' ') {
                    start++;
                }
                if (start < line_length) {
                    char *cur_comment = xmalloc(line_length - start + 1);
                    memcpy(cur_comment, line_buffer + start, line_length - start + 1);
                    comments[comment_index] = cur_comment;
                    comment_index++;
                }
                free(line_buffer);
                break;
            }
            case '~': {
                matched = sscanf(line_buffer+1, "%02d-%02d-%04d",
                                 &when.tm_mon, &when.tm_mday, &when.tm_year);
                if (matched != 3) goto fail_match;
                when.tm_mon--;
                if (!check_month(&when) || !check_day(&when)) goto fail_match;
                free(line_buffer);

                db_rem(D, &when);
                break;
            }
            case 'a': {
                matched = sscanf(line_buffer+1, "%c %02d-%04d",
                                 &aggregation_type, &when.tm_mon, &when.tm_year);
                if (matched != 3) goto fail_match;
                when.tm_mon--;
                if (!check_month(&when)) goto fail_match;
                free(line_buffer);

                aggregation_fn f = get_aggregation_fn(aggregation_type);
                if (f == NULL) goto fail_match;
                data_t result = db_aggregate_month(D, &when, f);
                printf("%ld\n", result);
                break;
            }
            default: {
                matched = sscanf(line_buffer, "%02d-%02d-%04d %ld",
                                 &when.tm_mon, &when.tm_mday, &when.tm_year, &item);
                if (matched != 4) goto fail_match;
                when.tm_mon--;
                if (!check_month(&when) || !check_day(&when)) goto fail_match;
                free(line_buffer);

                db_add(D, &when, item);
                break;
            }
        }

        continue;

        fail_match: fprintf(stderr, "Failed to execute \"%s\"\n", line_buffer);
    }

    if (comment_index > 0) {
        printf("Comments:\n");
        size_t i;
        for (i = 0; i < comment_index; ++i) {
            printf("    %s\n", comments[i]);
        }
    }

    return 0;
}
