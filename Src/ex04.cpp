#include "../Includes/Vector.hpp"

int main (void)
{
    Vector<float> v0 = Vector<float>({0, 0, 0});
    std::cout << v0.norm_1() << " " << v0.norm() << " " << v0.norm_inf() << std::endl;

    Vector<float> v1 = Vector<float>({1, 2, 3});
    std::cout << v1.norm_1() << " " << v1.norm() << " " << v1.norm_inf() << std::endl;

    Vector<float> v3 = Vector<float>({-1, 2});
    std::cout << v3.norm_1() << " " << v3.norm() << " " << v3.norm_inf() << std::endl;

    return 0;
}
