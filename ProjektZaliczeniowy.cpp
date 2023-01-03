

#include <iostream>
#include <windows.h>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <conio.h>

using namespace std;

double bramki()
{
    
    int bramki;
    srand(time(NULL));
    Sleep(1000);
    bramki = rand() % 6;
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
    const int size = bramki();

    for (int i = 0; i < size; i++)
    {
        Sleep(100);
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
    else if (gol1 == 0 && gol2 == 0)
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
    int bilans3 = -1;
    int pkt3 = 0;
    string druzyna3 = "Arabia";
    int wag3 = 2;
    string druzyna1 = "Polska";
    string druzyna2 = "Francja";
    cout << "Mecz 1:" << endl;
    mecz(&pkt1, &pkt2, &bilans1, &bilans2, wag1, wag2, druzyna1, druzyna2); cout << "Punkty1: " << pkt1 << "  Bilans1: " << bilans1 << endl; cout << "Punkty2: " << pkt2 << "  Bilans2: " << bilans2 << endl << endl;
    cout << endl << endl << endl;
    mecz(&pkt1, &pkt3, &bilans1, &bilans3, wag1, wag3, druzyna1, druzyna3); cout << "Punkty1: " << pkt1 << "  Bilans1: " << bilans1 << endl; cout << "Punkty3: " << pkt3 << "  Bilans3: " << bilans3 << endl << endl;


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



