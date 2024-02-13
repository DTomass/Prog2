//*****************************************************************
// File:   calculos.hpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2024
// Coms:   Fichero de interfaz de calculos.cpp para la práctica 2
//*****************************************************************

#include "calculos.hpp"
#include <cmath>

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: (n = 0 -> numCifras(n,b) = 1) ∧
//       (n > 0 -> numCifras(n,b) = NC ∧  n >= b^(NC-1) ∧ n < b^NC)
int numCifras(const int n, const int b)
{
    if (n < b)
    {
        return 1;
    }
    else
    {
        return 1 + numCifras(n / b, b);
    }
}

// Pre:  n >= 0 ∧ i >= 1 ∧ 2 <= b <= 10
// Post: cifra(n,i,b) = (n / b^(i-1)) % b
int cifra(const int n, const int i, const int b)
{
    int pos_cifra = pow(b, i - 1);
    return (n / pos_cifra) % b;
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMayor(n,b) = (Max α∊[1,∞].cifra(n,α,b))
int cifraMayor(const int n, const int b)
{
    if (n < b)
    {
        return n;
    }
    else
    {
        int cifra_mayor = cifraMayor(n / b, b);
        int resto = n % 10;
        if (cifra_mayor > resto)
        {
            return cifra_mayor;
        }
        else
        {
            return resto;
        }
    }
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: cifraMasSignificativa(n,bvp ) = n / b^(NC-1)
//       ∧ (n >= b^(NC-1) ∧ n < b^NC)
int cifraMasSignificativa(const int n, const int b)
{
    if (n < b)
    {
        return n;
    }
    else
    {
        return cifraMasSignificativa(n / b, b);
    }
}

// Pre:  n >= 0 ∧ 2 <= b <= 10
// Post: sumaCifras(n,b) = (∑ α∊[1,∞].cifra(n,α,b))
int sumaCifras(const int n, const int b)
{
    if (n < b)
    {
        return n;
    }
    else
    {
        return n % 10 + sumaCifras(n / b, b);
    }
}
