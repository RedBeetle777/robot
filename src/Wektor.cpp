#include "Wektor.hh"

using namespace std;

Wektor::Wektor(float x, float y)
{
    tab[0] = x;
    tab[1] = y;
}


Wektor::Wektor()
{
    //ctor
}

Wektor::~Wektor()
{
    //dtor
}

ostream & operator << (ostream & s, Wektor wektor)
{
    return s << wektor.tab[0] << " " << wektor.tab[1]; //odwoluje sie do klasy wyjscia
}

float Wektor::operator [] (int n)
{
    return tab[n]; //odwoluje sie do tej samej klasy
}

Wektor Wektor::operator + (Wektor wektor)
{
    return Wektor(wektor[0] + tab[0], wektor[1] + tab[1]);
}

Wektor Wektor::operator - (Wektor wektor)
{
    return Wektor(tab[0] - wektor[0], tab[1] - wektor[1]);
}

Wektor & Wektor::operator += (Wektor wektor)
{
    tab[0] += wektor[0];
    tab[1] += wektor[1];
    return * this;  // funkcja zwraca ten obiekt z ktorego zostala wywolana
}

istream & operator >> (istream & i, Wektor & wektor)
{
    return i >> wektor.tab[0] >> wektor.tab[1];
}

float Wektor::dlugosc()
{
  return sqrt(pow(tab[0],2)+pow(tab[1],2));
}

Wektor Wektor::operator * (float mnoz)
{
    return Wektor(tab[0]*mnoz, tab[1]*mnoz);
}
