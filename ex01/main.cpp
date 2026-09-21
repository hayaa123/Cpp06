#include "Serializer.hpp"

void test_conical_form()
{
    std::cout << "------------------" << std::endl;
    std::cout << "     Test Conical form      " << std::endl;
    std::cout << "------------------" << std::endl;
    try
    {
        Serializer serializer;
        Serializer serializer2(serializer);
        Serializer serializer3 = serializer;
        std::cout << "Success!" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test_serialization()
{
    std::cout << "------------------" << std::endl;
    std::cout << "     Test Serialization      " << std::endl;
    std::cout << "------------------" << std::endl;
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
int main()
{
    test_conical_form();
    test_serialization();
}