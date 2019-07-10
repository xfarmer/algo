// Author: Farmer Li (jxli.farmer@gmail.com)

#ifndef ALGO_QUEUE_LINKED_QUEUE_H_
#define ALGO_QUEUE_LINKED_QUEUE_H_

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*linked_queue_data_free_func)(void* data);

typedef struct tagLinkedQueueNode {
  void *data;
  struct tagLinkedQueueNode *next;
} LinkedQueueNode;

typedef struct tagLinkedQueue {
  int size;
  LinkedQueueNode *head;
  LinkedQueueNode *tail;
  linked_queue_data_free_func data_free_func;
} LinkedQueue;

#define linked_queue_is_empty(queue) ((queue->size) == 0)

LinkedQueue *linked_queue_create(linked_queue_data_free_func func);

void linked_queue_destroy(LinkedQueue *queue);

bool linked_queue_enqueue(LinkedQueue *queue, void *data);

bool linked_queue_dequeue(LinkedQueue *queue, void **data);

#ifdef __cplusplus
}
#endif

#endif  // ALGO_QUEUE_LINKED_QUEUE_H_
