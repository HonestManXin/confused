#! /bin/bash

#
#0 -1 1 string return true
#NULL, uninitialed variable ,null varibale return false
#

echo "test 0"
if [ 0 ]
then
    echo "0 is true"
else
    echo "0 is false"
fi

echo "test 1"
if [ 1 ]
then
    echo "1 is true"
else
    echo "1 is false"
fi

echo "test -1"
if [ -1 ]
then
    echo "-1 is true"
else
    echo "-1 is true"
fi

echo "test null"
if [ ]
then
    echo "NULL is true"
else
    echo "NULL is false"
fi

echo "test xyz string"
if [ xyz ]
then
    echo "xyz is true"
else
    echo "xyz is false"
fi

echo "test uninitialed variable"
if [ $xyz ]    
then
    echo "uninitialed variable is true"
else
    echo "unitialed varibale is false"
fi

echo "regular test of uninitialed variable"
if [ -n "$xyz" ]
then
    echo "regular test uninitialed is true"
else
    echo "regular test uninitialed is false"
fi

xyz=
echo "test null variale"
if [ $xyz ]
then 
    echo "null variable is true"
else
    echo "null variable is false"
fi

echo "test string false"
if [ "false" ]
then 
    echo "false string is true"
else
    echo "false string is false"
fi

echo "test false  variable"
if [ "$false" ]
then
    echo "false variable is true"
else
    echo "false variable is false"
fi



exit $?
