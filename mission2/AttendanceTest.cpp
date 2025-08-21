#include "gmock/gmock.h"
#include "GradePolicyFactory.h"
#include "Attendance.h"
#include "FileReaderMock.h"
#include "ReporterMock.h"
using namespace testing;

class AttendanceTestFixture : public Test {
protected:
	void SetUp() {
		GradePolicyFactory gf = GradePolicyFactory::getInstance();
		shared_ptr<IGradePolicy> policy = gf.getGradePolicy("default");
		Week training_day = wednesday;
		attendance = make_shared<Attendance>("file.txt", training_day, policy);
		mockReader = make_shared<FileReaderMock>();
		mockReporter = make_shared<ReporterMock>();
	}
public:
	shared_ptr<Attendance> attendance;
	shared_ptr<FileReaderMock> mockReader;
	shared_ptr<ReporterMock> mockReporter;
	void setMockedReader() {
		attendance->file_reader = mockReader;
	}
	void setMockedReporter() {
		attendance->reporter = mockReporter;
	}
	
	vector<string> getNormalData() {
		return {
		"Umar monday",
		"Daisy tuesday",
		"Alice tuesday",
		"Xena saturday",
		"Ian tuesday",
		"Hannah monday",
		"Hannah thursday",
		"Ethan wednesday",
		"Xena wednesday",
		"Daisy tuesday",
		"Vera saturday",
		"Xena sunday",
		"Rachel friday",
		"Charlie tuesday",
		"Hannah friday",
		"Steve sunday",
		"Ian friday",
		"Xena saturday",
		"Vera saturday",
		"Nina sunday",
		"Bob friday",
		"Ethan friday",
		"Xena sunday",
		"Nina wednesday",
		"Hannah saturday",
		"Xena friday",
		"Vera friday",
		"Xena tuesday",
		"Alice monday",
		"Nina tuesday",
		"Nina friday",
		"Steve sunday",
		"Ian wednesday",
		"Alice friday",
		"Charlie monday",
		"Xena tuesday",
		"George friday",
		"Hannah monday",
		"Umar sunday",
		"Charlie tuesday",
		"Daisy thursday",
		"Quinn friday",
		"Tina thursday",
		"Alice tuesday",
		"Hannah saturday",
		"Rachel saturday",
		"George thursday",
		"Xena monday",
		"Hannah tuesday",
		"Will wednesday",
		"Xena monday",
		"Umar monday",
		"Rachel monday",
		"Charlie friday",
		"Umar sunday",
		"Charlie saturday",
		"Hannah friday",
		"Steve wednesday",
		"Rachel wednesday",
		"Nina saturday",
		"Will tuesday",
		"Daisy sunday",
		"Vera tuesday",
		"Steve saturday",
		"Tina tuesday",
		"Hannah friday",
		"Hannah sunday",
		"Will thursday",
		"Hannah sunday",
		"Xena saturday",
		"Hannah wednesday",
		"Alice thursday",
		"Nina thursday",
		"Rachel wednesday",
		"Will tuesday",
		"Nina sunday",
		"George friday",
		"Will saturday",
		"Xena wednesday",
		"Alice monday",
		"Daisy monday",
		"Nina monday",
		"Alice tuesday",
		"Hannah sunday",
		"Charlie wednesday",
		"George friday",
		"Will wednesday",
		"Will tuesday",
		"Alice tuesday",
		"Daisy friday",
		"Will sunday",
		"Alice wednesday",
		"Ethan monday",
		"Hannah wednesday",
		"Rachel tuesday",
		"Hannah tuesday",
		"Oscar sunday",
		"Hannah wednesday",
		"Steve wednesday",
		"Nina friday",
		"Rachel thursday",
		"George sunday",
		"Alice saturday",
		"Nina wednesday",
		"Xena monday",
		"Ethan monday",
		"Xena thursday",
		"Daisy thursday",
		"Steve thursday",
		"Rachel saturday",
		"Alice tuesday",
		"George tuesday",
		"Hannah tuesday",
		"Nina wednesday",
		"George monday",
		"Rachel sunday",
		"George sunday",
		"Will thursday",
		"Daisy sunday",
		"Xena saturday",
		"Charlie thursday",
		"Tina friday",
		"Daisy friday",
		"Ethan saturday",
		"Tina saturday",
		"Rachel friday",
		"Charlie monday",
		"Hannah thursday",
		"Nina wednesday",
		"Rachel thursday",
		"Hannah friday",
		"Ian friday",
		"Hannah wednesday",
		"Daisy tuesday",
		"Hannah sunday",
		"Tina thursday",
		"George wednesday",
		"Hannah tuesday",
		"Xena monday",
		"Oscar sunday",
		"Hannah saturday",
		"George tuesday",
		"Vera saturday",
		"Rachel wednesday",
		"Nina wednesday",
		"Nina sunday",
		"Hannah saturday",
		"Tina saturday",
		"Charlie thursday",
		"Nina monday",
		"Alice tuesday",
		"Charlie saturday",
		"Alice wednesday",
		"Ian friday",
		"Vera wednesday",
		"Ian wednesday",
		"Nina sunday",
		"Ian wednesday",
		"Quinn saturday",
		"Nina sunday",
		"Xena tuesday",
		"Umar friday",
		"Hannah friday",
		"Ethan thursday",
		"Nina friday",
		"Tina tuesday",
		"Hannah tuesday",
		"Alice thursday",
		"Alice thursday",
		"Nina saturday",
		"Xena monday",
		"Xena monday",
		"Ian tuesday",
		"Alice saturday",
		"Alice saturday",
		"Daisy sunday",
		"Tina monday",
		"Bob monday",
		"Ethan monday",
		"Alice sunday",
		"Hannah sunday",
		"Umar monday",
		"Ethan friday",
		"Alice thursday",
		"Rachel friday",
		"Rachel saturday",
		"Ethan sunday",
		"Will thursday",
		"Alice wednesday",
		"Hannah thursday",
		"Hannah thursday",
		"Rachel tuesday",
		"Daisy sunday",
		"Steve friday",
		"Xena thursday",
		"Alice thursday",
		"Xena thursday",
		"Oscar tuesday",
		"Steve sunday",
		"Charlie friday",
		"Charlie sunday",
		"Alice monday",
		"Charlie thursday",
		"Hannah tuesday",
		"Ethan monday",
		"Nina monday",
		"Charlie tuesday",
		"Rachel thursday",
		"Rachel sunday",
		"Xena friday",
		"Hannah tuesday",
		"Tina tuesday",
		"Tina tuesday",
		"Xena friday",
		"Umar wednesday",
		"Charlie wednesday",
		"Ethan monday",
		"Hannah thursday",
		"Xena saturday",
		"Rachel friday",
		"Rachel wednesday",
		"Xena tuesday",
		"Ian sunday",
		"Xena friday",
		"Steve tuesday",
		"Xena tuesday",
		"Nina friday",
		"Ethan thursday",
		"Nina thursday",
		"George sunday",
		"George monday",
		"Hannah friday",
		"Nina tuesday",
		"Oscar saturday",
		"Umar saturday",
		"George tuesday",
		"Steve saturday",
		"Umar tuesday",
		"Will friday",
		"Alice tuesday",
		"Daisy saturday",
		"Umar wednesday",
		"Umar saturday",
		"Umar sunday",
		"Hannah sunday",
		"Ethan wednesday",
		"Xena friday",
		"Umar monday",
		"Nina thursday",
		"Bob thursday",
		"Umar thursday",
		"Xena monday",
		"Xena sunday",
		"Daisy tuesday",
		"Hannah thursday",
		"Steve tuesday",
		"Daisy wednesday",
		"Xena wednesday",
		"Ethan thursday",
		"Daisy tuesday",
		"Steve sunday",
		"Rachel friday",
		"Xena monday",
		"Daisy friday",
		"Oscar monday",
		"George saturday",
		"Will tuesday",
		"Will sunday",
		"Alice wednesday",
		"Umar wednesday",
		"Hannah saturday",
		"Daisy friday",
		"Ethan sunday",
		"Charlie thursday",
		"Charlie friday",
		"Daisy saturday",
		"Umar monday",
		"Xena tuesday",
		"Oscar tuesday",
		"Will saturday",
		"Xena saturday",
		"Hannah friday",
		"Xena saturday",
		"Rachel tuesday",
		"Nina monday",
		"Daisy saturday",
		"George monday",
		"Charlie wednesday",
		"Xena tuesday",
		"Hannah saturday",
		"Hannah tuesday",
		"Vera tuesday",
		"Charlie monday",
		"Daisy thursday"
		};
	}

};

