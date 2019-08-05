// Author: Farmer Li (jxli.farmer@gmail.com)

#include "tree/binary_tree.h"

#include <stdio.h>

#define SIZEOF_ARRAY(a) (sizeof(a) / sizeof(a[0]))

static int kTreeArray[] = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, 7, -1, -1, 8, -1, -1, 9, 10, -1, -1, 11, -1, -1};
//static int kTreeArray[] = {1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1};

int main(void) {
  printf("#### Test for binary tree common operations\n");
  BinaryTree *tree;
  printf("\nCreat a binary tree:");
  binary_tree_create_from_array(&tree, kTreeArray, SIZEOF_ARRAY(kTreeArray));

  printf("\nPreorder traversal of the tree is: \n");
  binary_tree_preorder(tree);

  printf("\n\nInorder traversal of the tree is: \n");
  binary_tree_inorder(tree);

  printf("\n\nPostorder traversal of the tree is: \n");
  binary_tree_postorder(tree);

  printf("\n\nLevel traversal of the tree is: \n");
  binary_tree_level(tree);

  int leaf_num = binary_tree_leaf_num(tree);
  printf("\n\nLeaf num of the tree is: %d", leaf_num);

  printf("\n\nAll leaf of the tree is: \n");
  binary_tree_leaf(tree);

  int height = binary_tree_height(tree);
  printf("\n\nThe height of the tree is: %d\n", height);

  printf("\n#### Test for some binary tree algorithms\n");

  printf("\nAlgo: is symmetric?");
  bool symmetric = binary_tree_is_symmetric(tree);
  printf("\nIs tree symmetric? %s",  symmetric ? "true" : "false");

  printf("\n\nFree the tree\n");
  binary_tree_destroy(tree);

  return 0;
}
