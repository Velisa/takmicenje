#include<stdio.h>

int 
main() {
	int broj = 0;
	while (broj != 42) {
		scanf("%d", &broj);
		if (broj != 42) 
			printf("%d\n", broj);
	}
	return 0;
}
