#include <iostream>
#include <sstream>
#include <fstream>

#include <vector>
#include <unordered_map>
#include <boost/intrusive/list.hpp>
#include <boost/intrusive/set.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <memory>
#include <algorithm>
#include <list>
#include <tuple>
#include <ranges>
#include <charconv>
#include <cmath>
#include <memory_resource>
#include <set>

#include <map>
#include <stack>

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

template<typename T>
struct MyVector {

    MyVector() {
        buffers_= new T*[capacity_];
    }

    void push_back(const T& t) {
        buffers_[size_++] = new T{t};
        if (size_ == capacity_) {
            reallocate();
        }
    }

    [[nodiscard]] std::size_t size() const {
        return size_;
    }

    T& operator[](std::size_t n) {
        return *buffers_[n];
    }

    void reallocate() {
        T** oldBuffers = buffers_;
        std::size_t oldCapacity = capacity_;
        capacity_ = oldCapacity * 2;
        buffers_ = new T*[capacity_];
        for (int i=0; i<size_; ++i) {
            buffers_[i] = oldBuffers[i];
        }
    }

    ~MyVector() {
        for (int i=0; i<size_; ++i) {
            delete buffers_[i];
        }
        delete buffers_;
    }

    std::size_t size_ = 0;
    std::size_t capacity_ = 10;
    T** buffers_;
};

struct T {
    inline static std::size_t created = 0;
    inline static std::size_t deleted = 0;

    T() {
        ptr = new char('a');
        ++created;
    }

    T(const T& rhs) {

        delete ptr;
        ptr = new char('a');
        *ptr = *rhs.ptr;
        ++created;
    }

    ~T() {
        ++deleted;
        delete ptr;
    }
    char * ptr = nullptr;
};

int main()
{
    //using Type = typename MyVector;
    {
        MyVector<T> my_vector{};
        for (int i=0; i<19; ++i) {
            my_vector.push_back(T{});
        }
    }
    std::cout << T::created << std::endl;
    std::cout << T::deleted << std::endl;
    return 0;
}
