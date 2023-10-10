#include "../Includes/Vector.hpp"
#include "../Includes/Matrix.hpp"

int main(int ac, char **av) {
    (void) ac, (void)av;

    float simpleVec[3] = {-1.2f, 2.2f ,3.3f};
    Vector<int> vec = Vector<int>();
    Vector<float> vec2 = Vector<float>(simpleVec, 3);
    Vector<int> vec3 = Vector<int>(3);
    Vector<int> vec4 = Vector<int>(-1);
    std::cout << vec.getSize() << std::endl;
    vec.toStdOut();
    std::cout << vec2.getSize() << std::endl;
    vec2.toStdOut();
    std::cout << vec3.getSize() << std::endl;
    vec3.toStdOut();
    return 0;
}
