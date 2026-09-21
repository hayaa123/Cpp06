#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void) other;
}
ScalarConverter::~ScalarConverter()
{

}
ScalarConverter ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

void ScalarConverter::trim(std::string &s)
{
    s.erase(0, s.find_first_not_of(" \t\n\r\f\v"));
    s.erase(s.find_last_not_of(" \t\n\r\f\v") + 1);
}

int ScalarConverter::is_char(std::string input)
{
    if(input.length() == 1 && !is_int(input))
        return (1);
    if(input.length() == 1 && (input[0] == '+' || input[0] == '-'))
        return (1);
    return (0);
}

int ScalarConverter::is_int(std::string input)
{
    std::string::size_type i = 0;
    
    trim(input);
    if(input.length() == 0)
        return (0);
    if(input[i] == '-' || input[i] == '+')
        i++;
    while (i < input.length())
    {
        if(!std::isdigit(input[i]))
            return(0);
        i++;
    };
    return(1);
}

int ScalarConverter::is_double(std::string input)
{
    std::string::size_type i;

    i = 0;
    trim(input);
    if(input.length() == 0)
        return (0);
    if(input[i] == '-' || input[i] == '+')
        i++;
    while(i < input.length())
    {
        if(!std::isdigit(input[i]))
            break;
        i++;
    }
    if(i == 0 || input[i] != '.')
        return(0);
    i++;
    while(i < input.length())
    {
        if(!std::isdigit(input[i]))
            break;
        i++;
    }
    return (1); 
}

int ScalarConverter::is_float(std::string input)
{
    std::string::size_type i;

    i = 0;
    trim(input);
    if(input.length() == 0)
        return (0);
    if(input[i] == '-' || input[i] == '+')
        i++;
    while(i < input.length())
    {
        if(!std::isdigit(input[i]))
            break;
        i++;
    }
    if(i == 0 || input[i] != '.')
        return(0);
    i++;
    while(i < input.length())
    {
        if(!std::isdigit(input[i]))
            break;
        i++;
    }
    if(input[i] != 'f' || input[i] != '\0')
        return (0);
    return (1);
}

DataType ScalarConverter::getType(std::string input)
{
    if(is_char(input))
        return(Char);
    if(is_int(input))
        return (Integer);
    if(is_float(input))
        return(Float);
    if(is_double(input))
        return (Double);
    if(
        input.compare("+inff") == 0 || 
        input.compare("-inff") == 0 ||
        input.compare("+inf") == 0 ||
        input.compare("-inf") == 0
    )
        return (Inf);
    if(input.compare("nan") == 0 || input.compare("nanf") == 0)
        return (Nan);
    return (Other);
}

void ScalarConverter::convert_char(std::string input)
{
    char c;

    c = input[0];
    if(std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else 
        std::cout << "char: " << "Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float> (c) <<"f" <<std::endl;
    std::cout << "double: " << static_cast<double> (c) << std::endl;
}

void ScalarConverter::convert_int(std::string input)
{
    int i;
    std::istringstream iss(input);

    if (iss >> i) {
        if(std::isprint(i))
            std::cout << "char: '" << static_cast<char> (i) << "'" << std::endl;
        else 
            std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float> (i) <<"f" <<std::endl;
        std::cout << "double: " << static_cast<double> (i) << std::endl;
    } else {
        return;    
    }
}

void ScalarConverter::convert_double(std::string input)
{
    double i;
    std::istringstream iss(input);

    if (iss >> i) {
        if(std::isprint(i))
            std::cout << "char: '" << static_cast<char> (i) << "'" << std::endl;
        else 
            std::cout << "char: " <<  "Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(i) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float> (i) <<"f" <<std::endl;
        std::cout << "double: " << static_cast<double> (i) << std::endl;
    } else {
        return;    
    }
}

void ScalarConverter::convert_float(std::string input)
{
    float i;
    std::istringstream iss(input);

    if (iss >> i) {
        if(std::isprint(i))
            std::cout << "char: '" << static_cast<char> (i) << "'" << std::endl;
        else 
            std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(i) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float> (i) <<"f" <<std::endl;
        std::cout << "double: " << static_cast<double> (i) << std::endl;
    } else {
        return;    
    }
}

void ScalarConverter::convert_nan()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convert_inf(std::string input)
{
    if(input.compare("+inf") == 0 || input.compare("+inff") == 0)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } 
    else{
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(std::string input)
{
    DataType type;

    type = getType(input);
    switch (type)
    {
    case Integer:
        convert_int(input);
        break;
    case Float:
        convert_float(input);
        break;
    case Double:
        convert_double(input);
        break;
    case Char:
        convert_char(input);
        break;
    case Nan:
        convert_nan();
        break;
    case Inf:
        convert_inf(input);
        break;
    default:
        std::cout << "Not a valid input" << std::endl;
        break;
    }
}
