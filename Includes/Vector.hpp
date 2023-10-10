#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>
#include <ostream>

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
        T           *_vec;

    public:
        //Creates vector of size 1 with templated type set to 0
        Vector(void) {
            this->_vec = static_cast<T *>(std::calloc(1, sizeof(T)));
            if (this->_vec == nullptr) {
                throw std::exception();
            }
            this->_size = 1;
        }

        //Creates empty _vector based on size
        Vector(const uint32_t count) {
            this->_vec = static_cast<T *>(std::calloc(count, sizeof(T)));
            if (this->_vec == nullptr) {
                throw std::exception();
            }
            this->_size = count;
            
        }

        Vector(const T *_vec, const uint32_t count) {
            this->_vec = static_cast<T *>(std::calloc(count, sizeof(T)));
            if (this->_vec == nullptr) {
                throw std::exception();
            }
            memcpy(this->_vec, _vec, sizeof(T) * count);
            this->_size = count;
        }
        
        //Deletes memory allocated for _vec;
        ~Vector() {
            delete this->_vec;
        }

        std::uint32_t   getSize() const {
            return this->_size;
        }

        void            toStdOut() const {
            for (uint32_t i = 0;  i < this->_size;  i++) {
                std::cout << _vec[i] << " "; 
            }
            std::cout << std::endl;
        }
    //function to reshape vector into matrix
};

#endif // !VECTOR_HPP
