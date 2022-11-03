#include "lambda.h"

#include <iostream>

void Lambda::TestLambda() {
	auto fn = [](const int& lhs, const int& rhs)
		-> bool {
		return lhs < rhs;
	};
	int a = 10;
	int b = 20;
	std::cout << "10 less than 20: "
		<< fn(a, b) << std::endl;
}