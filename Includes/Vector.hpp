#ifndef VECTOR_HPP
#define VECTOR_HPP

/*
 * For normal part should work only with float;
 * Bonus: with complex number;
 * -> use template array
    //array directly in memory, or ptr to array?
 */
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iostream>
#include <ostream>

template<typename T>
class Vector {
    private:
        uint32_t    size;
        T           *vec;

    public:
        //Creates vector of size 1 with templated type set to 0
        Vector(void) {
            this->vec = static_cast<T *>(std::calloc(1, sizeof(T)));
            if (this->vec == nullptr) {
                throw std::exception();
            }
            this->size = 1;
        }

        //Creates empty vector based on size
        Vector(const uint32_t size) {
            this->vec = static_cast<T *>(std::calloc(size, sizeof(T)));
            if (this->vec == nullptr) {
                throw std::exception();
            }
            this->size = size;
            
        }

        Vector(const T *vec, const uint32_t size) {
            this->vec = static_cast<T *>(std::calloc(size, sizeof(T)));
            if (this->vec == nullptr) {
                throw std::exception();
            }
            memcpy(this->vec, vec, sizeof(T) * size);
            this->size = size;
        }
        
        //Deletes memory allocated for vec;
        ~Vector() {
            delete this->vec;
        }

        std::uint32_t   getSize() {
            return this->size;
        }

        void            toStdOut() {
            for (uint32_t i = 0;  i < this->size;  i++) {
                std::cout << vec[i] << " "; 
            }
            std::cout << std::endl;
        }
    //function to reshape vector into matrix
};

#endif // !VECTOR_HPP
