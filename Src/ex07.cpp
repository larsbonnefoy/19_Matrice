#include "../Includes/Matrix.hpp"
#include "../Includes/Vector.hpp"
#include <iostream>
#include <ostream>

int main (void)
{
    Matrix<float> m1 = Matrix<float>({{1,0}, {0,1}});
    Vector<float> v1 = Vector<float>({4, 2});
    Vector<float> *vmul1 = m1.mul_vec(v1);
    std::cout << "m1: " << m1 << std::endl << "v1: " << v1 << std::endl;
    std::cout << "m1 * v1: " << *vmul1 << std::endl << std::endl;
    delete vmul1;

    Matrix<float> m2 = Matrix<float>({{2,0}, {0,2}});
    Vector<float> v2 = Vector<float>({4, 2});
    Vector<float> *vmul2 = m2.mul_vec(v2);
    std::cout << "m2: " << m2 << std::endl << "v2: " << v2 << std::endl;
    std::cout << "m2 * v2: " << *vmul2 << std::endl << std::endl;
    delete vmul2;

    Matrix<float> m3 = Matrix<float>({{2,-2}, {-2,2}});
    Vector<float> v3 = Vector<float>({4, 2});
    Vector<float> *vmul3 = m3.mul_vec(v3);
    std::cout << "m3: " << m3 << std::endl << "v3: " << v3 << std::endl;
    std::cout << "m3 * v3: " << *vmul3 << std::endl << std::endl;
    delete vmul3;

    Matrix<float> m4 = Matrix<float>({{3,-5}, {6,8}});
    Matrix<float> m5 = Matrix<float>({{2,1}, {4,2}});
    Matrix<float> *mmul = m4.mul_mat(m5);
    std::cout << "m4: " << m4 << std::endl << "m5: " << m5 << std::endl;
    std::cout << "m4 * m5: " << *mmul << std::endl << std::endl;
    delete mmul;


    std::cout << "mul in place: " << std::endl;
    std::cout << "m4: " << m4 << std::endl;
    std::cout << "m5: " << m5 << std::endl;
    mmul = m4.mul_mat_ip(m5);
    std::cout << "m4*m5: "<< *mmul << std::endl;
    std::cout << "m4: " << m4 << std::endl << std::endl;

    Matrix<float> id = Matrix<float>({{1,0,0}, {0,1,0}, {0,0,1}});
    Matrix<float> lamdaId = Matrix<float>({{3,0,0}, {0,3,0}, {0,0,3}});
    Matrix<float> rotation180 = Matrix<float>({{-1,0,0}, {0,1,0}, {0,0,1}});
    Matrix<float> rotation90 = Matrix<float>({{0,0,-1}, {0,1,0}, {1,0,0}});
    Vector<float> v = Vector<float>({1,2,3});

    std::cout << "v: " << v << std::endl << std::endl;

    Vector<float> *vmul4 = id.mul_vec(v);
    std::cout << "v*id: " << *vmul4 << std::endl << std::endl;
    delete vmul4;
    
    std::cout << "lamdaID" << lamdaId << std::endl;
    Vector<float> *vmul5 = lamdaId.mul_vec(v);
    std::cout << "lamdaId * v: " << *vmul5 << std::endl << std::endl;
    delete vmul5;

    std::cout << "rotation90" << rotation90 << std::endl;
    Vector<float> *vmul6 = rotation90.mul_vec(v);
    std::cout << "rotation90 * v: " << *vmul6 << std::endl << std::endl;
    delete vmul6;

    std::cout << "rotation180" << rotation180 << std::endl;
    Vector<float> *vmul7 = rotation180.mul_vec(v);
    std::cout << "rotation180 * v: " << *vmul7 << std::endl << std::endl;
    delete vmul7;

    Matrix<float> rect_3_2 = Matrix<float>({{1,2}, {3,4}, {5,6}});
    Matrix<float> rect_2_4 = Matrix<float>({{1,2,3,4}, {3,4,5,6}});
    std::cout << "3x2:" << rect_3_2 << std::endl;
    std::cout << "2x4:" << rect_2_4 << std::endl;
    Matrix<float>  *mmul1 = rect_3_2.mul_mat(rect_2_4);
    std::cout << "3x2 * 2x4: " << *mmul1 << std::endl << std::endl;

    std::cout << "a*b != b*a" << std::endl;
    Matrix<float> sheer = Matrix<float>({{1,2}, {0,1}});
    Matrix<float> rotation902D = Matrix<float>({{0,-1}, {1,0}});
    std::cout << "sheer: " << sheer << std::endl;
    std::cout << "rotation902D: " << rotation902D << std::endl << std::endl;
    Matrix<float>  *mmul3 = rotation902D.mul_mat(sheer);
    std::cout << "rotation902D * sheer" << *mmul3 << std::endl << std::endl;
    Matrix<float>  *mmul4 = sheer.mul_mat(rotation902D);
    std::cout << "sheer * rotation90" << *mmul4 << std::endl << std::endl;

    return 0;
}
