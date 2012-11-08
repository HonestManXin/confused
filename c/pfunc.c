/*
 * =====================================================================================
 *
 *       Filename:  pfunc.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012/11/04 16时40分51秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

# include <stdio.h>
# include <stdlib.h>

void test(void);
void hello(void);

int main()
{
    void (*func[])(void) = {test,hello};
    func[0]();
    func[1]();
    return 0;
}

void test(void)
{
    printf("test\n");
}

void hello(void)
{
    printf("hello world\n");
}
