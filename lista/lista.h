
#ifndef _HRC_LISTA_H
#define _HRC_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

/*
	BIBLIOTECA DE FUNÇÕES PARA LISTAS SIMPLESMENTE ENCADEADAS DE DADOS GENÉRICOS
	AUTOR: HERICK LIMA NUNES
	EMAIL: LIMAHRC@GMAIL.COM
	ENGENHARIA DE COMPUTAÇÃO
	UNIVERSIDADE FEDERAL DO ESPÍRITO SANTO
	VERSÃO 3.0
*/

// Definição do tipo node como nó da lista
typedef struct no node;
typedef node* lista;

#define null_ptr_msg \
	printf("O endereço de memória referenciado está vazio.\n")
#define console_test_message \
	printf("Até aqui, tudo OK.\n")

/*
* Aloca um novo nó e retorna um ponteiro para o mesmo.
* @dado: ponteiro para o dado a ser armazenado
*/ node* novo(void *dado);

/*
* Constrói e retorna uma nova lista a partir dos
* parâmetros passados
* @ndados: quantidade de elementos/parâmetros que serão passados
*/ lista novalista(int ndados, ...);

/*
*	Obtém o endereço de memória de objeto armazenado no nó
*	passado como parâmetro.
*/ void* getinfo(node* n);

/*
* Define a informação armazenada (ponteiro) no nó parâmetro e
* retorna true se a operação for bem sucedida ou false, caso contrário.
* @info: endereço do objeto que se deseja armazenar
*/ bool setinfo(node* n, void* info);

/*
* Obtém o endereço do próximo nó ligado ao nó parâmetro.
*/ node* getprox(node* n);

/*
* Define o endereço do próximo nó ligado ao nó parâmetro.
* retorna true se @n puder apontar para @m corretamente
* ou retorna false, caso contrário
*/ bool setprox(node* n, node* m);

/*
* Insere um novo nó no início da lista passada
* como parâmetro.
* @l: lista na qual se deseja inserir
* @novo: ponteiro para o nó o qual se deseja inserir
*/ void insini(lista *l, node *novo);

/*
* Insere um novo nó no fim da lista passada
* como parâmetro.
* @l: lista na qual se deseja inserir
* @novo: ponteiro para o nó o qual se deseja inserir
*/ void insfim(lista *l, node* novo);

/*
* Obtém o endereço do último nó da lista.
*/ node* ultimo(lista l);

/*
* Percorre e exibe as informações de todos os nós da lista.
* @l: lista que se deseja percorrer
* @tipo: string que define o tipo de dado que será exibido
* pela função. Os tipos padrão são: int float e string
*/ void mostra(lista l, char* tipo);


/*
*	Busca na lista um elemento e retorna seu endereço
*	@l: lista na qual se busca
*	@dado: informação do nó que se deseja buscar
*/ node* busca(lista l, void* dado);

/*
*	Remove um nó da lista
*	@l: lista na qual se busca
*	@dado: informação do nó que se deseja remover
*/ void remover(lista l, void *dado);

/*
* Percorre a lista desalocando seus nós da memória.
* @l: endereço da lista que se deseja desfazer
*/ void desfazlista(lista *l);

#endif
