#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "./Vector.hpp"
#include <exception>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <sys/types.h>
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

    /***********************PRIVATE HELPERS****************************/
        /*
         * Returns determinant for 1x1 matrix
         */
        T determinant_1() const {
            return (*_matrix[0])[0];
        }

        /*
         * Returns determinant for 2x2 of matrix passed in M;
         * | a b |
         * | c d | 
         * = ad - bc
         */
        T determinant_2(const Matrix<T> &m) const {
            Vector<T>** data = m.getData();
            return ((*data[0])[0]*(*data[1])[1] - (*data[0])[1]*(*data[1])[0]);
        }

        /*
         * Returns determinant for 3x3 of matrix passed in M;
         * Creates a copy and works in place on it
         */
        T determinant_3(const Matrix<T> &m) const {
            Matrix<T> tmpCpy = Matrix<T>(m);
            ssize_t factor = tmpCpy.gauss_elemination_ip();
            T rowMultVal = tmpCpy.mult_diag();
            return (factor * rowMultVal);
        }

        T determinant_4(const Matrix<T> &m) const {
            return (determinant_3(m));
        }

    /*****************************************************************/

    public:

/********************************Constructors**********************************/
        Matrix(void): Matrix(1,1) {
        }

        Matrix(const uint32_t m, const uint32_t n) : _rows(m), _cols(n) {
            _matrix = new Vector<T>*[_rows];
            for (uint32_t i = 0; i < _rows; i++) {
                _matrix[i] = new Vector<T>(_cols); 
                (*_matrix[i])[i] = 1;
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
            if (rowId > _rows - 1) {
                throw std::exception();
            }
            return _matrix[rowId];
        }

        Vector<T>** getData() const {
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
         * Input: matrices A and B
            Let C be a new matrix of the appropriate size
            For i from 1 to n:
                For j from 1 to p:
                    Let sum = 0
                    For k from 1 to m:
                        Set sum ← sum + Aik × Bkj
                    Set Cij ← sum
            Return C
        */
        Matrix<T>* mul_mat(const Matrix<T>& m) {

            if (_cols != m._rows) {
                throw std::exception();
            }

            Matrix<T> *res = new Matrix<T>(_rows);
            Vector<T>** resMatrix = res->getData();

            Vector<T>** mMatrixData = m.getData();

            for(uint32_t i = 0; i < _rows; i++) {
                Vector<T> *newRow = new Vector<T>(m.getColNb());
                T* dataRow = newRow->getData();
                for(uint32_t j = 0; j < m.getColNb(); j++) {
                    T sum = 0;
                    for (uint32_t k = 0; k < m.getRowsNb(); k++){
                        sum = std::fma((*_matrix[i])[k], (*mMatrixData[k])[j], sum);
                    }
                    dataRow[j] = sum;
                }
                resMatrix[i] = newRow;
            }
            return res;
        }

        /*
         * (m x n) * (n x p) = (m x p)
         *   this  *   m     = this._rows * m.getColNb
         *   n^3 complexity
         *   Need to get col of matrix m
         */
        Matrix<T>* mul_mat_transpose(const Matrix<T>& m) {
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
            if (_cols != m._rows && !this->isSquare()) {
                throw std::exception();
            }

            Vector<T>** mMatrixData = m.getData();

            for (uint32_t i = 0; i < _rows; i++) {
                Vector<T> *cpyCurrentRow = new Vector<T>(*_matrix[i]);
                T* cpyData = cpyCurrentRow->getData(); //already ith row
                for (uint32_t j = 0; j < m.getColNb(); j++) {
                    T sum = 0;
                    for (uint32_t k = 0; k < m.getRowsNb(); k++){
                        sum = std::fma(cpyData[k], (*mMatrixData[k])[j], sum);
                    }
                    (*_matrix[i])[j] = sum;
                }
                delete cpyCurrentRow;
            }
            return this;
        }

        /*
         * Computes sum of diagonal elements
         * Only defined for square matrices;
         */
        T trace() const {
            if (!this->isSquare()) {
                throw std::exception();
            }
            T trace = 0;
            for (uint32_t i = 0; i < _rows; i++) {
                trace += (*_matrix[i])[i]; 
            }
            return trace;
        }

        T mult_diag() const {
            if (!this->isSquare()) {
                throw std::exception();
            }
            T val = 1;
            for (uint32_t i = 0; i < _rows; i++) {
                val *= (*_matrix[i])[i]; 
            }
            return val;
        }

        Matrix<T>* transpose() const {
            Matrix<T> *res = new Matrix<T>(_cols);
            Vector<T> **resMatrix = res->getData();

            for (uint32_t i = 0; i < _cols; i++) {
                resMatrix[i] = this->getCol(i);
            }
            return res;
        }
       
        /*
         * swaps row i with row j
         * Going to crash if out of bonds;
         */
        void swap_row(uint32_t i, uint32_t j) {
            Vector<T>* tmp = getRowAddr(j);
            _matrix[j] = getRowAddr(i);
            _matrix[i] = tmp;
        }


        /*
         * Computes reduced row echelon from of matrix
         * Returns new Matrix obj
         *
         * There are three types of elementary row operations that do not change the solution set:
         * Swapping two rows                           -> multiplies det by -1
         * Multiplying a row by a nonzero number       -> multiplies det by same number
         * Adding a multiple of one row to another row -> does not change det

         * RREF
         * 1: Determine the leftmost non-zero column.
         * 2: Use elementary row operations to put a 1 in the topmost position of this column
         * 3: Use elementary row operations to put zeros (strictly) below the pivot position.
         * 4: If there are no more non-zero rows (strictly) below the pivot position, then go to Step 6
         * 5: Apply Step 2-5 to the submatrix consisting of the rows that lie (strictly below) the pivot position
         * 6: The resulting matrix is in row-echelon form 
         *
         */
        void row_echelon_ip() {
            uint32_t nextLeadPos = 0;
            uint32_t pivotRowIndex = 0;
            for (uint32_t i = 0; i < _cols; i++) { //i col i;
                //by using tmp col vector, have to scale values in this vector as well
                T   lead = 0;
                for (uint32_t j = 0; j < _rows; j++) { //j = row id 
                    if ((*_matrix[j])[i] != 0 && j >= nextLeadPos) {//only set new lead if row index is below the previous leading value
                        if (lead == 0 ) { 
                            lead = (*_matrix[j])[i];
                            pivotRowIndex = i > j ? j : i; //pivot row is at minium between j and i
                            if (lead != 1) {
                                (*_matrix[j]).scale(1/lead);
                            }
                            //should swap only if row is not in right place => j != i (j > i)
                            if (j > i) {
                                this->swap_row(j, i); 
                            }
                            //Should rescale every row up to i - 1 with new ith leading value (is not possible if there is no leading one in the col)
                            for (uint32_t k = 0; k < pivotRowIndex; k++) {
                                if ((*_matrix[k])[i] != 0) {
                                    Vector<T> scaledLeadingRow = Vector<T>(*_matrix[pivotRowIndex]).scale((*_matrix[k])[i]);
                                    (*_matrix[k]) - scaledLeadingRow; 
                                }
                            }
                            nextLeadPos++;
                        }
                        //set every other non 0 value in ith col to 0 by combi li of leading row (at nextLeadPos)
                        else {
                            Vector<T> scaledLeadingRow = Vector<T>(*_matrix[pivotRowIndex]).scale((*_matrix[j])[i]);
                            (*_matrix[j]) - scaledLeadingRow; 
                        }
                    }
                }
            }
        }
        
        /*
         * Returns new Matrix in row echelon form
         */
        Matrix<T>* row_echelon() const {
            Matrix<T> *res = new Matrix<T>(*this);
            res->row_echelon_ip();
            return res;
        }

        /*
         * Does in place gaussian elimination and returns factor by which
         * determinant should be scaled
         * There are three types of elementary row operations that do not change the solution set:
         * Swapping two rows                           -> multiplies det by -1
         * Multiplying a row by a nonzero number       -> multiplies det by same number
         * Adding a multiple of one row to another row -> does not change det
         */
        ssize_t gauss_elemination_ip() {
            uint32_t nextLeadPos = 0;
            uint32_t pivotRowIndex = 0;
            ssize_t scaleFactor = 1;
            for (uint32_t i = 0; i < _cols; i++) { //i col i;
                //by using tmp col vector, have to scale values in this vector as well
                T   lead = 0;
                for (uint32_t j = 0; j < _rows; j++) { //j = row id 
                    if ((*_matrix[j])[i] != 0 && j >= nextLeadPos) {//only set new lead if row index is below the previous leading value
                        if (lead == 0 ) { 
                            lead = (*_matrix[j])[i];
                            pivotRowIndex = i > j ? j : i; //pivot row is at minium between j and i
                            //should swap only if row is not in right place => j != i (j > i)
                            if (j > i) {
                                this->swap_row(j, i); 
                                scaleFactor *= -1;
                            }
                            nextLeadPos++;
                        }
                        //set every other non 0 value in ith col to 0 by scaling pivotRow by jthrow[i] / pivotRow[i]
                        else {
                            Vector<T> scaledPivotRow = Vector<T>(*_matrix[pivotRowIndex]).scale((*_matrix[j])[i]/(*_matrix[pivotRowIndex])[i]);
                            (*_matrix[j]) - scaledPivotRow; 
                        }
                    }
                }
            }
            return scaleFactor;
        }


        /*
         * Dispatches to right function depending on size
         */
        T determinant() const {
            T det;
            if (!this->isSquare()) {
                throw std::exception();
            }
            switch (this->_rows) {
                case(1):
                    det = determinant_1();
                    break;
                case(2):
                    det = determinant_2(*this);
                    break;
                case(3):
                    det = determinant_3(*this);
                    break;
                case(4):
                    det = determinant_4(*this);
                    break;
                default:
                    throw std::exception();
            }
            return det; 
        }


        /*
         * Returns new Fused matrix this with other horizonatly
         * (m x m).fuse(m x m) = (m x 2m)
         */
        Matrix<T>* fuse(Matrix<T> &other) const {
            Matrix<T>* res = new Matrix<T>(_rows);
            res->_cols = _cols * 2;
            Vector<T>** resData = res->getData();
            Vector<T>** otherData = other.getData();

            for (uint32_t i = 0; i < _rows; i++) {
                resData[i] = _matrix[i]->fuse((*otherData[i]));
            }
            return res;
        }

        /*
         * Returns new Matrix<T>* 
         * right part of horizontally splitted starting at colId
         */
        Matrix<T>* splitRight(uint32_t colId) {
            Matrix<T>* res = new Matrix<T>(_cols - colId);
            Vector<T>** resData = res->getData();
            res->_cols = colId;

            for (uint32_t i = 0; i < colId; i++) {
                resData[i] = _matrix[i]->splitRight(colId);
            }
            return res;
        }


        /*
         * Returns new Matrix that is the inverse of this object
         */
        Matrix<T>* inverse() {
            Matrix<T> id = Matrix<T>(_rows, _cols);
            Matrix<T> *augmentedMatrix = this->fuse(id);
            augmentedMatrix->row_echelon_ip();
            Matrix<T> *res = augmentedMatrix->splitRight(_cols);
            delete augmentedMatrix;
    
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
template<typename T>
    Matrix<T>* idMatrix(uint32_t size) {
        Matrix<T> *resultMatrix = new Matrix<T>(size, size);
        Vector<T>** matrix = resultMatrix->getData();
        for(uint32_t i = 0; i < size; i++) {
            (*matrix[i])[i] = 1;
        }
        return resultMatrix;
}
*/
/*
 * Returns new *Matrix 
 * linera interpolation of two matrices
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
