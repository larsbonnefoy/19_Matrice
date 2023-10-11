#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "./Vector.hpp"
#include <sys/types.h>
#include <vector>

/*
 * Cannot be irregular Matrix!
 * 
 * "ROW MAJOR"
 * C uses "Row Major", which stores all the elements for a given row contiguously in memory. -> Z
 * "COL MAJOR" 
 *  Have m different vectors of size n
 */

template<typename T>
class Matrix {
    private:
        uint32_t    _rows; //_rows
        uint32_t    _cols; //col
        Vector<T>   **_matrix;

    public:
        Matrix(void): Matrix(1,1) {
        }

        Matrix(const uint32_t m, const uint32_t n) : _rows(m), _cols(n) {
            _matrix = new Vector<T>*[_rows];
            for (uint32_t i = 0; i < _rows; i++) {
                _matrix[i] = new Vector<T>(_cols); 
            }
        }
        
        ~Matrix(void) {
            std::cout << "Destructor of Matrix Called" << std::endl;
            for (uint32_t i = 0; i < _rows; ++i) {
                delete _matrix[i];
            }
            delete this->_matrix;
        }

        bool isSquare(void) const {
            return (this->_rows == this->_cols);
        }

        uint32_t getRows(void) const {
            return (this->_rows);
        }

        uint32_t getCol(void) const {
            return (this->_cols);
        }

        void            toStdOut() const {
            for (uint32_t i = 0;  i < this->_rows;  i++) {
                std::cout << "|";
                _matrix[i]->toStdOut();
                std::cout << "|" << std::endl;
            }
        }
};

#endif
