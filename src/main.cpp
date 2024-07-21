#include <iostream>
#include "engine.hpp"

int main() {
    Value<int16_t> a(1);
    Value<int32_t> b(2);
    std::cout << (a + b).data() << std::endl;
    std::cout << sizeof(Operation) << std::endl;
}
