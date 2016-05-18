#include <stdio.h>
#include <stdlib.h>


int suma(int *t, int dl, int sum, int in, int prev) /*funkcja rekurencyjna stwierdzajaca, czy istnieje taki ciag o dlugosci dl, ktorego wyrazy sumuja sie do sumy sum i zapisujaca go do tablicy t*/
/*t to tablica zawierajaca kolejne wyrazy ciagu, in to indeks aktualnego wyrazu, a prev to poprzednia wartosc */
/* zwraca 1 jesli udalo sie obliczyc ciag, lub 0, gdy taki ciag nie istnieje */
{
	t[in]=prev; /*zapisanie wyrazu do tablicy*/
	if(in>=dl) return 0; /* jesli indeks wychodzi poza tablice, to nie istnieje taki ciag */
	if(in==dl-1 && sum==0) return 1; /* dlugosc ciagu jest rowna danej dlugosci i suma wyrazow rowna danej sumie, wtedy taki ciag juz jest obliczony w t */
	/* rekurencyjnie wywolujemy funkcje dla nastepnego indeksu i wartosci o jeden wiekszej lub o jeden mniejszej od aktualnego wyrazu ciagu */
	return (suma(t, dl, sum-(t[in]+1), in+1, t[in]+1) || suma(t, dl, sum-(t[in]-1), in+1, t[in]-1));
}


int main(void)
{
	int dl, sum; /*dlugosc ciagu i suma wyrazow ciagu */
	scanf("%d %d", &dl, &sum); /* wczytanie danych */
	int *t; /* tablica na kolejne wyrazy ciagu */
	t=(int*)calloc(dl, sizeof(int)); /*zaalokowanie tablicy */
	if(suma(t, dl, sum, 0, 0)==1) /*jesli ciag o podanych kryteriach istnieje, to wypisujemy go */
	{
		int i;
		for(i=0; i<dl; i++)
			printf("%d\t", t[i]);
		printf("\n");
	}
	else printf("Ciag o podanych kryteriach nie istnieje.\n"); /*w przeciwnym razie wypsisujemy, ze nie istnieje taki ciag*/
	
	return 0;
}

