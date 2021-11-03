//
// Jim Marsden (U09247027)
// JimPMarsden@gmail.com
// CSE-40477
// 159167 C/C++ Programming III -- Ray Mitchell
// 10/28/2021
// https://Jim-Marsden/course_3
// =====================================================================
// Date.h Tested on the following compilers in C++17 standard
// MSVC - 14.19
//
// A less feature rich version of std::array.
// =====================================================================
//

#ifndef JIMMARSDEN_HW6_ARRAY_H
#define JIMMARSDEN_HW6_ARRAY_H

#include <stdexcept>
#include <algorithm>

namespace JimMarsden {
    using size_t = unsigned;

    template<class ElemType, size_t SIZE> // Type of array, and size
    class Array {
    public:
        // Types ==============================================================================================[ Types ]
        using elm_array_t = ElemType[SIZE]; // array type

        // [ Constructors / Destructors ] =============================================== [ Constructors / Destructors ]
        constexpr Array() = default;

        constexpr Array(Array const &); // explicit copy constructor

        constexpr Array(Array &&) noexcept = default;

        ~Array() = default;

        // Operators ======================================================================================[ Operators ]
        constexpr Array &operator=(Array const &);

        constexpr bool operator==(Array const &op1) const noexcept;

        constexpr bool operator!=(Array const &op2) const noexcept;

        constexpr ElemType &operator[](size_t index); // does active bounds checking, and throws if out of bounds

        constexpr ElemType const &
        operator[](size_t index) const; // does active bounds checking, and throws if out of bounds

        // Mutators/Accessors ====================================================================[ Mutators/Accessors ]
        [[nodiscard]]constexpr size_t size() const noexcept; // returns the SIZE template value;

        // Utilities ======================================================================================[ Utilities ]
        // for ranged-based for loops and standard algorithms
        constexpr ElemType *begin() noexcept;

        constexpr ElemType const *begin() const noexcept;

        constexpr ElemType *end() noexcept;

        constexpr ElemType const *end() const noexcept;

    private:
        elm_array_t elem_array{}; // container array
    };

    // Copy Constructor
    template<class ElemType, size_t SIZE>
    constexpr Array<ElemType, SIZE>::Array(const Array &op) {
        std::copy(op.begin(), op.end(), begin());
    }

    template<class ElemType, size_t SIZE>
    constexpr Array<ElemType, SIZE> &Array<ElemType, SIZE>::operator=(const Array &op) {
        if (&op == this) return *this; // avoid self coping
        std::copy(op.begin(), op.end(), begin());
        return *this;
    }


    template<class ElemType, size_t SIZE>
    constexpr bool Array<ElemType, SIZE>::operator!=(const Array &op2) const noexcept {
        return !(*this == op2);
    }

    template<class ElemType, size_t SIZE>
    constexpr bool Array<ElemType, SIZE>::operator==(const Array &op1) const noexcept {
        for (unsigned x{}; x < SIZE; x++) {
            if (elem_array[x] != op1[x]) return false;
        }
        return true;
    }

    template<class ElemType, size_t SIZE>
    constexpr ElemType &Array<ElemType, SIZE>::operator[](unsigned int index) {
        if (index >= SIZE) throw std::invalid_argument("Index out of range");
        return elem_array[index];
    }

    template<class ElemType, size_t SIZE>
    constexpr ElemType const &Array<ElemType, SIZE>::operator[](unsigned int index) const {
        if (index >= SIZE) throw std::invalid_argument("Index out of range");
        return elem_array[index];
    }

    template<class ElemType, size_t SIZE>
    constexpr ElemType *Array<ElemType, SIZE>::begin() noexcept {
        return std::begin(elem_array);
    }

    template<class ElemType, size_t SIZE>
    constexpr ElemType const *Array<ElemType, SIZE>::begin() const noexcept {
        return std::cbegin(elem_array);
    }

    template<class ElemType, size_t SIZE>
    constexpr ElemType *Array<ElemType, SIZE>::end() noexcept {
        return std::end(elem_array);
    }

    template<class ElemType, size_t SIZE>
    constexpr ElemType const *Array<ElemType, SIZE>::end() const noexcept {
        return std::cend(elem_array);
    }

    template<class ElemType, unsigned int SIZE>
    constexpr unsigned int Array<ElemType, SIZE>::size() const noexcept {
        return SIZE;
    }

} // namespace JimMarsden

#endif //JIMMARSDEN_HW6_ARRAY_H
