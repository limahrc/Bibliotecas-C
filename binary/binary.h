#ifndef _HRC_BINARY_
#define _HRC_BINARY_

#include <stdio.h>
#include <stdlib.h>

/*
** Função: executar a soma de dois vetores de números binários.
*/ int* ADD(int* A, int* B, int* carry, const int size);

/*
** Função: executar a subtração de dois vetores de números binários.
*/ int* SUB(int* A, int* B, int* borrow, const int size);

/*
** Função: multiplicar dois vetores de números binários de n bits sem sinal.
*/ int* MUL(int* A, int* B, const int size);

/*
** Função: multiplicar dois vetores de números binários de n bits com sinal.
*/ int* IMUL(int* A, int* B, const int size);

/*
** Função: obter o complemento de dois de um número binário.
*/ int* COMP2(int* A, int* carry, const int size);

int* newvec(const int size);
void printv(int* vec, char* vec_name, const int size);

/*
** Procedimento: deslocar elementos dos vetores A e B para a direita.
*/ void rightshift(int* A, int* B, int carry, const int size);

int boothshift(int* A, int* B, const int size);

#endif
