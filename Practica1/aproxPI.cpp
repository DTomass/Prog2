//*****************************************************************
// File:   aproxPI.cpp
// Author: Daniel Tomas Martinez
// Date:   20/01/2024
// Coms:   Programa que aproxima el valor de PI mediante el metodo de Monte Carlo
//*****************************************************************
// #define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <cmath>
#include <ctime>

using namespace std;

// Pre:  ---
// Post: Muestra por pantalla el valor de PI aproximado mediante el metodo de Monte Carlo
int main(int argc, char *argv[])
{
    // Declaracion de variables de entrada
    int minN = 0;
    int paso = 0;
    int nIter = 0;

    // Declaracion de variables de salida
    float pi = 0.0;
    float error_rel = 0.0;
    float tiempo_cpu = 0.0;

    // Comprobacion de argumentos
    if (argc != 4)
    {
        cout << "Error: Numero de argumentos incorrecto." << endl;
        return 1;
    }
    minN = atoi(argv[1]);
    paso = atoi(argv[2]);
    nIter = atoi(argv[3]);

    // Declaracion de semilla de numeros aleatorios
    // srand(time(nullptr));

    // Comprobacion de argumentos
    if (minN <= 0 || paso < 0 || nIter <= 0)
    {
        cout << "Error: Los argumentos deben ser numeros enteros positivos." << endl;
        return 1;
    }

    // Bucle de ejecucion
    for (int i = 0; i < nIter; i++)
    {
        unsigned n = minN + paso * i;
        unsigned nDentro = 0;
        struct timespec start, finish;

        // Medimos el tiempo de CPU de la aproximacion en cada iteracion
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        // Generamos n puntos aleatorios en el cuadrado de lado 1
        for (int j = 0; j < n; j++)
        {
            double x = (double)rand() / RAND_MAX;
            double y = (double)rand() / RAND_MAX;

            // Comprobamos si el punto esta dentro del circulo de radio 1
            if (sqrt(x * x + y * y) <= 1)
            {
                nDentro++;
            }
        }
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);

        // Calculamos el valor de PI aproximado, el error relativo y el tiempo de CPU
        pi = 4.0 * nDentro / n;
        error_rel = 100.0 * abs(pi - M_PI) / M_PI;
        tiempo_cpu = (finish.tv_sec - start.tv_sec) + (finish.tv_nsec - start.tv_nsec) * 1e-9;

        // Convertimos los valores de n, PI, error relativo y tiempo de CPU a string para mostrarlos
        // por pantalla con el formato adecuado
        ostringstream n_str;
        n_str << n << ";";

        ostringstream pi_str;
        pi_str << pi << ";";

        ostringstream error_rel_str;
        error_rel_str << error_rel << ";";

        ostringstream tiempo_cpu_str;
        tiempo_cpu_str << tiempo_cpu << ";";

        // Mostramos el valor de PI aproximado, el error relativo y el tiempo de CPU en cada iteracion
        cout << fixed << left << "n=" << setw(8) << n_str.str()
             << " PI (estimada)=" << setw(8) << pi_str.str() << " Error relativo(%)=" << setw(12) << error_rel_str.str() << " Tiempo CPU(s)=" << tiempo_cpu_str.str() << endl;
    }
}