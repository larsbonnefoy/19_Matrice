#ifndef VECTOR_HPP
#define VECTOR_HPP

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
        //Creates vector of size 1 with templated type set to 0
        Vector(void) : _size(1){
            this->_data = new T[_size]();
        }

        //Creates empty _vector based on size
        Vector(const uint32_t count) : _size(count) {
            this->_data = new T[_size]();
        }

        //Creates Vector based on ptr on elem passed as argument
        Vector(const T *_data, const uint32_t count) : _size(count) {
            this->_data = new T[_size];
            memcpy(this->_data, _data, sizeof(T) * this->_size);
        }
        
        // Copy constructor
        Vector(const Vector& other) : _size(other._size) {
            _data = new T[_size];
            for (uint32_t i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
        
        //Deletes memory allocated for _vec;
        ~Vector() {
            std::cout << "Destructor of Vector Called" << std::endl;
            delete[] this->_data;
        }

        std::uint32_t   getSize() const {
            return this->_size;
        }

        void            toStdOut() const {
            for (uint32_t i = 0;  i < this->_size;  i++) {
                std::cout << _data[i]; 
                if (i != this->_size - 1) {
                    std::cout << " ";
                }
            }
        }
        //TODO: function to reshape vector into matrix
        //TODO: Operator overload
};

#endif // !VECTOR_HPP
