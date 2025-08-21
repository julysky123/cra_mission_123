#pragma once
#include <string>
#include <stdexcept>
#include "IGradePolicy.h"
using std::string;

class GradePolicy : public IGradePolicy {
private:
	static constexpr int GRADE_COUNT = 3;
	const string GRADE_NAME[GRADE_COUNT] = { "NORMAL", "SILVER", "GOLD" };
	enum Grade
	{
		normal = 0,
		silver,
		gold
	};

public:
	string getGradeName(const int grade_idx) override;
	int getGrade(const int point) override;
	bool isLowGrade(const int grade_idx) override;
};
