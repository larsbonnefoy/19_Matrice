#include "../Includes/Vector.hpp"
#include "../Includes/Matrix.hpp"

int main(int ac, char **av) {
    (void) ac, (void)av;

    float simpleVec[3] = {-1.2f, 2.2f ,3.3f};
    Vector<int> vec = Vector<int>();
    Vector<float> vec2 = Vector<float>(simpleVec, 3);
    Vector<int> vec3 = Vector<int>(10);
    std::cout << vec.getSize() << std::endl;
    vec.toStdOut();
    std::cout << vec2.getSize() << std::endl;
    vec2.toStdOut();
    std::cout << vec3.getSize() << std::endl;
    vec3.toStdOut();
    std::cout << std::endl;

    Matrix<float> *matFloat = new Matrix<float>(6, 3);
    matFloat->toStdOut();
    std::cout << std::endl;
    Matrix<int> *matInt = new Matrix<int>(3, 3);
    matInt->toStdOut();

    delete matFloat;
    delete matInt;
    /*
    std::cout << __builtin_cpu_supports("sse") << std::endl;
    std::cout << __builtin_cpu_supports("sse2") <<std::endl;
    std::cout << __builtin_cpu_supports("avx") << std::endl;
    std::cout << __builtin_cpu_supports("avx2") <<std::endl;
    std::cout << __builtin_cpu_supports("avx512f")<< std::endl;
    */
    return 0;
}
