#ifndef WEKTOR_HH
#define WEKTOR_HH

/*!
 * \file
 * \brief  Definicja klasy Wektor
 *
 *  Pozwala na stworzenie wektora o wymiarze 2
 *  oraz typie pól reprezentujących jego współrzędne, dla
 *  których zdefiniowane są podstawowe działania arytmetyczne.
 */

#include <iostream>
#include <cmath>



using namespace std;

/*!
 * \brief Klasa wektor
 *
 *  Umożliwia tworzenie instancji typu, który modeluje
 *  pojęcie wektora.
 */

class Wektor
{
    public:
    
    /*!
     * \brief Współrzędne wektora
     *
     *  Tablica zawiera kolejne współrzędne wektora.
     */
        Wektor(float x, float y);
    /*!
     * \brief Konstruktor wektora bezparametryczny
     */
        Wektor();
    /*!
     * \brief Wirtualny destruktor wektora
     */
    
        virtual ~Wektor();
    
    /*!
     * \brief Wypisuje kolejne współrzędne wektora
     *
     * Do strumienia wyjściowego w formie tekstowej wpisuje wszystkie wartości
     * współrzędnych wektora rozdzielając je spacją i parując je dla jednego punktu.
     * Przykład wyniku operacji
     \verbatim
     1 2
     4 5
     7 2
     \endverbatim
     *  \param[in,out]  out - strumień wyjściowy, do którego zostają wpisane
     *                            w formie tekstowej wartości kolejnych współrzędnych.
     *  \param[in] wektor - wektor, którego współrzędne mają zostać wpisane do strumienia.
     *  \return Referencja do strumienia wyjściowego będącego parametrem wywołania
     *          niniejszego przeciążenia operatora <<.
     */
    
        friend ostream & operator << (ostream & out, Wektor wektor);
    
    /*!
     * \brief Dostęp poprzez indeks do współrzędnych wektora w trybie tylko do odczytu.
     *
     *  Umożliwia dostęp do współrzędnych poprzez indeks w trybie tylko do odczytu.
     *  Nie jest sprawdzana poprawność wartości indeksu, czy mieści się we właściwym zakresie.
     *
     *  \param[in] n - indeks wybranej współrzędnej. Indeksowanie tak jak w przypadku
     *               tablicy, zaczyna się od 0.
     *  \pre Wartość parametru n musi być mniejsza niż 2.
     *  \return Wartość indeksowanej współrzędnej.
     */
    
        float operator [] (int n);
    
    /*!
     *  Realizuje dodawanie dwóch wektorów i zwraca wynik działania.
     *  \param[in] wektor - drugi argument operacji dodwania.
     *  \return Wynik operacji dodawania.
     */
    
        Wektor operator + (Wektor wektor);
    
    /*!
     *  Realizuje odejmowania dwóch wektorów i zwraca wynik działania.
     *  \param[in] wektor - drugi argument operacji odejmowania.
     *  \return Wynik operacji odejmowania.
     */
    
        Wektor operator - (Wektor wektor);
    
    /*!
     *  Realizuje nadpisywanie wektora wynikiem dodawania.
     *  \param[in] wektor - drugi argument operacji dodwania.
     *  \return Wynik operacji nadpisywania.
     */
    
        Wektor & operator += (Wektor wektor);
    
    /*!
     * \brief Zapisuje kolejne współrzędne wektora
     *
     * Do strumienia wejściowego w formie tekstowej wpisuje wszystkie wartości
     * współrzędnych wektora.
     *  \param[in,out]  in - strumień wejściowy, do którego zostają wpisane
     *                            w formie tekstowej wartości kolejnych współrzędnych.
     *  \param[in] wektor - wektor, którego współrzędne mają zostać wpisane do strumienia.
     *  \return Referencja do strumienia wejściowego będącego parametrem wywołania
     *          niniejszego przeciążenia operatora >>.
     */
    
        friend istream & operator >> (istream & in, Wektor & wektor);
        //friend ostream & operator << (ostream & out, Wektor wektor);
        float dlugosc();
    
    /*!
     *  Realizuje mnożenie wektora i liczby.
     *  \param[in] mnoz - wartość liczby mnożonej przez wartości wektora.
     *  \return Wynik operacji mnożenia.
     */
    
        Wektor operator * (float mnoz);


    protected:

    private:
    /*!
     * \brief Tablica wektora
     */
        float tab[2];

};

#endif // WEKTOR_H
