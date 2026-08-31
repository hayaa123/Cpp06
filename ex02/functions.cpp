#include "functions.hpp"

Base *generate(void)
{
    int num;
    Base *result;
    
    num = rand() % 3;
    switch (num)
    {
    case 0:
        result = new ClassA();
        break;
    case 1:
        result = new ClassB();
        break;
    case 2:
        result = new ClassC();
        break;
    default:
        break;
    }
    return (result);
}

void identify(Base* p)
{
    if(dynamic_cast<ClassA*>(p) != NULL)
        std::cout << "A" << std::endl;
    if(dynamic_cast<ClassB*>(p) != NULL)
        std::cout << "B" << std::endl;
    if(dynamic_cast<ClassC*>(p) != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        dynamic_cast<ClassA&>(p);
        std::cout << "A" << std::endl;
    }
    catch(std::exception& e){
        try
        {
            dynamic_cast<ClassB&>(p);
            std::cout << "B" << std::endl;
        }
        catch(const std::exception& e)
        {
           std::cout << "C" << std::endl;
        }
    }
}
