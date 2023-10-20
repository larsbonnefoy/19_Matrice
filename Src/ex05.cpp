#include "../Includes/Vector.hpp"

int main (void)
{
    Vector<float> v1 = Vector<float>({1, 0});
    Vector<float> v2 = Vector<float>({1, 0});
    std::cout << angle_cos(v1, v2) << std::endl;
    std::cout << angle_cos(v2, v1) << std::endl;

    Vector<float> v3 = Vector<float>({1, 0});
    Vector<float> v4 = Vector<float>({0, 1});
    std::cout << angle_cos(v3, v4) << std::endl;

    Vector<float> v5 = Vector<float>({-1, 1});
    Vector<float> v6 = Vector<float>({1, -1});
    std::cout << angle_cos(v5, v6) << std::endl;

    Vector<float> v7 = Vector<float>({2, 1});
    Vector<float> v8 = Vector<float>({4, 2});
    std::cout << angle_cos(v7, v8) << std::endl;

    Vector<float> v9 = Vector<float>({1, 2, 3});
    Vector<float> v10 = Vector<float>({4, 5, 6});
    std::cout << angle_cos(v9, v10) << std::endl;

    return 0;
}
