

#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
using namespace std;


//
//int bramki()
//{
//    int bramki;
//    srand(time(NULL));
//    bramki = rand() % 6 + 1;
//    return bramki;
//}
void szansa(int waga1, int waga2, int* szansa1, int* szansa2)
{
    szansa2 = &waga1;
}

int main()
{
    int *szansa1 = 0;
    int *szansa2 = 0;
    int a = 4;
    int b = 6;
    szansa(a, b, szansa1, szansa2);
    cout << szansa2;

}


