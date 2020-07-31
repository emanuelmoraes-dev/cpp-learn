#include "polimorfismo.hpp"
#include "strutil.hpp"
#include <stdio.h>

using namespace std;

// Animal

Animal::Animal(string info) : info(info) {};

void Animal::morder() {
    puts("mordendo como um animal");
}

string Animal::getInfo() {
    return this->info;
}

void Animal::setInfo(string info) {
    this->info = info;
}

// Cachorro

Cachorro::Cachorro(string info, string gender)
: Animal(info), gender(gender) {}

void Cachorro::morder() {
    puts("mordendo como um cachorro");
}

string Cachorro::getInfo() {
    return emdev::toupper(Animal::getInfo());
}

string Cachorro::getGender() {
    return this->gender;
}

void Cachorro::setGender(string gender) {
    this->gender = gender;
}