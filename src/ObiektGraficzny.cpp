/*!
 * \file
 * \brief Zawiera definicje metod klasy ObiektGraficzny
 *
 * Zawiera definicje metod klasy ObiektGraficzny
 * wraz z ich opisem.
 */

#include <fstream>
#include "ObiektGraficzny.hh"
//#include "Wektor.hh"


using namespace std;
ObiektGraficzny::ObiektGraficzny(Wektor w1, Wektor w2, Wektor w3, Wektor w4, Wektor w5, Wektor w6, Wektor w7, Robot *roboty, int ilosc)
{
    wierz[0] = w1;
    wierz[1] = w2;
    wierz[2] = w3;
    wierz[3] = w4;
    wierz[4] = w5;
    wierz[5] = w6;
    wierz[6] = w7;
    
    this->roboty = new Robot[ilosc];
    this->ilosc = ilosc;
    
    for (int i = 0; i < ilosc; i++)
    {
        this->roboty[i] = roboty[i];
    }
}

ObiektGraficzny::ObiektGraficzny()
{
}

ObiektGraficzny::~ObiektGraficzny()
{
}

/*!
 * Przypisuje wartości współrzędnych poszczególnym wierzchołkom.
 *
 * Uwaga:Ta metoda to tylko tymczasowe rozwiązanie. Ona powinna
 *       być w klasie pochodnej.
 */
void ObiektGraficzny::InicjalizujKsztalt()
{
    /*
    Wektor w1 = Wektor(3 , 6);
    Wektor w2 = Wektor(1 , 4);
    Wektor w3 = Wektor(1 , 2);
    Wektor w4 = Wektor(5 , 2);
    Wektor w5 = Wektor(5 , 4);
    Wektor w6 = Wektor(3 , 3);
    */
  _TabWierz[0][0] =   0;  _TabWierz[0][1]=   0;
  _TabWierz[1][0] =  30;  _TabWierz[1][1]=   0;
  _TabWierz[2][0] =   0;  _TabWierz[2][1]= -30;
  _TabWierz[3][0] = -30;  _TabWierz[3][1]= -30;
  _TabWierz[4][0] = -30;  _TabWierz[4][1]=  30;
  _TabWierz[5][0] =   0;  _TabWierz[5][1]=  30;
  _TabWierz[6][0] =  30;  _TabWierz[6][1]=   0;
     
}



/*!
 *  Zmiania współrzędne położenia punktu, względem którego tworzony
 *  jest obrys obiektu.
 *  \param[in] x - współrzędna x-owa nowego położenia.
 *  \param[in] y - współrzędna y-owa nowego położenia.
 */
void ObiektGraficzny::ZmienPolozenie(double x, double y)
{
  _PolozenieObiektu[0] = x;
  _PolozenieObiektu[1] = y;  
}


/*!
 * Zapisuje do strumienia współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoStrumienia(std::ostream& StrmWy) const
{
  Wektor  W_glob;

  for (const Wektor&  W_lok : _TabWierz) {
    W_glob = W_lok + _PolozenieObiektu;
    StrmWy << W_glob << endl;
  }
  return !StrmWy.fail();
}


/*!
 * Zapisuje do pliku współrzędne globalne wierzchołków
 * obrysu obiektu.
 * \param[in,out] - strumień, do którego wpisane zostałe współrzędne
 *                  wierzchołków.
 * \retval true - gdy operacja powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool ObiektGraficzny::ZapiszDoPliku(const char* sNazwaPliku) const
{
  ofstream   StrmWy(sNazwaPliku);

  if (!StrmWy.is_open()) {
    cerr << endl
         << "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku
	 << "' nie powiodlo sie." << endl
	 << endl;
    return false;
  }
  return ZapiszDoStrumienia(StrmWy);
}
