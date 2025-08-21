#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

struct IFileReader {
	virtual vector<string> read(const string& file_name) = 0;
};