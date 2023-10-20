#include "../Includes/Vector.hpp"
#include "../Includes/Matrix.hpp"

int main(int ac, char **av) {
    (void) ac, (void)av;

    Vector<float> vec1 = Vector<float>({-1.2, 2.2, 3.4});
    Vector<float> vec2 = Vector<float>({+1.0, +2.0, +3.0});


    Vector<float> v = vec1;
    Vector<float> v2 = Vector<float>(v);
    std::cout << vec1 << std::endl;
    std::cout << v  << std::endl;
    std::cout << v2  << std::endl;

    Matrix<float> one = Matrix<float>({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
    Matrix<float> two = Matrix<float>(one);
    Matrix<float> three = two;
    std::cout << one << std::endl;
    std::cout << two << std::endl;
    std::cout << three << std::endl;

    /*
    std::cout << __builtin_cpu_supports("sse") << std::endl;
    std::cout << __builtin_cpu_supports("sse2") <<std::endl;
    std::cout << __builtin_cpu_supports("avx") << std::endl;
    std::cout << __builtin_cpu_supports("avx2") <<std::endl;
    std::cout << __builtin_cpu_supports("avx512f")<< std::endl;
    */
    return 0;
}
