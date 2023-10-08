#include "../Includes/Vector.hpp"

int main(int ac, char **av) {
    (void) ac, (void)av;

    Vector<int> vec = Vector<int>();
    Vector<int> vec3 = Vector<int>(3);
    std::cout << vec.getSize() << std::endl;
    vec.toStdOut();
    std::cout << vec3.getSize() << std::endl;
    vec3.toStdOut();
    return 0;
}
