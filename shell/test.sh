#! /bin/bash

hello=
echo "\$hello (null value) = $hello"

files=`ls -l`
echo "$files"

arch=$(uname -m)
echo $arch




exit 0
