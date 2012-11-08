/*
 * =====================================================================================
 *
 *       Filename:  usedll.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/11/05 22时19分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

# include "dll.h"
# include <stdio.h>
# include <stdlib.h>

int main()
{
    int a = add(1,2);
    int b = multi(2,3);

    printf("%d %d \n",a,b);
}



