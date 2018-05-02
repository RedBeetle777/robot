#ifndef MACIERZ_HH
#define MACIERZ_HH

/*!
 * \file
 * \brief  Definicja szablonu Macierz
 *
 *  Pozwala na stworzenie tablicy 2x2
 */

#include "Wektor.hh"

/*!
 * \brief Klasa Macierz
 *
 *  Umożliwia tworzenie instancji typu, który modeluje
 *  pojęcie macierzy.
 */

class Macierz
{
    public:
    
    /*!
     * \brief Współrzędne wektora
     *
     *  Tablica zawiera kolejne współrzędne wektora.
     */
    
        Macierz(float m1,float m2,float m3,float m4);
    
    /*!
     * \brief Konstruktor macierzy bezparametryczny
     */
    
        Macierz();
    
    /*!
     * \brief Wirtualny destruktor macierzy
     */
    
        virtual ~Macierz();
    
    /*!
     *  Realizuje mnożenie macierzy przez wektor.
     *  \param[in] wektor - wektor prze który zostanie pomnożona macierz.
     *  \return Wynik operacji mnożenia.
     */
    
        Wektor operator * (Wektor wektor);

    protected:

    private:
    /*!
     * \brief Tablica macierzy
     */
        float tab[2][2];
};

#endif // MACIERZ_H
