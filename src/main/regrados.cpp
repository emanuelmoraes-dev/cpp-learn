#include "regrados.hpp"

using namespace std;

int main(int argc, const char* argv[]) {
    RegraDos3 r31;
    RegraDos3 r32 = r31;
    RegraDos3 r33;
    r33 = r31;

    RegraDos5 r51;
    RegraDos5 r52(r51);
    RegraDos5 r53;
    r53 = r51;
    r53 = move(r52);

    RegraDos0 r01;
    RegraDos0 r02;
    // r02 = r01;
    r02 = move(r01);

    return 0;
}