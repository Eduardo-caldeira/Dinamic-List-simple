#ifndef TAD_DINAMICO_H_INCLUDED
#define TAD_DINAMICO_H_INCLUDED

#include <iostream>
using namespace std;

///Alunos: Eduardo Caldeira Vicente e Julia Disner
///Lista Dinâmica Simplesmente Encadeada

template<typename tipo>
struct Dado{
    tipo dado;
};

template<typename tipo>
struct TElemento{
    tipo elemento;
    TElemento *next;
};

template<typename tipo>
struct TLista{
    TElemento<tipo> *primeiro;
};

template<typename tipo>
bool inicializa_lista_enc(TLista<tipo> *Lista){
    Lista->primeiro = NULL;
    return true;
}

template<typename tipo>
bool insere_fim_lista_enc(TLista<tipo> *Lista, tipo dado){
    TElemento<tipo> *var;
    TElemento<tipo> *escravo = Lista->primeiro;
    if(Lista->primeiro != NULL){///Caso a lista não esteja vazia
        while(escravo->next != NULL){
            escravo=escravo->next;
        }
        var = new TElemento<tipo>;
        var->elemento = dado;
        var->next = NULL;
        escravo->next=var;
        return true;
    }else{///Caso a lista esteja vazia
        var = new TElemento<tipo>;
        var->elemento = dado;
        var->next = NULL;
        Lista->primeiro=var;
        return true;
    }

}

template<typename tipo>
bool remove_fim_lista_enc(TLista<tipo> *Lista){
    if(Lista->primeiro==NULL){///Caso a lista esteja vazia
        return false;
    }else{///Caso a lista não esteja vazia
        TElemento<tipo> *escravo = Lista->primeiro;
        if(escravo->next == NULL){///se o próximo elemento do meu auxiliar for igual a NULL
            Lista->primeiro = escravo->next;
            delete escravo;
            return true;
        }else{
            TElemento<tipo> *lixeira = Lista->primeiro->next;
            while(lixeira->next != NULL){
                escravo=escravo->next;
                lixeira= lixeira->next;
            }
            escravo->next= NULL;
            delete lixeira;
            return true;
        }
    }
}

template<typename tipo>
bool insere_inicio_lista_enc(TLista<tipo> *Lista, tipo dado){
    TElemento<tipo> *var;
    var = new TElemento<tipo>;
    var->elemento = dado;
    if(Lista->primeiro==NULL){///Caso a lista esteja vazia
        Lista->primeiro = var;
        return true;
    }else{
        var->next = Lista->primeiro;
        Lista->primeiro= var;
        return true;
    }
}

template<typename tipo>
bool remove_inicio_lista_enc(TLista<tipo> *Lista){
    TElemento<tipo> *escravo=Lista->primeiro;
    if(Lista->primeiro==NULL){///Se a lista etá vazia, não ha algo para remover
        return false;
    }else{
        Lista->primeiro= Lista->primeiro->next;
        delete escravo;
        return true;
    }
}

template<typename tipo>
bool remove_posicao_lista_enc(TLista<tipo> *Lista, int posi){
    TElemento<tipo> *escravo=Lista->primeiro;
    TElemento<tipo> *lixeira=Lista->primeiro->next;
    if(Lista->primeiro==NULL){///Se a lista etá vazia, não ha algo para remover
        return false;
    }else if(posi==0){
        Lista->primeiro= Lista->primeiro->next;
        delete escravo;
    }else{
        for(int i=0; i<posi-1; i++){
            escravo = escravo->next;
            lixeira = lixeira->next;
        }
        escravo->next = lixeira->next;
        delete lixeira;
           return true;
    }
    return false;
}

template<typename tipo>
bool insere_posicao_lista_enc(TLista<tipo> *Lista, int posi, tipo dado){
    TElemento<tipo> *escravo=Lista->primeiro, *var;
    var= new TElemento<tipo>;
    var->elemento = dado;
    if(posi==0){
        var->next = Lista->primeiro;
        Lista->primeiro= var;
        return true;
    }else{
        for(int i=0; i<posi-1; i++){
            escravo = escravo->next;
        }
        var->next = escravo->next;
        escravo->next = var;
        return true;
    }
}

template<typename tipo>
int quantidade_enc(TLista<tipo> *Lista){
    TElemento<tipo> *escravo= Lista->primeiro;
    int cont=1;
    if(Lista->primeiro == NULL){
        return 0;
    }else{
        while(escravo->next!= NULL){
            escravo=escravo->next;
            cont++;
        }
        return cont;
    }
}

template <typename tipo>
void bubblesort(TLista<tipo> *Lista){
    int sim=0;
    int i,j;
    for(i=0;i<quantidade_enc(Lista);i++){
        TElemento<tipo> *escravo = Lista->primeiro;
        for(j=0;j<quantidade_enc(Lista)-1;j++){
            if(escravo->elemento > escravo->next->elemento){
                tipo aux;
                aux = escravo->elemento;
                escravo->elemento = escravo->next->elemento;
                escravo->next->elemento = aux;
                sim++;
            }
            escravo = escravo->next;
        }
    }
    system("cls");
    cout << "iondjnf: "<<sim;
    system("pause");
}

template<typename tipo>
TElemento<tipo>* cata_elemento(TLista<tipo> *Lista, int posi){
    TElemento<tipo> *escravo= Lista->primeiro;
    for(int i=0; i<posi;i++){
        escravo = escravo->next;
    }
    return escravo;
}

template<typename tipo>
int part(TLista<tipo> *Lista,int inicio,int fim){
    TElemento<tipo> *pivo=cata_elemento(Lista, fim);
    TElemento<tipo> *escravo = cata_elemento(Lista, inicio);
    int indice=inicio;
    TElemento<tipo> *escravo_2 = cata_elemento(Lista, indice);
    int i;
    tipo aux;

    for(i=inicio;i<fim;i++)
    {
        if(escravo->elemento<=pivo->elemento)
        {
            aux=escravo->elemento;
            escravo->elemento=escravo_2->elemento;
            escravo_2->elemento=aux;
            indice++;
            escravo_2=cata_elemento(Lista, indice);
        }
        escravo= escravo->next;
     }
      aux=pivo->elemento;
      pivo->elemento=escravo_2->elemento;
      escravo_2->elemento=aux;

     return indice;
 }

template<typename tipo>
void quicksort(TLista<tipo> *Lista,int inicio,int fim){
    if(inicio<fim)
    {
         int indice=part(Lista,inicio,fim);
             quicksort(Lista,inicio,indice-1);
             quicksort(Lista,indice+1,fim);
    }
}

#endif // TAD_DINAMICO_H_INCLUDED
