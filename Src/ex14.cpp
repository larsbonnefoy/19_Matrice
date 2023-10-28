#include "../Includes/Vector.hpp"
#include "../Includes/Matrix.hpp"
#include "../Includes/Projection.hpp"
#include <iostream>

int main(void) {
    Matrix<float> *proj = projection(1, 1, 1, 1);
    std::cout << *proj << std::endl;
    delete proj;
    return 0;
}
