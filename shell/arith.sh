#! /bin/bash

#算数运算操作符的使用

n=1
echo "n = $n" #1

let "n = $n + 1"
echo "after let plus 1 n = $n" #2

let "n = n + 1"
echo "after direct plus 1 n = $n" #3

: $((n = $n + 1)) 
echo "n value = $n" #4

((n = n + 1))
echo "direct (()) n = $n" #5

((n = $n +1))
echo "with \$ plus 1 n = $n" #6

n=$((n+1))
echo "n = $n" #7

n=$(($n+1))
echo "n = $n" #8

let "n++"
echo "n++ = $n" #9

((n++))
echo "() n++ = $n" #10


#below can run but not right
#n="$n + 1"
#echo "direct n = $n"

# below wth cause command not found error
#$(( n = $n + 1))
#echo "n value = $n"




