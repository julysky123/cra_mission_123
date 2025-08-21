#include "GradePolicy.h"

string GradePolicy::getGradeName(const int grade_idx) {

	if (grade_idx < 0 || grade_idx >= GRADE_COUNT) {
		throw std::runtime_error("grade가 잘못되었습니다.");
	}
	return GRADE_NAME[grade_idx];
}
int GradePolicy::getGrade(const int point) {
	static constexpr int GOLD_POINT = 50;
	static constexpr int SILVER_POINT = 30;
	if (point >= GOLD_POINT) return gold;
	else if (point >= SILVER_POINT) return silver;
	else return normal;
}

bool GradePolicy::isLowGrade(const int grade_idx) {
	return grade_idx == normal;
}