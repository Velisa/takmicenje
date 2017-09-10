/*

Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or
5, we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum 
of all the multiples of 3 or 5 below 1000. 

Answer: 233168 */

#include <stdio.h>

int
main()
{
	int i;
	int N = 1000;
	float suma = 0;
	
	for (i = 1; i < N; ++i)
	{
		if (i%3 == 0 || i%5 == 0)
		{
			suma += i;
		}
	}
	printf("%.0f", suma);
}