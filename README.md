# ProjektZaliczeniowy "Mundial"
zapraszam do pisania
© reszczaks team :)
 
## Opis projektu:

### Symulator Mundialu 2022 to program, który przedstawia symulacje mundialu 2022 wraz z wynikami wszystkich meczy. Program pobiera dane z plików tekstowych gdzie są wypisane wszystkie uczestniczące drużyny w wyżej	wymienionym mundialu oraz szanse na ich zwycięstwo,	biorąc pod uwagę cenę rynkową całej drużyny. Program jest łatwy w obsłudze, wystarczy go włączyć i podążać za instrukcjami wypisywanymi. 

## Jak działa program? 
1. Wczytanie danych z plików tekstowych

- ```c++
  int read_data(string filename, double *grades) {
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
  } else {
  cout << "Nie udalo sie otworzyc pliku." << endl;
  }
  return size;
  }

2. Wyświetlenie drużyn uczestniczących w mundialu

- klasa drużyna:
```c++
class druzyna {
public:
double ocena{};
int punkty{};
int bilans{};
string nazwa;
string JakaGrupa;
int wynik{};


void wypisz() const {
cout << setw(0) << setfill(' ') << nazwa << endl;

}

};

```
- stworzenie obiektów drużyn:
```c++
 for (int i = 0; i < MAX_SIZE; i++) {

        druz[i].ocena = grade[i];
        druz[i].punkty = points[i];
        druz[i].bilans = balance[i];
        druz[i].nazwa = team[i];
        druz[i].JakaGrupa = group[i];
    }
```
3. Rozegranie fazy grupowej z wyświetleniem wyników
- funkcja rozgrywająca mecz:
```c++
void mecz(int *dr1, int *dr2, int *bil1, int *bil2, double waga1, double waga2, string *druzyna1, string *druzyna2) {
    Sleep(500);
    int gol1 = 0;
    int gol2 = 0;
    int gol[6];
    int size = bramki();

    for (int i = 0; i < size; i++) {
        gol[i] = rand() % 101;
        if (gol[i] < szansa(waga1, waga2)) {
            gol1 = gol1 + 1;
            *bil1 = *bil1 + 1;
            *bil2 = *bil2 - 1;
        } else {
            gol2 = gol2 + 1;
            *bil1 = *bil1 - 1;
            *bil2 = *bil2 + 1;
        }
    }
    if (gol1 > gol2) {
        *dr1 = *dr1 + 3;
    } else if (gol2 > gol1) {
        *dr2 = *dr2 + 3;
    } else if (gol1 == gol2) {
        *dr1 = *dr1 + 1;
        *dr2 = *dr2 + 1;
    } else if (gol1 == 0 && gol2 == 0) {
        *dr1 = *dr1 + 1;
        *dr2 = *dr2 + 1;
    }
    string dlugosc1 = *druzyna1;
    string dlugosc2 = *druzyna2;
    cout << *druzyna1 << setw(12 - dlugosc1.size()) << setfill(' ') << gol1 << "   -   " << gol2 << setw(12)
         << setfill(' ') << *druzyna2 << endl;
}
```
- funkcja losująca szanse na bramkę oraz ile bramek padnie:
```c++
int bramki() {

    int bramki;
    bramki = rand() % 6;
    return bramki;
}

double szansa(double waga1, double waga2) {
    double szansa1;
    szansa1 = (waga1 / (waga1 + waga2)) * 100;
    return szansa1;
}
```
- wywołanie funkcji mecz:
```c++
for (int i = 0; i < MAX_SIZE; i++) {
        if (i == 0 || i % 4 == 0) {
            cout << "GRUPA " << group[i] << endl << endl;
            cout << "Kolejka 1: " << endl << endl;
            mecz(&points[i], &points[i + 1], &balance[i], &balance[i + 1], grade[i], grade[i + 1], &team[i],
                 &team[i + 1]);
            mecz(&points[i + 2], &points[i + 3], &balance[i + 2], &balance[i + 3], grade[i + 2], grade[i + 3],
                 &team[i + 2], &team[i + 3]);
            cout << endl << "Kolejka 2: " << endl << endl;
            mecz(&points[i], &points[i + 2], &balance[i], &balance[i + 2], grade[i], grade[i + 2], &team[i],
                 &team[i + 2]);
            mecz(&points[i + 1], &points[i + 3], &balance[i + 1], &balance[i + 3], grade[i + 1], grade[i + 3],
                 &team[i + 1], &team[i + 3]);
            cout << endl << "Kolejka 3: " << endl << endl;
            mecz(&points[i], &points[i + 3], &balance[i], &balance[i + 3], grade[i], grade[i + 3], &team[i],
                 &team[i + 3]);
            mecz(&points[i + 1], &points[i + 2], &balance[i + 1], &balance[i + 2], grade[i + 1], grade[i + 2],
                 &team[i + 1], &team[i + 2]);
            if(i==28){
                cout << endl<<"Nacisnij enter aby wyswietlic tabele grup"<<endl;
                getchar();
            }
            else
            {
                cout <<endl << "Nacisnij enter aby przejsc do kolejnej grupy"<<endl;
                getchar();
            }



        }
    }

