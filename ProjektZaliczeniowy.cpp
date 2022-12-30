

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
    int pkt1, pkt2, pkt3, pkt4;
    int bil1, bil2, bil3, bil4;
    string group;
    void druzyna1() 
    {
        cout << dr1 << " " << pkt1 << " " << bil1 << endl;;
    }
    void druzyna2()
    {
        cout << dr2 << " " << pkt2 << " " << bil2 << endl;;
    }
    void druzyna3()
    {
        cout << dr3 << " " << pkt3 << " " << bil3 << endl;;
    }
    void druzyna4()
    {
        cout << dr4 << " " << pkt4 << " " << bil4 << endl;;
    }
    
    void tabela() 
    {
        if (pkt1>pkt2>pkt3>pkt4)
        {
            druzyna1();
            druzyna2();
            druzyna3();
            druzyna4();
           
        }
        if (pkt1 > pkt2 > pkt4 > pkt3)
        {
            druzyna1();
            druzyna2();
            druzyna4();
            druzyna3();

        }
        if (pkt1 > pkt3 > pkt2 > pkt4)
        {
            druzyna1();
            druzyna3();
            druzyna2();
            druzyna4();

        }
        if (pkt1 > pkt3 > pkt4 > pkt2)
        {
            druzyna1();
            druzyna3();
            druzyna4();
            druzyna2();

        }
        if (pkt1 > pkt4 > pkt3 > pkt2)
        {
            druzyna1();
            druzyna4();
            druzyna3();
            druzyna2();

        }
        if (pkt1 > pkt4 > pkt2 > pkt3)
        {
            druzyna1();
            druzyna4();
            druzyna2();
            druzyna3();

        }
        if (pkt2 > pkt1 > pkt3 > pkt4)
        {
            druzyna2();
            druzyna1();
            druzyna3();
            druzyna4();

        }
        if (pkt2 > pkt1 > pkt4 > pkt3)
        {
            druzyna2();
            druzyna1();
            druzyna4();
            druzyna3();

        }
        if (pkt2 > pkt3 > pkt1 > pkt4)
        {
            druzyna2();
            druzyna3();
            druzyna1();
            druzyna4();

        }
        if (pkt2 > pkt3 > pkt4 > pkt1)
        {
            druzyna2();
            druzyna3();
            druzyna4();
            druzyna1();

        }
        if (pkt2 > pkt4 > pkt3 > pkt1)
        {
            druzyna2();
            druzyna4();
            druzyna3();
            druzyna1();

        }
        if (pkt2 > pkt4 > pkt1 > pkt3)
        {
            druzyna2();
            druzyna4();
            druzyna1();
            druzyna3();

        }
        if (pkt3 > pkt1 > pkt2 > pkt4)
        {
            druzyna3();
            druzyna1();
            druzyna2();
            druzyna4();

        }
        if (pkt3 > pkt1 > pkt4 > pkt2)
        {
            druzyna3();
            druzyna1();
            druzyna4();
            druzyna2();

        }
        if (pkt3 > pkt2 > pkt1 > pkt4)
        {
            druzyna3();
            druzyna2();
            druzyna1();
            druzyna4();

        }
        if (pkt3 > pkt2 > pkt4 > pkt1)
        {
            druzyna3();
            druzyna2();
            druzyna4();
            druzyna1();

        }
        if (pkt3 > pkt4 > pkt2 > pkt1)
        {
            druzyna3();
            druzyna4();
            druzyna2();
            druzyna1();

        }
        if (pkt3 > pkt4 > pkt1 > pkt2)
        {
            druzyna3();
            druzyna4();
            druzyna1();
            druzyna2();

        }
        if (pkt4 > pkt1 > pkt2 > pkt3)
        {
            druzyna4();
            druzyna1();
            druzyna2();
            druzyna3();

        }
        if (pkt4 > pkt1 > pkt3 > pkt2)
        {
            druzyna4();
            druzyna1();
            druzyna3();
            druzyna2();

        }
        if (pkt4 > pkt2 > pkt1 > pkt3)
        {
            druzyna4();
            druzyna2();
            druzyna1();
            druzyna3();

        }
        if (pkt4 > pkt2 > pkt3 > pkt1)
        {
            druzyna4();
            druzyna2();
            druzyna3();
            druzyna1();

        }
        if (pkt4 > pkt3 > pkt2 > pkt1)
        {
            druzyna4();
            druzyna3();
            druzyna2();
            druzyna1();

        }
        if (pkt4 > pkt3 > pkt1 > pkt2)
        {
            druzyna4();
            druzyna3();
            druzyna1();
            druzyna2();

        }
    
    }


};
//
//int bramki()
//{
//    int bramki;
//    srand(time(NULL));
//    bramki = rand() % 6 + 1;
//    return bramki;
//}
double szansa1(int waga1,int waga2)
{
   double szansa1;
    szansa1 = (waga1 / (waga1 + waga2))*100;
   return szansa1;
}
double szansa2(int waga1,int waga2)
{
    double szansa2;
    szansa2 = (waga2/(waga1 + waga2))*100;
    return szansa2;
}
//int mecz1(int dr1, int dr2) 
//{
//    int dr1p, dr2p, dr1m, dr2m;
//
//}

int main()
{
    int a = 4;
    int b = 6;
    cout << "szansa pierwszego zespolu to: " << szansa1(a, b) << "%" << endl;
    cout << "szansa drugiego zespolu to: " << szansa2(a, b) << "%"<<endl;
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
}


