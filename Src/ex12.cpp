#include "../Includes/Matrix.hpp"
#include "../Includes/Vector.hpp"
#include <iostream>

int main (void)
{
    /*
    Vector<float> v1 = Vector<float>({2, 1});
    Vector<float> v2 = Vector<float>({4, 2});
    Vector<float> *vfused = v1.fuse(v2);
    Vector<float> *vsplit = vfused->splitRight(2);
    std::cout << *vfused << std::endl;
    std::cout << *vsplit << std::endl;
    delete  vfused;
    */


    Matrix<float> m2 = Matrix<float>({{2, -1, 0}, {-1, 2, -1}, {0, -1, 2}});
    Matrix<float> *mInv2 = m2.inverse();
    std::cout << *mInv2 << std::endl;
    Matrix<float> *mmult2 = m2.mul_mat(*mInv2);
    std::cout << *mmult2 << std::endl;

    delete mInv2;
    delete mmult2;

    Matrix<float> m3 = Matrix<float>({{2,0,0}, {0, 2, 0}, {0, 0, 2}});
    Matrix<float> *mInv3 = m3.inverse();
    std::cout << *mInv3 << std::endl;
    Matrix<float> *mmult3 = m3.mul_mat(*mInv3);
    std::cout << *mmult3 << std::endl;

    delete mInv3;
    delete mmult3;

    Matrix<float> m1 = Matrix<float>({{8,5,-2}, {4,7,20}, {7,6,1}});
    Matrix<float> *mInv1 = m1.inverse();
    std::cout << *mInv1 << std::endl;
    Matrix<float> *mmult1 = m1.mul_mat(*mInv1);
    std::cout << *mmult1 << std::endl;

    delete mInv1;
    delete mmult1;

    return 0;
}
