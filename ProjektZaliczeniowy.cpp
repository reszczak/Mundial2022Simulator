

#include <iostream>
#include <windows.h>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <conio.h>
#include <fstream>
#include <string>

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
        cout << nazwa << "       " <<JakaGrupa << "       " << ocena;
    }

};


class grupa
{
public:
    druzyna x;
    druzyna y;
    druzyna z;
    druzyna w;

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
    
    
    
   
    //Grupa A
    druzyna holandia;
        holandia.ocena = grade[0];
        holandia.punkty = points[0];
        holandia.bilans = balance[0];
        holandia.nazwa = team[0];
        holandia.JakaGrupa = group[0];
    druzyna senegal;
        senegal.ocena = grade[1];
        senegal.punkty = points[1];
        senegal.bilans = balance[1];
        senegal.nazwa = team[1];
        senegal.JakaGrupa = group[1];
    druzyna ekwador;
        ekwador.ocena = grade[2];
        ekwador.punkty = points[2];
        ekwador.bilans = balance[2];
        ekwador.nazwa = team[2];
        ekwador.JakaGrupa = group[2];
    druzyna katar;
        katar.ocena = grade[3];
        katar.punkty = points[3];
        katar.bilans = balance[3];
        katar.nazwa = team[3];
        katar.JakaGrupa = group[3];
    //Grupa B
    druzyna anglia;
        anglia.ocena = grade[4];
        anglia.punkty = points[4];
        anglia.bilans = balance[4];
        anglia.nazwa = team[4];
        anglia.JakaGrupa = group[4];
    druzyna usa;
        usa.ocena = grade[5];
        usa.punkty = points[5];
        usa.bilans = balance[5];
        usa.nazwa = team[5];
        usa.JakaGrupa = group[5];
    druzyna iran;
        iran.ocena = grade[6];
        iran.punkty = points[6];
        iran.bilans = balance[6];
        iran.nazwa = team[6];
        iran.JakaGrupa = group[6];
    druzyna walia;
        walia.ocena = grade[7];
        walia.punkty = points[7];
        walia.bilans = balance[7];
        walia.nazwa = team[7];
        walia.JakaGrupa = group[7];
        //grupaC
    druzyna argentyna;
        argentyna.ocena = grade[8];
        argentyna.punkty = points[8];
        argentyna.bilans = balance[8];
        argentyna.nazwa = team[8];
        argentyna.JakaGrupa = group[8];
    druzyna polska;
        polska.ocena = grade[9];
        polska.punkty = points[9];
        polska.bilans = balance[9];
        polska.nazwa = team[9];
        polska.JakaGrupa = group[9];
    druzyna meksyk;
        meksyk.ocena = grade[10];
        meksyk.punkty = points[10];
        meksyk.bilans = balance[10];
        meksyk.nazwa = team[10];
        meksyk.JakaGrupa = group[10];
    druzyna arabia;
        arabia.ocena = grade[11];
        arabia.punkty = points[11];
        arabia.bilans = balance[11];
        arabia.nazwa = team[11];
        arabia.JakaGrupa = group[11];
        //grupaD
    druzyna francja;
        francja.ocena = grade[12];
        francja.punkty = points[12];
        francja.bilans = balance[12];
        francja.nazwa = team[12];
        francja.JakaGrupa = group[12];
    druzyna australia;
        australia.ocena = grade[13];
        australia.punkty = points[13];
        australia.bilans = balance[13];
        australia.nazwa = team[13];
        australia.JakaGrupa = group[13];
    druzyna tunezja;
        tunezja.ocena = grade[14];
        tunezja.punkty = points[14];
        tunezja.bilans = balance[14];
        tunezja.nazwa = team[14];
        tunezja.JakaGrupa = group[14];
    druzyna dania;
        dania.ocena = grade[15];
        dania.punkty = points[15];
        dania.bilans = balance[15];
        dania.nazwa = team[15];
        dania.JakaGrupa = group[15];
        //grupaE
    druzyna japonia;
        japonia.ocena = grade[16];
        japonia.punkty = points[16];
        japonia.bilans = balance[16];
        japonia.nazwa = team[16];
        japonia.JakaGrupa = group[16];
    druzyna hiszpania;
        hiszpania.ocena = grade[17];
        hiszpania.punkty = points[17];
        hiszpania.bilans = balance[17];
        hiszpania.nazwa = team[17];
        hiszpania.JakaGrupa = group[17];
    druzyna niemcy;
        niemcy.ocena = grade[18];
        niemcy.punkty = points[18];
        niemcy.bilans = balance[18];
        niemcy.nazwa = team[18];
        niemcy.JakaGrupa = group[18];
    druzyna kostaryka;
        kostaryka.ocena = grade[19];
        kostaryka.punkty = points[19];
        kostaryka.bilans = balance[19];
        kostaryka.nazwa = team[19];
        kostaryka.JakaGrupa = group[19];
        //grupaF
    druzyna maroko;
        maroko.ocena = grade[20];
        maroko.punkty = points[20];
        maroko.bilans = balance[20];
        maroko.nazwa = team[20];
        maroko.JakaGrupa = group[20];
    druzyna chorwacja;
        chorwacja.ocena = grade[21];
        chorwacja.punkty = points[21];
        chorwacja.bilans = balance[21];
        chorwacja.nazwa = team[21];
        chorwacja.JakaGrupa = group[21];
    druzyna belgia;
        belgia.ocena = grade[22];
        belgia.punkty = points[22];
        belgia.bilans = balance[22];
        belgia.nazwa = team[22];
        belgia.JakaGrupa = group[22];
    druzyna kanada;
        kanada.ocena = grade[23];
        kanada.punkty = points[23];
        kanada.bilans = balance[23];
        kanada.nazwa = team[23];
        kanada.JakaGrupa = group[23];
        //grupaG
    druzyna brazylia;
        brazylia.ocena = grade[24];
        brazylia.punkty = points[24];
        brazylia.bilans = balance[24];
        brazylia.nazwa = team[24];
        brazylia.JakaGrupa = group[24];
    druzyna szwajcaria;
        szwajcaria.ocena = grade[25];
        szwajcaria.punkty = points[25];
        szwajcaria.bilans = balance[25];
        szwajcaria.nazwa = team[25];
        szwajcaria.JakaGrupa = group[25];
    druzyna kamerun;
        kamerun.ocena = grade[26];
        kamerun.punkty = points[26];
        kamerun.bilans = balance[26];
        kamerun.nazwa = team[26];
        kamerun.JakaGrupa = group[26];
    druzyna serbia;
        serbia.ocena = grade[27];
        serbia.punkty = points[27];
        serbia.bilans = balance[27];
        serbia.nazwa = team[27];
        serbia.JakaGrupa = group[27];
        //grupaH
    druzyna portugalia;
        portugalia.ocena = grade[28];
        portugalia.punkty = points[28];
        portugalia.bilans = balance[28];
        portugalia.nazwa = team[28];
        portugalia.JakaGrupa = group[28];
    druzyna korea;
        korea.ocena = grade[29];
        korea.punkty = points[29];
        korea.bilans = balance[29];
        korea.nazwa = team[29];
        korea.JakaGrupa = group[29];
    druzyna urugwaj;
        urugwaj.ocena = grade[30];
        urugwaj.punkty = points[30];
        urugwaj.bilans = balance[30];
        urugwaj.nazwa = team[30];
        urugwaj.JakaGrupa = group[30];
    druzyna ghana;
        ghana.ocena = grade[31];
        ghana.punkty = points[31];
        ghana.bilans = balance[31];
        ghana.nazwa = team[31];
        ghana.JakaGrupa = group[31];




        //grupa A[8];
        //A[0].w.bilans = 4;
        //metoda klas
        //A[1].w.wypisz();
        
        francja.wypisz();


























































































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



