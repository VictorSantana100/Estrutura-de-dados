#include <stdio.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

struct lista1{
    int info;
    struct lista *prox;
    struct lista *dir;
};
typedef struct lista Lista1;


Lista* cria_lista(){
    return NULL;
}


Lista* insere_ini(Lista*l,int dado){
    Lista*no = (Lista*)malloc(sizeof(Lista));
    no->info = dado;
    no->prox = l;
    
    return no;
}

void exibir_lista(Lista*l){
    Lista* p ;
    
    for(p = l; p!=NULL; p = p->prox)
        printf("%d  ",p->info);
}

void verifica(Lista*l) {
    
    if(l==NULL)
    printf("Lista vazia\n");
     else{
        printf("Lista não vazia\n");
        }
} 


Lista* busca_elemento(Lista*l, int v){
    Lista*p;
    
    for(p=l; p!=NULL; p = p->prox){
        if(p->info == v){
            printf("\nValor encontado: %d", p->info);
            return p;
        }
    }
    
    printf("\nValor não encontrado :(");
    return NULL;
}


void libera_lista(Lista*l){
    Lista*p = l;
    while(p!=NULL){
        Lista* t;
        t = p->prox ;
        
        p = t;
    }
    
    
}

int remove_elemento(Lista*l,int v){
    Lista*ant = NULL;
    Lista* p = l;
    
    while(p!=NULL&& p->info!=v){
        ant = p;
        p = p->prox;
    }
    
    if(p==NULL)
        return l;
    
    if(ant==NULL){
        l = p->prox;
    }else{
        
        ant ->prox = p->prox;
    }
    
    free(p);
    
    return l ;
    
}

Lista* separa_lista(Lista*t, int v){
    Lista*aux;
    Lista*aux1;
    Lista*l;
    
    for(aux = t; aux!= NULL; aux=aux->prox){
        if(aux->info == v){
            l = aux->prox;
        }
    }
    
    for(aux = t; aux!= NULL; aux=aux->prox){
        if(aux->info == v){
            aux->prox = NULL;
        }
    }
    
    return l;
    
}

int main(){
    Lista*l;
    l = cria_lista();
    Lista* p = NULL;
    
    p = insere_ini(p,74);
    p = insere_ini(p,847);
    p = insere_ini(p,9884);
    p = insere_ini(p,84);
    p = insere_ini(p,4);
    p = insere_ini(p,98);
    
    remove_elemento(p,847);
    printf("\nLista de elementos\n");
    exibir_lista(p);
    printf("\n\nLista separada\n");
    exibir_lista(separa_lista(p,9884));
    printf("\n");
    exibir_lista(p);
    printf("\n");
    busca_elemento(p, 4);

    return 0;
}






