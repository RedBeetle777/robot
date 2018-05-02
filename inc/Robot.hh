#ifndef ROBOT_HH
#define ROBOT_HH

/*!
 * \file
 * \brief  Definicja klasy Robot
 *
 *  Pozwala na stworzenie robota złożonego z 6 punktów
 *  i prowadzenia na nim operacji translacji.
 */

#include "Wektor.hh"
#include <cmath>
#include "Macierz.hh"
#include "Scena.hh"

/*!
 * \brief Klasa Robot
 *
 *  Umożliwia tworzenie instancji typu, który modeluje
 *  pojęcie robota.
 */

class Robot
{
    public:
    
    /*!
     * \brief Współrzędne wektora
     *
     *  Tablica zawiera kolejne współrzędne wektora.
     */
    
        Robot(Wektor w1, Wektor w2, Wektor w3, Wektor w4, Wektor w5, Wektor w6); // w1 wierzcholek, idzie do lewej i w6 to srodek
    
    /*!
     * \brief Konstruktor robota bezparametryczny
     */
    
        Robot();
    
    /*!
     * \brief Wirtualny destruktor robota
     */
    
        virtual ~Robot();
    
    /*!
     * \brief Wypisuje kolejne współrzędne robota
     *
     * Do strumienia wyjściowego w formie tekstowej wpisuje wszystkie wartości
     * współrzędnych robota.
     * Przykład wyniku operacji
     \verbatim
     1 2
     4 5
     7 2
     \endverbatim
     *  \param[in,out]  out - strumień wyjściowy, do którego zostają wpisane
     *                            w formie tekstowej wartości kolejnych współrzędnych.
     *  \param[in] robot - wektor, którego współrzędne mają zostać wpisane do strumienia.
     *  \return Referencja do strumienia wyjściowego będącego parametrem wywołania
     *          niniejszego przeciążenia operatora <<.
     */
    
        friend ostream & operator << (ostream & out, Robot robot);
    
    /*!
     *  Realizuje przemieszczenie wszystkich wartości robota o zadany wektor
     *  \param[in] wektor - drugi argument operacji przemieszczenia.
     *  \return Wynik operacji przemieszczenia.
     */
    
        void trans (Wektor wektor);
        void rot (float kat);
        float bok (int b);
        void idz (float moc, Scena scena);


    protected:

    private:
    /*!
     * \brief Tablica robota złożona z wektorów
     */
        Wektor wierz[6];
};

#endif // ROBOT_H
