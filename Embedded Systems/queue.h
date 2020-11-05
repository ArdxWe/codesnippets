#ifndef QUEUE_H
    #define QUEUE_H


#define QUEUE_SIZE 0x04

typedef void (*task)(void);

typedef struct
{
    task func;
    int priority;
}entity;

typedef struct
{
    entity* list;
    int size;
    int count;
}queue;

void init_queue(queue*);
int add_queue(queue* q, task func, int priority);
task get_queue(queue*);
void destroy_queue(queue*);
void show_queue(queue* q);

# endif


