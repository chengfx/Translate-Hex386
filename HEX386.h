#ifndef __HEX_386__
#define __HEX_386__

#include <string>
#include <vector>

class HEX386
{
public:
	HEX386() = default;
	typedef unsigned int dataType;
	bool readFiles(const std::vector<std::string>& filePaths);       //read contents from files
	bool writeFile(const std::string& filePath, int numdataType)const;       //write contents into file
	~HEX386() = default;
private:
	static const int DATA_TYPE = 0;   
	static const int END_TYPE = 1;
	static const int DATA_START = 9;
	static const int DATA_POS_H = 1;
	static const int DATA_POS_L = 2;
	static const int DATA_TYPE_POS = 8;

	std::vector<std::vector<dataType>> extractedData;
	bool extractInfos(const std::vector<std::string>& fileContents);    //extract data from HEX386 files.
	void convertData(const std::vector<std::vector<dataType>>& srcVectors, std::vector<std::vector<dataType>>& destVectors, const int numdataType)const;
	int char2hex(char num)const;
};

template<typename T>
void displayVector(const std::vector<T>& vector);
template<>
void displayVector(const std::vector<std::string>& vector);

#endif
