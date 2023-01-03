

#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <conio.h>
using namespace std;

class grupa
{
public:
    string dr1, dr2, dr3, dr4;
    int* pkt1, * pkt2, * pkt3, * pkt4;
    int* bil1, * bil2, * bil3, * bil4;
    string group;
    void druzyna1()
    {
        cout << dr1 << " " << pkt1 << " " << bil1 << endl;
    }
    void druzyna2()
    {
        cout << dr2 << " " << pkt2 << " " << bil2 << endl;
    }
    void druzyna3()
    {
        cout << dr3 << " " << pkt3 << " " << bil3 << endl;
    }
    void druzyna4()
    {
        cout << dr4 << " " << pkt4 << " " << bil4 << endl;
    }
};
/*
//    void tabela()
//    {
//        if (dr1>dr2>dr3>dr4)
//        {
//            druzyna1();
//            druzyna2();
//            druzyna3();
//            druzyna4();
//
//        }
//        if (dr1 > dr2 > dr4 > dr3)
//        {
//            druzyna1();
//            druzyna2();
//            druzyna4();
//            druzyna3();
//
//        }
//        if (dr1 > dr3 > dr2 > dr4)
//        {
//            druzyna1();
//            druzyna3();
//            druzyna2();
//            druzyna4();
//
//        }
//        if (dr1 > dr3 > dr4 > dr2)
//        {
//            druzyna1();
//            druzyna3();
//            druzyna4();
//            druzyna2();
//
//        }
//        if (dr1 > dr4 > dr3 > dr2)
//        {
//            druzyna1();
//            druzyna4();
//            druzyna3();
//            druzyna2();
//
//        }
//        if (dr1 > dr4 > dr2 > dr3)
//        {
//            druzyna1();
//            druzyna4();
//            druzyna2();
//            druzyna3();
//
//        }
//        if (dr2 > dr1 > dr3 > dr4)
//        {
//            druzyna2();
//            druzyna1();
//            druzyna3();
//            druzyna4();
//
//        }
//        if (dr2 > dr1 > dr4 > dr3)
//        {
//            druzyna2();
//            druzyna1();
//            druzyna4();
//            druzyna3();
//
//        }
//        if (dr2 > dr3 > dr1 > dr4)
//        {
//            druzyna2();
//            druzyna3();
//            druzyna1();
//            druzyna4();
//
//        }
//        if (dr2 > dr3 > dr4 > dr1)
//        {
//            druzyna2();
//            druzyna3();
//            druzyna4();
//            druzyna1();
//
//        }
//        if (dr2 > dr4 > dr3 > dr1)
//        {
//            druzyna2();
//            druzyna4();
//            druzyna3();
//            druzyna1();
//
//        }
//        if (dr2 > dr4 > dr1 > dr3)
//        {
//            druzyna2();
//            druzyna4();
//            druzyna1();
//            druzyna3();
//
//        }
//        if (dr3 > dr1 > dr2 > dr4)
//        {
//            druzyna3();
//            druzyna1();
//            druzyna2();
//            druzyna4();
//
//        }
//        if (dr3 > dr1 > dr4 > dr2)
//        {
//            druzyna3();
//            druzyna1();
//            druzyna4();
//            druzyna2();
//
//        }
//        if (dr3 > dr2 > dr1 > dr4)
//        {
//            druzyna3();
//            druzyna2();
//            druzyna1();
//            druzyna4();
//
//        }
//        if (dr3 > dr2 > dr4 > dr1)
//        {
//            druzyna3();
//            druzyna2();
//            druzyna4();
//            druzyna1();
//
//        }
//        if (dr3 > dr4 > dr2 > dr1)
//        {
//            druzyna3();
//            druzyna4();
//            druzyna2();
//            druzyna1();
//
//        }
//        if (dr3 > dr4 > dr1 > dr2)
//        {
//            druzyna3();
//            druzyna4();
//            druzyna1();
//            druzyna2();
//
//        }
//        if (dr4 > dr1 > dr2 > dr3)
//        {
//            druzyna4();
//            druzyna1();
//            druzyna2();
//            druzyna3();
//
//        }
//        if (dr4 > dr1 > dr3 > dr2)
//        {
//            druzyna4();
//            druzyna1();
//            druzyna3();
//            druzyna2();
//
//        }
//        if (dr4 > dr2 > dr1 > dr3)
//        {
//            druzyna4();
//            druzyna2();
//            druzyna1();
//            druzyna3();
//
//        }
//        if (dr4 > dr2 > dr3 > dr1)
//        {
//            druzyna4();
//            druzyna2();
//            druzyna3();
//            druzyna1();
//
//        }
//        if (dr4 > dr3 > dr2 > dr1)
//        {
//            druzyna4();
//            druzyna3();
//            druzyna2();
//            druzyna1();
//
//        }
//        if (dr4 > dr3 > dr1 > dr2)
//        {
//            druzyna4();
//            druzyna3();
//            druzyna1();
//            druzyna2();
//
//        }
//
//    }
//
//
//};*/

