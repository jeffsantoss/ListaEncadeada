#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct no No;

struct lista {
	int tam;
	No * ini, *fim;
};

struct no {
	int info;
	No * prox;
};

Lista * criar() {
	Lista * l = (Lista *)malloc(sizeof(Lista));
	l->ini = NULL;
	l->fim = NULL;
	l->tam = 0;
	return l;
}

void destruir(Lista * l) {
	if (l != NULL) {
		limpar(l);
		free(l);
	}
}

void limpar(Lista * l) {
	No * aux = l->ini;
/*
Percorre toda a lista , enquanto o meu ponteiro não fica NULO. ou seja:
Vai ser criado um outro nó (aux2) pra apontar pro aux
aux vai apontar pro próximo e por fim,
o aux2 que é o nó a qual contém o aux preciso limpar ele.
*/

	while (aux != NULL) {  
		No * aux2 = aux;
		aux = aux->prox;
		free(aux2);
	}
/*
Quando não estiver mais nada, preciso dizer que meu ini e fim são iguais a NULO e o tamanho = 0;
*/
	
	l->ini = NULL;
	l->fim = NULL;
	l->tam = 0;
}

void imprimir(Lista * l) {
	
	/*
	Crio um nó auxiliar pra apontar ao início.
	enquanto o meu aux não fica nulo eu vou imprimindo as minhas informações.
	dou um printf com a info do nó.
	aponto ao próximo nó para pegar o outro valor.
	*/
	
	No * aux = l->ini;
	printf("[ ");
	while (aux != NULL) {
		printf("%d ", aux->info);
		aux = aux->prox;
	}
	printf("]\n");
}

int tamanho(Lista * l) {
	
	/*
	 retorno o tamanho da minha lista
	 o Tam vai está contido na minha struct Lista.
	*/
	
	return l->tam;
}

int esta_vazia(Lista * l) {
	return tamanho(l) == 0;
}

int ler_pos(Lista * l, int p) {
	
	/*
	Ao receber a minha posição lógica "p"
	Crio um aux apontando para o inico da lista e verificar se essa posição é inexistente. Ou seja, se é menor do que 0 ou maior do o tamanho da lista.
	Faço um loop pra percorrer até a posição que passei e vou apontando ao próximo Nó.
	Quando eu chegar no nó da minha posição eu retorno a informação desse nó.
	*/
	
	int i;
	No * aux = l->ini;
	if (p < 0 || p >= tamanho(l)) {
		printf("Posicao invalida!\n");
		return -1;
	}
	for (i = 0; i<p; i++) {
		aux = aux->prox;
	}
	return aux->info;
}

int primeiro(Lista * l) {
	return ler_pos(l, 0);
}

int ultimo(Lista * l) {
	return ler_pos(l, tamanho(l) - 1);
}

int buscar(Lista * l, int v) {
	
	/*
		for (i=0; i<tamanho(l); i++) {
		if (ler_pos(l,i) == v) {
		return i;
		}
		}
	*/
	
	/*
		Faço um aux apontando para o Início como vária das outras operações.
		Um loop enquanto não chega no fim ou seja, o ponteiro fica NULO e enquanto não acho a informação.
		Enquanto isso não acontecer eu fico apontando ao próximo nó e incremento o "p" 
		Se achar o valor retorna a posição " p " , se não achar e o aux for NULO vai retornar falso, ou seja -1.
	*/
	No * aux = l->ini;
	int p = 0;	
	while (aux != NULL && aux->info != v) {
		aux = aux->prox;
		p++;
	}
	
	/* Syntax Operador Ternário : Condição ? verdadeiro : falso */
	return aux != NULL ? p : -1;
}

void escrever_pos(Lista * l, int p, int v) {
	/*
	Recebo a minha posição e verifico se ele é menor ou maior que minha lista.
	depois um loop apontando pra cada próximo nó e quando eu chegar na posição eu vou retornar a informação daquele nó.
	*/
	int i;
	No * aux = l->ini;
	if (p < 0 || p >= tamanho(l)) {
		printf("Posicao invalida!\n");
		return;
	}
	for (i = 0; i<p; i++) {
		aux = aux->prox;
	}
	aux->info = v;
}

void inserir_pos(Lista * l, int p, int v) {
	
	/* Crio um aux apontando pro Inicio e um Aux2 pra guardar o meu parâmetro recebido "v" e verifico se minha posição é maior ou menor que a lista.
	Ao criar um Aux2 preciso guardar a minha info e dizer que o próximo é NULO.
	Na ListaEncadeada é complicado a situação pois preciso saber se meu p está no inicio, entre a lista ou no final e para isso preciso fazer algumas condições.
	se estiver ENTRE a lista eu percorro até a minha posição (p) - 1 e fico apontando ao próximo do aux a cada laço, quando chegar lá aponto o meu aux2 próximo 
	pro meu aux->prox e digo meu aux->prox vai ser igual ao aux2 , vou tipo "Adicionar" meu aux2 na lista e fazer meus ponteiros apontarem pra ele.
	
	se estiver no ÍNICIO da lista ou seja: p = 0, eu vou apontar o prox do meu AUX2 ao inicio da lista e depois digo que meu INICIO eh igual ao aux2.
	
	se estiver no FIM da lista, ou seja p = tamanho, verifico se a posição tá no FIM da lista, então l->fim = aux2 e se o fim for apenas um espaço vazio que não
	seja nulo, digo que o próximo ao l->fim é = aux2;
	
	no final incremeto o tamanho.
	
	*/
	
	int i;
	No * aux = l->ini, *aux2;
	if (p < 0 || p > tamanho(l)) {
		printf("Posicao invalida!\n");
		return;
	}

	aux2 = (No *)malloc(sizeof(No));
	aux2->info = v;
	aux2->prox = NULL;

	if (p > 0 && p < l->tam) {
		for (i = 0; i<p - 1; i++) {
			aux = aux->prox;
		}
		aux2->prox = aux->prox;
			aux->prox = aux2;
	}
	else {
		if (p == 0) {
			aux2->prox = aux; // ou l->ini;
			l->ini = aux2;
		}
		if (p == l->tam) {
			if (l->fim != NULL) {
				l->fim->prox = aux2;
			}
			l->fim = aux2;
		}
	}
	l->tam++;
}

