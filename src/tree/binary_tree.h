// Author: Farmer Li (jxli.farmer@gmail.com)

#ifndef ALGO_TREE_BINARY_TREE_H_
#define ALGO_TREE_BINARY_TREE_H_

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tagBinaryTree {
  int data;
  struct tagBinaryTree *lchild;
  struct tagBinaryTree *rchild;
} BinaryTree;

void binary_tree_create(BinaryTree **root);

void binary_tree_create_from_array(BinaryTree **root, int *arr, int len);

void binary_tree_destroy(BinaryTree *root);

/**
 * Common operations
 */

void binary_tree_preorder(BinaryTree *root);

void binary_tree_inorder(BinaryTree *root);

void binary_tree_postorder(BinaryTree *root);

void binary_tree_leaf(BinaryTree *root);

int binary_tree_leaf_num(BinaryTree *root);

int binary_tree_height(BinaryTree *root);

/**
 * Some normal algorithms
 */

bool binary_tree_is_symmetric(BinaryTree *root);

#ifdef __cplusplus
}
#endif

#endif  // ALGO_TREE_BINARY_TREE_H_
