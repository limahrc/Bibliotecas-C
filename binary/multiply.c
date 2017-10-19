#include <stdio.h>
#include <stdlib.h>

int* newvec(const int size){ //pra evitar a fadiga
  return (int*) calloc(size, sizeof(int));
}

void printv(int* vec, const int size){
	for (int i = 0; i < size; i++) {
		printf("%i ", vec[i]);
	}
}

static inline void seevec(int* v1, int* v2, const int size){
  printf("V1:\n");
  printv(v1, size);
  printf("\n");
  printf("V2:\n");
  printv(v2, size);
  printf("\n");
}

/*
** Função: executar a soma de dois vetores de números binários.
*/
int* binarysum(int* A, int* B, int* carry, const int size){
  int SUM,   //variável container para facilitar a compreensão do algoritmo.
      i, j; //iteradores para os vetores A, B e RES.

  int* RES = newvec(size); /* Aloca vetor dinamicamente já iniciado com zeros.
  Este vetor será usado para armazenar o resultado. */

  for(i=size-1; i>=0; i--){ //Laço da direita para a esquerda nos vetores.

    SUM = A[i]+B[i]+(*carry);

    /* Equivalência de possíveis resultados da soma decimal e sua representação
    em binário */
    if (SUM == 3){
      RES[i] = 1; //resultado binário da soma
      *carry = 1; // vai um
    } else if (SUM == 2) {
      RES[i] = 0; //resultado binário da soma
      *carry = 1; // vai um
    } else {
      RES[i] = SUM;
    }
  }
  return RES;
}

/*
** Procedimento: deslocar elementos dos vetores A e B para a direita.
*/
void rightshift(int* A, int* B, int carry, const int size) {
  int aux,  /* variável para armazenar o bit na última posição de A e
  que vai para a primeira posição de B. */
      i,  //iterador
      lsb = size-1; //posição do bit menos significativo de A.

  aux = A[lsb];
  for(i=lsb; i>=0; i--){ // Faz o deslocamento de todos os elementos para a direita.
    A[i] = A[i-1];
    B[i] = B[i-1];
  }
  A[0] = carry; // Deslocamento do bit de carry.
  B[0] = aux; // Desloca o último bit de A para o primeiro de B.
}

int* twocomplement(int* A, int* carry, const int size){
  int i;
  int* AUX = newvec(size);
  for(i=0; i<size; i++){
    if(A[i] == 0) A[i] = 1;
    else if(A[i] == 1) A[i] = 0;
  }
  AUX[size-1] = 1;

  seevec(A, AUX, size); //debugging

  return binarysum(A, AUX, carry, size);
}

/*
** Função: multiplicar dois vetores de números binários de n bits.
*/
int* multiply(int* A, int* B, const int size){
  int* TEMP = newvec(size); //vetor iniciado com zeros
  int i,
      carry = 0; //bit de carry da soma

  for(i=0; i<size; i++){ //Lógica de controle de deslocamento e adição
    if(B[size-1] == 1) TEMP = binarysum(TEMP, A, &carry, size);
    rightshift(TEMP, B, carry, size);
  }

  //Geração e preenchimento do vetor resultado:
  int* RES = newvec(2*size);
  for(i=0; i<size; i++) RES[i] = TEMP[i];
  for(i=0; i<size; i++) RES[i+size] = B[i];

  return RES;
}

int* binarysub(int* A, int* B, const int size){
  int carry = 0;
  int* min = twocomplement(B, &carry, size);
  return binarysum(A, min, &carry, size);
}

int main(int argc, char const *argv[])
{
	#define tam 4
	int v1[tam] = {1,0,0,1};
	int v2[tam] = {0,1,1,0};

	// int* res = multiply(v1, v2, tam);
  int carry=0;
  int* res = twocomplement(v1, &carry, tam);
  // printf("%i ", carry);
  // int* res = binarysub(v1, v2, tam);
	printv(res, tam);

	return 0;
}
