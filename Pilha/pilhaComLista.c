#include <stdio.h>
#define max 20

struct pilha{
    int n;
    float vet[max];
};
typedef struct pilha Pilha;

Pilha* cria_pilha(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->n = 0;
    
    return p;
}

void push(Pilha*p,float v){
    
    if(p->n == max){
        printf("cheia");
        exit(1);
    }
    
    p->vet[p->n] = v;
    p->n++;
}

float pop(Pilha*p){
    float v;
    
    if(p->n == 0){
        printf("vazia");
        exit(1);
    }
    
    v = p->vet[p->n -1];
    p->n--;
    
    return v;
}

void mostrar(Pilha*p){
    int i;
    
    for(i = p->n -1; i>=0; i--)
        printf("%.1f \n",p->vet[i]);
}


float topo(Pilha*p){
    
    float v;
    v = p->vet[p->n -1];
    
    return v;
}

void concatena(Pilha*p,Pilha*p1){
    int i;
    
    Pilha*aux = cria_pilha();
    
    for(i= p->n; i>=0; i--){
        push(aux,pop(p1));
        push(p,pop(aux));
    }
    
    mostrar(p);
}

Pilha* copia(Pilha* p){
    int i;
    
    Pilha* aux1 = cria_pilha();
    Pilha* aux2 = cria_pilha();
    
    for(i = p->n-1; i>=0; i--){
        push(aux1,pop(p));
        push(aux2,pop(aux1));
    }
        
    return aux2;
}

float maior(Pilha*p){
    
    int i;
    float t=0,v=0;
    
    for(i = p->n-1; i>=0; i--){
        v = p->vet[i];
        if(p->vet[i] >= t){
            t = v;
        }
    }
    
    return t;
}

int main(){
    int i;
    
    Pilha*primeira_pilha = cria_pilha();
    Pilha*segunda_pilha = cria_pilha();
    
    push(primeira_pilha,1.0);
    push(primeira_pilha,4.5);
    push(primeira_pilha,2.1);
    
    printf("\nPrimeira Pilha\n");
    mostrar(primeira_pilha);
    
    printf("\nExibe o topo da primeira pilha:\n%.2f\n", topo(primeira_pilha));
    
    printf("\nRemove elemento da primeira pilha\n");
    pop(primeira_pilha);
    mostrar(primeira_pilha);
    
    push(segunda_pilha,7.2);
    push(segunda_pilha,3.1);
    push(segunda_pilha,9.8);
    
    printf("\nSegunda Pilha\n");
    mostrar(segunda_pilha);
    
    printf("\nMaior elemento da segunda Pilha: \n%.2f \n", maior(segunda_pilha));
    
    printf("\nConcatena a primeira com a segunda pilha\n");
    concatena(primeira_pilha, segunda_pilha);

    return 0;
}
