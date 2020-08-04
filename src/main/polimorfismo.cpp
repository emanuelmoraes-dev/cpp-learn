#include "polimorfismo.hpp"
#include <locale>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char* argv[]) {

    setlocale(LC_ALL, "en_US.UTF-8");

    Animal animal("Bá! Um animal qualquer!");
    Cachorro cachorro("Bá! Um cachorro qualquer!", "masculino");
    Animal& mesmoCachorro = cachorro;

    animal.morder();
    cachorro.morder();
    mesmoCachorro.morder();

    cout << cachorro.getInfo() << endl;
    puts(mesmoCachorro.getInfo().c_str());

    return 0;
}