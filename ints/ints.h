#ifndef _INTS_H
#define _INTS_H

/*
	BIBLIOTECA DE FUNÇÕES PARA INTEIROS E VETORES DE INTEIROS
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

/*
* Identifica qual é o elemento de maior valor em um vetor
* @vec: vetor no qual se deseja atuar
* @len: tamanho do vetor
*/ int hvalue(int *vec, int tam);

/*
* Identifica qual é o elemento de menor valor em um vetor
* @vec: vetor no qual se deseja atuar
* @tam: tamanho do vetor
*/ int lvalue(int *vec, int tam);

/*
* Preenche um vetor com números aleatórios dentro de um limite
* informado pelo usuário.
* @tam: tamanho do vetor a ser criado
* @limInferior: número mínimo do qual os elementos podem variar
* @limSuperior: número máximo do qual os elementos podem variar
*/ int* fillvec(int tam, int limInferior, int limSuperior);

/*
* Imprime na tela um vetor
*/ void printvec(int *vec, int tam);

/*
* Cria um vetor C resultante da soma de dois vetores, vec1 e vec2
*/ int* vecsum(int *vec1, int *vec2, int tam);

/*
* Verifica se um número é par
*/ bool isEven(int x);

#endif /* end of include guard: _INTS_H_ */
