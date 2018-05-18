#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "Wektor.hh"
#include "Scena.hh"
#include "Robot.hh"
#include "Prost.hh"
#include "Sciezka.hh"
#define PI 3.14159265

int main()
{
    char menu = 0;
    float kat = 0;
    float przes = 0;
    char                  Znak;
    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
    // rysunku prostokata
    fstream plik1("figury/robot.dat", ios::out);
    fstream plik2("figury/scena.dat", ios::out);
    fstream plik3("figury/prost1.dat", ios::out);
    fstream plik4("figury/prost2.dat", ios::out);
    fstream plik5("figury/prost3.dat", ios::out);

    Wektor w1 = Wektor(60 , 100);
    Wektor w2 = Wektor(40 , 80);
    Wektor w3 = Wektor(40 , 60);
    Wektor w4 = Wektor(80 , 60);
    Wektor w5 = Wektor(80 , 80);
    Wektor w6 = Wektor(60 , 100);
    Wektor w7 = Wektor(60 , 70);
    
    /*
    
    Robot robot[3];
    robot[0] = Robot (Wektor(60 , 100), Wektor(40 , 80), Wektor(40 , 60), Wektor(80 , 60), Wektor(80 , 80), Wektor(60 , 100), Wektor(60 , 70));
    robot[1] = Robot (Wektor(60 , 100), Wektor(40 , 80), Wektor(40 , 60), Wektor(80 , 60), Wektor(80 , 80), Wektor(60 , 100), Wektor(60 , 70));
    robot[2] = Robot (Wektor(60 , 100), Wektor(40 , 80), Wektor(40 , 60), Wektor(80 , 60), Wektor(80 , 80), Wektor(60 , 100), Wektor(60 , 70));
    */
    Prost przeszkoda[3];
    przeszkoda[0] = Prost (Wektor(1, 130), Wektor(1, 150), Wektor(70, 150), Wektor(70, 130), Wektor(1, 130));
    przeszkoda[1] = Prost (Wektor(-200, -80), Wektor(-200, -150), Wektor(-100, -150), Wektor(-100, -80), Wektor(-200, -80));
    przeszkoda[2] = Prost (Wektor(140, 20), Wektor(140, 90), Wektor(190, 90), Wektor(190, 20), Wektor(140, 20));
    //przeszkoda[3] = Prost (Wektor(-300, -300), Wektor(-300, 300), Wektor(300, 300),
    //                       Wektor(300, -300), Wektor(-300, -300));
    
    Scena scena(Wektor(-300, -300), Wektor(-300, 300), Wektor(300, 300), Wektor(300, -300), przeszkoda, 3);

    Robot robot = Robot(w1, w2, w3, w4, w5, w6, w7);

    //plik1 << robot;
    //plik2 << scena;
    
    //plik2 << przeszkoda[3];
    plik3 << przeszkoda[0];
    plik4 << przeszkoda[1];
    plik5 << przeszkoda[2];
    
    //cout << robot << endl;
    //robot.trans(Wektor(0, 4));
    //cout << robot << endl;
    //Sciezka s;
    //s.Rysuj(Wektor(2,5), Wektor(5,5));
    
    
    
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
                plik1 << robot;
                
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
                plik1 << robot;
                
                break;
                
            case 'w':
                cout << "Wyswietl wierzcholki:" << endl << robot;
                
                plik1 << robot;
                Lacze.DodajNazwePliku("figury/robot.dat",PzG::RR_Ciagly,2);
                Lacze.DodajNazwePliku("figury/prost1.dat",PzG::RR_Ciagly,2);
                Lacze.DodajNazwePliku("figury/prost2.dat",PzG::RR_Ciagly,2);
                Lacze.DodajNazwePliku("figury/prost3.dat",PzG::RR_Ciagly,2);
                //Lacze.DodajNazwePliku("figury/scena.dat",PzG::RR_Ciagly,2);
                Lacze.ZmienTrybRys(PzG::TR_2D);
                Lacze.Rysuj();
                //cout << "Nacisnij ENTER, aby kontynuowac" << endl;
                cin >> noskipws >> Znak;
                cin >> skipws;
                break;
                
        
                
        }
    }
    while(menu != 'k');
    cout << endl << "Zakonczono prace programu" << endl;





    return 0;
}
