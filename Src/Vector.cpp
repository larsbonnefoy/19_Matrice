#include "../Includes/Vector.hpp"

//Should only work with size 3 or less;
//extern __m128d _mm_fmadd_pd(__m128d a, __m128d b, __m128d c);
//extern __m128 _mm_fmadd_ps(__m128 a, __m128 b, __m128 c);
//-> a x b + c
Vector<float>& linear_combination_fma(std::initializer_list<Vector<float> > vec, std::initializer_list<float> coefs) {
    if (vec.begin()[0].getSize() > 3 || coefs.size() > 3) {
        std::cout << "Used normal combi li" << std::endl;
        return (linear_combination(vec, coefs));
    }
    std::cout << "using Vector FMA" << std::endl;
    Vector<float> *resultVector = new Vector<float>(vec.begin()[0].getSize());

    return *resultVector;
}
