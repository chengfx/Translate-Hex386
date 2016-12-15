#include "HEX386.h"
#include <iostream>
#include<fstream>
#include<sstream>

bool HEX386::readFiles(const std::vector<std::string>& filePaths)
{
	if (filePaths.empty())
		return false;
	std::vector<std::string> fileContents;
	std::ifstream in;
	for (auto &path : filePaths)
	{
		in.open(path);
		if (!in)
		{
			std::cerr << "file|" << path << ": can not be opened " << std::endl;
			return false;
		}
		std::string line;
		while (getline(in, line))
			fileContents.push_back(line);
		in.close();
	}
	//displayVector(fileContents);
	extractInfos(fileContents);
	//for(auto& data: extractedData)
	//	displayVector(data);
	return true;
}

bool HEX386::writeFile(const std::string& filePath)const
{
	return true;
}

bool HEX386::extractInfos(const std::vector<std::string>& fileContents)
{
	std::ostringstream out;
	std::vector<Byte> tempVector;
	for (const auto& line : fileContents)
	{
		//如果不是开头不是':'，继续下一行
		if (line[0] != ':')
			continue;
		//计算数据段长度和数据段类型
		const int dataNum = (char2hex(line[DATA_POS_H]) << 4) + char2hex(line[DATA_POS_L]);
		const int dataType = char2hex(line[DATA_TYPE_POS]);
		//
		if(dataType == END_TYPE)
		{
			extractedData.push_back(tempVector);
			tempVector.clear();
			continue;
		}
		if (dataType != DATA_TYPE)
			continue;
		//
		const int dataEnd = DATA_START + dataNum * 2;
		for (int i = DATA_START; i < dataEnd; i = i + 2)
		{
			const int data = (char2hex(line[i]) << 4) + char2hex(line[i + 1]);
			tempVector.push_back(data);
		}
	}
	return true;
}


int HEX386::char2hex(char num)const
{
	if (num >= '0' && num <= '9')
		return static_cast<int>(num - '0');
	else if (num >= 'a' && num <= 'f')
		return 10 + static_cast<int>(num - 'a');
	else if (num >= 'A'&& num <= 'F')
		return 10 + static_cast<int>(num - 'A');
	return -1;
}

template<typename T>
void displayVector(const std::vector<T>& vector)
{
	std::cout << "vector contents are : " << std::endl;
	for (const T& content : vector)
		std::cout << content << " ";
	std::cout << std::endl;
}

template<>
void displayVector(const std::vector<std::string>& vector)
{
	std::cout << "vector contents are : " << std::endl;
	for (auto& content : vector)
		std::cout << content << std::endl;;
}