```
4. Wyświetlenie tabel grupowych po fazie grupowej 
- klasa grupa wraz z funkcją sortującą oraz wyświetlającą tabelę:
```c++
class grupa {
public:


    druzyna teams[4];

    void sortuj() {

        for (int i = 0; i < 4; i++) {
            for (size_t j = 0; j < 4 - 1; j++) {
                if (teams[j].punkty < teams[j + 1].punkty) {
                    swap(teams[j], teams[j + 1]);

                }
                if (teams[j].punkty == teams[j + 1].punkty) {
                    if (teams[j].bilans < teams[j + 1].bilans) {
                        swap(teams[j], teams[j + 1]);
                    }
                }

            }


        }
    }

    void wypisz2() {

        cout << "GRUPA " << teams[0].JakaGrupa << endl;

Sleep(500);
        for (int i = 0; i < 4; i++) {
            cout << setw(48) << setfill('#') <<" "<< endl;
            cout << "#  "<<teams[i].nazwa << setw(20 - teams[i].nazwa.size()) << setfill(' ') <<"   #   "<< teams[i].punkty <<"   #   "<< setw(10)
                 << setfill(' ') <<"   #   "<< teams[i].bilans <<"   #"<< endl;
            if (i==3) {

                cout << setw(48) << setfill('#') << " " << endl;
            }

        }
        cout << endl;

    }

};
```
- stworzenie obiektów grupy i wywołanie funkcji sortującej i wypisującej:
```c++
const int IloscGrup = 8;
    grupa grupy[IloscGrup];
    int j = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (j == 4) { j = 0; }


        grupy[i / 4].teams[j] = druz[i];

        j++;
    }
    for (int i = 0; i < IloscGrup; i++) {
        grupy[i].sortuj();
        grupy[i].wypisz2();
    }

```
5. Rozegranie fazy pucharowej z wyświetleniem wyników 
- klasa mecz rozgrywająca całą fazę pucharową:
```c++
class meczycho {
public:

    druzyna druzynyPucharowe[2];

    double szansa([[maybe_unused]] double waga1, [[maybe_unused]] double waga2) {
        double szansa1;
        szansa1 = (druzynyPucharowe[0].ocena / (druzynyPucharowe[0].ocena + druzynyPucharowe[0].ocena)) * 100;
        return szansa1;
    }

    string meczpucharowy() {
Sleep(500);
        druzynyPucharowe[0].wynik = 0;
        druzynyPucharowe[1].wynik = 0;


         int gol1 = 0;
         int gol2 = 0;
        int gol[6];
        int size = rand() % 6;
        cout << "MECZ: " << endl;
        for (int i = 0; i < size; i++) {

            gol[i] = rand() % 101;
            if (gol[i] < szansa(druzynyPucharowe[0].ocena, druzynyPucharowe[1].ocena)) {

                druzynyPucharowe[0].wynik = druzynyPucharowe[0].wynik + 1;

            } else {
                druzynyPucharowe[1].wynik = druzynyPucharowe[1].wynik + 1;
            }
        }
        cout << "WYNIK : " << druzynyPucharowe[0].nazwa << "   " << druzynyPucharowe[0].wynik << "  -  "
             << druzynyPucharowe[1].wynik << "   " << druzynyPucharowe[1].nazwa << endl;
        if (druzynyPucharowe[0].wynik > druzynyPucharowe[1].wynik) {
            return "dr1";
        }
        if (druzynyPucharowe[1].wynik > druzynyPucharowe[0].wynik) {
            return "dr2";
        }
        if (druzynyPucharowe[0].wynik == druzynyPucharowe[1].wynik) {
            return "draw";
        }


    }

    string dogrywka() {
        Sleep(500);
        cout << endl;
         int gol1 = 0;
         int gol2 = 0;
        int gol[6];
        int size = rand() % 2;
        for (int i = 0; i < size; i++) {


            gol[i] = rand() % 101;
            if (gol[i] < szansa(druzynyPucharowe[0].ocena, druzynyPucharowe[1].ocena)) {

                druzynyPucharowe[0].wynik = druzynyPucharowe[0].wynik + 1;

            } else {
                druzynyPucharowe[1].wynik = druzynyPucharowe[1].wynik + 1;
            }
        }
        cout << "WYNIK PO DOGRYWCE : " << druzynyPucharowe[0].nazwa << "   " << druzynyPucharowe[0].wynik << "  -  "
             << druzynyPucharowe[1].wynik << "   " << druzynyPucharowe[1].nazwa << endl;
        if (druzynyPucharowe[0].wynik > druzynyPucharowe[1].wynik) {
            return "dr1";
        }
        if (druzynyPucharowe[1].wynik > druzynyPucharowe[0].wynik) {
            return "dr2";
        }
        if (druzynyPucharowe[0].wynik == druzynyPucharowe[1].wynik) {
            return "draw";
        }
    }

