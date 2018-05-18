#include "Sciezka.hh"

using namespace std;

void Sciezka :: Rysuj(Wektor v1, Wektor v2)
{
    //return v1;
}
/*
bool LaczeDoGNUPlota::RysujDoPliku(const char *NazwaPliku)
{
    if (!CzyPolaczenieJestZainicjowane()) {
        if (!Inicjalizuj()) return false;
    }
    string Polecenie = "\n\n\nset output '";
    Polecenie += NazwaPliku;
    Polecenie += "\n set term png\n";
    if (!PrzeslijDoGNUPlota(Polecenie.c_str())) {
        KomunikatBledu("!!! Rysunek nie moze byc utworzony.");
        return false;
    }
    
    bool Wynik = Rysuj();
    if (!PrzeslijDoGNUPlota("\n\n\nset output \nset term x11\n")) {
        KomunikatBledu("!!! Wyjscie dla gnuplot'a nie zostalo poprawnie\n"
                       "!!! przestawione na STDOUT.\n");
        return false;
    }
    return Wynik;
}
*/
