#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "./Vector.hpp"
#include <exception>
#include <initializer_list>
#include <sys/types.h>
#include <vector>

/*
 * Cannot be irregular Matrix!
 * 
 * "ROW MAJOR"
 * C uses "Row Major", which stores all the elements for a given row contiguously in memory. -> Z
 *  Have m different vectors of size n
 */

template<typename T>
class Matrix {
    private:
        uint32_t    _rows; //_rows
        uint32_t    _cols; //col
        Vector<T>   **_matrix;

    public:

/********************************Constructors**********************************/
        Matrix(void): Matrix(1,1) {
        }

        Matrix(const uint32_t m, const uint32_t n) : _rows(m), _cols(n) {
            _matrix = new Vector<T>*[_rows];
            for (uint32_t i = 0; i < _rows; i++) {
                _matrix[i] = new Vector<T>(_cols); 
            }
        }

        Matrix(std::initializer_list<Vector<T> > vecList) : _rows(vecList.size()), _cols(0) {
            _matrix = new Vector<T>*[_rows];
            typename std::initializer_list<Vector<T> >::iterator vecIt;
            uint32_t i = 0;
            for ( vecIt=vecList.begin(); vecIt!=vecList.end(); ++vecIt) {
                if (_cols == 0) {
                    _cols = vecIt->getSize();
                }
                else if (vecIt->getSize() != _cols) {
                    throw std::exception();
                }
                _matrix[i] = new Vector<T>(*vecIt);
                i++;
            }
        }

        ~Matrix(void) {
            for (uint32_t i = 0; i < _rows; ++i) {
                delete _matrix[i];
            }
            delete[] this->_matrix;
        }

/****************************Getters*******************************************/

        bool isSquare(void) const {
            return (this->_rows == this->_cols);
        }

        uint32_t getRowsNb(void) const {
            return (this->_rows);
        }

        uint32_t getColNb(void) const {
            return (this->_cols);
        }

        //Returns in matrix by id
         Vector<T>* getRow(uint32_t rowId) const {
             if (rowId > this->_rows) {
                throw std::exception();
             }
             return _matrix[rowId];
        }

/*********************************Operations***********************************/

        //Row by Row addition of matrix into "this" object
        Matrix<T>& add(const Matrix<T>& matrix) {
            for (uint32_t i = 0;  i < this->_rows;  i++) {
                _matrix[i]->add(*(matrix.getRow(i)));
            }
            return (*this);
        }

        //Row by Row substraction of matrix into "this" object
        Matrix<T>& sub(const Matrix<T>& matrix) {
            for (uint32_t i = 0;  i < this->_rows;  i++) {
                _matrix[i]->sub(*(matrix.getRow(i)));
            }
            return (*this);
        }

        Matrix<T>& scale(const T&a) {
            for (uint32_t i = 0;  i < this->_rows;  i++) {
                _matrix[i]->scale(a);
            }
            return (*this);
        }


/****************************Operator Overload*********************************/

        void            toStdOut() const {
            std::cout << std::endl;
            for (uint32_t i = 0;  i < this->_rows;  i++) {
                std::cout << "|";
                _matrix[i]->toStdOut();
                std::cout << "|";
                if (i != this->_rows - 1) {
                    std::cout << std::endl;
                }
            }
        }
        
        //Adds second Matrix into first one 
        Matrix<T>& operator+(const Matrix<T> &matrix) {
            this->add(matrix);
            return (*this);
        }

        //Subtract second Matrix into first one 
        Matrix<T>& operator-(const Matrix<T> &matrix) {
            this->sub(matrix);
            return (*this);
        }

        //Scales Matrix by value of T
        Matrix<T>& operator*(const T &a) {
            this->scale(a);
            return (*this);
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix<T> &matrix) {
            matrix.toStdOut();
            return os;
        }
};

template<typename T>
Matrix<T>& lerp(Matrix<T> &m1, Matrix<T>& m2, float t) {
    (void) t;
    (void) m2;
    std::cout << m1.getColNb() << " " << m1.getRowsNb() << std::endl;
    Matrix<T> *resultMatrix = new Matrix<T>(m1.getColNb(), m1.getRowsNb());

    return *resultMatrix;
}
#endif