    int randomKarne() {
        Sleep(400);
        int czygol = rand() % 2;
        return czygol;
    }

    string karne() {

        int gol1 = 0;
        int gol2 = 0;
        int seria = 1;
        for (int i = 0; i < 5; i++) {
            if (randomKarne() == 1) {
                gol1 = gol1 + 1;

            }
            if (randomKarne() == 1) {
                gol2 = gol2 + 1;

            }
            cout << "Seria " << seria << " : " << gol1 << " - " << gol2 << endl;
            seria++;
            if (i > 2) {
                if (((gol1 == 3) && (gol2 == 0)) || ((gol1 == 0) && (gol2 == 3)) || ((gol1 == 4) && (gol2 == 1)) ||
                    ((gol1 == 1) && (gol2 == 4))) {
                    break;
                }

            }
        }
        while (gol1 == gol2) {
            if (randomKarne() == 1) {
                gol1 = gol1 + 1;

            }
            if (randomKarne() == 1) {
                gol2 = gol2 + 1;

            }
            cout << "Seria " << seria << " : " << gol1 << " - " << gol2 << endl;
            seria++;

        }
        cout << " WYNIK PO KARNYCH: " << druzynyPucharowe[0].nazwa << "  " << druzynyPucharowe[0].wynik << " (" << gol1
             << ")  -  " << druzynyPucharowe[1].wynik << " (" << gol2 << ")  " << druzynyPucharowe[1].nazwa << endl;
        if (gol1 > gol2) {
            return "dr1";
        }
        if (gol2 > gol1) {
            return "dr2";
        }


    }

    string run() {
        string wynikmecz;
        string wynikdogrywka;
        string wynikkarne;

        wynikmecz = meczpucharowy();
        if (wynikmecz == "draw") {
             wynikdogrywka= dogrywka();
            if (wynikdogrywka == "draw") {
                cout << "KARNE:" << endl;
                wynikkarne=karne();
                if (wynikkarne == "dr1") {
                    return "dr1";
                }
                if (wynikkarne == "dr2") {
                    return "dr2";
                }
            }
            if (wynikdogrywka == "dr1") {
                return "dr1";
            }
            if (wynikdogrywka == "dr2") {
                return "dr2";
            }
        }
        if (wynikmecz == "dr1") {
            return "dr1";
        }
        if (wynikmecz == "dr2") {
            return "dr2";
        }

    }

};
```
- definicja drużyn biorących udział w jednej ósmej mundialu
```c++
 meczycho osiem[8];

    osiem[0].druzynyPucharowe[0] = grupy[0].teams[0];
    osiem[0].druzynyPucharowe[1] = grupy[1].teams[1];
    osiem[1].druzynyPucharowe[0] = grupy[0].teams[1];
    osiem[1].druzynyPucharowe[1] = grupy[1].teams[0];
    osiem[2].druzynyPucharowe[0] = grupy[2].teams[0];
    osiem[2].druzynyPucharowe[1] = grupy[3].teams[1];
    osiem[3].druzynyPucharowe[0] = grupy[2].teams[1];
    osiem[3].druzynyPucharowe[1] = grupy[3].teams[0];
    osiem[4].druzynyPucharowe[0] = grupy[4].teams[0];
    osiem[4].druzynyPucharowe[1] = grupy[5].teams[1];
    osiem[5].druzynyPucharowe[0] = grupy[4].teams[1];
    osiem[5].druzynyPucharowe[1] = grupy[5].teams[0];
    osiem[6].druzynyPucharowe[0] = grupy[6].teams[0];
    osiem[6].druzynyPucharowe[1] = grupy[7].teams[1];
    osiem[7].druzynyPucharowe[0] = grupy[6].teams[1];
    osiem[7].druzynyPucharowe[1] = grupy[7].teams[0];

