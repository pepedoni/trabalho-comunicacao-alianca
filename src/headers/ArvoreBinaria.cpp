#include "TipoNo.hpp"
#include "ArvoreBinaria.hpp"
#include <cstddef>
#include <stdio.h>
#include <string.h>

ArvoreBinaria::ArvoreBinaria(){
    raiz = NULL;
}

ArvoreBinaria::~ArvoreBinaria(){
    Limpa();
}

void ArvoreBinaria::Insere(TipoItem item){
    InsereRecursivo(raiz,item);
}

void ArvoreBinaria::Encripta(std::string p) {
    int pos = 0;
    EncriptaPreOrdem(raiz, &pos, p);
}

void ArvoreBinaria::Decripta(int posDesejada) {
    int posAtual = 0;
    DecriptaPreOrdem(raiz, &posAtual, posDesejada);
}

void ArvoreBinaria::SubstituirItem(std::string pAntiga, std::string pNova) {
    Remove(pAntiga);
    TipoItem t = TipoItem(pNova);
    Insere(pNova);
}

void ArvoreBinaria::Antecessor(TipoNo *q, TipoNo* &r){
    if(r->dir != NULL) {
        Antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}

void ArvoreBinaria::Remove(std::string pn) {
    RemoveRecursivo(raiz, pn);
}

void ArvoreBinaria::RemoveRecursivo(TipoNo* &no, std::string pn){
    TipoNo *aux;
    if (no == NULL) {
        throw("Item nao está presente");
    }
    if(no->item.ComparaPalavra(pn) > 0)
        return RemoveRecursivo(no->esq, pn);
    else if(no->item.ComparaPalavra(pn) < 0)
        return RemoveRecursivo(no->dir, pn);
    else {
        if (no->dir == NULL) {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if(no->esq == NULL) {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else {
            Antecessor(no, no->esq);
        }
    }
}


void ArvoreBinaria::InsereRecursivo(TipoNo* &p, TipoItem item){
    if(p == NULL){
        p = new TipoNo();
        p->item = item;
    }
    else{
        if(item.ComparaPalavra(p->item.GetPalavra()) < 0) {
            InsereRecursivo(p->esq, item);
        }
        else {
            InsereRecursivo(p->dir, item);
        }
    }
}

bool ArvoreBinaria::EncriptaPreOrdem(TipoNo* p, int *pos, std::string pn){
    bool find = false;
    if(p!=NULL){
        *pos += 1;
        if(p->item.GetPalavra() == pn) {
            std::cout << *pos;
            return true;
        } else {
            find = EncriptaPreOrdem(p->esq, pos, pn);
            if(find == false) {
                find = EncriptaPreOrdem(p->dir, pos, pn);
            } 
            return find;
        }
    }
    return find;
}

bool ArvoreBinaria::DecriptaPreOrdem(TipoNo* p, int *posAtual, int posDesejada){
    bool find = false;
    if(p!=NULL){
        *posAtual += 1;
        if(*posAtual == posDesejada) {
            std::cout << p->item.GetPalavra();
            return true;
        } else {
            find = DecriptaPreOrdem(p->esq, posAtual, posDesejada);
            if(find == false) {
                find = DecriptaPreOrdem(p->dir, posAtual, posDesejada);
            } 
            return find;
        }
    }
    return find;
}

void ArvoreBinaria::Limpa(){
    ApagaRecursivo(raiz);
    raiz = NULL;
}
void ArvoreBinaria::ApagaRecursivo(TipoNo *p){
    if(p!=NULL){
        ApagaRecursivo(p->esq);
        ApagaRecursivo(p->dir);
        delete p;
    }
}