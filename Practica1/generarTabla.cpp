//*****************************************************************
// File:   generarTabla.cpp
// Author: Daniel Tomas Martinez
// Date:   20/01/2024
// Coms:   Programa que genera una tabla de numeros aleatorios comprendidos entre dos numeros
//*****************************************************************

#include "genNum.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

// Pre: a <= b
// Post: Muestra por pantalla una tabla de numeros aleatorios comprendidos entre dos numeros dados en argumentos
int main(int argc, char *argv[])
{
    // Declaracion de variables
    double a;
    double b;
    unsigned num_nums;
    char caracter;

    // Comprobacion de argumentos
    if (argc != 5)
    {
        cout << "Error: Numero de argumentos incorrecto." << endl;
        return 1;
    }

    // Asignacion de variables
    caracter = argv[1][0];
    num_nums = atoi(argv[2]);
    a = atof(argv[3]);
    b = atof(argv[4]);

    // Comprobacion de tipo de numero segun primer argumento
    switch (caracter)
    {
    case 'E':
        for (unsigned i = 0; i < num_nums; i++)
        {
            int num_entero = randInt(a, b);
            cout << right << setw(6) << num_entero;
            if ((i + 1) % 10 == 0)
            {
                cout << endl;
            }
        }
        break;

    case 'R':
        for (unsigned i = 0; i < num_nums; i++)
        {
            double num_real = randDouble(a, b);
            cout << fixed << setprecision(3) << right << setw(8) << num_real;
            if ((i + 1) % 10 == 0)
            {
                cout << endl;
            }
        }
        break;

    default:
        break;
    }
    cout << endl;
}