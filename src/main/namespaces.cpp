#include <stdio.h>
#include "namespaces.hpp"

using namespace emdev_gaming;
// using namespace emdev_killer;

int main(int argc, const char* argv[]) {
	attack();
	emdev_gaming::attack();
	emdev_killer::attack();
	return 0;
}
