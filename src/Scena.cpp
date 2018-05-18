#include "Scena.hh"
#include "Prost.hh"

Scena::Scena(Wektor w5, Wektor w6, Wektor w7, Wektor w8, Prost *przeszkody, int ilosc)
{
    wierz[0] = w5;
    wierz[1] = w6;
    wierz[2] = w7;
    wierz[3] = w8;
    
    this->przeszkody = new Prost[ilosc];
    this->ilosc = ilosc;
    
    for (int i = 0; i < ilosc; i++)
    {
        this->przeszkody[i] = przeszkody[i];
    }
}

Scena::Scena()
{
    
}

Scena::~Scena()
{
}

bool Scena::poza_scena(Wektor punkt)
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

bool Scena::kolizja_z_przeszkoda(Wektor punkt)
{
    for(int i = 0; i < ilosc; i++)
    {
        if(!przeszkody[i].poza_prostokatem(punkt))
        {
            return true;
        }
    }
    return false;
}
