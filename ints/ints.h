#ifndef _INTS_H
#define _INTS_H

/*
	BIBLIOTECA DE FUNÇÕES PARA INTEIROS, VETORES DE INTEIROS E LISTAS ENCADEADAS
  DE INTEIROS
	AUTOR: HERICK LIMA NUNES
	EMAIL: LIMAHRC@GMAIL.COM
	ENGENHARIA DE COMPUTAÇÃO
	UNIVERSIDADE FEDERAL DO ESPÍRITO SANTO
	VERSÃO 1.2
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct int_node node;
typedef node* lint;

/*
* Identifica qual é o elemento de maior valor em um vetor
* @vec: vetor no qual se deseja atuar
* @len: tamanho do vetor
*/ int hvalue(int* vec, int tam);

/*
* Identifica qual é o elemento de menor valor em um vetor
* @vec: vetor no qual se deseja atuar
* @tam: tamanho do vetor
*/ int lvalue(int* vec, int tam);

/*
* Preenche um vetor com números aleatórios dentro de um limite
* informado pelo usuário.
* @tam: tamanho do vetor a ser criado
* @limInferior: número mínimo do qual os elementos podem variar
* @limSuperior: número máximo do qual os elementos podem variar
*/ int* fillvec(int tam, int limInferior, int limSuperior);

/*
* Imprime na tela um vetor
*/ void printvec(int* vec, int tam);

/*
* Cria um vetor C resultante da soma de dois vetores, vec1 e vec2
*/ int* vecsum(int* vec1, int* vec2, int tam);

/*
* Verifica se um número é par
*/ bool isEven(int x);

/*
* Aloca e preenche uma matriz com números aleatórios dentro de um limite
* informado pelo usuário.
* @lines: número de linhas da matriz
* @collumns: número de colunas da matriz
* @lowerbound: número mínimo do qual os elementos podem variar
* @upperbound: número máximo do qual os elementos podem variar
*/ int** fillmtx(int lines, int collumns, int lowerbound, int upperbound);

/*
* Imprime uma matriz na tela
* @matrix: matriz que se deseja imprimir
* @lines: número de linhas da matriz
* @collumns: número de colunas da matriz
*/ void printmtx(int** matrix, int lines, int collumns);

/*
* Prepara a lista para ser montada (ainda sem corpo).
*/ void* make();

/*
* Aloca um novo nó e retorna um ponteiro para o mesmo.
* @dado: ponteiro para o dado a ser armazenado
*/ node* newnode(int x);

/*
* Obtém o endereço do último nó da lista.
*/ static node* last(lint l);

/*
* Obtém o endereço do nó anterior ao nó parâmetro.
*/ static node* previous(lint l, node* n);

/*
* Insere um novo nó no fim da lista passada
* como parâmetro.
* @l: lista na qual se deseja inserir
* @novo: ponteiro para o nó o qual se deseja inserir
*/ void insend(lint* l, node* novo);

/*
* Insere um novo nó no início da lista passada
* como parâmetro.
* @l: lista na qual se deseja inserir
* @novo: ponteiro para o nó o qual se deseja inserir
*/ void instop(lint* l, node *novo);

/*
* Cria uma lista a partir de um vetor parâmetro.
  @vec: vetor de inteiros
  @size: tamanho do vetor
*/ lint insvec(int* vec, int size);

/*
* Percorre a lista desalocando seus nós da memória.
* @l: endereço da lista que se deseja desfazer
*/ void unmake(lint* l);

/*
*	Obtém o endereço de memória de objeto armazenado no nó
*	passado como parâmetro.
*/ int getinfo(node* n);

/*
* Define a informação armazenada (ponteiro) no nó parâmetro e
* retorna true se a operação for bem sucedida ou false, caso contrário.
* @info: endereço do objeto que se deseja armazenar
*/ bool setinfo(node* n, int info);

/*
* Obtém o endereço do próximo nó ligado ao nó parâmetro.
*/ node* getprox(node* n);

/*
* Define o endereço do próximo nó ligado ao nó parâmetro.
* retorna true se @n puder apontar para @m corretamente
* ou retorna false, caso contrário
*/ bool setprox(node* n, node* m);

/*
* Percorre e exibe as informações de todos os nós da lista.
* @l: lista que se deseja percorrer
*/ void show(lint l);

#endif /* end of include guard: _INTS_H_ */
