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
    /*
    std::cout << "m1: " << m1 << std::endl;
    std::cout << "m1T: " << *m1T << std::endl << std::endl;
    delete m1T;

    Matrix<float> m2 = Matrix<float>({{2,0}, {2,2}});
    Matrix<float> *m2T = m2.transpose();
    std::cout << "m2: " << m2 << std::endl;
    std::cout << "m2T: " << *m2T << std::endl << std::endl;
    delete m2T;

    Matrix<float> m3 = Matrix<float>({{2,-2}, {-2,-2}});
    Matrix<float> *m3T = m3.transpose();
    std::cout << "m3: " << m3 << std::endl;
    std::cout << "m3T: " << *m3T << std::endl << std::endl;
    delete m3T;

    Matrix<float> m4 = Matrix<float>({{3,-5}, {6,8}});
    Matrix<float> *m4T = m4.transpose();
    std::cout << "m4: " << m4 << std::endl;
    std::cout << "m4T: " << *m4T << std::endl << std::endl;
    delete m4T;

    Matrix<float> rect_3_2 = Matrix<float>({{1,2}, {3,4}, {5,6}});
    Matrix<float> *rect_3_2T = rect_3_2.transpose();
    std::cout << "rect_3_2: " << rect_3_2 << std::endl << std::endl;
    std::cout << "rect_3_2T: " << *rect_3_2T << std::endl << std::endl;
    delete rect_3_2T;

    Matrix<float> rect_2_4 = Matrix<float>({{1,2,3,4}, {3,4,5,6}});
    Matrix<float> *rect_2_4T = rect_2_4.transpose();
    std::cout << "rect_2_4: " << rect_2_4 << std::endl << std::endl;
    std::cout << "rect_2_4T: " << *rect_2_4T << std::endl << std::endl;
    delete rect_2_4T;
    */

    return 0;
}
