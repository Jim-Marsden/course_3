//
// Created by james on 10/28/2021.
//

#ifndef JIMMARSDEN_COURSE_3_ARRAY_H
#define JIMMARSDEN_COURSE_3_ARRAY_H
#include <stdexcept>
#include <algorithm>
namespace JimMarsden {
    template<class ElemType, unsigned SIZE>
    class Array {
    public:
        using elm_array_t = ElemType[SIZE];
        Array() = default;

        Array(Array const &);

        Array(Array &&) noexcept = default;

        ~Array() = default;

        Array &operator=(Array const &);

        bool operator==(Array const &op1);

        bool operator!=(Array const &op2);

        ElemType &operator[](unsigned index);

        ElemType const &operator[](unsigned index) const;

        auto begin();
        auto begin() const;
        auto end();
        auto end() const;

        [[nodiscard]] unsigned int size() const;

    private:
        elm_array_t elem_array{};
    };


    template<class ElemType, unsigned int SIZE>
    Array<ElemType, SIZE> &Array<ElemType, SIZE>::operator=(const Array &op) {
        if (&op == this) return *this;
        for (unsigned int i{}; i < SIZE; i++) {
            elem_array[i] = op[i];
        }
        return *this;
    }

    template<class ElemType, unsigned int SIZE>
    ElemType &Array<ElemType, SIZE>::operator[](unsigned int index) {
        if (index >= SIZE) throw std::invalid_argument("Index out of range");
        return elem_array[index];
    }

    template<class ElemType, unsigned int SIZE>
    ElemType const &Array<ElemType, SIZE>::operator[](unsigned int index) const {
        if (index >= SIZE) throw std::invalid_argument("Index out of range");
        return elem_array[index];
    }

    template<class ElemType, unsigned int SIZE>
    Array<ElemType, SIZE>::Array(const Array &op) {
        for (unsigned int i{}; i < SIZE; i++) {
            elem_array[i] = op[i];
        }
    }
    template<class ElemType, unsigned int SIZE>
    auto Array<ElemType, SIZE>::begin() {
        return std::begin(elem_array);
    }

    template<class ElemType, unsigned int SIZE>
    auto Array<ElemType, SIZE>::begin() const {
        return std::cbegin(elem_array);
    }



    template<class ElemType, unsigned int SIZE>
    auto Array<ElemType, SIZE>::end() {
        return std::end(elem_array);
    }

    template<class ElemType, unsigned int SIZE>
    auto Array<ElemType, SIZE>::end() const {
        return std::cend(elem_array);
    }



    template<class ElemType, unsigned int SIZE>
    unsigned int Array<ElemType, SIZE>::size() const {
        return SIZE;
    }

    template<class ElemType, unsigned int SIZE>
    bool Array<ElemType, SIZE>::operator==(const Array &op1) {
        for(unsigned  x{}; x < SIZE; x++){
            if(elem_array[x] != op1[x]) return false;
        }
        return true;
    }

    template<class ElemType, unsigned int SIZE>
    bool Array<ElemType, SIZE>::operator!=(const Array &op2) {
        return !(*this == op2);
    }




} // namespace JimMarsden

#endif //JIMMARSDEN_COURSE_3_ARRAY_H
