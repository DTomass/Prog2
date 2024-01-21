//*****************************************************************
// File:   genNum.cpp
// Author: Daniel Tomas Martinez
// Date:   20/01/2024
// Coms:   Fichero de implementación de las funciones de generación de números aleatorios
//*****************************************************************
#include "genNum.hpp"
#include <cstdlib>

// Pre:  a <= b
// Post: randInt(a,b) es un entero generado aleatoriamente en el intervalo [a,b]
int randInt(const int a, const int b)
{
    return a + rand() % (b - a + 1);
}

// Pre:  a <= b
// Post: randDouble(a,b) es un real generado aleatoriamente en el intervalo [a,b]
double randDouble(const double a, const double b)
{
    return a + (b - a) * ((double)rand() / RAND_MAX);
}