#include <stdio.h>
#include <stdlib.h>

struct arv{
    int info;
    struct arv *esq;
    struct arv *dir;
};
typedef struct arv Arv;

Arv* cria_arv(int info){
    Arv* p  = (Arv*)malloc(sizeof(Arv));
    p->esq  = NULL;
    p->dir  = NULL;
    p->info = info;
    
    return p;
}

// percurso em ordem  esq-raiz-dir
void mostrarEmOrdem(Arv*a){
    if(a!=NULL){
        mostrarEmOrdem(a->esq);
        printf("%d\n",a->info);
        mostrarEmOrdem(a->dir);
    }
}

// percuso em preordem raiz-esq-dir
void mostrarEmPreOrdem(Arv*a){
    if(a!=NULL){
      
        printf("%d\n",a->info);
        mostrarEmOrdem(a->esq);
        mostrarEmOrdem(a->dir);
    }
}

// percuso em pos ordem 
void mostrarEmPosOrdem(Arv*a){
    if(a!=NULL){
      
        mostrarEmOrdem(a->esq);
        mostrarEmOrdem(a->dir);
        printf("%d\n",a->info);
    }
}

// Rotacao para a esquerda
void rot_esq(Arv*v){
    Arv *q;
    Arv *temp;
    q = v->dir;
    temp = q->esq;
    q->esq = v;
    v->dir = temp;
    v = q;
    
}
// Rotacao para a direita
void rot_dir(Arv*v){
    Arv*q;
    Arv*temp;
    
    q = v->esq;
    temp = q->dir;
    q->dir = v;
    v->esq = temp;
    v = q;
}

// Rotacao para a direita caso 2
void rot_esq_dir(Arv*v){
    rot_esq(v->esq);
    rot_dir(v);
}

// Rotaciona para esquerda caso 2
void rot_dir_esq(Arv*v){
    rot_dir(v->dir);
    rot_esq(v);
}

Arv* rotacionaH(Arv*r){
    
    Arv* aux = r;
    r = r->dir;
    aux->esq = r->dir;
    r->dir = aux;
    
    return r;
}

int altura(Arv*r) {
   if (r == NULL) 
      return -1; // altura da árvore vazia
   else {
      int he = altura (r->esq);
      int hd = altura (r->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

// FB = HE - HD
int fator_balanciamento(Arv*r){
    
    int he = altura (r->esq);
    int hd = altura (r->dir);
    
    int fb = he - hd;
    
    return fb;
}

Arv* inserir(Arv* r, int t){
    if(r == NULL)
        return cria_arv(t);
    else{   
             
            if(t > r -> info){
              r->dir =   inserir(r->dir, t);
              return r;
             }
             
        if(t < r->info){
              r->esq =   inserir(r->esq,t);
              return r;
        }
        
        // fator balanceamento raiz
          int fat = fator_balanciamento(r);
          
          // fator balanceamento filhos
          int sinald = fator_balanciamento(r->dir);
          int sinale = fator_balanciamento(r->esq);
          
        //****************** Rotacao caso 1 ****************
          if(sinald>=1 || sinale>=1 && fat == 2 )
            rot_dir(r);
          
          if(sinald<=-1 || sinale<=-1 && fat == -2 )
             rot_esq(r);
          
        //****************** Rotacao caso 2 *****************
          
          if(sinald>=1 || sinale>=1 && fat == -2 )
            rot_dir_esq(r);
        
          if(sinald<= -1 || sinale<=-1 && fat == 2 )
            rot_esq_dir(r);
            //***********************************************

    }
}

int main(){
    Arv* t = NULL;
    Arv*aux;
    t = inserir(t,6);
    t = inserir(t,3);
    t = inserir(t,4);
    t = inserir(t,2);
    t = inserir(t,1);
   
    printf("Elementos em Ordem:\n");
    mostrarEmOrdem(t);
    printf("\nFator de balanceamento: %d", fator_balanciamento(t));
    printf("\n\nAltura da arvore: %d\n",altura(t));
    return 0;
}
