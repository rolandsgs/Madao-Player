#ifndef FILA_H
#define FILA_H

#include <iostream>

using namespace std;

template<typename T>
struct no_simples
{
	T data;
	no_simples *next;
};

template<typename type>
class Queue
{
private:
	no_simples<type> *var;  ///variavel da lista
	no_simples<type> *aux;  ///variavel que aponta para o ultimo
	int sizequeue;     	    ///tamanho da fila
	
public:
    Queue();
    ~Queue();
	
	int &front();     ///acessa o primeiro elemento da lista como referencia
	int size();		  ///retorna o tamanho da fila
	void pop();       ///retira o primeiro elemento da fila
    void push(type a); ///insere um dado na fila
};

#include "fila.cpp"

#endif