double bramki()
{
    int bramki;
    srand(time(NULL));
    bramki = rand() % 6 + 1;
    return bramki;
}
double szansa1(double waga1, double waga2)
{
    double szansa1;
    szansa1 = (waga1 / (waga1 + waga2)) * 100;
    return szansa1;
}
double szansa2(double waga1, double waga2)
{
    double szansa2;
    szansa2 = (waga2 / (waga1 + waga2)) * 100;
    return szansa2;
}

void mecz(int* dr1, int* dr2, int* bil1, int* bil2, double waga1, double waga2, string druzyna1, string druzyna2)
{
    int gol1 = 0;
    int gol2 = 0;
    int gol[10];
    for (int i = 0; i < bramki(); i++)
    {
        srand(time(NULL));
        gol[i] = rand() % 101;
        if (gol[i] < szansa1(waga1, waga2))
        {
            gol1 = gol1 + 1;
            *bil1 = *bil1 + 1;
            *bil2 = *bil2 - 1;
        }
        else
        {
            gol2 = gol2 + 1;
            *bil1 = *bil1 - 1;
            *bil2 = *bil2 + 1;
        }
    }
    if (gol1 > gol2)
    {
        *dr1 = *dr1 + 3;
    }
    else if (gol2 > gol1)
    {
        *dr2 = *dr2 + 3;
    }
    else if (gol1 = gol2)
    {
        *dr1 = *dr1 + 1;
        *dr2 = *dr2 + 1;
    }
    cout << "Wynik meczu: " << druzyna1 << " - " << druzyna2 << "     " << gol1 << " - " << gol2 << endl;
}


int main()
{
    int pkt1 = 0;
    int pkt2 = 0;
    int bilans1 = 0;
    int bilans2 = 0;
    int wag1 = 6;
    int wag2 = 4;
    string druzyna1 = "Polska";
    string druzyna2 = "Francja";
    cout << "Mecz 1:" << endl;
    mecz(&pkt1, &pkt2, &bilans1, &bilans2, wag1, wag2, druzyna1, druzyna2); cout << "Punkty1: " << pkt1 << "  Bilans1: " << bilans1 << endl; cout << "Punkty2: " << pkt2 << "  Bilans2: " << bilans2 << endl << endl;



    /* JAK MA WYGLĄDAĆ WYWOŁANIE KLASY?:

    grupa gr1;
    gr1.dr1=druzyna1;
     gr1.dr2=druzyna2;
      gr1.dr3=druzyna3;
       gr1.dr4=druzyna4;
    gr1.pkt1 = punkty1;
     gr1.pkt2 = punkty2;
      gr1.pkt3 = punkty3;
       gr1.pkt4 = punkty4;
    gr1.bil1=bilans1;
     gr1.bil2=bilans2;
      gr1.bil3=bilans3;
       gr1.bil4=bilans4;
    gr1.group="A";
    gr1.tabela();
    */



    return 0;
}
