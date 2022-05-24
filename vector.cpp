#include <iostream>

template < typename T >

class Vector {

public:

Vector(){
_size = 0;
_cap = 0;
_buf = nullptr;
}

Vector(int m_cap){
    _size = m_cap ;
    _cap = m_cap ;
    _buf = new T[_cap];
}

Vector(int m_cap , T value){
    _size = m_cap ;
    _cap = m_cap ;
    _buf = new T[_cap];
    for (int i = 0; i<_size; i++){
        _buf[i] = value;  
    }
}

Vector(const Vector& obj){
    _size = obj._size;
    _cap = obj._cap;
    _buf = new T[obj._cap];
    for (int i = 0; i<obj._size; i++){
        _buf[i] = obj._buf[i];  
    }
}

Vector& operator=(Vector& obj){
     if ( this == &obj){
         return *this;
     }
     _size = obj._size;
    _cap = obj._cap;
    _buf = new T[obj._cap];
    for (int i = 0; i<obj._size; i++){
        _buf[i] = obj._buf[i];  
    }
    return *this;
}

Vector& operator=(Vector&& obj){
    std::swap (_cap , obj._cap);
    std::swap (_size , obj._size);
    std::swap (_buf,obj._buf);
    return *this;
}

Vector(const Vector&& obj){
    _size=obj._size;
    _cap=obj._cap;
    _buf=obj._buf;
    obj._size = 0;
    obj._cup = 0;
    obj._buf=nullptr;
}

~Vector(){
    delete[] _buf;
}

bool empty() const {
    if(_buf == nullptr){
        return true;
    }
    else {
        return false;
    }
}

int get_size() const {
    return _size;
}

int get_capacity() const {
    return _cap;
}

void clear() {
    _buf = nullptr;
}

void erase(int position) {
    T* _buf_copy = new T[_cap];
    for (int i = 0; i < _size; i++){
        if(i!=position){
            _buf_copy[i] = _buf[i];
        }
    }
    for (int i = position; i < _size; i++){
        _buf_copy[i] = _buf[i+1];
    }
    _buf = _buf_copy;
    _buf_copy = nullptr; 
} 

void erase(int start , int end) {
    T* _buf_copy = new T[_cap];
    for (int i = 0; i < _size; i++){
        if(i != start){
            _buf_copy[i] = _buf[i];
        }
    }
    for (int i = end; i < _size; i++){
        _buf_copy[i] = _buf[i+1];
    }
    _buf = _buf_copy;
    _buf_copy = nullptr; 
}

void push_back(T value) {
    if ( _size != _cap){
        _cap = _cap * 2 ;
        T* _buf1 = new T[_cap];
        for ( int i = 0 ; i < _size ; i++){
            _buf1[i] = _buf[i];
        }
        _buf = _buf1;
        _buf1 = nullptr;
    }
        _buf[_size+1] = value;
}

T pop_back() {
    
    T* _buf_copy = new T[_cap];
    for (int i = 0; i < _size - 1; i++){
            _buf_copy[i] = _buf[i];
    }
    T return_value = _buf[_size];
    _buf = _buf_copy;
    _buf_copy = nullptr;
    return return_value;
}

void insert  (int position , T value)  {
    T* _buf_copy = new T[_cap];
    
    if ( _size != _cap){
        _cap = _cap * 2 ;
        T* _buf1 = new T[_cap];
        for ( int i = 0 ; i < _size ; i++){
            _buf1[i] = _buf[i];
        }
        _buf = _buf1;
        _buf1 = nullptr;
    }
    for (int i = 0; i < _size; i++){
        if ( i < position ){
            _buf_copy[i] = _buf[i] ;
        }
        if(i==position){
            _buf_copy[i] = value;
        }
        if ( i > position ){
            _buf_copy[i+1] = _buf[i];
        }
    }
    
    _buf = _buf_copy;
    _buf_copy = nullptr;
    }

T& operator[](int position){
    return _buf[position];
}

private:
int _size;
int _cap;
T* _buf;

};

int main() {
int size = 10;
int value = 5;
Vector<int> vec(size, value); 
std::cout << vec.get_size() << std::endl;
std::cout << vec[5];
vec.insert(6 , 3);
std::cout << std::endl << vec[6];
std::cout << std::endl;
std::cout << vec.pop_back();
}