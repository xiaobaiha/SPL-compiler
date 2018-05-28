#ifndef TREE_H
#define TREE_H

#include <stdio.h>

typedef struct treeNode {
	struct treeNode *child; // for exp
	struct treeNode *sibling; // for stmt
} TreeNode;


#endif
