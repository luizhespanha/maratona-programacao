#include<stdio.h>

/*
 * Algoritmo para resolver o problema Feynman da final nacional da maratona de programação 2008.
 *
 * AVISO: O objetivo deste código é resolver o problema. Regras de boa escrito de código são deixadas
 * para segundo plano. Profissionalmente eu não escrevo código assim tão feio! :-)
 */

int main() {

	long a[101];

	a[0] = 0;
	for (int i = 1; i <= 100; i++) {
		a[i] = a[i-1] + (i * i);
	}

	int n = 0;

	scanf("%d", &n);
	while (n != 0) {
		printf("%ld\n", a[n]);
		scanf("%d", &n);
	}

	return 0;
}
