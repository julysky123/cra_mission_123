#pragma once
#include <memory>
#include <string>
#include <stdexcept>
#include "GradePolicy.h"
#include "IGradePolicy.h"
using std::shared_ptr;
using std::string;
using std::make_shared;
class GradePolicyFactory {
private:
	GradePolicyFactory() {}
public:
	static GradePolicyFactory getInstance() {
		static GradePolicyFactory instance;
		return instance;
	}
	shared_ptr<IGradePolicy> getGradePolicy(const string& policy) {
		// policy를 추가하세요.
		if (policy == "default") return make_shared<GradePolicy>();

		throw std::runtime_error("grade policy 이름이 적합하지 않습니다.");
	}
};