#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "./Vector.hpp"

/*
 * Cannot be irregular Matrix!
 * 
 * "ROW MAJOR"
 * C uses "Row Major", which stores all the elements for a given row contiguously in memory. -> Z
 * "COL MAJOR" 
 * With column-major order, a "matrix × vector" multiply can be implemented with vectorized multiply-add operations -> W
 *  -> implemented in COL major 
 *  => Each Col is a vector (each column is stored contiguously in memory)
 *  Have n different vectors of size m
 */

template<typename T>
class Matrix {
    private:
        uint32_t _m; //rows
        uint32_t _n; //col



};

#endif
