#include <stdio.h>
#include "str.h"

int main(void) {
    str* st = str_set("./build/etc/src/");
    printf("Core: %s, len:%d\n", str_get(st), str_len(st));

    str* new = str_copy(st);
    str_toupper(new);
    printf("ToUpper: %s\n", str_get(new));
    
    str_tolower(new);
    printf("ToLower: %s\n", str_get(new));
    
    str_concat(new, "?");
    printf("Concatination: %s\n", str_get(new));
    
    str* slice = str_slice(new, 6, 14);
    printf("Slice [6,14]: %s\n", str_get(slice));

    str_free(&st);
    str_free(&new);
    str_free(&slice);
    return 0;
}