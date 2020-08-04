#ifndef REGRADOS_H_INCLUDED
#define REGRADOS_H_INCLUDED

#include <string>
#include <vector>
#include <memory>

class Membro {
public:
    std::string nome;
};

class RegraDos3 {
public:
    Membro membro;
    Membro* aloc1;
    Membro* aloc2;
    std::vector<Membro> membros;

    RegraDos3();
    // Aplicando regra dos 3
    RegraDos3(const RegraDos3&); // cópia
    ~RegraDos3(); // destrutor
    RegraDos3& operator=(const RegraDos3&); // cópia
};

class RegraDos5 {
public:
    Membro membro;
    Membro* aloc1;
    Membro* aloc2;
    std::vector<Membro> membros;

    RegraDos5();
    // Aplicando regra dos 5
    RegraDos5(const RegraDos5&); // cópia
    RegraDos5(const RegraDos5&&); // mover
    ~RegraDos5(); // destrutor
    RegraDos5& operator=(const RegraDos5&); // cópia
    RegraDos5& operator=(const RegraDos5&&); // mover
};

class RegraDos0 {
public:
    Membro membro;
    std::shared_ptr<Membro> aloc1;
    std::unique_ptr<Membro> aloc2;
    std::vector<Membro> membros;
};

#endif // REGRADOS_H_INCLUDED