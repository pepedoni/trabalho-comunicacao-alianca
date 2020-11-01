#ifndef TIPO_ITEM_HPP
#define TIPO_ITEM_HPP
#include "string.h"
#include <iostream>
typedef int TipoChave;

class TipoItem
{
    public:
        TipoItem();
        TipoItem(std::string p);
        ~TipoItem(){};
        void SetPalavra(std::string p);
        int ComparaPalavra(std::string p2);
        std::string GetPalavra();
        void Imprime();
    private:
        std::string palavra;
};
#endif