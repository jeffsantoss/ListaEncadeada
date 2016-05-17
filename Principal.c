#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Lista.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Lista * l = criar();
	inserir_ultimo(l, 2);
	imprimir(l);
	inserir_ultimo(l, 5);
	system("pause");
	imprimir(l);
	inserir_ultimo(l, 7);
	imprimir(l);
	inserir_ultimo(l, 9);
	imprimir(l);
	inserir_pos(l, 2, 4);
	imprimir(l);
	inserir_primeiro(l, 3);
	imprimir(l);
	inserir_ultimo(l, 8);
	imprimir(l);
	destruir(l);
	system("pause");
}