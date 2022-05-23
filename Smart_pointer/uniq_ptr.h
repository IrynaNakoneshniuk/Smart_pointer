#pragma once
#include <iostream>
template <typename T>
class uniq_ptr
{
  private:
	  T* obj;
  public:
      uniq_ptr(T* obj) {
          this->obj = obj;
      }
      ~uniq_ptr() {
          delete this->obj;
      }
      T* operator ->()
      {
          return obj;
      }
      T& operator *()
      {
          return *obj;
      }
      void Reset() {
          delete this->obj;
          this->obj = nullptr;
      }
      T* get() { return this->obj; }
      T* reales() { T* object = this->obj; this->obj = nullptr; return object; }
      void Swap(T* object) { std::swap(this->obj, object); }
      operator bool() { return (obj == nullptr) ? false : true; }

};

