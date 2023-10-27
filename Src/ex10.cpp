#include "../Includes/Matrix.hpp"
#include "../Includes/Vector.hpp"
#include <exception>
#include <iostream>

int main (void)
{
    Matrix<float> m1 = Matrix<float>({{0,2,0,1}, {0,0,-1,3},{2,0,2,0}, {-3,2,0,4}});
    std::cout << m1 << std::endl;
    m1.row_echelon_ip();
    std::cout << m1 << std::endl;

    std::cout << "===========" << std::endl;
    Matrix<float> m2 = Matrix<float>({{1,0,0}, {0,1,0},{0,0,1}});
    std::cout << m2 << std::endl;
    m2.row_echelon_ip();
    std::cout << m2 << std::endl;

    std::cout << "===========" << std::endl;
    Matrix<float> m3 = Matrix<float>({{1,2}, {3,4}});
    std::cout << m3 << std::endl;
    m3.row_echelon_ip();
    std::cout << m3 << std::endl;

    std::cout << "===========" << std::endl;
    Matrix<float> m4 = Matrix<float>({{1,2}, {2,4}});
    std::cout << m4 << std::endl;
    m4.row_echelon_ip();
    std::cout << m4 << std::endl;

    std::cout << "===========" << std::endl;
    Matrix<float> m5 = Matrix<float>({{8, 5, -2, 4, 28}, {4, 2.5, 20, 4, -4}, {8, 5, 1, 4, 17}});
    std::cout << m5 << std::endl;
    m5.row_echelon_ip();
    std::cout << m5 << std::endl;

    std::cout << "===========" << std::endl;
    Matrix<float> m6 = Matrix<float>({{3, 2, -4, 3}, {2, 3, 3, 15}, {5, -3, 1, 14}});
    Matrix<float> *m7 = m6.row_echelon();
    std::cout << m6 << std::endl;
    m6.row_echelon_ip();
    std::cout << m6 << std::endl;

    std::cout << "===========" << std::endl;
    std::cout << *m7 << std::endl;

    delete m7;
    return 0;
}
