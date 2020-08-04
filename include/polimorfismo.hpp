#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <string>

class Animal {
private:
    std::string info;
public:
    // construtors
    Animal(std::string info);

    // methods
    virtual void morder();

    // getters and setters
    std::string getInfo();
    void setInfo(std::string info);
};

class Cachorro : public Animal {
private:
    std::string gender;
public:
    // construtor
    Cachorro(std::string info, std::string gender);

    // métodos
    Cachorro reproduzir(Cachorro cachorro);
    Cachorro& reproduzir(Cachorro& cachorro);
    Cachorro* reproduzir(Cachorro* cachorro);

    // override
    void morder();

    // getters and setters
    std::string getInfo();
    std::string getGender();
    void setGender(std::string gender);
};

#endif // CLASSES_H_INCLUDED