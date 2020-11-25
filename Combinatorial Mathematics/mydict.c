#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int factorial(int num);
void get_next(char* src, int len, char* dst);
char* find_near_big(char* start, char* end, int value);
void swap(char* a, char* b);
int compare(const void *a, const void *b);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: ./dict number (1 < number < 10)\n");
        printf("       use q or bye quit me : )\n");
        return 0;
    }

    int num = atoi(argv[1]);
    
    if (num <= 0 || num >= 10) {
        printf("usage: ./dict number (1 < number < 10)\n");
        printf("       use q or bye quit me : )\n");
        return 0;
    }

    int str_len = num + 1;
    // printf("strlen: %d\n", str_len);

    int list_len = factorial(num);
    // printf ("all counts: %d\n", list_len);
    // printf("list_len: %d\n", list_len);

    char* target_ptr = malloc(str_len * list_len * sizeof(char));

    for (int i = 0; i < str_len - 1; i++) {
        *(target_ptr + i) = '1' + i;
    }
    *(target_ptr + str_len - 1) = '\0';
    // printf("%s\n", target_ptr);

    char* p = target_ptr;

    printf("     index     |     number\n");
    printf(" %9d     |     %s\n", 1, target_ptr);
    for (int i = 1; i < list_len; i++) {
        get_next(p, str_len, p + str_len);
        printf(" %9d     |     %s\n", i + 1, p + str_len);
        p += str_len;
    }

    char input[10];
    int index;
    while (true) {
        printf("\n");
        printf("show your index, I will give you number :)\n");
        scanf("%s", input);
        if ((strcmp("bye", input) == 0) || (strcmp("BYE", input) == 0) || (strcmp("Bye", input) == 0)
             || (strcmp("b", input) == 0) || (strcmp("q", input) == 0)) {
            printf("Good bye :) \n");
            printf("You could see my code in website: https://github.com/ArdxWe/codesnippets/tree/master/Combinatorial%%20Mathematics\n");
            free(target_ptr);
            return 0;
        }
        index = atoi(input);
        if ( index > 0 && index <= list_len) {
            printf("%s\n", target_ptr+ (index-1) * str_len);
        }
        else {
            printf("Please give me an int in [%d, %d] :)\n", 1, list_len);
        }
    }
    free(target_ptr);
}

int factorial(int num) {
    if (num <= 0) {
        return 0;
    }

    int ret = 1;
    while (num > 0) {
        ret = ret * num;
        num--;
    }
    return ret;
}

void get_next(char* src, int len, char* dst) {
    // printf("src: %s\n", src);
    char buffer[len];
    strcpy(buffer, src);
    // printf("buffer: %s\n", buffer);

    char* end = buffer + len - 2;
    char* start = buffer;

    char* p = end;
    while (p > start) {
        if (*p > *(p - 1)) {
            char* x = find_near_big(p, end, *(p - 1));
            // printf(" near number: %c\n", *x);
            swap(x, p - 1);
            // printf("after swap: %s\n", p - 1);
            qsort(p, end - p + 1, sizeof(char), compare);
            strcpy(dst, buffer);
            // printf("return: %s\n", dst);
            return;
        }
        p--;
    }
    strcpy(dst, buffer);
}

char* find_near_big(char* start, char* end, int value) {
    // printf("value: %c\n", value);
    char* ret = start;
    // printf("first %c\n", *start);
    // printf("end: %c\n", *end);
    for (char* p = start; p <= end; p++) {
        if (*p  > value && *p < *ret) {
            // printf("bijiao %d\n", *p - '0');
            ret = p;
        }
    }
    return ret;
}

void swap(char* a, char* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}