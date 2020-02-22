#!/bin/bash

FILES=./input/*
make
sum=0
for file in $FILES
do
    outfile=output/$(basename $file)
    echo $outfile
    x=$(./executable $file $outfile)
    echo $x
    sum=$(($sum+$x))
done
echo $sum
