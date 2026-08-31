#include "functions.hpp"

int main() {

    srand(time(NULL));
    ClassA a;
    ClassB b;
    ClassC c;
    Base *bs;

    std::cout << "Identify the random generated class:" << std::endl;
    bs = generate();
    identify(bs);
    free(bs);
    std::cout << "Identify with references:" << std::endl;
    identify(a);
    identify(b);
    identify(c);
    std::cout << "Identify with pointers:" << std::endl;
    identify(&a);
    identify(&b);
    identify(&c);
}
