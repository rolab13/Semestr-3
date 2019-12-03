////////////////////////////////////////////////////////////////
//
// JP3 - zadanie 1 - macierze.
//
// Autor - Mateusz Krzeszewski
//
// 19.10.2018 - utworzenie programu.
//
// UPDATES
//
// 20.10.2018 - dodanie +/- dla macierzy, drobne zmiany w kodzie. / MK
// 21.10.2018 - dodanie mo¿liwoœci deklarowania macierzy o dowolnych rozmiarach. / MK
//
////////////////////////////////////////////////////////////////

#include <iostream>
#include "macierz.h"

int main()
{
    macierz A,B,C,D;
    A.set(0, 0, 1.0);
    A.set(0, 1, 2.0);
    A.set(1, 0, 3.0);
    A.set(1, 1, 4.0);
    B = A;
    B.set(0, 0, 5.0);
    C = A * B;
    D = B * A;
    if( C == D )
        std::cout << "rowne";

    return 0;
}