void inserir_primeiro(Lista * l, int v) {
	/*
	Crio um aux pra guardar meus valores.
	o proximo do aux vai apontar pro inicio
	inicio vai ser meu aux.
	*/
	No *aux = (No*)malloc(sizeof(No));
	aux->info = v;
	aux->prox = NULL;
	
	aux->prox = l->ini;
	l->ini = aux;

	//inserir_pos(l, 0, v);
}

void inserir_ultimo(Lista * l, int v) {
	
	/*
	aux pra guardar as minhas informações
	verificar se a minha lista não tem nada.
	coloco meu aux lá no inicio direcionando os ponteiros.
	*/
	
	No *aux;
	aux = (No *)malloc(sizeof(No));
	aux->info = v;
	aux->prox = NULL;
	
	if(l->tam == 0) 
	{
		aux->prox = l->ini; // ou l->ini;
		l->ini = aux;
	}
	
	if(l->fim != NULL) {
		l->fim->prox = aux;
	}

	l->fim = aux;

	l->tam++;
	
	//inserir_pos(l, tamanho(l), v);
}

int remover_pos(Lista * l, int p) {
	int i, v;
	No * aux = l->ini, *aux2;
	if (p < 0 || p >= tamanho(l)) {
		printf("Posicao invalida!\n");
		return -1;
	}
	if (p > 0) {
		for (i = 0; i<p - 1; i++) {
			aux = aux->prox;
		}
		aux2 = aux->prox;
		aux->prox = aux2->prox;
	}
	else {
		aux = NULL;
		aux2 = l->ini;
		l->ini = aux2->prox;
	}
	if (p == l->tam - 1) {
		l->fim = aux;
	}
	v = aux2->info;
	free(aux2);
	l->tam--;
	return v;
}

int remover_primeiro(Lista * l) {
	int v;
    No *aux;
	if(l->tam ==0) {
		printf("Lista Vazia!");
		return -1;
	}
	aux = l->ini;
	l->ini = aux->prox;
	if( l->tam == 1) {
		l->fim = NULL;
	}
	v = aux->info;
	free(aux);
	l->tam--;
	return v;
	//return remover_pos(l, 0);
}

int remover_ultimo(Lista * l) {
	
	int v,i;
	No *aux;
	No *aux2;

	if(l->tam ==0 ){
		printf("Lista vazia!");
		return -1;
	}
	
	if (l->tam > 1){
		for (i=0;i<l->tam-2;i++){
			aux = aux->prox;
		}
		aux2 = aux->prox;
		aux->prox = NULL;
		l->fim = aux;
	} else {
		aux2 = l->ini;
		l->ini = NULL;
		l->fim = NULL;
	}
	v = aux2->info;
	free(aux2);
	l->tam--;
	return v;
	//return remover_pos(l, tamanho(l) - 1);
}

void remover(Lista * l, int v) {
	No * aux = NULL, *aux2 = l->ini;
	while (aux2 != NULL && aux2->info != v) {
		aux = aux2;
		aux2 = aux2->prox;
	}
	if (aux2 != NULL) {
		if (aux2 != l->ini) {
			aux->prox = aux2->prox;
		}
		else {
			l->ini = aux2->prox;
		}
		if (aux2 == l->fim) {
			l->fim = aux;
		}
		free(aux2);
		l->tam--;
	}
}

void remover_todos(Lista * l, int v) {
	No * aux = NULL, *aux2 = l->ini;
	while (aux2 != NULL) {
		while (aux2 != NULL && aux2->info != v) {
			aux = aux2;
			aux2 = aux2->prox;
		}
		if (aux2 != NULL) {
			if (aux2 != l->ini) {
				aux->prox = aux2->prox;
			}
			else {
				l->ini = aux2->prox;
			}
			if (aux2 == l->fim) {
				l->fim = aux;
			}
			free(aux2);
			aux2 = aux != NULL ? aux->prox : l->ini;
			l->tam--;
		}
	}
}

void inverter(Lista *l)
{
	
	No *aux = l->ini, *aux2;
	int i,j,tmp;
	for (i=0; i<tamanho(l) / 2; i++){
		aux2 = aux;
		for (j = i; j<tamanho(l) - i - 1 ;j++){
			aux2 = aux2->prox;
		}
		
		tmp = aux->info;
		aux->info = aux2->info;
		aux2->info = tmp;
		aux = aux->prox;
	}
	
}


void inverter2(Lista *l){
	No *aux, *aux2 = NULL;
	int i;
	l->fim = l->ini;
	for (i = 0 ; i < tamanho(l) - 1 ; i++) {
		aux = l->ini;
		l->ini = aux->prox;
		aux->prox = aux2;
		aux2 = aux;
	}
	l->ini->prox = aux2;
	
}











