#! /bin/bash

a=1

if [ 0 ] && ((a++)) #a = 2
then
    echo "a = $a"
else
    echo "a = $a"
fi

#短路
if [ 0 ] || ((a++)) #a = 2
then
    echo "a = $a"
else
    echo "a = $a"
fi

if [ "$b" ] || ((a++)) #a = 3
then
    echo "a = $a"
else
    echo "a = $a"
fi

#短路
if [ "$b" ] && ((a++)) #a = 3
then
    echo "a = $a"
else
    echo "a = $a"
fi

