/*
    sort_strings.c
    Created by Alyxandra Spikerman on 1/31/17.
    Copyright © 2017 Computer Systems. All rights reserved.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compStrings(const void* a, const void* b);

int main(int argc, const char * argv[]) {
    int num_strings = atoi(argv[1]);
    char string[80];
    char* string_arr[num_strings];

    for (int i = 0; i < num_strings; i++){
        fgets(string, 80, stdin);
        string_arr[i] = (char *)malloc(strlen(string)+1);
        strcpy(string_arr[i], string);
    }

    qsort(string_arr, sizeof(string_arr)/sizeof(char*), sizeof(char*), compStrings);

    for (int j = 0; j < num_strings; j++){
        printf("%s", string_arr[j]);
        free(string_arr[j]);
    }

    return 0;
}

int compStrings(const void* a, const void* b){
    const char** aa = (const char**) a;
    const char** bb = (const char**) b;
    return strcmp(*aa, *bb);
}
