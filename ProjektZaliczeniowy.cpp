

#include <iostream>
#include <windows.h>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <conio.h>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const int MAX_SIZE = 32;
class druzyna
{
public:
    double ocena;
    int punkty;
    int bilans;
    string nazwa;
    string JakaGrupa;
    

    void wypisz() 
    {
        cout << setw(0) << setfill(' ') << nazwa << setw(20-nazwa.size()) << setfill(' ') << JakaGrupa << setw(10) << setfill(' ') << ocena << endl;
    }

};


class grupa
{
public:
    

    druzyna teams[4];

    void sortuj()
    {
        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4-1; j++)
            {
                if (teams[j].bilans > teams[j+1].bilans)
                {
                    

                }
            }

        }
    }
    void wypisz2()
    {
        for (int i = 0; i < 4; i++)
        {
            cout << teams[i].nazwa<<endl;
        }
    }

}; 
class turniej
{
public: 


};

int read_data(string filename, double* grades) {
    int size = 0;
    ifstream file(filename);
    if (file.is_open()) {
        int value;
        while (file >> value) {
            if (size < MAX_SIZE) {
                grades[size] = value;
            }
            size++;
        }
        file.close();
    }
    else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
    return size;
}
int read_data2(string filename, string* groups) {
    int size = 0;
    ifstream file(filename);
    if (file.is_open()) {
        string value;
        while (getline(file, value)) {
            if (size < MAX_SIZE) {
                groups[size] = value;
            }
            size++;
        }
        file.close();
    }
    else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
    return size;
}
double bramki()
{

    int bramki;
    srand(time(NULL));
    Sleep(1500);
    bramki = rand() % 6;
    return bramki;
}
double bramkiPuchar()
{

    int bramki;
    srand(time(NULL));
    Sleep(1000);
    bramki = rand() % 2;
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
    int gol[6];
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
int randomKarne()
{
    Sleep(400);
    srand(time(NULL));
    int czygol = rand() % 2;
    return czygol;
}
void karne(int* dr1, int* dr2, int* wynik1, int* wynik2, string druzyna1, string druzyna2)
{
    cout << endl;
    int gol1 = 0;
    int gol2 = 0;
    int seria = 1;
    for (int i = 0; i < 5; i++)
    {
        if (randomKarne() == 1)
        {
            gol1 = gol1 + 1;

        }
        if (randomKarne() == 1)
        {
            gol2 = gol2 + 1;

        }
        cout << "seria " << seria << " : " << gol1 << " - " << gol2 << endl;
        seria++;
        if (i > 2)
        {
            if (((gol1 == 3) && (gol2 == 0)) || ((gol1 == 0) && (gol2 == 3)) || ((gol1 == 4) && (gol2 == 1)) || ((gol1 == 1) && (gol2 == 4)))
            {
                break;
            }

        }
    }
    while ((gol1 == gol2))
    {
        if (randomKarne() == 1)
        {
            gol1 = gol1 + 1;

        }
        if (randomKarne() == 1)
        {
            gol2 = gol2 + 1;

        }
        cout << "seria " << seria << " : " << gol1 << " - " << gol2 << endl;
        seria++;

    }
    if (gol1 > gol2)
    {
        *wynik1 = *wynik1 + 1;
    }
    if (gol2 > gol1)
    {
        *wynik2 = *wynik2 + 1;
    }

    cout << " Wynik: " << druzyna1 << "  " << *dr1 << " (" << gol1 << ")  -  " << *dr2 << " (" << gol2 << ")  " << druzyna2 << endl;
}
void dogrywka(int* dr1, int* dr2, double waga1, double waga2, int* wynik1, int* wynik2, string druzyna1, string druzyna2)
{
    cout << endl;
    int gol1 = 0;
    int gol2 = 0;
    int gol[6];
    const int size = bramkiPuchar();
    for (int i = 0; i < size; i++)
    {
        Sleep(100);
        srand(time(NULL));
        gol[i] = rand() % 101;
        if (gol[i] < szansa1(waga1, waga2))
        {

            *dr1 = *dr1 + 1;

        }
        else
        {
            *dr2 = *dr2 + 1;
        }
    }
    if (*dr1 > *dr2)
    {
        *wynik1 = *wynik1 + 1;
    }
    if (*dr2 > *dr1)
    {
        *wynik2 = *wynik2 + 1;
    }
    cout << "Wynik: " << druzyna1 << "   " << *dr1 << "  -  " << *dr2 << "   " << druzyna2;
}
void puchary(int* dr1, int* dr2, double waga1, double waga2, int* wynik1, int* wynik2, string druzyna1, string druzyna2)
{
    *dr1 = 0;
    *dr2 = 0;
    *wynik1 = 0;
    *wynik2 = 0;
    int gol1 = 0;
    int gol2 = 0;
    int gol[6];
    const int size = bramki();
    cout << "Mecz: " << endl;
    for (int i = 0; i < size; i++)
    {
        Sleep(100);
        srand(time(NULL));
        gol[i] = rand() % 101;
        if (gol[i] < szansa1(waga1, waga2))
        {

            *dr1 = *dr1 + 1;

        }
        else
        {
            *dr2 = *dr2 + 1;
        }
    }
    if (*dr1 > *dr2)
    {
        *wynik1 = *wynik1 + 1;
    }
    if (*dr2 > *dr2)
    {
        *wynik2 = *wynik2 + 1;
    }
    cout << "Wynik: " << druzyna1 << "   " << *dr1 << "  -  " << *dr2 << "   " << druzyna2;
    if (*dr1 == *dr2)
    {
        cout << "Dogrywka:" << endl;
        dogrywka(dr1, dr2, waga1, waga2, wynik1, wynik2, druzyna1, druzyna2);
        if (*dr1 == *dr2)
        {
            cout << "Karne:" << endl;
            karne(dr1, dr2, wynik1, wynik2, druzyna1, druzyna2);
        }

    }
}


int main()
{
    double* grade = new double[MAX_SIZE];
    string* group = new string[MAX_SIZE];
    string* team = new string[MAX_SIZE];

    int size = read_data("chances.txt", grade);
    int size2 = read_data2("groups.txt", group);
    int size3 = read_data2("teams.txt", team);
    
    int* points = new int[MAX_SIZE];
    int* balance = new int[MAX_SIZE];
    
        druzyna druz[32];
        for ( int i = 0;  i < MAX_SIZE; i++)
        {
            
            druz[i].ocena = grade[i];
            druz[i].punkty = points[i];
            druz[i].bilans = balance[i];
            druz[i].nazwa = team[i];
            druz[i].JakaGrupa = group[i];
        }
      /*  for (int i = 0; i < MAX_SIZE; i++)
        {
            druz[i].wypisz();
        }
        */
        
        
        const int IloscGrup = 8;
        grupa grupy[IloscGrup];
       /* for (int i = 0; i < MAX_SIZE; i++)
        {
            for (int j = 0; j < MAX_SIZE; j+4)
            {
                for (int k = 0; k < MAX_SIZE; k+8)
                {
                    if (i==0,j==0,k==0)
                    {
                        grupy[j].teams[k] = druz[i];
                    }
                    else
                    {
                        grupy[j - 3].teams[k - 7] = druz[i];
                    }
                }
            }
        }*/
        int i = 0;
        int j = 0;
        for (int k = 0; k < MAX_SIZE; k++)
        {


            if (j == 8)
            {
                j = 0;

                grupy[i].teams[j] = druz[k];
            }
            if (i == 4)
            {
                i = 0;

                grupy[i].teams[j] = druz[k];
            }
            else
            {
                grupy[i].teams[j] = druz[k];
            }
            i++;
            j++;
        }
       


        grupy[0].wypisz2() ;
        
        
        
        //A[0].w.bilans = 4;
        //metoda klas
        //A[1].w.wypisz();
        
        


























































































//int pkt1 = 0;
//int pkt2 = 0;
//int bilans1 = 0;
//int bilans2 = 0;
//int wag1 = 5;
//int wag2 = 5;
//int bilans3 = -1;
//int pkt3 = 0;
//int wynik1 = 0;
//int wynik2 = 0;
//string druzyna3 = "Arabia";
//int wag3 = 2;
//string druzyna1 = "Polska";
//string druzyna2 = "Francja";
//cout << "Mecz 1:" << endl;
//mecz(&pkt1, &pkt2, &bilans1, &bilans2, wag1, wag2, druzyna1, druzyna2); cout << "Punkty1: " << pkt1 << "  Bilans1: " << bilans1 << endl; cout << "Punkty2: " << pkt2 << "  Bilans2: " << bilans2 << endl << endl;
//cout << endl << endl << endl;
//mecz(&pkt1, &pkt3, &bilans1, &bilans3, wag1, wag3, druzyna1, druzyna3); cout << "Punkty1: " << pkt1 << "  Bilans1: " << bilans1 << endl; cout << "Punkty3: " << pkt3 << "  Bilans3: " << bilans3 << endl << endl;
//
//cout << endl << endl << endl << endl;
//puchary(&pkt1, &pkt2, wag1, wag2, &wynik1, &wynik2, druzyna1, druzyna2);
    return 0;
}



