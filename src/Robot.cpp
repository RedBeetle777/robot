#include "Robot.hh"
#define PI 3.14159265

Robot::Robot(Wektor w1, Wektor w2, Wektor w3, Wektor w4, Wektor w5, Wektor w6, Wektor w7)
{
    wierz[0] = w1;
    wierz[1] = w2;
    wierz[2] = w3;
    wierz[3] = w4;
    wierz[4] = w5;
    wierz[5] = w6;
    wierz[6] = w7;
}

Robot::Robot()
{
    //ctor
}

Robot::~Robot()
{
    //dtor
}

ostream & operator << (ostream & s, Robot robot)
{
    return s << robot.wierz[0] << endl
    << robot.wierz[1] << endl
    << robot.wierz[2] << endl
    << robot.wierz[3] << endl
    << robot.wierz[4] << endl
    << robot.wierz[5] << endl
    << robot.wierz[6] << endl;
}

void Robot::trans (Wektor wektor)
{
    wierz[0] += wektor;
    wierz[1] += wektor;
    wierz[2] += wektor;
    wierz[3] += wektor;
    wierz[4] += wektor;
    wierz[5] += wektor;
    wierz[6] += wektor;
}

void Robot::rot (float kat)
{
    float x = kat*PI/180;
    
    float s = sin(x);
    float c = cos(x);
    Macierz macierz = Macierz(c, -s, s, c);
    
    Wektor odleglosc(-wierz[6][0], -wierz[6][1]);
    trans(odleglosc);
    
    for (int i = 0; i < 7; i++)
    {
        wierz[i] = macierz * wierz[i];
    }
    
    Wektor odleglosc2(-odleglosc[0], -odleglosc[1]);
    trans(odleglosc2);
}

float Robot::bok (int b)
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

void Robot::idz (float moc, Scena scena)
{
    Wektor kier;
    kier = wierz[0] - wierz[6];
    
    kier = Wektor(kier [0]/kier.dlugosc(), kier [1]/kier.dlugosc());
    kier = kier*moc;
    
    bool robot_poza_scena = false;
    bool robot_w_przeszkodzie = false;
    for (int i = 0; i < 7; i++)
    {
        if (scena.poza_scena(wierz[i]+kier))
        {
            robot_poza_scena = true;
            break;
        }
        else if(scena.kolizja_z_przeszkoda(wierz[i]+kier))
        {
            robot_w_przeszkodzie = true;
            break;
        }
    }
    
    if (robot_poza_scena) {
        cout << "Robot wyszedl poza scene. nie wykonano polecenia." << endl;
    } else if(robot_w_przeszkodzie)
    {
        cout << "Robot wszedl w przeszkode. nie wykonano polecenia." << endl;
    } else
    {
        trans(kier);
    }
}
