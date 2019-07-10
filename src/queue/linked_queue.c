// Author: Farmer Li (jxli.farmer@gmail.com)
#include "linked_queue.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

LinkedQueue *linked_queue_create(linked_queue_data_free_func func) {
  LinkedQueue *queue = (LinkedQueue *) malloc(sizeof(LinkedQueue));
  if (queue == NULL) return NULL;

  queue->size = 0;
  queue->head = NULL;
  queue->tail = NULL;
  queue->data_free_func = func;

  return queue;
}

void linked_queue_destroy(LinkedQueue *queue) {
  if (queue == NULL) return;

  while (queue->head != NULL) {
    LinkedQueueNode *p_node = queue->head;
    queue->head = queue->head->next;

    if (queue->data_free_func != NULL) {
      queue->data_free_func(p_node->data);
    }
    free(p_node);
  }

  free(queue);
}

bool linked_queue_enqueue(LinkedQueue *queue, void *data) {
  if (queue == NULL) return false;

  LinkedQueueNode *node = (LinkedQueueNode *) malloc(sizeof(LinkedQueueNode));
  if (node == NULL) return false;

  node->data = data;
  node->next = NULL;

  if (queue->head == NULL) {
    queue->head = node;
  } else {
    queue->tail->next = node;
  }
  queue->tail = node;
  ++queue->size;

  return true;
}

bool linked_queue_dequeue(LinkedQueue *queue, void **data) {
  if (queue == NULL || data == NULL || linked_queue_is_empty(queue)) return false;

  LinkedQueueNode *ptmp= queue->head;
  *data = queue->head->data;
  queue->head = queue->head->next;
  --queue->size;

  if (queue->head == NULL) {
    queue->tail = NULL;
  }

  free(ptmp);
  return true;
}
