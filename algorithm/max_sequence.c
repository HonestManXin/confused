//
//该题还有很多细节没有考虑，需要考虑清楚
//
//http://zhedahht.blog.163.com/blog/static/254111742007219147591/
//
//

#include <stdio.h>
#include <stdlib.h>


int curr_sum = 0;
int max_sum = 0;
void max_sequence(int data[],int length);
int main()
{
    int data[] = {1,-2,3,10,-4,7,2,-5};
    max_sequence(data,8);
    printf("max sum is %d\n",max_sum);
    return 0;
}


void max_sequence(int data[],int length)
{
    int i=0;
    for(i=0;i<length;i++)
    {
       curr_sum +=data[i];
       if(curr_sum < 0)
       {
           curr_sum = 0;
           continue;
       }
       else if(curr_sum > max_sum)
           max_sum = curr_sum;
    }
}
