#include "lista.h"
#include <string.h>

struct no {
	void *info;
	node *prox;
};


node* novo(void *dado){
	node *novo = (node*) calloc(1, sizeof(node));
	novo->info = dado;
	return novo;
}

node* ultimo(lista l){
  if (l!=NULL) {
    while(l->prox!=NULL) l = l->prox;
    return l;
  }
  return NULL;
}

node* anterior(lista l, node* n){
	if (l!=NULL) {
		while(l->prox!=n) l = l->prox;
		return l;
	}
	return NULL;
}

void insfim(lista *l, node* novo){
	if(l!=NULL){
  	if(*l==NULL) *l = novo;
   	else {
  		node *aux = *l;
  		aux = ultimo(*l);
  		aux->prox = novo;
  	}
  } else null_ptr_msg;
}

void insini(lista *l, node *novo){
	if(l!=NULL){
  	if(*l==NULL) *l = novo;
  	else {
  		novo->prox = *l;
  		*l = novo;
  	}
  } else null_ptr_msg;
}

static bool contem(lista l, void *dado){
	while(l != NULL){
		if(l->info == dado) return true;
		l = l->prox;
	}
	return false;
}

node* busca(lista l, void* dado){
	while (l!=NULL) {
		if (l->info == dado) return l;
		l = l->prox;
	}
	return NULL;
}

void remover(lista l, void *dado) {
	node* aux = busca(l, dado);
	if (aux != NULL){
		node* ant = anterior(l, aux);
		ant->prox = aux->prox;
		free(aux);
	}
}

lista novalista(int ndados, ...){
  node *nova = NULL;
  int i;
  va_list ap;
  va_start(ap, ndados);
  for(i=0; i<ndados; i++){
    insfim(&nova, va_arg(ap, void*));
  }
  va_end(ap);
  return nova;
}

void mostra(lista l, char* tipo){
  if(l == NULL) null_ptr_msg;
  else {
    if( (strcmp(tipo, "int") == 0 )){
        while(l!=NULL){
          printf("%i ", *(int*) l->info);
          l=l->prox;
        }
      }
    else if( (strcmp(tipo, "float") == 0 )){
      while(l!=NULL){
        printf("%.2f ", *(float*) l->info);
        l=l->prox;
      }
    }
    else if( (strcmp(tipo, "string") == 0 )){
      while(l!=NULL){
        printf("%s ", (char*) l->info);
        l=l->prox;
      }
    }
    else printf("Tipo de dado não suportado. Considere criar uma função exclusiva para este tipo.\n");
  }
}

void desfazlista(lista *l) {
	node* aux = NULL;
	while((*l)->prox!=NULL){
		aux = *l;
		*l = (*l)->prox;
		free(aux);
	}
	free(*l);
	*l = NULL; //Só pra garantir
}

void* getinfo(node* n){
	if(n!=NULL){
		return n->info;
	}
}

bool setinfo(node* n, void* info){
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
