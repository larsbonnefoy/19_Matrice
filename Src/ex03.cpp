#include "../Includes/Vector.hpp"

int main (void)
{
    Vector<float> v1 = Vector<float>({2, 1});
    Vector<float> v2 = Vector<float>({4, 2});
    std::cout << v1.dot(v2) << std::endl;
    std::cout << v2.dot(v1) << std::endl;

    Vector<float> v3 = Vector<float>({0, 0}); //dot product with nul vector = 0
    Vector<float> v4 = Vector<float>({4, 2});
    std::cout << v3.dot(v4) << std::endl;

    Vector<float> v5 = Vector<float>({-1, 6});
    Vector<float> v6 = Vector<float>({3, 2});
    std::cout << v5.dot(v6) << std::endl;

    Vector<float> v7 = Vector<float>({-1, 6, 10, -2});
    Vector<float> v8 = Vector<float>({3, 2, -3, 4});
    std::cout << v7.dot(v8) << std::endl;

    Vector<float> v9 = Vector<float>({-1, 6});
    Vector<float> v10 = Vector<float>({3, 2, -3, 4});
    std::cout << v9.dot(v10) << std::endl;

    return 0;
}
