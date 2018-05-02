#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "Wektor.hh"
#include "Scena.hh"
#include "Robot.hh"
#define PI 3.14159265

int main()
{
    char menu = 0;
    float kat = 0;
    float przes = 0;
    char                  Znak;
    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
    // rysunku prostokata
    fstream plik("figury/robot.dat", ios::out);

    Wektor w1 = Wektor(20 , 20);
    Wektor w2 = Wektor(20 , 60);
    Wektor w3 = Wektor(0 , 40);
    Wektor w4 = Wektor(0 , 0);
    Wektor w5 = Wektor(40 , 0);
    Wektor w6 = Wektor(40 , 40);

    Scena scena(Wektor(0, 0), Wektor(0, 50), Wektor(50, 50), Wektor(50, 0));

    Robot robot = Robot(w1, w2, w3, w4, w5, w6);

    //cout << robot << endl;
    //robot.trans(Wektor(0, 4));
    //cout << robot << endl;
    
    cout << "ROBOT I KOLIZJE" << endl;
    cout << "MENU" <<endl;
    cout << "///////////////////////////////////////////////////////////" << endl;
    cout << "o- obrot robota o podany kat" << endl;
    cout << "p- ruch robota o podana wartosc" << endl;
    cout << "w- wyswietlenie pozycji robota" << endl;
    cout << "m- wyswietl menu" << endl;
    cout << "k- koniec pracy programu" << endl;
    
    do
    {
        
        cout << endl << "Prosze wybrac opcje (m- menu): ";
        cin >> menu;
        
        switch(menu)
        {
            case 'o':
                cout << "Podaj kat: ";
                cin >> kat;
                
                robot.rot(kat);
                plik << robot;
                
                break;
                
            case 'm':
                cout << "MENU" <<endl;
                cout << "///////////////////////////////////////////////////////////" << endl;
                cout << "o- obrot robota o podany kat i okreslona ilosc razy" << endl;
                cout << "p- ruch robota o podana wartosc" << endl;
                cout << "w- wyswietlenie pozycji robota" << endl;
                cout << "m- wyswietl menu" << endl;
                cout << "k- koniec pracy programu" << endl;
                
                break;
                
            case 'p':
                cout << "Podaj wektor przesuniecia: ";
                cin >> przes;
                
                robot.idz(przes, scena);
                plik << robot;
                
                break;
                
            case 'w':
                cout << "Wyswietl wierzcholki:" << endl << robot;
                plik << robot;
                Lacze.DodajNazwePliku("figury/robot.dat",PzG::RR_Ciagly,2);
                Lacze.ZmienTrybRys(PzG::TR_2D);
                Lacze.Rysuj();
                cout << "Nacisnij ENTER, aby kontynuowac" << endl;
                cin >> noskipws >> Znak;
        
                break;
                
        }
    }
    while(menu != 'k');
    cout << endl << "Zakonczono prace programu" << endl;





    return 0;
}
