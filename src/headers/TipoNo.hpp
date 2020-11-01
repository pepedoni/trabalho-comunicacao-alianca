#ifndef TIPO_NO_HPP
#define TIPO_NO_HPP
#include "TipoItem.hpp"

class TipoNo
{
    public:
        TipoNo();
    private:
        TipoItem item;
        TipoNo *esq;
        TipoNo *dir;
        friend class ArvoreBinaria;
};
#endif