
#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP
#include "Base.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void);
void identify(Base* p);
void identify(Base& p);

#endif