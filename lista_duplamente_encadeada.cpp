#ifndef LIST_DUP_ENC_CPP
#define LIST_DUP_ENC_CPP

#include "lista_duplamente_encadeada.hpp"

template<typename type>
ListaDuplaEncadeada<type>::ListaDuplaEncadeada()
{
	if(this == NULL)
		return;

    var = new no_duplo<type>;
    var->next = NULL;
    var->prev = NULL;
    pos_no = 0;
    num_nos = 0;
}

template<typename type>
ListaDuplaEncadeada<type>::~ListaDuplaEncadeada()
{
    clearList();
}

template<typename type>
void ListaDuplaEncadeada<type>::pushBack(type b)
{
    if(num_nos == 0)
    {
        var->data = b;
        num_nos++;
        return;
    }
    operator[](num_nos-1);
    no_duplo<type> *p = new no_duplo<type>;
    p->data = b;
    p->prev = var;
    p->next = NULL;
    var->next = p;
    var = p;
    num_nos++;
    pos_no++;
}

template<typename type>
int ListaDuplaEncadeada<type>::posisList()
{
    return pos_no;
}

template<typename type>
int ListaDuplaEncadeada<type>::numbersNos()
{
    return num_nos;
}

template<typename type>
type &ListaDuplaEncadeada<type>::operator[](unsigned int a)
{
    if(a >= num_nos)
    {
        return operator[](num_nos-1);
    }
    else
    {
        if(a > pos_no)
        {
            while(a != pos_no)
            {
                var = var->next;
                pos_no++;
            }
        }
        else if(a < pos_no)/* a menor que posição do no*/
        {
            while(a != pos_no)
            {
                var = var->prev;
                pos_no--;
            }
        }
    }

    return var->data;
}

template<typename type>
void ListaDuplaEncadeada<type>::deletar(unsigned int b)
{
    if(b >= num_nos)
        return;

    operator[](b);
    no_duplo<type> *pr;
    no_duplo<type> *nt;

    pr = var->prev;
    nt = var->next;

    if(pr != NULL)
        pr->next = var->next;
    if(nt != NULL)
        nt->prev = var->prev;

    delete var;

    if(pr!=NULL)
    {
        var = pr;
        pos_no--;
    }
    else if(nt!=NULL)
    {
        var = nt;
    }

    num_nos--;

    operator[](num_nos-1);
}

template<typename type>
void ListaDuplaEncadeada<type>::clearList()
{
	unsigned int i = 0;
    for(;num_nos < i;)
    {
        deletar(0);
    }
}


#endif
