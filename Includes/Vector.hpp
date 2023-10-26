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

/*******************************Private Helpers********************************/

/******************************************************************************/

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

        /*
         * How do make the difference between ptr data that has to be switched
         * and raw data that has to be copied?
         *
         */
        void swap_elements(uint32_t i, uint32_t j) {
            T tmp = _data[i];
            _data[i] = _data[j]; 
            _data[j] = tmp;
        }

        //Should create variable list size set to 1; len = _size;
        // /!\ Doesnt work !!
        bool is_null() {
            Vector<T> vec = Vector<T>({1});
            if (!this->dot(vec)) {
                return false;
            }
            return true;
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

//Has to be as much vectors as coefs
//O(n) time complexity: i (=coefs) * j(=nb of elemets per vector)
template<typename T>
Vector<T>* linear_combination(std::initializer_list<Vector<T> > vec, std::initializer_list<T> coefs) {
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
    return resultVector;
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

//Returns cos(alpha), alpha = angle between v1 and v2
template<typename T>
float angle_cos(Vector<T>& v1, Vector<T> &v2) {
    return ( v1.dot(v2) / (v1.norm() * v2.norm()) );
}

/*
 *  c = a x b
 *  c = |a||b| sin(theta) n
 *  theta = angle between both vectors
 *  n = unit vector perpendicular to the plan of a b
 *  
 *  i = [1 0 0]
 *  j = [0 1 0]
 *  k = [0 0 1]
 *
 *          | i  j  k  |
 *  a x b = | a1 a2 a3 |
 *          | b1 b2 b3 |
 *
 *  a x b = (a2b3 - a3b2)i - (a1b3 - a3b1)j + (a1b2 - a2b1)k
 *  
 *  | s1 |   | a2b3 - a3b2 |
 *  | s2 | = | a3b1 - a1b3 |
 *  | s3 |   | a1b2 - a2b1 |
 *
 * Returns new Vector
 */
template<typename T>
Vector<T>* cross_product(Vector<T>& v1, Vector<T> &v2) {
    T* a = v1.getData();
    T* b = v2.getData();

    T s1 =  a[1] * b[2] - a[2] * b[1];
    T s2 =  a[2] * b[0] - a[0] * b[2];
    T s3 =  a[0] * b[1] - a[1] * b[0];
    
    return (new Vector<T>({s1, s2, s3}));
}

//!!Function not usable atm
Vector<float>& linear_combination_fma(std::initializer_list<Vector<float> > vec, std::initializer_list<float> coefs);
#endif // !VECTOR_HPP
