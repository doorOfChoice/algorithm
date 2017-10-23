#!/bin/sh
filename=$1.cpp
filein='D:\\\\linuxshare\\\\c\\\\algorithm\\\\data.in'
fileout='D:\\\\linuxshare\\\\c\\\\algorithm\\\\data.out'
touch $filename
echo "#include<iostream>" >> $filename
echo "#include<string>" >> $filename
echo "#include<vector>" >> $filename
echo "#include<set>" >> $filename
echo "#include<math.h>" >> $filename
echo "#include<memory.h>" >> $filename
echo "using namespace std;" >> $filename
echo \#define FILE_IN \"$filein\" >> $filename
echo \#define FILE_OUT \"$fileout\" >> $filename
echo "void run()">> $filename
echo "{">> $filename
echo "}">> $filename
echo "int main()" >> $filename
echo "{" >> $filename
echo '  freopen(FILE_IN, "r", stdin);' >> $filename
echo '  freopen(FILE_OUT, "w", stdout);' >> $filename
echo "  run();" >> $filename
echo "}" >> $filename
