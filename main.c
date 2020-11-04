#include "queue.h"
#include <stdio.h>

void a();
void b();
void c();

int main() {
    queue q;
    init_queue(&q);
    add_queue(&q, &a, 1);
    show_queue(&q);
    add_queue(&q, &a, 18);
    show_queue(&q);
    add_queue(&q, &a, 8);
    show_queue(&q);
    add_queue(&q, &a, 56);
    show_queue(&q);
    task x = get_queue(&q);
    x();
    add_queue(&q, &a, 45);
    show_queue(&q);
    add_queue(&q, &a, 34);
    add_queue(&q, &a, 34);
    return 0;
}

void a() {
    printf("a call\n");
}

void b() {
    printf("b call\n");
}

void c() {
    printf("c call\n");
}