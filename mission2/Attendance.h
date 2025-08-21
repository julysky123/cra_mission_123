#pragma once
#include "Week.h"
#include "IGradePolicy.h"
#include "player.h"
#include "IFileReader.h"
#include "FileReader.h"
#include "AttendanceLoader.h"
#include "PointCalculator.h"
#include "GradeCalculator.h"
#include "RemovedPlayerFinder.h"
#include "IReporter.h"
#include "Reporter.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;
class Attendance {
public:
	Attendance(const string& file_name, Week training_day, shared_ptr<IGradePolicy> gradePolicy) :file_name{ file_name }, training_day { training_day }, gradePolicy{ gradePolicy }
	{
		file_reader = make_shared<FileReader>();
		attendance_loader = make_shared<AttendanceLoader>();
		point_calculator = make_shared<PointCalculator>(training_day);
		grade_calculator = make_shared<GradeCalculator>(gradePolicy);
		removed_player_finder = make_shared<RemovedPlayerFinder>(gradePolicy, training_day);
		reporter = make_shared<Reporter>(gradePolicy);
	}
	void run();

	friend class AttendanceTestFixture;
private:
	const string& file_name;
	Week training_day;
	shared_ptr<IGradePolicy> gradePolicy;
	shared_ptr<IFileReader> file_reader;
	shared_ptr <AttendanceLoader> attendance_loader;
	shared_ptr <PointCalculator> point_calculator;
	shared_ptr <GradeCalculator> grade_calculator;
	shared_ptr <RemovedPlayerFinder> removed_player_finder;
	shared_ptr <IReporter> reporter;

};