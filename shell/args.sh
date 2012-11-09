#! /bin/bash

default_name=$(date +%m-%d-%y)
filename=${1:-$default_name}

echo $filename

exit 0