class ReportTestHelper {
public:
	vector<int> pointReport;
	vector<int> gradeReport;
	vector<string> nameReport;

	vector<string> removedReport;

	void printMock(const vector<Player>& players, const map<int, int>& points, const map<int, int>& grades) {
		for (const auto& player : players)
		{
			int point = points.at(player.id);
			int grade = grades.at(player.id);
			pointReport.push_back(point);
			gradeReport.push_back(grade);
			nameReport.push_back(player.name);
		}
	}
	void removedMock(const vector<string>& removed_players) {
		removedReport = removed_players;
	}
};

TEST_F(AttendanceTestFixture, normal_case_test_and_verify_result) {
	ReportTestHelper helper;
	setMockedReader();
	setMockedReporter();
	EXPECT_CALL(*mockReader, read).WillRepeatedly(
		Return(getNormalData())
	);
	
	EXPECT_CALL(*mockReporter, printPlayerReport).Times(1)
		.WillOnce(Invoke(&helper, &ReportTestHelper::printMock));
	EXPECT_CALL(*mockReporter, printRemovedPlayers).Times(1)
		.WillOnce(Invoke(&helper, &ReportTestHelper::removedMock));

	attendance->run();

	EXPECT_EQ(helper.nameReport[0], "Umar");
	EXPECT_EQ(helper.pointReport[0], 27);
	EXPECT_EQ(helper.gradeReport[0], 0);
	EXPECT_EQ(helper.removedReport.size(), 1);
	EXPECT_EQ(helper.removedReport[0], "Bob");
}

TEST_F(AttendanceTestFixture, normal_case_test_dont_throw) {
	ReportTestHelper helper;
	setMockedReader();
	EXPECT_CALL(*mockReader, read).WillRepeatedly(
		Return(getNormalData())
	);
	attendance->run();
	SUCCEED();
}

TEST_F(AttendanceTestFixture, wrong_date_case_throw_error) {
	setMockedReader();
	setMockedReporter();
	EXPECT_CALL(*mockReader, read).WillRepeatedly(
		Return(vector<string>{ "aaa NODAY" })
	);
	EXPECT_THROW(attendance->run(), std::runtime_error);
}