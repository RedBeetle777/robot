#include "Prost.hh"
#define PI 3.14159265

Prost::Prost(Wektor w1, Wektor w2, Wektor w3, Wektor w4, Wektor w5)
{
    wierz[0] = w1;
    wierz[1] = w2;
    wierz[2] = w3;
    wierz[3] = w4;
    wierz[4] = w5;
}

Prost::Prost()
{
    //ctor
}

Prost::~Prost()
{
    //dtor
}

ostream & operator << (ostream & s, Prost prost)
{
    return s << prost.wierz[0] << endl
    << prost.wierz[1] << endl
    << prost.wierz[2] << endl
    << prost.wierz[3] << endl
    << prost.wierz[4] << endl;
}

void Prost::trans (Wektor wektor)
{
    wierz[0] += wektor;
    wierz[1] += wektor;
    wierz[2] += wektor;
    wierz[3] += wektor;
    wierz[4] += wektor;
}

void Prost::rot (float kat, int razy)
{
    float x = (float)kat*PI/180;

    float s = sin(x);
    float c = cos(x);
    Macierz macierz = Macierz(c, -s, s, c);

    for (int i = 0; i < razy; i++)
    {
        wierz[0] = macierz * wierz[0];
        wierz[1] = macierz * wierz[1];
        wierz[2] = macierz * wierz[2];
        wierz[3] = macierz * wierz[3];
    }
}

float Prost::bok (int b)
{
    Wektor Dlugosc;
    if (b == 4)
    {
        Wektor Dlugosc = wierz[b-1] - wierz[b-4];
        return Dlugosc.dlugosc();
    }
    else
    {
        Wektor Dlugosc = wierz[b-1] - wierz[b];
        return Dlugosc.dlugosc();
    }
  //return Dlugosc.dlugosc();
}

bool Prost::poza_prostokatem (Wektor punkt)
{
    if (punkt[0] < wierz[0][0])
    {
        return true;
    } else if(punkt[1] > wierz[1][1])
    {
        return true;
    } else if(punkt[0] > wierz[2][0])
    {
        return true;
    } else if(punkt[1] < wierz[3][1])
    {
        return true;
    }
    return false;
}

