#include "str.h"

struct str {
    char* data;
    size_t length;
};

str* str_set(const char* value) {
    size_t l = strlen(value);
    
    str* st = malloc(sizeof(str));
    if (!st) return NULL;
    
    st->data = malloc(l + 1);
    if (!st->data) return NULL;
    
    memcpy(st->data, value, l);
    st->data[l] = '\0';
    
    st->length = l;
    return st;
}

void str_free(str** st){
    if (!st || !*st) return;
    free((*st)->data);
    free(*st);
    *st = NULL;
}

const char* str_get(const str* st){ 
    if (!st || !st->data) return NULL;
    return st->data;
}

str* str_copy(const str* st){
    if (!st || !st->data) return NULL;
    return (str_set(st->data));
}

const char str_at(const str* st, size_t at){
    if (!st || !st->data) return '\0';
    if (at > st->length)  return '\0';

    return st->data[at];
}

size_t str_len(const str* st){
    if (!st || !st->data) return (size_t)-1;
    return st->length; 
}

void str_concat(str* st, const char* value){
    if (!st || !st->data) return;
    size_t l0 = st->length;
    size_t l1 = strlen(value);

    char* temp = realloc(st->data, l0 + l1 + 1);
    if (!temp) return;

    st->data = temp;
    memcpy(st->data + l0, value, l1);
    st->data[l0 + l1] = '\0';
    st->length = l0 + l1;
}

void str_clear(str* st){
    if (!st || !st->data) return;
    
    char* temp = realloc(st->data, 1);
    if (!temp) return;

    st->data = temp;
    st->data[0] = '\0';
    st->length = 0;
}

str* str_slice(const str* st, size_t sos, size_t eos){
    if (!st || !st->data)   return NULL;
    if (eos < sos)          return NULL;
    if (eos > st->length)   return NULL;

    size_t len = eos - sos;
    str* res = malloc(sizeof(str));
    if (!res) return NULL;

    res->data = malloc(len + 1);
    if (!res->data) return NULL;

    memcpy(res->data, st->data + sos, len);
    res->data[len] = '\0';
    res->length = len;
    return res;
}

void str_tolower(str* st){
    for (size_t i = 0 ; i < st->length; ++i){
        st->data[i] = tolower(st->data[i]);
    }
}

void str_toupper(str* st){
    for (size_t i = 0 ; i < st->length; ++i){
        st->data[i] = toupper(st->data[i]);
    }
}