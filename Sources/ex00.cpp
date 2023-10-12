#include "../Includes/Vector.hpp"
#include "../Includes/Matrix.hpp"

int main(int ac, char **av) {
    (void) ac, (void)av;

    Vector<float> v1 = Vector<float>({-1.2, 2.2, 3.4});
    Vector<float> v2 = Vector<float>({+1.0, +2.0, +3.0});

    Vector<float> vX = Vector<float>({1, 0, 0});
    Vector<float> vY = Vector<float>({0, 1, 0});
    Vector<float> vZ = Vector<float>({0, 0, 1});

    std::cout << "ADDITION" << std::endl;
    std::cout << v1 << std::endl;
    std::cout << "+" << std::endl;
    std::cout << vX << std::endl;
    std::cout << "=" << std::endl;
    std::cout << v1 + vX << std::endl;
    std::cout << v1 << " -> in place operation, does not return new value" << std::endl;
    std::cout << std::endl;

    std::cout << "SUBSTRACTION" << std::endl;
    std::cout << v1 << std::endl;
    std::cout << "-" << std::endl;
    std::cout << vY << std::endl;
    std::cout << "=" << std::endl;
    std::cout << v1 - vY << std::endl;
    std::cout << std::endl;

    std::cout << "SCALE" << std::endl;
    std::cout << v1 << std::endl;
    std::cout << "*" << std::endl;
    std::cout << 2 << std::endl;
    std::cout << "=" << std::endl;
    std::cout << v1 * 2 << std::endl;
    std::cout << std::endl;

    Matrix<float> id = Matrix<float>({vX, vY, vZ});
    std::cout << "ID: " << id << std::endl;
    Matrix<float> one = Matrix<float>({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
    std::cout << "One: " << one << std::endl;
    Matrix<float> empty = Matrix<float>(3, 3);
    std::cout << "Empty: " << empty << std::endl << std::endl;

    std::cout << "ADDITION";
    std::cout << empty << std::endl;
    std::cout << "+";
    std::cout << id << std::endl;
    std::cout << "=";
    std::cout << empty + id<< std::endl;
    std::cout << empty << " -> in place operation, does not return new value" << std::endl;
    std::cout << std::endl;

    std::cout << "SUBSTRACTION";
    std::cout << one << std::endl;
    std::cout << "-";
    std::cout << id << std::endl;
    std::cout << "=";
    std::cout << one - id<< std::endl;
    std::cout << std::endl;

    std::cout << "SCALE";
    std::cout << id << std::endl;
    std::cout << "*";
    std::cout << 2 << std::endl;
    std::cout << "=";
    std::cout << id * 2 << std::endl;
    std::cout << std::endl;
    return 0;
}
