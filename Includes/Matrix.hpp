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

        //init only rows of matrix
        Matrix(const uint32_t m) : _rows(m) {
            _matrix = new Vector<T>*[_rows];
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

        Matrix(const Matrix& other) : _rows(other.getRowsNb()), _cols(other.getColNb()) {
            _matrix = new Vector<T>*[_rows];
            for (uint32_t i = 0; i < _rows; ++i) {
                _matrix[i] = new Vector<T>(*other._matrix[i]);
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
        Vector<T>& getRow(uint32_t rowId) const {
            if (rowId > this->_rows) {
                throw std::exception();
            }
            return *_matrix[rowId];
        }

        /*
         * Returns a new Obj Vector representing column of matrix
         */
        Vector<T>* getCol(uint32_t colId) const {
            if (_cols - 1 < colId) {
                throw std::exception();
            }
            Vector<T> *resVec = new Vector<T>(_rows);
            T* vecData = resVec->getData();

            for (uint32_t i = 0; i < _rows; i++) {
                vecData[i] = _matrix[i]->getData()[colId];
            }
            return resVec;
        }

        Vector<T>* getRowAddr(uint32_t rowId) {
            if (rowId > this->_rows) {
                throw std::exception();
            }
            return _matrix[rowId];
        }

        Vector<T>** getData() {
            return _matrix;
        }


/*********************************Operations***********************************/

        //Row by Row addition of matrix into "this" object
        Matrix<T>& add(const Matrix<T>& matrix) {
            for (uint32_t i = 0;  i < this->_rows;  i++) {
                _matrix[i]->add(matrix.getRow(i));
            }
            return (*this);
        }

        //Row by Row substraction of matrix into "this" object
        Matrix<T>& sub(const Matrix<T>& matrix) {
            for (uint32_t i = 0;  i < this->_rows;  i++) {
                _matrix[i]->sub(matrix.getRow(i));
            }
            return (*this);
        }

        Matrix<T>& scale(const T&a) {
            for (uint32_t i = 0;  i < this->_rows;  i++) {
                _matrix[i]->scale(a);
            }
            return (*this);
        }
        
        /*
         * Dot production of each row with vector
         */
        Vector<T>* mul_vec(const Vector<T>& vec) {
            Vector<T> *res = new Vector<T>(vec.getSize());
            T* data = res->getData();

            for (uint32_t i = 0; i < _rows; i++) {
                data[i] = _matrix[i]->dot(vec);
            }
            return res;
        }

        /*
         * (m x n) * (n x p) = (m x p)
         *   this  *   m     = this._rows * m.getColNb
         *   n^3 complexity
         *   Need to get col of matrix m
         */
        Matrix<T>* mul_mat(const Matrix<T>& m) {
            if (_cols != m._rows) {
                throw std::exception();
            }

            Matrix<T> *res = new Matrix<T>(_rows);
            Vector<T>** resMatrix = res->getData();

            Matrix<T> *mT = m.transpose();
            Vector<T> ** mTData = mT->getData();

            for (uint32_t i = 0; i < _rows; i++) {
                Vector<T> *newRow = new Vector<T>(m.getColNb());
                T* dataRow = newRow->getData();

                for (uint32_t j = 0; j < mT->getRowsNb(); j++) {
                    dataRow[j] = _matrix[i]->dot(*mTData[j]);
                }
                resMatrix[i] = newRow;
            }

            delete mT;
            return res;
        }

        /*
         * Multiply in place matrice this with m
         * Need a copy of current row of this matrix
         * Only possible if both matrices are square
         * Returns ptr to this object
         */
        Matrix<T>* mul_mat_ip(const Matrix<T>& m) {
            if (_cols != m._rows) {
                throw std::exception();
            }

            Matrix<T> *mT = m.transpose();
            Vector<T> ** mTData = mT->getData();

            for (uint32_t i = 0; i < _rows; i++) {
                Vector<T> *cpyCurrentRow = new Vector<T>(*_matrix[i]);

                for (uint32_t j = 0; j < mT->getRowsNb(); j++) {
                    (*_matrix[i])[j] = cpyCurrentRow->dot(*mTData[j]);
                }
                delete cpyCurrentRow;
            }

            return this;
        }

        Matrix<T>* transpose() const {
            Matrix<T> *res = new Matrix<T>(_cols);
            Vector<T> **resMatrix = res->getData();

            for (uint32_t i = 0; i < _cols; i++) {
                resMatrix[i] = this->getCol(i);
            }
            return res;
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

        Vector<T>& operator[](uint32_t index) {
            return this->getRow(index);
        }

        Matrix<T>& operator=(const Matrix<T> &other) {
            for (uint32_t i = 0; i < other.getRowsNb(); i++) {
                _matrix[i] = other._matrix[i]; 
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Matrix<T> &matrix) {
            matrix.toStdOut();
            return os;
        }
};

/*
 * Returns new *Matrix 
 */
template<typename T>
Matrix<T>* lerp(Matrix<T> &m1, Matrix<T> &m2, float t) {
    Matrix<T> *resultMatrix = new Matrix<T>(m1.getRowsNb());
    Vector<T>** matrix = resultMatrix->getData();

    for (uint32_t i = 0; i < m1.getColNb(); i++) {
        matrix[i] = lerp(m1[i], m2[i], t);
    }
    return resultMatrix;
}
#endif
