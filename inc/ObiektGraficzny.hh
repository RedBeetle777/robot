#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH

/*!
 * \file
 * \brief Definicja klasy ObiektGraficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny.
 */

#include <iostream>
#include "Wektor.hh"

/*!
 * \brief Modeluje obiekt, który ma swoją reprezentację graficzną
 *
 * Modeluje obiekt, który ma swoją reprezentację graficzną
 * w postaci łamanej. Może ona być łamaną zamkniętą w postaci
 * wieloboku lub otwartą. Ilość jej wierzchołków nie jest jawnie
 * ograniczona. Jedynym ograniczeniem jest dostępność pamięci
 * komputera.
 */
class ObiektGraficzny {
  /*!
   * \brief Współrzędne pozycji obiektu
   *
   *  Zawiera współrzędne punktu względem, którego podane są
   *  współrzędne punktów obrysu obiektu.
   */
   Wektor   PolozenieObiektu;
  /*!
   * \brief Tablica wierzchołków
   *
   *  
   */
   //Wektor   _TabWierz[7]; // To jest tylko tymczasowe rozwiązanie.
                            // Tu należy użyć szablonu wektor.

  public:
  /*!
   * \brief Inicjalizacja współrzędnych wierzchołków
   */
   void InicjalizujKsztalt();
  /*!
   * \brief Metoda zapisuje do pliku współrzędne wierzchołków
   */
   bool ZapiszDoPliku(const char* sNazwaPliku) const;
  /*!
   * \brief Metoda zapisuje do strumienia współrzędne wierzchołków
   */   
   bool ZapiszDoStrumienia(std::ostream& StrmWy) const;
  /*!
   * \brief Zmiania współrzędne położenia obiektu
   */
  void ZmienPolozenie(double x, double y);
};


#endif
