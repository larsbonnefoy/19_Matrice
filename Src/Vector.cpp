#include "../Includes/Vector.hpp"
#include <cstring>

//Should only work with size 3 or less;
//extern __m128d _mm_fmadd_pd(__m128d a, __m128d b, __m128d c);
//extern __m128 _mm_fmadd_ps(__m128 a, __m128 b, __m128 c);
//-> a x b + c
//https://stackoverflow.com/questions/5273929/multiplying-vector-by-constant-using-sse/20458599#20458599
Vector<float>& linear_combination_fma(std::initializer_list<Vector<float> > vec, std::initializer_list<float> coefs) {
    uint32_t vecSize = vec.begin()[0].getSize();
    if (vecSize > 3 || coefs.size() > 3) {
        std::cout << "Used normal combi li" << std::endl;
        return (linear_combination(vec, coefs));
    }
    std::cerr << "FUNCTION DOES NOTHING ATM" << std::endl;
    Vector<float> *resultVector = new Vector<float>(vec.begin()[0].getSize());
    /*

    float* resVectorData = resultVector->getData();
    uint32_t i = 0; 
    for (const float& coef : coefs) {
        //const __m128 scalar = _mm_set1_ps(coef); //create vector of scalar values
        //__mm_fmadd_ps(scalar, scalar, scalar);
        i++;
    }
    */

    return *resultVector;
}
