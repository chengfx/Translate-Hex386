#include<iostream>
#include"HEX386.h"


int main(int argc, char ** argv)
{
	if (argc <= 2)
	{
		std::cerr << "Please input correct file path" << std::endl;
		return 1;
	}
	std::vector<std::string> srcFilePaths;
	for (int i = 1; i < argc - 1; i++)
		srcFilePaths.push_back(argv[i]);
	HEX386 hex386;
	hex386.readFiles(srcFilePaths);

	return 0;
}