#ifndef TEMPLATE_ITERATOR2_H_INCLUDED
#define TEMPLATE_ITERATOR2_H_INCLUDED

#include <memory>

template <typename T>
class Percorrer {
private:
    T* value;
    std::shared_ptr<Percorrer<T>> vnext;
    std::shared_ptr<Percorrer<T>> head;
public:
    Percorrer(T*);

    Percorrer<T>& next(T*);
    bool isEmpty();

    T& operator*();
    Percorrer<T>& operator++();
    bool operator!=(const Percorrer<T>&);

    // Regra dos 5
    // ~Percorrer();
    Percorrer(const Percorrer<T>&) = default;
    Percorrer(Percorrer<T>&&);
    // Percorrer<T>& operator=(const Percorrer<T>&);
    Percorrer<T>& operator=(Percorrer<T>&&);
};

#include "tpp/template_iterator2.cpp"

#endif // TEMPLATE_ITERATOR2_H_INCLUDED