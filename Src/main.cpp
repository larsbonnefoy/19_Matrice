#include "../Includes/Vector.hpp"
#include "../Includes/Matrix.hpp"

int main(int ac, char **av) {
    (void) ac, (void)av;

    Vector<float> vec1 = Vector<float>({-1.2, 2.2, 3.4});
    Vector<float> vec2 = Vector<float>({+1.0, +2.0, +3.0});
    Vector<float> smallVec = Vector<float>({+2.0, +1.0});
    Vector<float> bigVec = Vector<float>({+2.0, +1.0, +0, -1});
    Matrix<float> test = Matrix<float>({vec1, vec1, vec1});
    Matrix<float> testbis = Matrix<float>({{1.0, 0, 0}, {0, 1, 0}, {0, 0, 1}});
    Matrix<float> oneMatrix = Matrix<float>({{1.0, 1, 1}, {1, 1, 1}, {1, 1, 1}});
    std::cout << "vec1 " << vec1 << std::endl;
    std::cout << "vec1 * 2 " << vec1  * 2 << std::endl;
    std::cout << "vec2 + smallVec " << vec2 + smallVec << std::endl;
    std::cout << "vec2 + bigVec " << vec2 + bigVec << std::endl;
    std::cout << "matrix test " << std::endl << test << std::endl;
    std::cout << "matrix testbis " << std::endl << testbis << std::endl;
    test.add(testbis);
    std::cout << "added Matrix" << std::endl << test << std::endl;
    std::cout << "testbis " << std::endl << testbis << std::endl;
    test.scale(2);
    std::cout << "scaled matrix" << std::endl << test << std::endl;

    //test.toStdOut();
    //testbis.toStdOut();
    /*
    std::cout << __builtin_cpu_supports("sse") << std::endl;
    std::cout << __builtin_cpu_supports("sse2") <<std::endl;
    std::cout << __builtin_cpu_supports("avx") << std::endl;
    std::cout << __builtin_cpu_supports("avx2") <<std::endl;
    std::cout << __builtin_cpu_supports("avx512f")<< std::endl;
    */
    return 0;
}
