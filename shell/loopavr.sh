#! /bin/bash
#该脚本的目的是为了遍历脚本的所有参数

#直接遍历参数
for var in $@
do
    echo $var
done

#间接一点
for i in `seq $#`
do 
    echo ${!i}
    #eval echo \$$i
done

until [ -z "$1" ]
do
    echo $1
    shift
done


exit 0
