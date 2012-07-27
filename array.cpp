#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "array.hpp"

template<typename type>
Array<type>::Array(int a)
{
	var = new type[a];
	i = a;
}

template<typename type>
Array<type>::~Array()
{
	delete [] var;
}

template<typename type>
bool Array<type>::isEmpty()
{
	if(size == 0)
		return true;
		
	return false;
}

template<typename type>
bool Array<type>::resize(unsigned int b)
{
	type *p = new type[b];
	
	for(unsigned int i1=0;i1<b;i1++)
		p[i1] = var[i1];
		
	delete var;
	var = p;
	
	return true;
}

template<typename type>
type &Array<type>::back()
{
	return operator[](i-1);
}

template<typename type>
type &Array<type>::front()
{
	return operator[](0);
}

template<typename type>
type &Array<type>::operator[](unsigned int a)
{
	if(a >= i)
		return &trash;
		
	return var[a];
}

template<typename type>
void Array<type>::operator=(Array a)
{
	resise(a.i);
	for(int i1;i1 < this->i;i1++)
		this->var[i1] = a->var[i1];
}

#endif

