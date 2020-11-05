#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


static void insert_maxheap(entity* head, int len, entity* node) {
    if (len == 0) {
        head->func = node->func;
        head->priority = node->priority;
        return;
    }
    int i = len;
    while(node->priority > (head + (i-1)/2)->priority) {
        (head + i)->func = (head + (i-1)/2)->func;
        (head + i)->priority = (head + (i-1)/2)->priority;
        i = (i - 1) / 2;
        if (i == 0) {
            break;
        }
    }
    (head + i)->func = node->func;
    (head + i)->priority = node->priority; 
}

static task delete_max_heap(entity* head, int len){
    task ret = head->func;
    entity temp;
    temp.func = head[len-1].func;
    temp.priority = head[len-1].priority;

    int parent = 0, child = 1;
    while (child < len -1) {
        if ((child + 1 < len - 1) && head[child].priority < head[child+1].priority) {
            child++;
        }
        if (temp.priority > head[child].priority) {
            break;
        }
        head[parent].func = head[child].func;
        head[parent].priority = head[child].priority;
        parent = child;
        child = child * 2 + 1;
    }

    head[parent].func = temp.func;
    head[parent].priority = temp.priority;
    return ret;
}


void init_queue(queue* q) {
    q->list = malloc(sizeof(entity) * QUEUE_SIZE);
    q->size = QUEUE_SIZE;
    q->count = 0;
}

int add_queue(queue* q, task func, int priority) {
    if(q->size == q->count) {
        q->list = realloc(q->list, (q->size) * 2 * sizeof(entity));
        q->size = (q->size) * 2;
    }

    entity a;
    a.func = func;
    a.priority = priority;
    insert_maxheap(q->list, q->count, &a);
    q->count += 1;
}

task get_queue(queue* q) {
    if (q->count == 0) {
        return NULL;
    }
    task ret = delete_max_heap(q->list, q->count);
    q->count -= 1;
    return ret;
}

void destroy_queue(queue* q) {
    free(q->list);
}

void show_queue(queue* q) {
    printf("p: ");
    for (int i=0; i<q->count; i++) {
        printf("%d ", (q->list)[i].priority);
    }
    printf("\n");
}