```
- rozgrywanie kolejnych meczów włącznie z finałem
```c++
meczycho cztery[4];
    cout << endl<<"Nacisnij enter aby przejsc do fazy pucharowej"<<endl;
    getchar();
    cout << "JEDNA OSMA: "<< endl<<setw(85) << setfill('#')<<" "<<endl<<endl;
    string wynikJednejOsmej[8];
    j = 0;
    for (int i = 0; i < 8; i++) {
        wynikJednejOsmej[i] = osiem[i].run();
        if (j == 2) {
            j = 0;
        }
        if (wynikJednejOsmej[i] == "dr1") {
            cztery[i / 2].druzynyPucharowe[j] = osiem[i].druzynyPucharowe[0];
        }
        if (wynikJednejOsmej[i] == "dr2") {
            cztery[i / 2].druzynyPucharowe[j] = osiem[i].druzynyPucharowe[1];
        }
        cout << endl;
        j++;

    }cout <<setw(85) << setfill('#')<<" "<< endl;
    cout << endl<<"Aby przejsc do meczow cwiercfinalowych wcisnij enter";
    cout << endl<<endl;
    getchar();
    cout << "CWIERCFINALY:"<< endl<<setw(85) << setfill('#')<<" "<<endl<<endl;
    string wynikJednejCzwartej[4];
    meczycho dwa[2];

    j = 0;
    for (int i = 0; i < 4; i++) {
        wynikJednejCzwartej[i] = cztery[i].run();
        if (j == 2) {
            j = 0;
        }
        if (wynikJednejCzwartej[i] == "dr1") {
            dwa[i / 2].druzynyPucharowe[j] = cztery[i].druzynyPucharowe[0];
        }
        if (wynikJednejCzwartej[i] == "dr2") {
            dwa[i / 2].druzynyPucharowe[j] = cztery[i].druzynyPucharowe[1];
        }
        cout << endl;
        j++;

    }
    cout <<setw(85) << setfill('#')<<" "<< endl;
    cout << endl<<"Aby przejsc do meczow polfinalowych wcisnij enter";
    cout << endl<<endl;
    getchar();
    string wynikJednejDrugiej;
    meczycho jeden;
    meczycho trzeci;
    cout << "POLFINALY: " << endl<<setw(85) << setfill('#')<<" "<<endl<<endl;
    for (int i = 0; i < 2; i++) {
        wynikJednejCzwartej[i] = dwa[i].run();
        if (j == 2) {
            j = 0;
        }
        if (wynikJednejCzwartej[i] == "dr1") {
            jeden.druzynyPucharowe[j] = dwa[i].druzynyPucharowe[0];
            trzeci.druzynyPucharowe[j] = dwa[i].druzynyPucharowe[1];
        }
        if (wynikJednejCzwartej[i] == "dr2") {
            jeden.druzynyPucharowe[j] = dwa[i].druzynyPucharowe[1];
            trzeci.druzynyPucharowe[j] = dwa[i].druzynyPucharowe[0];
        }
        cout << endl;
        j++;

    }
    cout <<setw(85) << setfill('#')<<" "<< endl;
    cout << endl<<"Aby przejsc do meczu o 3 miejsce wcisnij enter";
    cout << endl<<endl;
    getchar();
    cout << "MECZ O TRZECIE MIEJSCE: " << endl<<setw(85) << setfill('#')<<" "<<endl<<endl;
    string wynikTrzecie = trzeci.run();

    if (wynikTrzecie == "dr1") {
        cout << "Trzecie miejsce zdobywa: " << trzeci.druzynyPucharowe[0].nazwa << endl;
    }
    else {
        cout << "Trzecie miejsce zdobywa: " << trzeci.druzynyPucharowe[1].nazwa << endl;
    }
    cout <<setw(85) << setfill('#')<<" "<< endl;
    cout << endl<<"Aby przejsc do finalu wcisnij enter";
    cout << endl<<endl;
    getchar();

    cout << "FINAŁ: " << endl<<setw(85) << setfill('#')<<" "<<endl<<endl;
    string wynikFinalu = jeden.run();
```

6. Wyświetlenie drużyny, która została mistrzem świata
```c++
cout << "Nacisnij enter aby przejsc do ceremonii wręczenia pucharu"<<endl;
    getchar();
    if (wynikFinalu == "dr1") {
        cout << "MUNDIAL ZWYCIEZA: " << endl;
        Sleep(5000);
        for (int i = 0; i < 10000; ++i) {
            cout << jeden.druzynyPucharowe[0].nazwa << " ";
if(i%70==0)cout <<endl;
        }
    }
    else {
        cout << "MUNDIAL ZWYCIEZA: " << endl;
        Sleep(5000);
        for (int i = 0; i < 10000; ++i) {
            cout << jeden.druzynyPucharowe[1].nazwa << " ";
if (i % 70 == 0)cout << endl;

        }
    }

```



## Wykonanie programu
1. Mateusz Polak
- lekka pomoc przy programie
- funkcja wczytująca dane z plików
- sprawozdanie
2. Jakub Cymiński
- oprawa graficzna programu
- obliczanie danych statystycznych i przygotowanie plików
3. Dawid Reszczyński
- program
- sprawozdanie

## Pomysłodawca projektu i założyciel reszczaks team ©
![panda](panda.jpg)
### Dawid Reszczyński

