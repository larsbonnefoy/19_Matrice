#include "../Includes/Vector.hpp"
#include "../Includes/Matrix.hpp"

int main(int ac, char **av) {
    (void) ac, (void)av;

    Vector<float> vec1 = Vector<float>({-1.2, 2.2, 3.4});
    Matrix<float> test = Matrix<float>({vec1, vec1, vec1});
    Matrix<float> testbis = Matrix<float>({{1.0, 0, 0}, {0, 1, 0}, {0, 0, 1}});

    test.toStdOut();
    testbis.toStdOut();
    /*
    std::cout << __builtin_cpu_supports("sse") << std::endl;
    std::cout << __builtin_cpu_supports("sse2") <<std::endl;
    std::cout << __builtin_cpu_supports("avx") << std::endl;
    std::cout << __builtin_cpu_supports("avx2") <<std::endl;
    std::cout << __builtin_cpu_supports("avx512f")<< std::endl;
    */
    return 0;
}
