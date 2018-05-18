#ifndef SCIEZKA_HH
#define SCIEZKA_HH

/*!
 * \file
 * \brief  Definicja klasy Sciezka
 *
 *  Pozwala na stworzenie robota złożonego z 6 punktów
 *  i prowadzenia na nim operacji translacji.
 */

#include "Wektor.hh"
#include <cmath>
#include "Macierz.hh"
#include "Scena.hh"
#include "ObiektGraficzny.hh"
#include "lacze_do_gnuplota.hh"

class Sciezka : public ObiektGraficzny
{
    public :
    void Rysuj(Wektor v1, Wektor v2);
};

#endif // SCIEZKA_H
