#include "Serializer.hpp"

int main()
{
    Data t;
    Data *result;
    Serializer serializer;
    uintptr_t ptr;

    t.name = "name";
    t.age = 12;
    t.height = 120;
    t.weight = 30;
    ptr = serializer.serialize(&t);
    result = serializer.deserialize(ptr);
    std::cout << result->name << "  |   " << t.name << std::endl;
    std::cout << result->age << "  |   " << t.age << std::endl;
    std::cout << result->height << "  |   " << t.height << std::endl;
    std::cout << result->weight << "  |   " << t.weight << std::endl;
    if(result == &t)
        std::cout << "Same address :D" << std::endl;
    else
        std::cout << "Failed!" << std::endl;
}