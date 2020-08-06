#ifndef TEMPLATE_ITERATOR_H_INCLUDED
#define TEMPLATE_ITERATOR_H_INCLUDED

template <typename T>
class Percorrer {
private:
    T* value;
    Percorrer<T>* vnext;
    Percorrer<T>* head;
public:
    Percorrer(T*);

    Percorrer<T>& next(T*);
    bool isEmpty();

    T& operator*();
    Percorrer<T>& operator++();
    bool operator!=(const Percorrer<T>&);

    // Regra dos 5
    ~Percorrer();
    Percorrer(const Percorrer<T>&);
    Percorrer(Percorrer<T>&&);
    Percorrer<T>& operator=(const Percorrer<T>&);
    Percorrer<T>& operator=(Percorrer<T>&&);
};

#include "tpp/template_iterator.cpp"

#endif // TEMPLATE_ITERATOR_H_INCLUDED