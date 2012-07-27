/***************************************************************************************************
*   MADE BY LUCK_T                                                                                 *
*   DATE 13/05/12                                                                                  *
****************************************************************************************************
** ListaDuplaEncadeada lista(&lista) como declarar uma variavel das lista duplamente encadeada.    *
** A Lista Duplamente Encadeada Pode ser Acessada como um Array de n elementos de 0 a n-1.         *
** Quando voc� cria a lista ela n�o tem nenhum elemento por isso o numero de n�s � 0.              *
** Qualquer posi��o acessada inexistente da lista retornara o ultimo adicionado                    *
** Se voc� nao adicionou nada na lista e tenta acessar qualquer local dela ela retornara lixo      *
***************************************************************************************************/
#ifndef LISTA_DUP_ENCA_H
#define LISTA_DUP_ENCA_H
#include <iostream>

using namespace std;

template<typename t>
struct no_duplo
{
    t data;
    no_duplo *next;
    no_duplo *prev;
};

template<typename type>
class ListaDuplaEncadeada
{
	private:
        no_duplo<type> *var;        ///variavel da lista
        unsigned int pos_no;        ///qual no est� (0 ~ n_no-1) qual a posi��o
        unsigned int num_nos;       ///numero de nos feito (1 ~ n_no) quantos n�s j� foram alocados

    public:
        ListaDuplaEncadeada();
        ~ListaDuplaEncadeada();

		void pushBack(type b);             ///Adiciona mais um no e adiciona o dado
        void deletar(unsigned int b);      ///Deleta uma posi��o expecifica do n� e posiciona a lista no ultimo n�
        void clearList();                  ///Desaloca todos os nos da lista
        int posisList();                   ///Retorna a posi��o do no atual
        int numbersNos();                  ///Diz quantos n�s voc� ja tem

        type &operator[](unsigned int a);  ///array operador da lista
};

#include "lista_duplamente_encadeada.cpp"

#endif
