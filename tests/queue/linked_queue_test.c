// Author: Farmer Li (jxli.farmer@gmail.com)

#include "queue/linked_queue.h"

#include <stdio.h>

static int kDataArray[] = {1, 2, 3, 4, 5, 6, 7, 8};

int main(void) {
  LinkedQueue *queue = linked_queue_create(NULL);
  int data_len = sizeof(kDataArray) / sizeof(kDataArray[0]);

  printf("Enqueue 8 elements\n");
  for (int i = 0; i < data_len; ++i) {
    linked_queue_enqueue(queue, &(kDataArray[i]));
  }
  printf("Current queue size: %d\n", queue->size);

  int *p_value = NULL;
  printf("Dequeue 6 elements:\n");
  for (int j = 0; j < data_len - 2; ++j) {
    linked_queue_dequeue(queue, (void**)&p_value);
    printf("%d ", *p_value);
  }
  printf("\nCurrent queue size: %d\n", queue->size);

  printf("\nEnqueue 8 elements again\n");
  for (int i = 0; i < data_len; ++i) {
    linked_queue_enqueue(queue, &(kDataArray[i]));
  }
  printf("Current queue size: %d\n", queue->size);

  printf("Dequeue 6 elements again:\n");
  for (int j = 0; j < data_len - 2; ++j) {
    linked_queue_dequeue(queue, (void**)&p_value);
    printf("%d ", *p_value);
  }
  printf("\nCurrent queue size: %d\n", queue->size);

  linked_queue_destroy(queue);
  return 0;
}
