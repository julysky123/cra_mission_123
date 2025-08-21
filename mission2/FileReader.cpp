#include "FileReader.h"
#include <fstream>
using std::ifstream;

vector<string> FileReader::read(const string& file_name) {
	ifstream fin{ file_name };

	if (fin.is_open() == false) {
		throw std::runtime_error("파일을 열 수 없습니다.");
	}
	string line;
	vector<string> lines;
	while (std::getline(fin, line))
	{
		lines.push_back(line);
	}
	return lines;
}