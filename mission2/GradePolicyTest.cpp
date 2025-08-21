#include "gmock/gmock.h"
#include "GradePolicy.h"

TEST(GradePolicy, AbnormalGrade) {
	GradePolicy gradePolicy;
	EXPECT_THROW(gradePolicy.getGradeName(10), std::runtime_error);
}

TEST(GradePolicy, NormalGrade) {
	GradePolicy gradePolicy;
	EXPECT_EQ(gradePolicy.getGradeName(0), "NORMAL");
}

TEST(GradePolicy, SilverGrade) {
	GradePolicy gradePolicy;
	EXPECT_EQ(gradePolicy.getGradeName(1), "SILVER");
}

TEST(GradePolicy, GoldGrade) {
	GradePolicy gradePolicy;
	EXPECT_EQ(gradePolicy.getGradeName(2), "GOLD");
}