#include "../Includes/Vector.hpp"

int main (void)
{
    Vector<float> v1 = Vector<float>({0, 0, 1});
    Vector<float> v2 = Vector<float>({1, 0, 0});
    Vector<float> *crossV1V2 = cross_product(v1, v2);
    std::cout << "v1 = " << v1 << " v2 = " << v2 << " cross = "<< *crossV1V2 << " norm = "<< crossV1V2->norm() << std::endl;
    
    Vector<float> v3 = Vector<float>({1, 2, 3});
    Vector<float> v4 = Vector<float>({4, 5, 6});
    Vector<float> *crossV3V4 = cross_product(v3, v4);
    std::cout << "v3 = " << v3 << " v4 = " << v4 << " cross = "<< *crossV3V4 << " norm = "<< crossV3V4->norm() << std::endl;

    Vector<float> v5 = Vector<float>({4, 2, -3});
    Vector<float> v6 = Vector<float>({-2, -5, 16});
    Vector<float> *crossV5V6 = cross_product(v5, v6);
    std::cout << "v5 = " << v5 << " v6 = " << v6 << " cross = "<< *crossV5V6 << " norm = "<< crossV5V6->norm() << std::endl;

    Vector<float> v7 = Vector<float>({4, 2, -3});
    Vector<float> v8 = Vector<float>({4, 2, -3});
    Vector<float> *crossV7V8 = cross_product(v7, v8);
    std::cout << "v7 = " << v7 << " v8 = " << v8 << " cross = "<< *crossV7V8 << " norm = "<< crossV7V8->norm() << std::endl;

    Vector<float> v9 = Vector<float>({4, 2, });
    Vector<float> v10 = Vector<float>({-4, -2, -3});
    Vector<float> *crossV9V10 = cross_product(v9, v10);
    std::cout << "v9 = " << v9 << " v10 = " << v10 << " cross = "<< *crossV9V10 << " norm = "<< crossV9V10->norm() << std::endl;

    delete crossV1V2;
    delete crossV3V4;
    delete crossV5V6;
    delete crossV7V8;
    delete crossV9V10;
    return 0;
}
