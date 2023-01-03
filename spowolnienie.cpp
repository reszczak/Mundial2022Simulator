#include <iostream>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <conio.h>
#include "spowolnienie.hpp"
using namespace std;

void spowolnienie() 
{
    srand(time(NULL));
	int tab[10000];
		for (int i = 0; i < 10000; i++)
		{
			tab[i] = rand() % 1500;
		}
        for (int i = 0; i <10000; i++)
        {
            for (int j = 0; j < 10000 - 1; j++)
            {
                if (tab[j] > tab[j + 1])
                    swap(tab[j], tab[j + 1]);

            }
        }
}