#include<iostream>
#include"HEX386.h"


int main(int argc, char ** argv)
{
	if (argc <= 3)
	{
		std::cerr << "Please input correct file path" << std::endl;
		return 1;
	}
	std::string numByte(argv[1]);
	if (numByte.size() > 1 && numByte[0] > '4' && numByte[0] < '1')
	{
		std::cerr << "Please input correct numByte you want to convert in one data, 1 <= numByte <= 4" << std::endl;
		return 1;
	}
	std::vector<std::string> srcFilePaths;
	for (int i = 2; i < argc - 1; i++)
		srcFilePaths.push_back(argv[i]);
	HEX386 hex386;
	if (hex386.readFiles(srcFilePaths))
	{
		std::string destFilePath(argv[argc - 1]);
		int nByte = numByte[0] - '0';
		if (!hex386.writeFile(destFilePath, nByte))
			std::cerr << "failed: write data into files" << std::endl;
	}
	return 0;
}