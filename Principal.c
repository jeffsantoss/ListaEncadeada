#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Lista.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void inverter_principal(Lista *l) {
	int i;
	for (i=0; i < tamanho(l) / 2 ; i++){
		tmp = ler_pos(l,i);
		escrever_pos(l,i,ler_pos(l,tamanho(l) - i - 1));
		escrever_pos(l,tamanho(l)-i-1, tmp);
	}
	
}

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
