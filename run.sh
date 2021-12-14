#!/bin/sh
RED="\033[1;31m"
RESET="\033[m"
main=test.c
if [[ -z $1 && -z $2 && -z $3 ]]
then
	width=20
	height=20
	dens=5
else
	width=$1
	height=$2
	dens=$3
fi

if [ -z $4]
then
	filename="assets/fun_board.txt"
else
	filename=$4
fi

echo "${RED}Generate assets/fun_board.txt${RESET}"
perl generate_fun_board.pl $width $height $dens> assets/fun_board.txt
cat $filename
echo "";

gcc -Wall -Wextra -Werror $main utilities/*.c -o runner.out
echo "\033[1;32;47m=== Result ===\033[m";
./runner.out

#Clean
rm runner.out
