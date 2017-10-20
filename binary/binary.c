#include "binary.h"

// FUNÇÕES ARITMÉTICAS:

int* ADD(int* A, int* B, int* carry, const int size){
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
      *carry = 0;
    }
  }
  return RES;
}

int* SUB(int* A, int* B, int* borrow, const int size){
  int* compB = COMP2(B, borrow, size);
  return ADD(A, compB, borrow, size);
}

int* MUL(int* A, int* B, const int size){
  int* TEMP = newvec(size); //vetor iniciado com zeros
  int i,
      carry = 0; //bit de carry da soma

  for(i=0; i<size; i++){ //Lógica de controle de deslocamento e adição
    if(B[size-1] == 1) TEMP = ADD(TEMP, A, &carry, size);
    rightshift(TEMP, B, carry, size);
  }

  //Geração e preenchimento do vetor resultado:
  int* RES = newvec(2*size);
  for(i=0; i<size; i++) RES[i] = TEMP[i];
  for(i=0; i<size; i++) RES[i+size] = B[i];

  return RES;
}

int* IMUL(int* A, int* B, const int size){}

int* COMP2(int* A, int* carry, const int size){
  int i;
  int* compA = A;
  int* AUX = newvec(size);

  for(i=0; i<size; i++){
    if(compA[i] == 0) compA[i] = 1;
    else if(compA[i] == 1) compA[i] = 0;
  }
  AUX[size-1] = 1;
  return ADD(compA, AUX, carry, size);
}



// FUNÇÕES DE LÓGICA E CONTROLE:

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

int boothshift(int* A, int* B, const int size){
  int aux,
      i,
      ctrl     = 0,
      borrow   = 0,
      sign_bit = A[0],
      lsb      = size-1;

  aux = A[lsb];
  for(i=lsb; i>=0; i--){ // Faz o deslocamento de todos os elementos para a direita.
    ctrl = A[i];
    A[i] = A[i-1];
    B[i] = B[i-1];
  }
  A[0] = sign_bit; // Mantém o bit de sinal como bit mais significativo.
  B[0] = aux; // Desloca o último bit de A para o primeiro de B.

  return ctrl;
}


// FUNÇÕES AUXILIARES:

int* newvec(const int size){ //pra evitar a fadiga
  return (int*) calloc(size, sizeof(int));
}

void printv(int* vec, char* vec_name, const int size){
  printf("\n%s: ", vec_name);
	for (int i = 0; i < size; i++) {
		printf("%i ", vec[i]);
	}
}
