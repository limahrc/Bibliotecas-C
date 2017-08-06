#include "lista.h"
#include <string.h>

#define null_ptr_msg \
	printf("O endereço de memória referenciado está vazio.\n");
#define console_test_message \
	printf("Até aqui, tudo OK.\n");

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

void insfim(lista *l, void *dado){
	if(l!=NULL){
		node *no = novo(dado);
  	if(*l==NULL) *l = no;
   	else {
  		node *aux = *l;
  		aux = ultimo(*l);
  		aux->prox = no;
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
  if(l == NULL) null_ptr_msg
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
