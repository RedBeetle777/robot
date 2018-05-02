#ifndef SCENA_HH
#define SCENA_HH

/*!
 * \file
 * \brief  Definicja klasy Scena
 *
 *  Pozwala na stworzenie wektora o 4 współrzędnych
 *  zapewniających obszar działania robota
 */

#include "Wektor.hh"
#include <cmath>
#include "Macierz.hh"
#include <iostream>

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
    
        Scena(Wektor w5, Wektor w6, Wektor w7, Wektor w8); //w5-lewy dlony, w6-lewy gorny i dalej
    
    /*!
     * \brief Konstruktor sceny bezparametryczny
     */
    
        Scena();
    
    /*!
     * \brief Wirtualny destruktor sceny
     */
    
        virtual ~Scena();

    protected:

    private:
    
    /*!
     * \brief Tablica sceny
     */
    
        Wektor wierz[4];
};

#endif // SCENA_H
