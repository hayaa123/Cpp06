#include "Serializer.hpp"

void test_serialization()
{
    std::cout << "------------------" << std::endl;
    std::cout << "     Test Serialization      " << std::endl;
    std::cout << "------------------" << std::endl;
    Data t;
    Data *result;
    uintptr_t ptr;

    t.name = "name";
    t.age = 12;
    t.height = 120;
    t.weight = 30;
    ptr = Serializer::serialize(&t);
    result = Serializer::deserialize(ptr);
    std::cout << result->name << "  |   " << t.name << std::endl;
    std::cout << result->age << "  |   " << t.age << std::endl;
    std::cout << result->height << "  |   " << t.height << std::endl;
    std::cout << result->weight << "  |   " << t.weight << std::endl;
    if(result == &t)
        std::cout << "Same address :D" << std::endl;
    else
        std::cout << "Failed!" << std::endl;
}

int main()
{
    test_serialization();
}