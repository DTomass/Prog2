//*****************************************************************
// File:   tiempoReaccion.cpp
// Author: Daniel Tomas Martinez
// Date:   20/01/2024
// Coms:   Programa que mide el tiempo de reaccion del usuario al pulsar enter
//*****************************************************************

#include <iostream>
#include <time.h>

using namespace std;

// Muestra por pantalla el tiempo que tarda el usuario en pulsar la tecla enter desde
// que se muestra el mensaje "Pulse la tecla de fin de linea , por favor ... " las
// veces que se indique en el argumento del programa
int main(int argc, char *argv[])
{
    // Declaracion de variables
    unsigned veces = 0;
    float tiempo = 0.0;

    // Comprobacion de argumentos
    if (argc == 1)
    {
        veces = 1;
    }
    else
    {
        veces = atoi(argv[1]);
    }

    // Bucle de ejecucion
    for (int i = 0; i < veces; i++)
    {
        // Pedimos al usuario que pulse enter
        cout << i + 1 << ") Pulse la tecla de fin de linea , por favor ... ";

        // Medimos el tiempo de reaccion del usuario al pulsar enter desde que se muestra el mensaje
        struct timespec start, finish;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        cin.get();
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);

        // Mostramos el tiempo de reaccion
        tiempo += (finish.tv_sec - start.tv_sec) + (finish.tv_nsec - start.tv_nsec) * 1e-9;
        cout << "Su tiempo de reaccion ha sido de " << tiempo << " segundos." << endl
             << endl;
    }

    // Interpretacion: El tiempo que se muestra por pantalla es el tiempo que esta la CPU ocupada,
    //                 al ser una instruccion que se ejecuta en un tiempo muy corto, el tiempo que
    //                 se muestra es muy pequeño.
}