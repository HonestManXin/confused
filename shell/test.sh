#! /bin/bash

quote=$'\042'

echo " $quote this is a quoted string"

a=032
echo "oct number a = $a"
let "a = 032"
echo "oct number a = $a" 


exit 0
