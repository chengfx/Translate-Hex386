#include "HEX386.h"
#include <iostream>
#include<fstream>
#include<sstream>
using namespace std;

HEX386::HEX386(int fileNum, char** filePaths)
{
	if (setFilePaths(fileNum, filePaths) && readFiles());
}

bool HEX386::setFilePaths(int fileNum, char** filePaths)
{
	if (fileNum < 2)
	{
		cerr << "too less argumenst" << endl;
		for (int i = 0; i < fileNum; i++)
			cout << "fileNum:" << fileNum << "  filePath：" << filePaths[i] << endl;
		return false;
	}
	for (int i = 0; i < fileNum - 1; i++)
		srcFilePaths.push_back(filePaths[i]);
	destFilePath = filePaths[fileNum - 1];
	return true;
}

bool HEX386::readFiles()
{
	ifstream in;
	for (auto& filePath : srcFilePaths)
	{
		in.open(filePath);
		if (!in)
		{
			cerr << "file|" << filePath << " : can not be opened" << endl;
			state = STATE::wrong;
			return false;
		}
		string line;
		while (getline(in, line))
			srcFileContents.push_back(line);
		in.close();
	}
	return true;
}