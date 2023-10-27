#include "../Includes/Matrix.hpp"
#include "../Includes/Vector.hpp"
#include <iostream>

int main (void)
{
    Matrix<float> m2 = Matrix<float>({{2, -1, 0}, {-1, 2, -1}, {0, -1, 2}});
    std::cout << "m: " << m2 << std::endl;
    Matrix<float> *mInv2 = m2.inverse();
    std::cout << "minv : "<< *mInv2 << std::endl;
    Matrix<float> *mmult2 = m2.mul_mat(*mInv2);
    std::cout << "id : "<< *mmult2 << std::endl;

    delete mInv2;
    delete mmult2;
    std::cout << "============================" << std::endl;

    Matrix<float> m3 = Matrix<float>({{2,0,0}, {0, 2, 0}, {0, 0, 2}});
    std::cout << "m: " << m3 << std::endl;
    Matrix<float> *mInv3 = m3.inverse();
    std::cout << "minv : " << *mInv3 << std::endl;
    Matrix<float> *mmult3 = m3.mul_mat(*mInv3);
    std::cout << "id : "<< *mmult3 << std::endl;

    delete mInv3;
    delete mmult3;
    std::cout << "============================" << std::endl;

    Matrix<float> m1 = Matrix<float>({{8,5,-2}, {4,7,20}, {7,6,1}});
    std::cout << "m: " << m1 << std::endl;
    Matrix<float> *mInv1 = m1.inverse();
    std::cout << "minv : "<< *mInv1 << std::endl;
    Matrix<float> *mmult1 = m1.mul_mat(*mInv1);
    std::cout << "id : "<< *mmult1 << std::endl;

    delete mInv1;
    delete mmult1;
    std::cout << "============================" << std::endl;

    return 0;
}
