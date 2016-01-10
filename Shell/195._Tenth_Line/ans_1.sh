#/bin/bash

#Read from the file file.txt and output the tenth line to stdout.

lines=`cat file.txt | awk 'END{print NR}'`

if [ $lines -ge 10 ];then
    head -n10 file.txt | tail -n1
fi
	
