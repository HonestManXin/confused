#include "tree.h"


int main()
{
    int a[] = {10,6,4,8,14,12,16};
    int i;
    pTree root = NULL;
    for(i =0 ;i<sizeof(a)/sizeof(int);i++)
    {
        root = add_tree(root,a[i]);
    }
    pre_travel(root);
    return 1;
}
