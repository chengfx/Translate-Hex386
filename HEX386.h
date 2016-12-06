#ifndef __HEX_386__
#define __HEX_386__

#include <string>
#include <vector>

class HEX386
{
public:
	HEX386() = default;
	HEX386(int fileNum, char** filePaths);
	void convertData();
	~HEX386() = default;
private:
	static const int DATA_TYPE = 0;   
	static const int END_TYPE = 1;
	static const int DATA_START = 9;
	std::vector<std::string> srcFilePaths;
	std::string destFilePath;
	std::vector<std::string> fileContents;
	bool setFilePaths(int fileNum, char** filePaths);
	bool readFiles();
	void extractInfos();
};
#endif
