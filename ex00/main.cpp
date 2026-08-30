#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    ScalarConverter converter;
    if(argc != 2)
    {
        std::cout << "Error: Invalid number of arguments." << std::endl;
        return (1);
    }
    converter.convert(argv[1]);
}