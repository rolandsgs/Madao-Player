#ifndef FILA_CPP
#define FILA_CPP

#include "fila.hpp"

template<typename type>
Queue<type>::Queue()
{
	var = new no_simples<type>;
	var->next = NULL;
	aux = var;
	sizequeue = 0;
}

template<typename type>
Queue<type>::~Queue()
{
	
}

template<typename type>
void Queue<type>::push(type a)
{
	if(sizequeue == 0)	
	{
		var->data = a;
		sizequeue++;
		return;
	}
	no_simples<type> *p = new no_simples<type>;
	if(p == NULL)
		return;
	p->data = a;
	p->next = NULL;
	aux->next = p;
	aux = p;
}

template<typename type>
int &Queue<type>::front()
{
	return var->data;
}

template<typename type>
int Queue<type>::size()
{
	return sizequeue;
}

template<typename type>
void Queue<type>::pop()
{
    no_simples<type> *p;
	p = var;
	var = var->next;
	delete p;
}


#endif

