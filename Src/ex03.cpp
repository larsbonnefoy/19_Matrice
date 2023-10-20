#include "../Includes/Vector.hpp"

int main (void)
{
    Vector<float> v1 = Vector<float>({2, 1});
    Vector<float> v2 = Vector<float>({4, 2});

    Vector<float> v3 = Vector<float>({0, 0});
    Vector<float> v4 = Vector<float>({4, 2});
    Vector<float> v5 = Vector<float>({-1, 6});
    Vector<float> v6 = Vector<float>({3, 2});
    std::cout << v1.dot(v2) << std::endl;
    std::cout << v2.dot(v1) << std::endl;

    std::cout << v3.dot(v4) << std::endl;
    std::cout << v5.dot(v6) << std::endl;
    return 0;
}
