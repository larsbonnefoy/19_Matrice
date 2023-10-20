#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
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
        
        T dot(const Vector<T> &vec) {
            T res = 0;
            for (uint32_t i = 0; i < this->getSize(); i++) {
                res = std::fma(_data[i], vec.getData()[i], res);
            }
            return (res);
        }

        T abs(const T val) {
            if (val < 0) {
                return (-val);
            }
            return (val);
        }

        T norm_1() {
            T res = 0;
            for (uint32_t i = 0; i < this->getSize(); i++) {
                res += abs(_data[i]);
            }
            return res;
        }

        T norm() {
            return std::sqrt(this->dot(*this));
        }

        T norm_inf() {
            T res = abs(_data[0]);
            for (uint32_t i = 1; i < this->getSize(); i++) {
                res = std::max(res, abs(_data[i]));
            }
            return res;
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
        
        T& operator[](uint32_t index) {
            return _data[index];
        }

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

//Generic lerp function, computes linear interpolation between two points
//fma = x * y + z
//t not incl [0;1] => get any point on the line drawn between p1 and p2
template<typename T>
T lerp(T p1, T p2, float t) {
    return (std::fma(t, (p2 - p1), p1));  //p1 + t * (p2 - p1);
}

//Computes linear interpolation between v1 and v2, t incl [0,1]
template<typename T>
Vector<T>* lerp(Vector<T>& v1, Vector<T> &v2, float t) {
    uint32_t size = v1.getSize();
    Vector<T> *resultVector = new Vector<T>(size);
    T *resultVectorData = resultVector->getData();

    for (uint32_t i = 0; i < size; i++) {
        resultVectorData[i] = lerp(v1[i], v2[i], t);
    }
    return resultVector;
}

//!!Function not usable atm
Vector<float>& linear_combination_fma(std::initializer_list<Vector<float> > vec, std::initializer_list<float> coefs);
#endif // !VECTOR_HPP
