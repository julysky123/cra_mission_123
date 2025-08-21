#pragma once
#include <string>
#include <vector>
#include <map>
#include "IFileReader.h"
#include "player.h"
using std::string;
using std::vector;
using std::map;
using std::pair;

class FileReader: public IFileReader{
public:
	vector<string> read(const string& file_name) override;
};