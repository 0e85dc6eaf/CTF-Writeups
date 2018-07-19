/* Time to enter the matrix. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXR 10000
#define MAXC 10000
#define MAXM 512

struct matrix {
    int nrows, ncols;
    float *data;
};

struct matrix *matrices[MAXM];

#define PROMPT(fmt, ...) printf(fmt ": ", ##__VA_ARGS__)
#define ERROR(fmt, ...) printf("ERROR: " fmt "\n", ##__VA_ARGS__)
#define INFO(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define FATAL(fmt, ...) do { printf("FATAL: " fmt "\n", ##__VA_ARGS__); exit(-1); } while(0)

void bye(void) {
    INFO("Goodbye");
    exit(0);
}

int find_free_index(void) {
    for(int i=0; i<MAXM; i++) {
        if(matrices[i] == NULL)
            return i;
    }
    return -1;
}

struct matrix *get_matrix(int id) {
    if(id < 0 || id >= MAXM || matrices[id] == NULL) {
        return NULL;
    } else {
        return matrices[id];
    }
}

void handle_create(int nrows, int ncols) {
    int id = find_free_index();
    if(id == -1)
        FATAL("MatrixOverflow!");
    if(nrows <= 0 || nrows > MAXR)
        FATAL("Invalid number of rows: %d", nrows);
    if(ncols <= 0 || ncols > MAXC)
        FATAL("Invalid number of cols: %d", ncols);

    struct matrix *m = malloc(sizeof(struct matrix));
    m->nrows = nrows;
    m->ncols = ncols;
    m->data = calloc(nrows * ncols, sizeof(float));

    matrices[id] = m;
    INFO("Successfully created matrix #%d.", id);
}

void handle_destroy(int id) {
    struct matrix *m = get_matrix(id);
    if(!m)
        FATAL("No such matrix!");

    free(m->data);
    free(m);
    matrices[id] = NULL;
    INFO("Successfully destroyed matrix #%d.", id);
}

void matrix_info(int id, struct matrix *m) {
    INFO("Matrix #%d: %d row%s, %d column%s", id,
        m->nrows, (m->nrows == 1) ? "" : "s",
        m->ncols, (m->ncols == 1) ? "" : "s"
    );
}

void handle_print(int id) {
    struct matrix *m = get_matrix(id);
    if(!m)
        FATAL("No such matrix!");

    matrix_info(id, m);
    float *ptr = m->data;
    for(int i=0; i<m->nrows; i++) {
        for(int j=0; j<m->ncols; j++) {
            printf("%.9g\t", *ptr++);
        }
        printf("\n");
    }
}

void handle_list() {
    for(int i=0; i<MAXM; i++) {
        struct matrix *m = get_matrix(i);
        if(m == NULL)
            continue;
        matrix_info(i, m);
    }
}

void handle_get(int id, int r, int c) {
    struct matrix *m = get_matrix(id);
    if(!m)
        FATAL("No such matrix!");
    if(r < 0 || r >= m->nrows)
        FATAL("Can't get row %d", r);
    if(c < 0 || c >= m->ncols)
        FATAL("Can't get column %d", c);

    INFO("Matrix[%d][%d] = %.9g", r, c, m->data[r * m->nrows + c]);
}

void handle_set(int id, int r, int c, float v) {
    struct matrix *m = get_matrix(id);
    if(!m)
        FATAL("No such matrix!");
    if(r < 0 || r >= m->nrows)
        FATAL("Can't set row %d", r);
    if(c < 0 || c >= m->ncols)
        FATAL("Can't set column %d", c);

    m->data[r * m->nrows + c] = v;
    INFO("Successfully set matrix[%d][%d] = %.9g", r, c, v);
}

void usage() {
    INFO("Available operations:\n"
           "\tcreate <rows> <cols>\n"
           "\tdestroy <id>\n"
           "\tlist\n"
           "\tprint <id>\n"
           "\tget <id> <row> <col>\n"
           "\tset <id> <row> <col> <value>\n"
           "\thelp\n"
           "\tquit");
}

void handle_command(const char *cmdbuf) {
    int id;
    int r, c;
    float v;
    if(2 == sscanf(cmdbuf, "create %d %d", &r, &c)) {
        handle_create(r, c);
    } else if(1 == sscanf(cmdbuf, "destroy %d", &id)) {
        handle_destroy(id);
    } else if(!strncmp(cmdbuf, "list", 4)) {
        handle_list();
    } else if(2 == sscanf(cmdbuf, "print %d", &id)) {
        handle_print(id);
    } else if(3 == sscanf(cmdbuf, "get %d %d %d", &id, &r, &c)) {
        handle_get(id, r, c);
    } else if(4 == sscanf(cmdbuf, "set %d %d %d %f", &id, &r, &c, &v)) {
        handle_set(id, r, c, v);
    } else if(!strncmp(cmdbuf, "help", 4)) {
        usage();
    } else if(!strncmp(cmdbuf, "quit", 4)) {
        bye();
    } else {
        ERROR("'%s' is not a valid command.", cmdbuf);
    }
}

int main() {
    /* Turn off buffering so we can see output right away */
    char cmdbuf[128];

    setbuf(stdout, NULL);

    INFO("Welcome to the Matrix!");
    usage();

    while(1) {
        PROMPT("Enter command");
        if(fgets(cmdbuf, sizeof(cmdbuf), stdin) == NULL) {
            bye();
        }

        handle_command(cmdbuf);
    }
}
