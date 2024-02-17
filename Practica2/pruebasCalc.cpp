//*****************************************************************
// File:   pruebasCal.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2024
// Coms:   Programa de pruebas del comportamiento de las funciones
//         definidas en el módulo calculos
//*****************************************************************

#include <iostream>
#include "calculos.hpp"

using namespace std;

// Pre:  <cifras> es el número de cifras de <n> cuando se escribe en base <b>
//       y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar numCifras(n, b) es igual
//       a <cifras> o no lo es
void probarNumCifras(const int n, const int b, const int cifras)
{
    int r = numCifras(n, b);
    if (r == cifras)
    {
        cout << "Ok. numCifras(" << n << "," << b << ") = " << r << endl;
    }
    else
    {
        cout << "Mal. numCifras(" << n << "," << b << ") = " << r << ", pero debería ser "
             << cifras << endl;
    }
}

// Pre:  <cifrax> es el valor de la cifra <i> de <n> cuando se escribe en base <b>
//       y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar cifra(n, i, b) es igual
//       a <cifrax> o no lo es
void probarCifra(const int n, const int i, const int b, const int cifrax)
{
    int r = cifra(n, i, b);
    if (r == cifrax)
    {
        cout << "Ok. cifra(" << n << "," << i << "," << b << ") = " << r << endl;
    }
    else
    {
        cout << "Mal. cifra(" << n << "," << i << "," << b << ") = " << r << ", pero debería ser "
             << cifrax << endl;
    }
}

// Pre:  <cifra_mayor> es el valor de la cifra mayor de <n> cuando se escribe en base <b>
//       y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar cifraMayor(n, b) es igual a <cifra_mayor>
//       o no lo es
void probarCifraMayor(const int n, const int b, const int cifra_mayor)
{
    int r = cifraMayor(n, b);
    if (r == cifra_mayor)
    {
        cout << "Ok. cifraMayor(" << n << "," << b << ") = " << r << endl;
    }
    else
    {
        cout << "Mal. cifraMayor(" << n << "," << b << ") = " << r << ", pero debería ser "
             << cifra_mayor << endl;
    }
}

// Pre:  <cifra_mas_significativa> es el valor de la cifra más significativa de <n>
//       cuando se escribe en base <b> y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar cifraMasSignificativa(n, b) es igual
//       a <cifra_mas_significativa> o no lo es
void probarCifraMasSignificativa(const int n, const int b, const int cifra_mas_significativa)
{
    int r = cifraMasSignificativa(n, b);
    if (r == cifra_mas_significativa)
    {
        cout << "Ok. cifraMasSignificativa(" << n << "," << b << ") = " << r << endl;
    }
    else
    {
        cout << "Mal. cifraMasSignificativa(" << n << "," << b << ") = " << r << ", pero debería ser "
             << cifra_mas_significativa << endl;
    }
}

// Pre:  <suma_cifras> es el valor de la suma de las cifras de <n> cuando se escribe en base <b>
//       y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar sumaCifras(n, b) es igual a <suma_cifras>
//       o no lo es
void probarSumaCifras(const int n, const int b, const int suma_cifras)
{
    int r = sumaCifras(n, b);
    if (r == suma_cifras)
    {
        cout << "Ok. sumaCifras(" << n << "," << b << ") = " << r << endl;
    }
    else
    {
        cout << "Mal. sumaCifras(" << n << "," << b << ") = " << r << ", pero debería ser "
             << suma_cifras << endl;
    }
}

// Prueba el comportamiento de numCifras(n,10) para los siguientes valores de n:
// 0, 1, 9, 10, 99, 100, 999, 1000, ... , 99999, 100000, 99999 y 1000000
// y prueba el comportamiento de numCifras(n,2) para los siguientes valores de n:
// 0, 1, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, ..., 4095, 4096, 8191 y 8192
void probarNumCifras()
{
    // Prueba el comportamiento de numCifras(n) para los siguientes valores de n:
    // 0, 1, 9, 10, 99, 100, 999, 1000, ..., 99999, 100000, 99999 y 1000000
    probarNumCifras(0, 10, 1);
    probarNumCifras(1, 10, 1);
    int n = 10;
    int cifras = 2;
    while (n <= 1000000)
    {
        probarNumCifras(n - 1, 10, cifras - 1);
        probarNumCifras(n, 10, cifras);
        n = 10 * n;
        cifras = cifras + 1;
    }
    cout << endl;
    // Prueba el comportamiento de numCifras(n,2) para los siguientes valores de n:
    // 0, 1, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, ..., 4095, 4096, 8191 y 8192
    probarNumCifras(0, 2, 1);
    probarNumCifras(1, 2, 1);
    n = 2;
    cifras = 2;
    while (n <= 10000)
    {
        probarNumCifras(n - 1, 2, cifras - 1);
        probarNumCifras(n, 2, cifras);
        n = 2 * n;
        cifras = cifras + 1;
    }
    cout << endl;
}

