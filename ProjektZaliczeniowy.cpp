

#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
using namespace std;



int bramki()
{
    int bramki;
    srand(time(NULL));
    bramki = rand() % 6 + 1;
    return bramki;
}
double szansa1(double waga1,double waga2)
{
   double szansa1;
    szansa1 = (waga1 / (waga1 + waga2))*100;
   return szansa1;
}
double szansa2(double waga1,double waga2)
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
    double a = 4;
    double b = 6;
    cout << "szansa pierwszego zespolu to: " << szansa1(a ,b) << "%" << endl;
    cout << "szansa drugiego zespolu to: " << szansa2(a, b) << "%"<<endl;

}


