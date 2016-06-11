#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void inverter_principal(Lista *l) {
	int i,tmp;
	
	for (i=0; i < tamanho(l) / 2 ; i++)
	{
		tmp = ler_pos(l,i);
		escrever_pos(l,i,ler_pos(l,tamanho(l) - i - 1));
		escrever_pos(l,tamanho(l)-i-1, tmp);
	}
	
}

int esta_ordem_principal(Lista *l){
	int n_ma = 0, n_me = 0;
	int i;
	if ( tamanho(l) > 2) {
	
	for ( i = 0; i<tamanho(l) - 1 ;i++){
		int x = ler_pos(l,i);
		int y = ler_pos(l,i+1);
		
		if (x < y)
		n_me++;
		if(x > y)
		n_ma++;
		
		if (n_ma > 0 && n_ma > 0)
		return 0;

	}
}
	return 1;	
}

int main(int argc, char *argv[]) {
	Lista * l = criar();
	inserir_ultimo(l, 2);
	imprimir(l);
	inserir_ultimo(l, 5);
	imprimir(l);
	inserir_ultimo(l, 7);
	imprimir(l);
	inserir_ultimo(l, 9);
	imprimir(l);
	inserir_pos(l, 0, 4);
	imprimir(l);
	inserir_primeiro(l, 3);
	imprimir(l);
	inserir_ultimo(l, 8);
	printf("Ordenada: %s", esta_ordem_principal(l)? "Sim":"Nao");
	imprimir(l);
	destruir(l);
	
	system("pause");
}
