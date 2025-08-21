#include "gmock/gmock.h"
#include "Attendance.h"
#include "IGradePolicy.h"
#include "GradePolicyFactory.h"

int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
