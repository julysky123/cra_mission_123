#pragma once
#include <string>
using std::string;
struct IGradePolicy {
	
	virtual string getGradeName(const int grade_idx) = 0;
	virtual int getGrade(const int point) = 0;
	virtual bool isLowGrade(const int grade_idx) = 0;
};