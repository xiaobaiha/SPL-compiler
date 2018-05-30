#ifndef TREE_H
#define TREE_H

/* ------------- parse tree definition --------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
    // struct treeNode *child; // for exp
    // struct treeNode *sibling; // for stmt
    int item;               // Value of the node
    int nodeIdentifier;     // Type of the node 
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
} TreeNode;

typedef TreeNode *PARSE_TREE;

/* ------------- Managing Parse Tree --------------------------- */

PARSE_TREE create_node(int ival, int case_identifier, PARSE_TREE p1,
                       PARSE_TREE p2, PARSE_TREE p3)
{
    PARSE_TREE t;
    t = (PARSE_TREE)malloc(sizeof(TreeNode));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return (t);
}

void print_tree(PARSE_TREE t, int indent)
{
    int i;
    if (t == NULL)
        return;
    for (i = indent; i; i--)
    {
        printf(" ");
    }
    printf("nodeIdentifier: %d", t->nodeIdentifier);
    printf("item: %d\n", t->item);
    PrintTree(t->first, indent + 2);
    PrintTree(t->second, indent + 2);
    PrintTree(t->third, indent + 2);
}

#endif
