#include <stdio.h>
#define N 25

struct fila{
    int n;
    int ini;
    float vet[N];
};

typedef struct fila Fila;

Fila* cria_fila(){
    Fila*f = (Fila*)malloc(sizeof(Fila));
    f->n = 0;
    f->ini = 0;
    
    return f;
}

void inserir(Fila*f, int v){
    int fim;
    
    if(f->n == N){
        printf("Fila cheia");
        exit(1);
    }
    
    fim = (f->ini + f->n) % N;
    f->vet[fim] = v;
    f->n++;
}

void libera_fila(Fila*f){
    free(f);
}

float remove_fila(Fila*f){
    
    float v;
    if(f->n == 0){
        printf("Fila vazia");
    }
    
    v = f->vet[f->ini];
    f->ini = (f->ini + 1)%N;
    f->n--;
    
    return v;
}

void mostrar(Fila*f){
    int i;
    
    for(i = 0; i<f->n; i++)
        printf("%.2f \n",f->vet[(f->ini +i)%N]);
}

void repetido(Fila*f, int v){
    int i,cont=0;
    
    for(i=0; i<f->n; i++){
        if(v == f->vet[(f->ini + i)%N]){
            cont++;   
        }
    }
    if(cont!=0){
        printf("\nElemento %d repetido:\n%d vez(es)",v,cont);
    }else{
        printf("\nElemento não repetido\n");
    }
}

int main(){
    
    Fila*f;
    
    f = cria_fila();
    inserir(f,78);
    inserir(f,8);
    printf("\nElementos inseridos na fila\n");
    mostrar(f);
    repetido(f,8);

    return 0;
}


