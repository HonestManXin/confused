/*
 * =====================================================================================
 *
 *       Filename:  swap.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/11/08 20时08分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

extern int buf[];

int *buf0 = &buf[0];

int *buf1;

void swap()
{
    int temp;
    buf1 = &buf[1];

    temp = *buf0;
    *buf0 = *buf1;
    *buf1 = temp;
}

