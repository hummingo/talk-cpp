#include <iostream>

#include "sample.h"
#include "smart_pointer.h"
#include "lambda.h"
#include "sample_gl.h"

using namespace std;

int main(int argc, char** argv) {
    std::cout << "hello talk-cpp" << std::endl;

    // Sample::TestSample();
    // SmartPtr::TestSmartPtr();
    // Lambda::TestLambda();
    SampleGL::TestSampleGL();

    return 0;
}