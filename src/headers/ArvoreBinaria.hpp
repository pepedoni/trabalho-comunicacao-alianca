#ifndef ARVORE_BINARIA_HPP
#define ARVORE_BINARIA_HPP

#include "TipoItem.hpp"
#include "TipoNo.hpp"

class ArvoreBinaria
{
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();
        void Insere(TipoItem item);
        void Caminha(int tipo);
        void Limpa();
        void Encripta(std::string pn);
        void Decripta(int posDesejada);
        void SubstituirItem(std::string pAntiga, std::string pNova);
    private:
        void InsereRecursivo(TipoNo* &p, TipoItem item);
        void ApagaRecursivo(TipoNo* p);
        void PorNivel();
        bool EncriptaPreOrdem(TipoNo* p, int *i, std::string pn);
        bool DecriptaPreOrdem(TipoNo* p, int *posAtual, int posDesejada);
        void RemoveRecursivo(TipoNo* &no, std::string pn);
        void Remove(std::string pn);
        void Antecessor(TipoNo *q, TipoNo* &r);
        TipoNo *raiz;
};
#endif