//ALUNO: Lukas de Menezes Pereira
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int info;
   struct no *prox;
}Lista;

Lista* crialista() {
    return NULL;
}

Lista* insere(Lista *list, int valor) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = list;
    return novo;
}

void imprime (Lista *list) {
    Lista *p;
    for (p = list; p != NULL; p = p->prox) {
        printf("info = %d\n", p->info);
    }
}

int estavazia(Lista *list) {
    return (list == NULL);
}

Lista* busca (Lista *list, int valor) {
    Lista* p;
        for(p=list; p != NULL; p=p->prox){
            if (p->info == valor){
                return p;
            }
        }
    return NULL;
}

Lista *retira(Lista *lista, int v) {
        Lista *ant = NULL;
        Lista *p = lista;

        while (p != NULL && p->info != v) {
            ant = p;
            p = p->prox;
        }

        if (p==NULL) {
            return lista;
        }

        if (ant==NULL) {
                lista = p->prox;
        } else {
            ant->prox = p->prox;
        }
	free(p);
	return lista;
}

Lista* libera(Lista* lista) {
    Lista *p = lista;
    while (p != NULL) {
        p = lista->prox;
        free(lista);
        lista = p;
    }
    return NULL;
}

int main() {
   //IMPLEMENTE AS FUNÇÕES ANTERIORES

   //EM SEGUIDA CRIE A LISTA E FAÇA AS SEGUINTES OPERAÇÕES
    Lista *minhalista;
    minhalista = crialista();
   //INSIRA 6 ELEMENTOS (88,71,23,12,29,1)
    minhalista = insere(minhalista, 88);
    minhalista = insere(minhalista, 71);
    minhalista = insere(minhalista, 23);
    minhalista = insere(minhalista, 12);
    minhalista = insere(minhalista, 29);
    minhalista = insere(minhalista, 1);
   //IMPRIMA A LISTA
    imprime(minhalista);
   //BUSQUE PELO ELEMENTO 70
    Lista *r = busca(minhalista, 70);
    if(r!=NULL){
        printf("NO com valor %d encontrado \n", r->info);
    }
    else{
        printf("NO nao encontrado \n");
    }
   //BUSQUE PELO ELEMENTO 29
    Lista *r2 = busca(minhalista, 29);
    if(r2!=NULL){
        printf("NO com valor %d encontrado \n", r2->info);
    }
    else{
        printf("NO nao encontrado \n");
    }
   //REMOVA OS ELEMENTOS 12, 23, 1
    minhalista = retira(minhalista, 12);
    minhalista = retira(minhalista, 23);
    minhalista = retira(minhalista, 1);
   //IMPRIMA A LISTA
    imprime(minhalista);
   //LIBERE A LISTA
    libera(minhalista);
    return 0;
}
