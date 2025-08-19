#pragma once

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct str str;

str* str_set(const char* value);
str* str_copy(const str* st);
void str_free(str** st);

size_t str_len(const str* st);
const char* str_get(const str* st);
const char str_at(const str* st, size_t at);

void str_concat(str* st, const char* value);
void str_clear(str* st);

str* str_slice(const str* st, size_t sos, size_t eos);

void str_tolower(str* st);
void str_toupper(str* st);