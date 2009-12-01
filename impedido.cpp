#include<stdio.h>

/*
 * Algoritmo para resolver o problema Impedimento da final nacional da maratona de programação 2007.
 *
 * AVISO: O objetivo deste código é resolver o problema. Regras de boa escrito de código são deixadas
 * para segundo plano. Profissionalmente eu não escrevo código assim tão feio! :-)
 */

int main() {


	int a = 0;
	int d = 0;

	scanf("%d %d", &a, &d);
	while (a != a || d != 0) {

		int dist_atacante_mais_perto = 0x3F3F3F3F;
		int conta_zagueiros = 0;
		int x = 0;
		for (int i = 0; i < a; i++) {
			scanf("%d", &x);
			if (x < dist_atacante_mais_perto) {
				dist_atacante_mais_perto = x;
			}
		}
		for (int i = 0; i < d; i++) {
			scanf("%d", &x);
			if (x <= dist_atacante_mais_perto) {
				conta_zagueiros++;
			}
		}
		if (conta_zagueiros >= 2) {
			printf("N\n");
		} else {
			printf("Y\n");
		}

		scanf("%d %d", &a, &d);
	}

	return 0;
}
