#include "TipoItem.hpp"
#include <iostream>
#include "string.h"
#include <iostream>

TipoItem::TipoItem() {}

TipoItem::TipoItem( std::string p){
    palavra = p;
}

void TipoItem::SetPalavra(std::string p){
    palavra = p;
}

std::string TipoItem::GetPalavra() {
    return palavra;
}

int TipoItem::ComparaPalavra(std::string p2) {
    std::size_t lenght = palavra.length();
    if(p2.length() < lenght) {
        lenght = p2.length();
    }
    for(std::size_t i = 0; i < lenght; i++) {
        if(palavra[i] < p2[i]) {
            return -1;
        } else if(palavra[i] > p2[i]) {
            return 1;
        } 
    }
    if(palavra.length() < p2.length()) {
        return -1;
    } else if(palavra.length() > p2.length()) {
        return 1;
    } 
    return 0;
}

void TipoItem::Imprime() {
    std::cout << GetPalavra();
}
