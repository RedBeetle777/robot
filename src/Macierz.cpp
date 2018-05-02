#include "Macierz.hh"

Macierz::Macierz(float m1,float m2,float m3,float m4)
{
    tab[0][0] = m1;
    tab[0][1] = m2;
    tab[1][0] = m3;
    tab[1][1] = m4;
}

Macierz::Macierz()
{
    //ctor
}

Macierz::~Macierz()
{
    //dtor
}

Wektor Macierz::operator * (Wektor wektor)
{
    float wekX = wektor[0] * tab[0][0] + wektor[1] * tab[0][1];
    float wekY = wektor[0] * tab[1][0] + wektor[1] * tab[1][1];
    Wektor wektor2 = Wektor(wekX, wekY);
    //wektor2[0] = wektor[0] * tab[0][0] + wektor[1] * tab[0][1];
    //wektor2[1] = wektor[0] * tab[1][0] + wektor[1] * tab[1][1];
    return wektor2;
}
