#include "ints.h"

struct int_node {
	int info;
	node* prox;
	node* ant;
};

#define null_ptr_msg printf("hrc: the refered address is null.\n")

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

int** fillmtx(int lines, int collumns, int lowerbound, int upperbound){
    int** m = (int**) calloc(lines, sizeof(int*));
    int i, j;
    for (i=0; i<lines; i++){
        m[i] = (int*) calloc(collumns, sizeof(int));
    }
    srand((unsigned)time(NULL));
    for (i=0; i<lines; i++){
        for (j=0; j<collumns; j++){
        m[i][j] = lowerbound+rand()%upperbound;
        }
    }
    return m;
}

void printmtx(int** matrix, int lines, int collumns){
	int i, j;
	for (i=0; i<lines; i++){
        for (j=0; j<collumns; j++){
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool isEven(int x){
  if(x%2==0) return true;
  else return false;
}

void* make(){
	return NULL;
}

node* newnode(int x){
	node* n = (node*) calloc(1, sizeof(node));
	n->info = x;
	return n;
}

static node* last(lint l){
  if (l!=NULL) {
    while(l->prox!=NULL) l = l->prox;
    return l;
  }
  return NULL;
}

static node* previous(lint l, node* n){
	if (l!=NULL) {
		while(l->prox!=n) l = l->prox;
		return l;
	}
	return NULL;
}

void insend(lint *l, node* novo){
	if(l!=NULL){
  		if(*l==NULL) {
  			*l = novo;
  		} else {
			node *aux = *l;
			aux = last(*l);
			aux->prox = novo;
  		}
  	} else null_ptr_msg;
}

void instop(lint *l, node *novo){
	if(l!=NULL){
  	if(*l==NULL) *l = novo;
  	else {
  		novo->prox = *l;
  		*l = novo;
  	}
  } else null_ptr_msg;
}

lint insvec(int *vec, int size){
	lint l = make();
	int i;
	for (i=0; i<size; i++) insend(&l, newnode(vec[i]));
	return l;
}

void unmake(lint *l) {
	node* aux = NULL;
	while((*l)->prox!=NULL){
		aux = *l;
		*l = (*l)->prox;
		free(aux);
	}
	free(*l);
	*l = NULL; //Só pra garantir
}

int getinfo(node* n){
	if(n!=NULL){
		return n->info;
	}
}

bool setinfo(node* n, int info){
	if(n!=NULL){
		n->info = info;
		return true;
	}
	else return false;
}

node* getprox(node* n){
	if(n!=NULL){
		return n->prox;
	}
}

bool setprox(node* n, node* m){
	if(n!=NULL){
		n->prox = m;
		return true;
	}
	else return false;
}

void show(lint l){
	while (l!=NULL) {
		printf("%i ", l->info);
		l = l->prox;
	}
}
