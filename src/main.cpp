#include <cstdio> // em C substituir por #include <stdio.h>
#include <iostream>
#include "headers/TipoItem.hpp"
#include "headers/TipoNo.hpp"
#include "headers/ArvoreBinaria.hpp" 
#include "string.h"

using namespace std;

int main() {
  ArvoreBinaria* a = new ArvoreBinaria();

  char operacao;
  int nPalavras = 0;
  string palavra;
  string palavra2;
  while(scanf("%c", &operacao) != EOF){
    if(operacao == 'i'){
        cin >> palavra; 
        TipoItem t = TipoItem(palavra);
        a->Insere(t);
    } else if(operacao == 's') {
        cin >> palavra;
        cin >> palavra2;
        a->SubstituirItem(palavra, palavra2);
    } else if(operacao == 'e') {
        cin >> nPalavras;
        string palavras[nPalavras];
        for(int i = 0; i < nPalavras; i++){
          cin >> palavras[i];
          a->Encripta(palavras[i]);
          if(i != (nPalavras -1)) {
            cout << " ";
          } else {
            cout << "\n";
          }
        }
    } else if(operacao == 'd') {
        cin >> nPalavras;
        int palavrasDecriptar[nPalavras];
        for(int i = 0; i < nPalavras; i++){
          cin >> palavrasDecriptar[i];
          a->Decripta(palavrasDecriptar[i]);
          if(i != (nPalavras -1)) {
            cout << " ";
          } else {
            cout << "\n";
          }
        }
    }
  }
  return 0;
}
