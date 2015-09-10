#!/bin/bash
var=1
#var=$var+1   #字符串操作
let var1=var+1
# let可以用(())代替
((var2=var+1))
var3=`expr $var + 1`  #必须有空格
var4=`expr $1 + $2`
echo var1 = $var1
echo var2 = $var2
echo var3 = $var3
echo var4 = $var4
