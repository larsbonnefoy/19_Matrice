#include "../Includes/Vector.hpp"
#include "../Includes/Matrix.hpp"

int main (void)
{
    Vector<float> vX = Vector<float>({1, 0, 0});
    Vector<float> vY = Vector<float>({0, 1, 0});
    Vector<float> vZ = Vector<float>({0, 0, 1});

    Vector<float> v1 = Vector<float>({1, 2, 3});
    Vector<float> v2 = Vector<float>({0, 10, -100});
    Vector<float> v3 = Vector<float>({0, 0, 0});
    
    Vector<float> *combiLi = linear_combination({vX, vY, vZ}, {10.0f, -2.0f, -0.5f});
    Vector<float> *combiLi2 = linear_combination({v1, v2}, {10.0f, -2.0f});

    std::cout << *combiLi << std::endl;
    std::cout << *combiLi2 << std::endl;

    delete combiLi;
    delete combiLi2;
    return 0;
}
