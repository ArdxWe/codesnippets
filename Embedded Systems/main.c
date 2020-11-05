/*
 * author: Duan Jiahua
 * date  : 2020-11-05
 * steps : gcc queue.c main.c -o main.out
 *         ./main.out
 */

#include "queue.h"
#include <stdio.h>

void test();
void a();
void b();
void c();
void d();
void e();
void f();

int main() {
    test();
    return 0;
}

void test() {
    queue q;
    task func;
    init_queue(&q);

    add_queue(&q, &a, 1);
    show_queue(&q);

    add_queue(&q, &b, 18);
    show_queue(&q);

    add_queue(&q, &c, 8);
    show_queue(&q);

    add_queue(&q, &d, 56);
    show_queue(&q);

    add_queue(&q, &e, 79);
    show_queue(&q);

    add_queue(&q, &f, 65);
    show_queue(&q);

    func = get_queue(&q);
    func();

    add_queue(&q, &a, 99);
    show_queue(&q);

    func = get_queue(&q);
    func();

    add_queue(&q, &b, 564);
    show_queue(&q);

    add_queue(&q, &c, 34);
    show_queue(&q);

    add_queue(&q, &d, 3);
    show_queue(&q);

    add_queue(&q, &e, 569);
    show_queue(&q);

    func = get_queue(&q);
    func();

    add_queue(&q, &f, 45);
    show_queue(&q);

    destroy_queue(&q);
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

void d() {
    printf("d call\n");
}

void e() {
    printf("e call\n");
}

void f() {
    printf("f call\n");
}
