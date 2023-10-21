#include "../Includes/Matrix.hpp"
#include "../Includes/Vector.hpp"

int main (void)
{
    Matrix<float> m1 = Matrix<float>({{1,0}, {0,1}});
    Vector<float> v1 = Vector<float>({4, 2});
    Vector<float> *vmul1 = m1.mul_vec(v1);
    std::cout << *vmul1 << std::endl;

    delete vmul1;

    Matrix<float> m2 = Matrix<float>({{2,0}, {0,2}});
    Vector<float> v2 = Vector<float>({4, 2});
    Vector<float> *vmul2 = m2.mul_vec(v2);
    std::cout << *vmul2 << std::endl;
    delete vmul2;

    Matrix<float> m3 = Matrix<float>({{2,-2}, {-2,2}});
    Vector<float> v3 = Vector<float>({4, 2});
    Vector<float> *vmul3 = m3.mul_vec(v3);
    std::cout << *vmul3 << std::endl;
    delete vmul3;

    Matrix<float> m4 = Matrix<float>({{3,-5}, {6,8}});
    Matrix<float> m5 = Matrix<float>({{2,1}, {4,2}});
    Matrix<float> *mmul = m4.mul_mat(m5);
    std::cout << *mmul << std::endl;
    delete mmul;

    std::cout << m4 << std::endl;
    mmul = m4.mul_mat_ip(m5);
    std::cout << *mmul << std::endl;
    std::cout << m4 << std::endl;

    /*
    Vector<float> vX = Vector<float>({1, 0, 0});
    Vector<float> vY = Vector<float>({0, 1, 0});
    Vector<float> vZ = Vector<float>({0, 0, 1});

    Matrix<float> id = Matrix<float>({vX, vY, vZ});
    std::cout << "ID: " << id << std::endl;
    Matrix<float> one = Matrix<float>({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
    std::cout << "One: " << one << std::endl;
    Matrix<float> empty = Matrix<float>(3, 3);
    std::cout << "Empty: " << empty << std::endl << std::endl;
    */

    return 0;
}
