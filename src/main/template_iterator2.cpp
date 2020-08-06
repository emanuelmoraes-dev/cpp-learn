#include "template_iterator2.hpp"
#include <iostream>

using namespace std;

template <typename P, typename F>
void process(P& percorrer, F fn) {
    for (auto& i = percorrer; !i.isEmpty(); ++i)
        fn(i);
}

int main(int argc, const char* argv[]) {
    int x = 10, y = 89, z = 3;

    Percorrer<int> p1(&x);
    p1.next(&y).next(&z);

    Percorrer<int> p2 = p1;
    // Percorrer<int>& p2 = p1;

    cout << "Listando p1..." << endl;
    process(p1, [](auto& i){
        cout << *i << endl;
    });

    cout << "Listando p2..." << endl;
    process(p2, [](auto& i){
        cout << *i << endl;
    });

    return 0;
}