#include "regrados.hpp"
#include <stdio.h>

using namespace std;

// RegraDos3

RegraDos3::RegraDos3() {
    puts("Construtor padrão #RegraDos3");

    this->aloc1 = nullptr;
    this->aloc2 = nullptr;
}

RegraDos3::RegraDos3(const RegraDos3& that)
: membro(that.membro), membros(that.membros) {
    puts("Construtor cópia #RegraDos3");

    this->aloc1 = nullptr;
    this->aloc2 = nullptr;

    if (that.aloc1 != nullptr)
        this->aloc1 = new Membro(*that.aloc1);
    if (that.aloc2 != nullptr)
        this->aloc2 = new Membro(*that.aloc2);
}

RegraDos3::~RegraDos3() {
    puts("Destrutor #RegraDos3");

    if (this->aloc1 != nullptr)
        delete this->aloc1;
    if (this->aloc2 != nullptr)
        delete this->aloc2;
}

RegraDos3& RegraDos3::operator=(const RegraDos3& that) {
    puts("Cópia na atribuição #RegraDos3");

    this->membro = that.membro;
    this->membros = that.membros;

    Membro* _aloc1 = nullptr;
    Membro* _aloc2 = nullptr;

    if (that.aloc1 != nullptr)
        _aloc1 = new Membro(*that.aloc1);

    if (that.aloc2 != nullptr)
        _aloc2 = new Membro(*that.aloc2);

    this->~RegraDos3();

    this->aloc1 = _aloc1;
    this->aloc2 = _aloc2;

    return *this;
}

// RegraDos5

RegraDos5::RegraDos5() {
    puts("Construtor padrão #RegraDos5");

    this->aloc1 = nullptr;
    this->aloc2 = nullptr;
}

RegraDos5::RegraDos5(const RegraDos5& that)
: membro(that.membro), membros(that.membros) {
    puts("Construtor cópia #RegraDos5");

    this->aloc1 = nullptr;
    this->aloc2 = nullptr;

    if (that.aloc1 != nullptr)
        this->aloc1 = new Membro(*that.aloc1);
    if (that.aloc2 != nullptr)
        this->aloc2 = new Membro(*that.aloc2);
}

RegraDos5::RegraDos5(RegraDos5&& that) {
    puts("Construtor de movimentação #RegraDos5");

    this->membro = move(that.membro);
    this->membros = move(that.membros);
    this->aloc1 = that.aloc1;
    this->aloc2 = that.aloc2;

    that.aloc1 = nullptr;
    that.aloc2 = nullptr;
}

RegraDos5::~RegraDos5() {
    puts("Destrutor #RegraDos5");

    if (this->aloc1 != nullptr)
        delete this->aloc1;
    if (this->aloc2 != nullptr)
        delete this->aloc2;
}

RegraDos5& RegraDos5::operator=(const RegraDos5& that) {
    puts("Cópia na atribuição #RegraDos5");

    this->membro = that.membro;
    this->membros = that.membros;

    Membro* _aloc1 = nullptr;
    Membro* _aloc2 = nullptr;

    if (that.aloc1 != nullptr)
        _aloc1 = new Membro(*that.aloc1);

    if (that.aloc2 != nullptr)
        _aloc2 = new Membro(*that.aloc2);

    this->~RegraDos5();

    this->aloc1 = _aloc1;
    this->aloc2 = _aloc2;

    return *this;
}

RegraDos5& RegraDos5::operator=(RegraDos5&& that) {
    puts("Movimentação na atribuição #RegraDos5");

    this->membro = move(that.membro);
    this->membros = move(that.membros);

    if (this->aloc1 != nullptr)
        delete this->aloc1;
    if (this->aloc2 != nullptr)
        delete this->aloc2;

    this->aloc1 = that.aloc1;
    this->aloc2 = that.aloc2;

    that.aloc1 = nullptr;
    that.aloc2 = nullptr;

    return *this;
}
