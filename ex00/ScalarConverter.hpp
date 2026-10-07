#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

enum DataType{
    Float,
    Integer,
    Char,
    Double,
    Nan,
    Inf,
    Other
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &other);
        static int is_char(std::string input);
        static int is_int(std::string input);
        static int is_double(std::string input);
        static int is_float(std::string input);
        static void trim(std::string &s);
        static void convert_char(std::string input);
        static void convert_int(std::string input);
        static void convert_double(std::string input);
        static void convert_float(std::string input);
        static void convert_nan();
        static void convert_inf(std::string input);
        static void print_char(long c);
        static void print_impossible();
        static DataType getType(std::string input);

    public:
        static void convert(std::string input);
};

#endif