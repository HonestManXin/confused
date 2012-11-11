//
//
//
//
//
//
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

pTree make_list(pTree node)
{
    if(node == NULL)
        return NULL;
    pTree llist = NULL,rlist = NULL;
    pTree start;
    if(node->lchild != NULL)
    {
        llist = make_list(node->lchild);
        start = llist;
        while(start->rchild != NULL)
            start = start->rchild;
        start->rchild = node;
        node->lchild = start;
    }

    if(node->rchild != NULL)
    {
        rlist = make_list(node->rchild);
        start = rlist;
        while(start->lchild != NULL)
            start = start->lchild;
        start->lchild = node;
        node->rchild = start;
    }
    return node;
}

pTree find_start(pTree node)
{
    while(node->lchild !=  NULL)
        node = node->lchild ;
    return node;
}

void travel_list(pTree root)
{
    while(root != NULL)
    {
        printf("%d-->",root->data);
        root = root->rchild;
    }
}

int main()
{
    int data[] = {10,6,4,8,14,12,16};
    pTree root = NULL;
    pTree node = NULL;
    int i = 0;
    for(i=0;i<sizeof(data)/sizeof(int);i++)
    {
        root = add_tree(root,data[i]);
    }
    pre_travel(root);
    printf("\n");
    node = make_list(root);
    node = find_start(node);
    travel_list(node);
    return 0;
}
