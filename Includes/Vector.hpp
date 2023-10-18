#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>
#include <cstring>
#include <initializer_list>
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
                _data[i++] = elem;          //In order to make a vector of vectors, need to make a deep copy of elem here
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
        Vector<T>& add(const Vector<T> &vec) {
            for (uint32_t i = 0; i < this->_size; i++) {
                _data[i] += vec.getData()[i]; 
            }
            return (*this);
        }

        //Subtract vec._data to this._data
        Vector<T>& sub(const Vector<T> &vec) {
            for (uint32_t i = 0; i < this->_size; i++) {
                _data[i] -= vec.getData()[i]; 
            }
            return (*this);
        }

        //Scales all the values of a vector by factor a
        Vector<T>& scale(const T &a) {
            for (uint32_t i = 0; i < this->_size; i++) {
                _data[i] *= a; 
            }
            return (*this);
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
        

        //au lieu de return tout le vector, return le 1er element du vector
        //TODO: fix
        /*
        T& operator[](uint32_t index) {
            std::cout << "sizeof " << sizeof(T) << std::endl;
            return _data[index].getData();
        }
        */

        Vector<T>& operator=(const Vector<T> &other) {
            for (uint32_t i = 0; i < other.getSize(); i++) {
                _data[i] = other._data[i]; 
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os, const Vector<T> &vec) {
            vec.toStdOut();
            return os;
        }

        //TODO: function to reshape vector into matrix
        //= operator overload
};

//TODO:
//Can use fma only when T = float or int 
//Otherwise have to use multiplication/addition of class T
//Has to be as much vectors as coefs
//O(n) time complexity: i (=coefs) * j(=nb of elemets per vector)
//extern __m128d _mm_fmadd_pd(__m128d a, __m128d b, __m128d c);
template<typename T>
Vector<T>& linear_combination(std::initializer_list<Vector<T> > vec, std::initializer_list<T> coefs) {
    Vector<T> *resultVector = new Vector<T>(vec.begin()[0].getSize());

    T* resVectorData = resultVector->getData();
    uint32_t i = 0; 
    for (const T& coef : coefs) {
        const Vector<T> &currVec = vec.begin()[i];
        const T* data = currVec.getData();

        for(uint32_t j = 0; j < currVec.getSize(); j++) {
            resVectorData[j] = std::fma(coef, data[j], resVectorData[j]);
        }
        i++;
    }
    return *resultVector;
}

Vector<float>& linear_combination_fma(std::initializer_list<Vector<float> > vec, std::initializer_list<float> coefs);
#endif // !VECTOR_HPP
