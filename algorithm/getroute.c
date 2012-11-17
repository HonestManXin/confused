//
//注意：这题是用递归做的，还没想通怎么实现非递归实现
//同时这题目前还是可以优化的，在中间的节点中若当前的curr_data > sum可以马上返回0
//http://zhedahht.blog.163.com/blog/static/254111742007228357325/
//
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int printroute(pTree node,pTree root,int curr_sum,int sum);
void helper_touter(pTree node);

int main()
{
    pTree root = NULL;
    int datanode[] = {10,5,4,7,12};
    int i =0 ;
    for(i=0;i<sizeof(datanode)/sizeof(int);i++)
    {
        root = add_tree(root,datanode[i]);
    }
    //pre_travel(root);
    helper_touter(root);
    return 0;
}

void helper_touter(pTree root)
{
    printroute(root,root,0,22);
}

int printroute(pTree node,pTree root,int curr_sum,int sum)
{
    int true = 0;
   if(node == NULL)
       return 0;
   if(node->lchild == NULL && node ->rchild == NULL)
   {
       if(curr_sum + node->data == sum)
       {
           if(node != root)
                printf("%d<--",node->data);
           else
               printf("%d\n",node->data);
           return 1;
       }
       else
           return 0;
   }
   else
   {
        curr_sum += node->data;
        if(printroute(node->lchild,root,curr_sum,sum))
        {
           if(node != root)
                printf("%d<--",node->data);
           else
               printf("%d\n",node->data);
            true = 1;
        }
        if(printroute(node->rchild,root,curr_sum,sum))
        {
           if(node != root)
                printf("%d<--",node->data);
           else
               printf("%d\n",node->data);
            true = 1;
        }
        return true;
   }
}




