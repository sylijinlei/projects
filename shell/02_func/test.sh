#!/bin/bash
function add()
{
	echo $1 $2
	return `expr $1 + $2`
}
var=$(add 4 6)
echo $?
 cd `dirname $0`
 echo `pwd`
