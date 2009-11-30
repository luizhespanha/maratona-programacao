#include<stdio.h>

/*
 * Algoritmo para resolver o problema Loteria de Final de semana da final nacional da maratona de programação 2006.
 *
 * AVISO: O objetivo deste código é resolver o problema. Regras de boa escrito de código são deixadas
 * para segundo plano. Profissionalmente eu não escrevo código assim tão feio! :-)
 */

int main() {

	int n, c , k;

	scanf("%d %d %d", &n, &c, &k);

	while (n != 0 || c != 0 || k != 0) {

		int numeros[k+1];

		for (int i = 1; i <= k; i++) {
			numeros[i] = 0;
		}

		int x = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < c; j++) {
				scanf("%d", &x);
				numeros[x]++;

			}
		}

		int min = 0x3F3F3F3F;
		for (int i = 1; i <= k; i++) {
			if (numeros[i] < min) {
				min = numeros[i];
			}
		}
		for (int i = 1; i <= k; i++) {
			if (numeros[i] == min) {
				printf("%d ", i);
			}
		}
		printf("\n");

		scanf("%d %d %d", &n, &c, &k);
	}

	return 0;
}
