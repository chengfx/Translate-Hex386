#Introduction
This repository is created to hold the codes which are built to extract data from the Hex386 file. Hex386 is the format of file which holds the memory data in embeded systems. If you can read chinese, you could ask for helps from my Blog [stm32调试 -- 获取内存数据][1] to know what the Hex386 format is. Or you could search for answers by [Google][2]. Anyway, this is just a program I write for the convenience in work.
##Environment
The compiler I use is Vs2015. In turth, any platform which supports the features of c++11 and generic programming can be used here to build source codes.
##How to use
After you've built this codes, the method of using it is type the following command on your bash

	ProgramName numBytes srcFiles destFile

1. ProgramName is the name of program which you've just compiled
2. numBytes is the number of Bytes which you want to merge into one data
3. srcFiles are the HEX386 Files from which you want to extract data
4. destFile is the File to store the results

[1]: http://blog.csdn.net/flydreamforever/article/details/53436302
[2]: http://www.google.com
