// Sample custom iterator.
// By perfectly.insane (http://www.dreamincode.net/forums/index.php?showuser=76558)
// From: http://www.dreamincode.net/forums/index.php?showtopic=58468

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

template <typename T>
class fixed_array {
public:
    typedef int size_type;

    class iterator {
    public:
        typedef iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;

        iterator(pointer ptr) : ptr_(ptr) { }

        self_type operator++() {
            self_type i = *this;
            ptr_++;
            return i;
        }

        self_type operator++(int junk) {
            ptr_++;
            return *this;
        }

        reference operator*() {
            return *ptr_;
        }

        pointer operator->() {
            return ptr_;
        }

        bool operator==(const self_type& rhs) {
            return ptr_ == rhs.ptr_;
        }

        bool operator!=(const self_type& rhs) {
            return ptr_ != rhs.ptr_;
        }

    private:
        pointer ptr_;
    };

    class const_iterator {
    public:
        typedef const_iterator self_type;
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef int difference_type;
        typedef std::forward_iterator_tag iterator_category;

        const_iterator(pointer ptr) : ptr_(ptr) { }

        self_type operator++() {
            self_type i = *this;
            ptr_++;
            return i;
        }

        self_type operator++(int junk) {
            ptr_++;
            return *this;
        }

        const reference operator*() {
            return *ptr_;
        }

        const pointer operator->() {
            return ptr_;
        }

        bool operator==(const self_type& rhs) {
            return ptr_ == rhs.ptr_;
        }

        bool operator!=(const self_type& rhs) {
            return ptr_ != rhs.ptr_;
        }

    private:
        pointer ptr_;
    };

    fixed_array(size_type size): size_(size) {
        data_ = new T[size_];
    }

    size_type size() const {
        return size_;
    }

    T& operator[](size_type index)
    {
        assert(index < size_);
        return data_[index];
    }

    const T& operator[](size_type index) const
    {
        assert(index < size_);
        return data_[index];
    }

    iterator begin()
    {
        return iterator(data_);
    }

    iterator end()
    {
        return iterator(data_ + size_);
    }

    const_iterator begin() const
    {
        return const_iterator(data_);
    }

    const_iterator end() const
    {
        return const_iterator(data_ + size_);
    }

private:
    T* data_;
    size_type size_;
};


int main()
{
    fixed_array<double> point3d(3);
    point3d[0] = 2.3;
    point3d[1] = 3.2;
    point3d[2] = 4.2;

    for(fixed_array<double>::iterator i = point3d.begin(); i != point3d.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;

    std::vector<double> vec;
    std::copy(point3d.begin(), point3d.end(), std::back_inserter(vec));

    for(std::vector<double>::iterator i = vec.begin(); i != vec.end(); i++)
    {
        std::cout << *i << " ";
    }

    std::cout << std::endl;
    return 0;
}
