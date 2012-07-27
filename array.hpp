#ifndef ARRAY_HPP
#define ARRAY_HPP

/*****************************************************************************************************************
** Made By Luck_T 19/06/12                                                                                       *
******************************************************************************************************************
** QUANDO ACESSADO UMA POSIÇÃO ALEM DA ALOCADA O ARRAY RETORNA LIXO												 *
** SE DESALOCADO TODO O ARRAY E TENTOU ACESSAR ALGUMA PARTE ELE RETORNARA LIXO                                   *
*****************************************************************************************************************/

template <typename type>
class Array
{
private:
	type *var;		  		///Variavel alocada para o array
	unsigned int i;   		///Tamanho do array


public:
	Array(int a=0);
	virtual ~Array();

	type trash;

	bool isEmpty();         		///Função para saber se o Array esta vasio
	bool resize(unsigned int b);	///Função para redimencionar o Array
	int size();             		///Retorna o tamanho do array alocado
	type &back();                   ///Acessa o primeiro elemento
	type &front();                  ///Acessa o ultimo

	type &operator[](unsigned int a);
	void operator=(Array a);
};

#include "array.cpp"

#endif
