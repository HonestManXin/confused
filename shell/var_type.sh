#! /bin/bash

a=1244
let "a += 1"
echo "a = $a"
 
b=${a/12/BB}
echo "b = $b"
let "b += 1"
echo "after change b = $b"

echo "var count $#"
echo "all var are $*"
echo "'\$@' is $@"

args=$#
lastargs=${!args}
echo $lastargs,$4

echo "scriptname is $0"
echo "script base name is `basename $0`"

exit 0
