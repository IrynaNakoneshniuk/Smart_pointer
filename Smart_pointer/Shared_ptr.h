#pragma once
#include <iostream>
using namespace std;
template<typename T>
class Share_pointer {
private:
    T* obj;
    static  uint32_t  counter;
public:
    Share_pointer(T* obj)
    {
        this->obj = obj;
    }
    Share_pointer() :Share_pointer(nullptr) {};
    ~Share_pointer()
    {
        if (counter == 0) {
            delete this->obj;
        }
        else {
            counter--;
        }
    }
    T* operator ->()
    {
        return obj;
    }
    T& operator *()
    {
        return *obj;
    }
    void operator = (Share_pointer<T>&object) {
        counter++;
           this->obj=object.obj;
    }
    uint32_t get_counter() { return counter; }



};
template <typename T>
uint32_t Share_pointer <T>:: counter = 0;
