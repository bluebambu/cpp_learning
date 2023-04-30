#include "foo.h"
namespace example {
    template<typename T>
    void foo() {
        std::cout << "Generic type" << std::endl;
    }

    template void foo<int>();
}
