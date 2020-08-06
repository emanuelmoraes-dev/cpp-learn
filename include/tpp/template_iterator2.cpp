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

template <typename T>
Percorrer<T>::Percorrer(Percorrer<T>&& that) {
    this->value = that.value;
    this->vnext = move(that.vnext);
    this->head = move(that.head);

    that.value = nullptr;
    that.vnext = nullptr;
    that.head = nullptr;
}

template <typename T>
Percorrer<T>& Percorrer<T>::operator=(Percorrer<T>&& that) {
    this->value = that.value;
    this->vnext = move(that.vnext);
    this->head = move(that.head);

    that.value = nullptr;
    that.vnext = nullptr;
    that.head = nullptr;

    return *this;
}
