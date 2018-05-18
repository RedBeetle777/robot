#ifndef SCENA_HH
#define SCENA_HH

/*!
 * \file
 * \brief  Definicja klasy Scena
 *
 *  Pozwala na stworzenie wektora o 4 współrzędnych
 *  zapewniających obszar działania robota
 */

#include <cmath>
#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "Prost.hh"
//#include "Robot.hh"


/*!
 * \brief Klasa Scena
 *
 *  Umożliwia tworzenie instancji typu, który modeluje
 *  pojęcie sceny.
 */

class Scena
{
    public:
    
    /*!
     * \brief Współrzędne sceny
     *
     *  Tablica zawiera kolejne współrzędne wsceny.
     */
    
        Scena(Wektor w5, Wektor w6, Wektor w7, Wektor w8, Prost *przeszkody, int ilosc); //w5-lewy dlony, w6-lewy gorny i dalej
    
    /*!
     * \brief Konstruktor sceny bezparametryczny
     */
    
        Scena();
    
    /*!
     * \brief Wirtualny destruktor sceny
     */
    
        virtual ~Scena();
    
        bool poza_scena(Wektor punkt);
        bool kolizja_z_przeszkoda(Wektor punkt);

    protected:

    private:
    
    /*!
     * \brief Tablica sceny
     */
    
        Wektor wierz[4];
        Prost *przeszkody;
        //Robot *robot;
        int ilosc;
};

#endif // SCENA_H
