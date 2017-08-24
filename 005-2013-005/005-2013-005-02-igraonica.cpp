/* igraonica: Imamo N klijenata i K kablova razlicite duzine. Od tih K 
kablova treba isjeci n kablova potpuno iste, ali najvece moguce duzine. 
Ovaj program odredjuje tu duzinu. */

#include <cstdio>
#include <math.h>

using namespace std;

int 
main (void)
{ 
  int i;

  int N; /* Broj klijenata */
  int K; /* Broj kablova */

  int ispravnoN = 0;
  int ispravnoK = 0;
  int ispravnaDuzina = 0;

  int nadjeno;
  int novi_broj; /* Koliko cijelih kablova mozemo napraviti */
  float duzina; /* U ovoj promjenjljivoj je odgovor */
  float kablovi[5000]; /* Ovo je niz duzina kablova */
  float ukpDuzina = 0.0;
  
  printf ("\n= PROGRAM IGRAONICA =");
  printf ("\n*********************");

  while (!ispravnoN) {
    printf ("\n\nUnesi broj klijenata: N = ");
    scanf ("%d", &N);
    if (N > 5000 || N < 0)
      printf ("\nGRESKA: N mora biti 0 < N <= 5000")  ;
    else
      ispravnoN = 1;
  }
  while (!ispravnoK) {
    printf ("\n\nUnesi broj kablova: K = ");
    scanf ("%d", &K);
    if (K > 5000 || K < 0)
      printf ("\nGRESKA: K mora biti 0 < K <= 5000");
    else
      ispravnoK = 1;
  }
  
  for (i = 0; i < K; ++i) {
	ispravnoK = 0;
	while (!ispravnoK) {
		printf ("\n\nUnesi duzinu kabla broj %d: ", i + 1);
		scanf ("%f", &kablovi[i]); /* Mozda zaokruziti na dvije decimale? */
	if (kablovi[i] > 10000.00)
		printf ("\nGRESKA: K mora biti K <= 10000m");
	else
		ispravnoK = 1;
	}
  }
  
  for (i = 0; i < K; i++) {
    ukpDuzina += kablovi[i];
  }
  
  nadjeno = 0;
  duzina = ukpDuzina / K; /* Ovo bi bila ukupna duzina */
  while (!nadjeno) {
    novi_broj = 0;
    for (i = 0; i < K; i++) {
      novi_broj += (int) floor(kablovi[i] / duzina);
    }
    if (novi_broj == N)
      nadjeno = 1;
    else
      /* Veca preciznost je potrebna za neke primjere */
      duzina -= 0.001;
  }
  
  printf ("\nNajveca moguca duzina pojedinacnog kabla je: %.2f", duzina);
  printf ("\n\n= KRAJ PROGRAMA IGRAONICA =");
  printf ("\n***************************\n\n");
  return 0;
}
