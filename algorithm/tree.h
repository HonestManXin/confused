/*
 * =====================================================================================
 *
 *       Filename:  tree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/11/07 23时35分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    struct Tree *lchild;
    struct Tree *rchild;
    int data;
}*pTree,aTree;

pTree init_tree(int data)
{
    pTree root = (pTree)malloc(sizeof(aTree));
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

pTree add_tree(pTree root,int data)
{
    if(root == NULL)
    {
        root = (pTree)malloc(sizeof(aTree));
        root->data = data;
        root->lchild = NULL;
        root->rchild = NULL;
        return root;
    }
    else
    {
        if(root->data > data)
        {
            root->lchild = add_tree(root->lchild,data);
        }
        else
        {
            root->rchild = add_tree(root->rchild,data);
        }
        return root;
    }
}

void pre_travel(pTree root)
{
    if(root == NULL)
        return ;
    if(root->lchild != NULL)
    {
        pre_travel(root->lchild);
    }
    printf("%d number",root->data);
    if(root->rchild != NULL)
    {
        pre_travel(root->rchild);
    }
}

void free_tree(pTree root)
{
    if(root == NULL)
        return ;
    free_tree(root->lchild);
    free_tree(root->rchild);
    free(root);
}


