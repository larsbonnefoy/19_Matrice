#include "../Includes/Matrix.hpp"
#include "../Includes/Vector.hpp"

int main (void)
{
    Matrix<float> m0 = Matrix<float>({{1}});
    std::cout << m0 << std::endl;
    std::cout << "d: " << m0.determinant() << std::endl;

    Matrix<float> m1 = Matrix<float>({{1,1}, {0,1}});
    std::cout << m1 << std::endl;
    std::cout << "d: "<< m1.determinant() << std::endl;

    Matrix<float> m2 = Matrix<float>({{1,-1}, {-1,1}});
    std::cout << m2 << std::endl;
    std::cout << "d: "<< m2.determinant() << std::endl;

    Matrix<float> m3 = Matrix<float>({{2, 1, -1}, {-3, -1, 2}, {-2, 1, 2}});
    std::cout << m3 << std::endl;
    std::cout << "d: "<< m3.determinant() << std::endl;

    Matrix<float> m4 = Matrix<float>({{2,0,0}, {0,2,0}, {0,0,2}});
    std::cout << m4 << std::endl;
    std::cout << "d: "<< m4.determinant() << std::endl;

    Matrix<float> m5 = Matrix<float>({{8,5,-2}, {4,7,20}, {7,6,1}});
    std::cout << m5 << std::endl;
    std::cout << "d: "<< m5.determinant() << std::endl;

    Matrix<float> m6 = Matrix<float>({{8,5,-2,4}, {4,2.5,20,4}, {8,5,1,4},{28,-4,17,1}});
    std::cout << m6 << std::endl;
    std::cout << "d: "<< m6.determinant() << std::endl;

    return 0;
}
