#include <memory>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    std::cout << "hello talk-cpp" << std::endl;

    shared_ptr<int> sp = make_shared<int>(100);
    std::cout << "sp use count: " << sp.use_count() << std::endl;
    std::cout << "sp value: " << *sp << std::endl;
    
    weak_ptr<int> wp = sp;
    std::cout << "wp whether expired: " << wp.expired() << std::endl;
    std::cout << "sp use count: " << sp.use_count() << std::endl;
    if (!wp.expired()) {
        auto swp = wp.lock();
        *swp = 200;
        std::cout << "swp value: " << *swp << std::endl;
    }
    std::cout << "sp value: " << *sp << std::endl;

    return 0;
}
