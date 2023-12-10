#include <iostream>
#include "domeConfig.hpp"

int main() {
    std::cout << "f_v: " << DOME_VERSION_MAJOR << std::endl;
    std::cout << "s_v: " << DOME_VERSION_MINOR << std::endl;
    std::cout << __cplusplus << std::endl;
    return 0;
}