#include "../Includes/Vector.hpp"

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
    return 0;
}
