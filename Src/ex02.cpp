#include "../Includes/Vector.hpp"
#include "../Includes/Matrix.hpp"

int main (void)
{
    Vector<float> v1 = Vector<float>({2, 1});
    Vector<float> v2 = Vector<float>({4, 2});

    std::cout << "(0;1;0) = "<< lerp(0.0f, 1.0f, 0.0f) << std::endl;
    std::cout << "(1;2;0.5) = "<< lerp(1.0f, 2.0f, 0.5f) << std::endl;
    std::cout << "(0;1;1) = " << lerp(0.0f, 1.0f, 1.0f) << std::endl;
    std::cout << "(0;1;0.5) = " << lerp(0.0f, 1.0f, 0.5) << std::endl;
    std::cout << "(0;10;0.9) = " << lerp(0.0f, 10.0f, 0.9) << std::endl;
    std::cout << "(0;10;1.1) = " << lerp(0.0f, 10.0f, 1.1) << std::endl;

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    std::cout << "(v1;v2;0.3) = " << lerp(v1, v2, 0.3) << std::endl;

    //Vector<float> v3 = Vector<float>({2, 1});
    //Vector<float> v4 = Vector<float>({3, 4});
    ////TODO: if not newed here, use after free segfault, if new, the segfault when delete
    //Matrix<float> m1 = Matrix<float>({v3, v4});
    //Vector<float> v5 = Vector<float>({20, 10});
    //Vector<float> v6 = Vector<float>({30, 40});
    //Matrix<float> m2 = Matrix<float>({v5, v6});
    //std::cout << "(m1;m2;0.5) = " << lerp(m1, m2, 0.5)<< std::endl;
    return 0;
}
