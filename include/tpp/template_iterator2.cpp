#include "template_iterator2.hpp"

#include <memory>
#include <iostream>

// template class Percorrer<int>;

template <typename T>
Percorrer<T>::Percorrer(T* value) : value(value), vnext(nullptr), head(nullptr) {}

template <typename T>
Percorrer<T>& Percorrer<T>::next(T* value) {
    this->vnext.reset(new Percorrer<T>(value));
    this->head = this->vnext;
    return *this->vnext;
}

template <typename T>
bool Percorrer<T>::isEmpty() {
    return this->value == nullptr;
}

template <typename T>
T& Percorrer<T>::operator*() {
    return *this->value;
}

template <typename T>
Percorrer<T>& Percorrer<T>::operator++() {
    if (this->vnext != nullptr) {
        this->value = this->vnext->value;
        this->vnext = this->vnext->vnext;
    } else {
        this->value = nullptr;
        this->vnext = nullptr;
    }
    return *this;
}

template <typename T>
bool Percorrer<T>::operator!=(const Percorrer<T>& that) {
    return this->value != that.value;
}

// Regra dos 5

// template <typename T>
// Percorrer<T>::~Percorrer() {
//     if (this->head != nullptr)
//         delete this->head;
// }

// template <typename T>
// Percorrer<T>::Percorrer(const Percorrer<T>& that)
// : value(that.value) {
//     auto assigner = this;
//     auto i = that.vnext;

//     while (i != nullptr) {
//         assigner->vnext = new Percorrer<T>(i->value);
//         assigner->head = assigner->vnext;
//         assigner = assigner->vnext;
//         i = i->vnext;
//     }
// }

// template <typename T>
// Percorrer<T>::Percorrer(Percorrer<T>&& that) {
//     this->value = that.value;
//     this->vnext = that.vnext;
//     this->head = that.head;

//     that.value = nullptr;
//     that.vnext = nullptr;
//     that.head = nullptr;
// }

// template <typename T>
// Percorrer<T>& Percorrer<T>::operator=(const Percorrer<T>& that) {
//     this->~Percorrer();

//     this->value = that.value;

//     auto assigner = this;
//     auto i = that.vnext;

//     while (i != nullptr) {
//         assigner->vnext = new Percorrer<T>(i->value);
//         assigner->head = assigner->vnext;
//         assigner = assigner->vnext;
//         i = i->vnext;
//     }

//     return *this;
// }

// template <typename T>
// Percorrer<T>& Percorrer<T>::operator=(Percorrer<T>&& that) {
//     this->~Percorrer();

//     this->value = that.value;
//     this->vnext = that.vnext;
//     this->head = that.head;

//     that.value = nullptr;
//     that.vnext = nullptr;
//     that.head = nullptr;

//     return *this;
// }
