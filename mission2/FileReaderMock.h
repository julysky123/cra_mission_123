#include "gmock/gmock.h"
#include "IFileReader.h"

class FileReaderMock : public IFileReader{
public:
	MOCK_METHOD(vector<string>, read, (const string&), (override));
};
