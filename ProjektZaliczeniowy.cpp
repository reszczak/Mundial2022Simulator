

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
        cout << setw(0) << setfill(' ') << nazwa << setw(20 - nazwa.size()) << setfill(' ') << punkty << setw(10) << setfill(' ') << bilans << endl;

    }

};


class grupa:public druzyna
{
public:


    druzyna teams[4];

    void sortuj()
    {

        for (int i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4 - 1; j++)
            {
                if (teams[j].punkty < teams[j + 1].punkty)
                {
                    swap(teams[j], teams[j + 1]);

                }
                if (teams[j].punkty == teams[j + 1].punkty)
                {
                    if (teams[j].bilans < teams[j + 1].bilans)
                    {
                        swap(teams[j], teams[j + 1]);
                    }
                }

            }


        }
    }
    void wypisz2()
    {
cout << "Grupa "<< teams[0].JakaGrupa<<endl;
        for (int i = 0; i < 4; i++)
        {
            cout << teams[i].nazwa << setw(20 - teams[i].nazwa.size()) << setfill(' ') << teams[i].punkty << setw(10) << setfill(' ') << teams[i].bilans << endl;

        }

    }

};

class meczycho
{
public:

    double szansa(double waga1, double waga2)
    {
        double szansa1;
        szansa1 = (waga1 / (waga1 + waga2)) * 100;
        return szansa1;
    }
    void meczpucharowy(int* dr1, int* dr2, double waga1, double waga2, int* wynik1, int* wynik2, string druzyna1, string druzyna2)
    {
        *dr1 = 0;
        *dr2 = 0;
        *wynik1 = 0;
        *wynik2 = 0;
        int gol1 = 0;
        int gol2 = 0;
        int gol[6];
        int size = rand()%6;
        cout << "Mecz: " << endl;
        for (int i = 0; i < size; i++)
        {
            Sleep(100);
            srand(time(NULL));
            gol[i] = rand() % 101;
            if (gol[i] < szansa(waga1, waga2))
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

    }
    void dogrywka(int* dr1, int* dr2, double waga1, double waga2, int* wynik1, int* wynik2, string druzyna1, string druzyna2)
    {
        cout << endl;
        int gol1 = 0;
        int gol2 = 0;
        int gol[6];
        int size = rand()%2;
        for (int i = 0; i < size; i++)
        {
            Sleep(100);
            srand(time(NULL));
            gol[i] = rand() % 101;
            if (gol[i] < szansa(waga1, waga2))
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
    int randomKarne() {
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

};
class Osemka:public druzyna
{
public:
int wynik;
druzyna druzynyPucharowe[2];


};
class Czworka
{
public:

};
class Dwojka
{
public:

};
class run
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
int bramki()
{

    int bramki;
    srand(time(NULL));
    Sleep(2000);
    bramki = rand() % 6;
    return bramki;
}
double szansa(double waga1, double waga2)
{
    double szansa1;
    szansa1 = (waga1 / (waga1 + waga2)) * 100;
    return szansa1;
}


void mecz(int* dr1, int* dr2, int* bil1, int* bil2, double waga1, double waga2, string* druzyna1, string* druzyna2)
{
    int gol1 = 0;
    int gol2 = 0;
    int gol[6];
    int size = bramki();

    for (int i = 0; i < size; i++)
    {
        Sleep(500);
        srand(time(NULL));
        gol[i] = rand() % 101;
        if (gol[i] < szansa(waga1, waga2))
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
    string dlugosc1 = *druzyna1;
    string dlugosc2 = *druzyna2;
    cout << *druzyna1 << setw(12 - dlugosc1.size()) << setfill(' ') << gol1 << "   -   " << gol2 << setw(12) << setfill(' ') << *druzyna2 << endl;
}
int randomKarne()
{
    Sleep(400);
    srand(time(NULL));
    int czygol = rand() % 2;
    return czygol;
}
/*void karne(int* dr1, int* dr2, int* wynik1, int* wynik2, string druzyna1, string druzyna2)
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
}*/
/*void dogrywka(int* dr1, int* dr2, double waga1, double waga2, int* wynik1, int* wynik2, string druzyna1, string druzyna2)
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
        if (gol[i] < szansa(waga1, waga2))
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
}*/
/*void puchary(int* dr1, int* dr2, double waga1, double waga2, int* wynik1, int* wynik2, string druzyna1, string druzyna2)
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
        if (gol[i] < szansa(waga1, waga2))
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
}*/


int main()
{
    double grade[MAX_SIZE];
    string* group = new string[MAX_SIZE];
    string* team = new string[MAX_SIZE];

    int size = read_data("chances.txt", grade);
    int size2 = read_data2("groups.txt", group);
    int size3 = read_data2("teams.txt", team);

    int* points = new int[MAX_SIZE];
    int* balance = new int[MAX_SIZE];
    //Definicja Points i Balance
    for (int i = 0; i < MAX_SIZE; i++)
    {
        points[i] = 0;
        balance[i] = 0;
    }

    //Faza GRUPOWA





    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (i == 0 || i % 4 == 0)
        {
            cout << "GRUPA " << group[i] << endl << endl;
            cout << "Kolejka 1: " << endl << endl;
            mecz(&points[i], &points[i + 1], &balance[i], &balance[i + 1], grade[i], grade[i + 1], &team[i], &team[i + 1]);
            mecz(&points[i + 2], &points[i + 3], &balance[i + 2], &balance[i + 3], grade[i + 2], grade[i + 3], &team[i + 2], &team[i + 3]);
            cout << endl << "Kolejka 2: " << endl << endl;
            mecz(&points[i], &points[i + 2], &balance[i], &balance[i + 2], grade[i], grade[i + 2], &team[i], &team[i + 2]);
            mecz(&points[i + 1], &points[i + 3], &balance[i + 1], &balance[i + 3], grade[i + 1], grade[i + 3], &team[i + 1], &team[i + 3]);
            cout << endl << "Kolejka 3: " << endl << endl;
            mecz(&points[i], &points[i + 3], &balance[i], &balance[i + 3], grade[i], grade[i + 3], &team[i], &team[i + 3]);
            mecz(&points[i + 1], &points[i + 2], &balance[i + 1], &balance[i + 2], grade[i + 1], grade[i + 2], &team[i + 1], &team[i + 2]);
            cout << endl;
        }
    }
    druzyna druz[32];
    for (int i = 0; i < MAX_SIZE; i++)
    {

        druz[i].ocena = grade[i];
        druz[i].punkty = points[i];
        druz[i].bilans = balance[i];
        druz[i].nazwa = team[i];
        druz[i].JakaGrupa = group[i];
    }
    for (int i = 0; i < MAX_SIZE; i++)
    {
        druz[i].wypisz();
    }
    cout << endl << endl << endl << endl;


    const int IloscGrup = 8;
    grupa grupy[IloscGrup];
//WCZYTYWANIE DO GRUP
int j =0;
     for (int i = 0; i < MAX_SIZE; i++)
     {
         if (j==4)
         {j=0;}


             grupy[i / 4].teams[j] = druz[i];

        j++;
     }
      for (int i = 0; i < IloscGrup; i++)
      {
          grupy[i].sortuj();
          grupy[i].wypisz2();
      }
      const int mecze16=8;

      Osemka osiem[mecze16];
    for (int i = 0; i < MAX_SIZE; ++i)
    {

        osiem[i].druzynyPucharowe[i]= grupy[i].teams[i];

    }



    return 0;
}



