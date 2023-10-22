#include "../Includes/Matrix.hpp"
#include "../Includes/Vector.hpp"
#include <iostream>

int main (void)
{
    Matrix<float> m1 = Matrix<float>({{1,0}, {0,1}});
    std::cout << "m1: " << m1 << std::endl;
    std::cout << m1.trace() << std::endl;

    Matrix<float> m2 = Matrix<float>({{2,0}, {0,2}});
    std::cout << "m2: " << m2 << std::endl;
    std::cout << m2.trace() << std::endl;

    Matrix<float> m3 = Matrix<float>({{2,-2}, {-2,-22}});
    std::cout << "m3: " << m3 << std::endl;
    std::cout << m3.trace() << std::endl;

    Matrix<float> id = Matrix<float>({{1,0,0}, {0,1,0}, {0,0,1}});
    std::cout << "id: " << id << std::endl;
    std::cout << id.trace() << std::endl;

    Matrix<float> lamdaId = Matrix<float>({{3,0,0}, {0,3,0}, {0,0,3}});
    std::cout << "lamdaId: " << lamdaId << std::endl;
    std::cout << lamdaId.trace() << std::endl;

    Matrix<float> rect_4_4 = Matrix<float>({{1,2,3,4}, {3,4,5,6}, {5,6,6,7}, {8,5,6,8}});
    std::cout << "rect_4_4: " << rect_4_4 << std::endl;
    std::cout << rect_4_4.trace() << std::endl;

    return 0;
}