// Prueba el comportamiento de cifra(n,i,b) para diferentes números naturales
// en las bases de numeración 2 y 10
void probarCifra()
{
    probarCifra(0, 1, 10, 0);
    probarCifra(1, 1, 10, 1);
    probarCifra(9, 1, 10, 9);
    probarCifra(10, 1, 10, 0);
    probarCifra(89, 2, 10, 8);
    probarCifra(1673, 4, 10, 1);
    probarCifra(45342, 3, 10, 3);
    cout << endl;
    probarCifra(0, 1, 2, 0);
    probarCifra(1, 1, 2, 1);
    probarCifra(9, 1, 2, 1);
    probarCifra(10, 1, 2, 0);
    probarCifra(89, 2, 2, 0);
    probarCifra(1673, 4, 2, 1);
    probarCifra(45342, 9, 2, 1);
    cout << endl;
}

// Prueba el comportamiento de cifraMayor(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMayor()
{
    probarCifraMayor(0, 10, 0);
    probarCifraMayor(1, 10, 1);
    probarCifraMayor(9, 10, 9);
    probarCifraMayor(10, 10, 1);
    probarCifraMayor(89, 10, 9);
    probarCifraMayor(1673, 10, 7);
    cout << endl;
    probarCifraMayor(0, 8, 0);
    probarCifraMayor(1, 8, 1);
    probarCifraMayor(9, 8, 1);
    probarCifraMayor(10, 8, 2);
    probarCifraMayor(89, 8, 3);
    probarCifraMayor(1673, 8, 3);
    cout << endl;
    probarCifraMayor(0, 2, 0);
    probarCifraMayor(1, 2, 1);
    probarCifraMayor(9, 2, 1);
    probarCifraMayor(10, 2, 1);
    probarCifraMayor(89, 2, 1);
    cout << endl;
}

// Prueba el comportamiento de cifraMasSignificativa(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMasSignificativa()
{
    probarCifraMasSignificativa(0, 10, 0);
    probarCifraMasSignificativa(1, 10, 1);
    probarCifraMasSignificativa(9, 10, 9);
    probarCifraMasSignificativa(10, 10, 1);
    probarCifraMasSignificativa(89, 10, 8);
    probarCifraMasSignificativa(1673, 10, 1);
    cout << endl;
    probarCifraMasSignificativa(0, 8, 0);
    probarCifraMasSignificativa(1, 8, 1);
    probarCifraMasSignificativa(9, 8, 1);
    probarCifraMasSignificativa(10, 8, 1);
    probarCifraMasSignificativa(89, 8, 1);
    probarCifraMasSignificativa(1673, 8, 3);
    cout << endl;
    probarCifraMasSignificativa(0, 2, 0);
    probarCifraMasSignificativa(1, 2, 1);
    probarCifraMasSignificativa(9, 2, 1);
    probarCifraMasSignificativa(10, 2, 1);
    probarCifraMasSignificativa(89, 2, 1);
    probarCifraMasSignificativa(1673, 2, 1);
    cout << endl;
}

// Prueba el comportamiento de probarSumaCifras(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarSumaCifras()
{
    probarSumaCifras(0, 10, 0);
    probarSumaCifras(1, 10, 1);
    probarSumaCifras(9, 10, 9);
    probarSumaCifras(10, 10, 1);
    probarSumaCifras(89, 10, 17);
    probarSumaCifras(1673, 10, 17);
    cout << endl;
    probarSumaCifras(0, 8, 0);
    probarSumaCifras(1, 8, 1);
    probarSumaCifras(9, 8, 2);
    probarSumaCifras(10, 8, 3);
    probarSumaCifras(89, 8, 5);
    probarSumaCifras(1673, 8, 7);
    cout << endl;
    probarSumaCifras(0, 2, 0);
    probarSumaCifras(1, 2, 1);
    probarSumaCifras(9, 2, 2);
    probarSumaCifras(10, 2, 2);
    probarSumaCifras(89, 2, 4);
    probarSumaCifras(1673, 2, 5);
}

// Ejecuta una secuencia de pruebas de las funciones definidas en el módulo calculos.hpp
int main()
{
    // Pruebas del comportamiento de numCifras(n,b)
    probarNumCifras();
    // Pruebas del comportamiento de cifra(n,i,b)
    probarCifra();
    // Pruebas del comportamiento de cifraMayor(n,b)
    probarCifraMayor();
    // Pruebas del comportamiento de cifraMasSignificativa(n,b)
    probarCifraMasSignificativa();
    // Pruebas del comportamiento de sumaCifras(n,b)
    probarSumaCifras();

    return 0;
}
