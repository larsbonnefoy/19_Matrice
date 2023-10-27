#include "../Includes/Matrix.hpp"
#include "../Includes/Vector.hpp"
#include <iostream>

int main (void)
{
    Matrix<float> m2 = Matrix<float>({{1, 2, 1}, {-2, -3, 1}, {3, 5, 0}});
    std::cout << "m: " << m2 << std::endl;
    uint32_t rank2 = m2.rank();
    std::cout << "rank " << rank2 << std::endl;
    std::cout << "============================" << std::endl;

    Matrix<float> m3 = Matrix<float>({{1, 2, 0,0}, {2, 4, 0, 0}, {-1, 2, 1, 1}});
    std::cout << "m: " << m3 << std::endl;
    uint32_t rank3 = m3.rank();
    std::cout << "rank " << rank3 << std::endl;
    std::cout << "============================" << std::endl;

    Matrix<float> m4 = Matrix<float>({{8, 5, -2}, {4, 7, 2}, {7, 6, 1}, {21, 18, 7}});
    std::cout << "m: " << m4 << std::endl;
    uint32_t rank4 = m4.rank();
    std::cout << "rank " << rank4 << std::endl;
    std::cout << "============================" << std::endl;
    return 0;
}
