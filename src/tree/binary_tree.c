// Author: Farmer Li (jxli.farmer@gmail.com)

#include "binary_tree.h"

#include <stdio.h>
#include <stdlib.h>

#include "queue/linked_queue.h"

void binary_tree_create(BinaryTree **root) {
  int value = 0;
  printf("\nInput node value(-1 as null): ");
  scanf("%d", &value);

  if (value == -1) {
    printf("Set child to null");
    (*root) = NULL;
  } else {
    (*root) = (BinaryTree *) malloc(sizeof(BinaryTree));
    if ((*root) == NULL) return;
    (*root)->data = value;
    printf("\nCreate LEFT  child of: %d", value);
    binary_tree_create(&((*root)->lchild));
    printf("\nCreate RIGHT child of: %d", value);
    binary_tree_create(&((*root)->rchild));
  }
}

static void create_tree_from_array(BinaryTree **root, int *arr, int *current, int len) {
  if (*current >= len) return;

  int value = arr[*current];
  *current += 1;

  if (value == -1) {
    (*root) = NULL;
  } else {
    (*root) = (BinaryTree *) malloc(sizeof(BinaryTree));
    if ((*root) == NULL) return;
    (*root)->data = value;
    printf("\nCreate LEFT  child of: %d", value);
    create_tree_from_array(&((*root)->lchild), arr, current, len);
    printf("\nCreate RIGHT child of: %d", value);
    create_tree_from_array(&((*root)->rchild), arr, current, len);
  }
}

void binary_tree_create_from_array(BinaryTree **root, int *arr, int len) {
  int current = 0;
  create_tree_from_array(root, arr, &current, len);
  printf("\n");
}

void binary_tree_destroy(BinaryTree *root) {
  if (root == NULL) return;

  binary_tree_destroy(root->lchild);
  binary_tree_destroy(root->rchild);
  free(root);
}

void binary_tree_preorder(BinaryTree *root) {
  if (root == NULL) return;

  printf("%d ", root->data);
  binary_tree_preorder(root->lchild);
  binary_tree_preorder(root->rchild);
}

void binary_tree_inorder(BinaryTree *root) {
  if (root == NULL) return;

  binary_tree_inorder(root->lchild);
  printf("%d ", root->data);
  binary_tree_inorder(root->rchild);
}

void binary_tree_postorder(BinaryTree *root) {
  if (root == NULL) return;

  binary_tree_postorder(root->lchild);
  binary_tree_postorder(root->rchild);
  printf("%d ", root->data);
}

void binary_tree_level(BinaryTree *root) {
  if (root == NULL) return;

  LinkedQueue *queue = linked_queue_create(NULL);
  linked_queue_enqueue(queue, (void *) root);
  void *data;
  BinaryTree *child;
  while (!linked_queue_is_empty(queue)) {
    if (linked_queue_dequeue(queue, &data)) {
      if (data != NULL) {
        child = (BinaryTree *) data;
        printf("%d ", child->data);

        if (child->lchild != NULL) {
          linked_queue_enqueue(queue, (void *) child->lchild);
        }
        if (child->rchild != NULL) {
          linked_queue_enqueue(queue, (void *) child->rchild);
        }
      }
    }
  }

  linked_queue_destroy(queue);
}

void binary_tree_leaf(BinaryTree *root) {
  if (root == NULL) return;

  if (root->lchild == NULL && root->rchild == NULL) {
    printf("%d ", root->data);
  } else {
    binary_tree_leaf(root->lchild);
    binary_tree_leaf(root->rchild);
  }
}

int binary_tree_leaf_num(BinaryTree *root) {
  if (root == NULL) return 0;

  if (root->lchild == NULL && root->rchild == NULL) {
    return 1;
  }

  return binary_tree_leaf_num(root->lchild) + binary_tree_leaf_num(root->rchild);
}

int binary_tree_height(BinaryTree *root) {
  if (root == NULL) return 0;

  if (root->lchild == NULL && root->rchild == NULL) {
    return 1;
  }

  int left_height = binary_tree_height(root->lchild);
  int right_height = binary_tree_height(root->rchild);

  return (left_height > right_height) ? (left_height + 1) : (right_height + 1);
}

static bool is_mirror(BinaryTree *left, BinaryTree *right) {
  if (left == NULL && right == NULL) return true;
  if (left == NULL || right == NULL) return false;
  return left->data == right->data && is_mirror(left->lchild, right->rchild) && is_mirror(left->rchild, right->lchild);
}

bool binary_tree_is_symmetric(BinaryTree *root) {
  if (root == NULL) return true;
  return is_mirror(root->lchild, root->rchild);
}
