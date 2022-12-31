#include <stdio.h>

struct lista{
    int dado;
    struct lista*prox;
};
typedef struct lista Lista;

struct fila{
    Lista* ini;
    Lista*fim;
};
typedef struct fila Fila;

Fila* cria_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    
    return f;
}

void insere_fila(Fila*f, int v){
    Lista*n = (Lista*)malloc(sizeof(Lista));
    n->dado = v;
    n->prox = NULL;
    
    if(f->fim!=NULL)
    f->fim->prox = n;
    else
    f->ini = n;
    
    f->fim = n;
}

int remove_fila(Fila*f){
    int v;
    Lista*t;
    
    if(f->ini == NULL){
        printf("Fila vazia");
        exit(1);
    }
    
    t = f->ini;
    v = t->dado;
    f->ini = t->prox;
    if(f->ini == NULL)
    f->fim = NULL;
    
    free(t);
    
    return v;
    
}

void mostrar(Fila*f){
    Lista* v;
    
    for(v=f->ini; v!=NULL; v=v->prox)
        printf("%d \n",v->dado);
    
}


int main(){
    Fila*f;
    f = cria_fila();
    
    insere_fila(f,140);
    insere_fila(f,1);
    insere_fila(f,2);
    insere_fila(f,3);
    insere_fila(f,58);
    printf("\nMostra elementos da fila\n");
    mostrar(f);

    return 0;
}


