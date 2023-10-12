#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>
#include <iostream>

/*
 * For normal part should work only with float;
 * Bonus: with complex number;
 * -> use template array
    //array directly in memory, or ptr to array?
 * TODO: add operator overload
 * Vector(void)                     -> returns 1 element array set to 0
 * Vector(uint32_t count)           -> inits vector to 0;
 * Vector(T *vec, uint32_t count)   -> copies vec into class
 */
template<typename T>
class Vector {
    private:
        uint32_t    _size;
        T           *_data;

    public:
        
/********************************Constructors**********************************/

        //Creates vector of size 1 with templated type set to 0
        Vector(void) : _size(1){
            this->_data = new T[_size]();
        }

        //Creates empty _vector based on size
        Vector(const uint32_t count) : _size(count) {
            this->_data = new T[_size]();
        }

        Vector(std::initializer_list<T> args): _size(args.size()), _data(new T[args.size()]){
            uint32_t i = 0;
            for (const T& elem : args) {
                _data[i++] = elem;
            }
        }
        
        // Copy constructor
        Vector(const Vector& other) : _size(other._size) {
            _data = new T[_size];
            for (uint32_t i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
        
        //Deletes memory allocated for _vec;
        ~Vector() {
            delete[] this->_data;
        }

/****************************Getters*******************************************/

        std::uint32_t   getSize() const {
            return this->_size;
        }

        T*              getData() const {
            return this->_data;
        }
        
/*********************************Operations***********************************/
        
        //Adds vec._data to this._data
        void add(const Vector<T> &vec) {
            for (uint32_t i = 0; i < this->_size; i++) {
                _data[i] += vec.getData()[i]; 
            }
        }

        //Subtract vec._data to this._data
        void sub(const Vector<T> &vec) {
            for (uint32_t i = 0; i < this->_size; i++) {
                _data[i] -= vec.getData()[i]; 
            }
        }

        //Scales all the values of a vector by factor a
        void scale(const T &a) {
            for (uint32_t i = 0; i < this->_size; i++) {
                _data[i] *= a; 
            }
        }

/****************************Operator Overload*********************************/
        void            toStdOut() const {
            for (uint32_t i = 0;  i < this->_size;  i++) {
                std::cout << _data[i]; 
                if (i != this->_size - 1) {
                    std::cout << " ";
                }
            }
        }

        //add second vector into first one 
        Vector<T>& operator+(const Vector<T> &vec) {
            this->add(vec);
            return (*this);
        }

        //Subtract second vector into first one 
        Vector<T>& operator-(const Vector<T> &vec) {
            this->sub(vec);
            return (*this);
        }

        //Scales Vector by value of T
        Vector<T>& operator*(const T &a) {
            this->scale(a);
            return (*this);
        }
        
        friend std::ostream& operator<<(std::ostream& os, const Vector<T> &vec) {
            vec.toStdOut();
            return os;
        }

        //TODO: function to reshape vector into matrix
};

#endif // !VECTOR_HPP
