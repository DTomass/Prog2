//*****************************************************************
// File:   calculos.hpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2024
// Coms:   Fichero de interfaz de calculos.cpp para la práctica 2
//*****************************************************************

#ifndef CALCULOS_HPP
#define CALCULOS_HPP

#include <cmath>

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: (n = 0 -> numCifras(n,b) = 1) ∧
//       (n > 0 -> numCifras(n,b) = NC ∧  n >= b^(NC-1) ∧ n < b^NC)
int numCifras(const int n, const int b = 10)
{
    int NC = 1;
    int aux = n;
    while (aux >= b)
    {
        aux = aux / b;
        NC++;
    }
    return NC;
}

// Pre:  n >= 0 ∧ i >= 1 ∧ 2 <= b <= 10
// Post: cifra(n,i,b) = (n / b^(i-1)) % b
int cifra(const int n, const int i, const int b = 10)
{
    return static_cast<int>(n / pow(b, i - 1)) % b;
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMayor(n,b) = (Max α∊[1,∞].cifra(n,α,b))
int cifraMayor(const int n, const int b = 10)
{
    int max = 0;
    int aux = n;
    while (aux > 0)
    {
        if (aux % b > max)
        {
            max = aux % b;
        }
        aux = aux / b;
    }
    return max;
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMasSignificativa(n,bvp ) = n / b^(NC-1)
//       ∧ (n >= b^(NC-1) ∧ n < b^NC)
int cifraMasSignificativa(const int n, const int b = 10)
{
    int NC = 1;
    int aux = n;
    while (aux >= b)
    {
        aux = aux / b;
        NC++;
    }
    return n / pow(b, NC - 1);
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: sumaCifras(n,b) = (∑ α∊[1,∞].cifra(n,α,b))
int sumaCifras(const int n, const int b = 10)
{
}

#endif
