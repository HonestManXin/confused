#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

char *convert_int(int data,int *length)
{
    int count = 1;
    int base = 10;
    char *buf = NULL;
    while(data / base)
    {
        count ++;
        base *= 10;
    }
    count ++; //多余一位存储后面的\n
    *length = count;

    buf = (char *)malloc(sizeof(char)*count);
    buf[count-1] = 0;
    count -=2;
    base = 10;
    while(data)
    {
        int number = data % base;
        buf[count] = '0' + number;
        count --;
        data /=base;
    }
    return buf;

}

//和当前的数字对比,data较大返回1 否则返回-1
int compare(int node_data,int data)
{
    int length1,length2;
    char *buf1 = convert_int(node_data,&length1);
    char *buf2 = convert_int(data,&length2);
    int i=0;

    while(buf1[i] && buf2[i])
    {
        if(buf1[i] < buf2[i])
            return 1;
        else if(buf1[i] > buf2[i])
            return -1;
        i++;
    }
    if(buf1[i])
    {
        if(buf1[i] > buf1[0])
            return -1;
        else 
            return 1;
    }
    else
    {
        if(buf2[i] > buf2[0])
            return 1;
        else 
            return -1;
    }
}

pTree build_tree(pTree root,int data)
{
    if(root == NULL)
    {
        root = (pTree)malloc(sizeof(aTree));
        root->data = data;
        root->lchild = root->rchild = NULL;
    }
    else
    {
        if(compare(root->data,data)<0)
        {
            root->lchild = build_tree(root->lchild,data);
        }
        else
        {
            root->rchild =build_tree(root->rchild,data);
        }
    }
    return root;
}

void mid_travel(pTree root)
{
    if(root == NULL)
        return;
    if(root->lchild)
        mid_travel(root->lchild);
    printf ( "%d",root->data );
    if(root->rchild)
        mid_travel(root->rchild);
}


int main()
{
    int data[] = {32,321};
    pTree root;
    int i = 0;
    for(i=0;i<sizeof(data)/sizeof(int);i++)
    {
        root = build_tree(root,data[i]);
    }
    mid_travel(root);
}

