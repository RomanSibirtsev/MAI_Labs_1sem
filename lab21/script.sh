#!/usr/bin/env bash

if [ "$1" = "?" ]
   then
      echo "this program changes the encodings of all files with the .txt extension"
      echo "./script.sh [encoding] [path="./"]"
      exit 0
fi

t=$1
path=$2

if [ -z "$path" ]
   then
      path="./"
fi

if [ -z "$t" ]
   then
      t="ASCII"
fi
pr=$(iconv -l) ;
array=($(echo $pr | tr "//" "\n")) 

while [[ ! "${array[@]}" =~ "${t}" ]] 
   do 
      if [ "${t}" = "iconv -l" ]
         then
            iconv -l
      fi
      echo "Please, selec a correct encoding (the full list of encodings can be found here iconv -l)"
      read t
done


for files in `find $path -type f -name "*.txt"`
do
   code=`uchardet $files` 
   iconv -f ${code} -t $t -o $files $files

done
echo "Program shutdown!!!"