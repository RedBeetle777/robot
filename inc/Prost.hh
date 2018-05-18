#ifndef PROST_HH
#define PROST_HH
#include "Wektor.hh"
#include <cmath>
#include "Macierz.hh"
#include "ObiektGraficzny.hh"

class Prost : public ObiektGraficzny
{
    public:
        Prost(Wektor w1, Wektor w2, Wektor w3, Wektor w4, Wektor w5);
        Prost();
        virtual ~Prost();
        friend ostream & operator << (ostream & out, Prost prost);
        void trans (Wektor wektor);
        void rot (float kat, int razy);
        float bok (int b);
        bool poza_prostokatem (Wektor punkt);

    protected:

    private:
        Wektor wierz[5];
};

#endif // PROST_HH

