#include <xmmintrin.h>
#include <stdio.h>

int main() {
    __m128 vec = {1.0, 2.0, 3.0, 4.0};
    __m128 vec1 = {3.4, 1.1, 2.7, 3.1};
    int a[8] __attribute__((aligned(16))) = { 1, 2, 3, 4, 5, 6, 7, 8 };

    for (int i  = 0; i < 4; i++) {
        printf("%f ", vec[i]);
    }
    printf("\n");
    for (int i  = 0; i < 4; i++) {
        printf("%f ", vec1[i]);
    }
    printf("\n");

    __m128 res = _mm_add_ps(vec, vec1);

    for (int i  = 0; i < 4; i++) {
        printf("%f ", res[i]);
    }
}
