#include "ints.h"

int hvalue(int *vec, int tam){
	int higherv;
	higherv = vec[0];
	for(int i=0; i<tam; i++){
		if(vec[i]>higherv) higherv = vec[i];
	}
	return higherv;
}

int lvalue(int *vec, int tam){
	int lowerv;
	lowerv = vec[0];
	for(int i=0; i<tam; i++){
		if(vec[i]<lowerv) lowerv = vec[i];
	}
	return lowerv;
}

int* fillvec(int tam, int limInferior, int limSuperior){
	int *vec, i;
	vec = (int*)calloc(tam, sizeof(int));
  srand((unsigned)time(NULL));
	for(i=0; i<tam; i++) vec[i] = limInferior+rand()%limSuperior;
	return vec;
}

void printvec(int *vec, int tam){
	for(int i=0; i<tam; i++){
		printf("%i ", vec[i]);
	}
}

int* vecsum(int *vec1, int *vec2, int tam){
	int *c;
	c = (int*)calloc(tam, sizeof(int));
	for(int i=0; i<tam; i++) c[i] = vec1[i]+vec2[i];
	return c;
}

bool isEven(int x){
  if(x%2==0) return true;
  else return false;
}
