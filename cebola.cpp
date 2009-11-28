#include<stdio.h>
#include<iostream>
#include<math.h>

/*
 * Algoritmo para resolver o problema Onion rings da final nacional da maratona de programação 2006.
 *
 * AVISO: O objetivo deste código é resolver o problema. Regras de boa escrito de código são deixadas
 * para segundo plano. Profissionalmente eu não escrevo código assim tão feio! :-)
 */

using namespace std;

long area2(int xa, int ya, int xb, int yb, int xc, int yc) {
	return ( (xa - xc) * (yb - yc) - (ya - yc) * (xb - xc) );
}

int direita(int xa, int ya, int xb, int yb, int xc, int yc) {
	long r = area2(xa, ya, xb, yb, xc, yc);
	if (r < 0) {
		return +1;
	} else if (r == 0) {
		return 0;
	} else {
		return -1;
	}
}

long distSemRaiz(int x1, int y1, int x2, int y2) {
	return pow((pow(x1-x2,2) + pow (y1-y2,2)), 2);
}



int main() {

	int n = 0;

	scanf("%d", &n);

	while (n != 0) {

		int X[n];
		int Y[n];
		int h = 0;
		int H[n];
		int T[n];
		int conta_camadas = 0;

		int indice_maior_x = 0;

		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			X[i] = x;
			Y[i] = y;
			T[i] = 0;
		}

		while (n >= 3) {

			indice_maior_x = 0;
			h = 0;

			for (int i = 0; i < n; i++) {
				if (X[i] > X[indice_maior_x]) {
					indice_maior_x = i;
				}
			}

			H[0] = indice_maior_x;
			int i = 0;

			do {
				i = H[h] + 1;
				if (i >= n) {
					i = 0;
				}
				for (int j = 0; j < n; j++) {
					if (area2(X[H[h]], Y[H[h]], X[i], Y[i], X[j], Y[j]) < 0) {
						i = j;
					}
				}
				h = h + 1;
				H[h] = i;
				T[i] = 1;

			} while (i != H[0]);

			int X1[n-h];
			int Y1[n-h];

			int j = 0;
			for (int i= 0; i < n; i++) {
				if (T[i] == 0) {
					X1[j] = X[i];
					Y1[j] = Y[i];
					j++;
				}
			}
			for (int i = 0; i < n-h; i++) {
				X[i] = X1[i];
				Y[i] = Y1[i];
				H[i] = 0;
				T[i] = 0;
			}

			n = n - h;
			conta_camadas = conta_camadas + 1;

		}

		if (n <= 1 && conta_camadas % 2 != 0) {
			printf("Take this onion to the lab!\n");
		} else {
			printf("Do not take this onion to the lab!\n");
		}

		scanf("%d", &n);
	}

	return 0;
}
