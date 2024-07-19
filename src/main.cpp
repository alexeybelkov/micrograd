#include <iostream>
#include "engine.hpp"

int main() {
    const Value<float> a(1.5);
    const Value<double> b(2);
    std::cout << (a + b).data() << std::endl;
}
