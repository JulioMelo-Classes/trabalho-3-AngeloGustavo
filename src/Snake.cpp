#include "Snake.h"

#include <iostream>

using namespace std;

Snake::Snake(){
    local.direcao = 0; 
    tamanho = 0;
}
Pos Snake::getPos(){
    return local;
}
int Snake::getLinha(){
    return local.linha;
}
int Snake::getColuna(){
    return local.coluna;
}
int Snake::getDirecao(){
    return local.direcao;
}
int Snake::getTamanho(){
    return tamanho;
}
void Snake::zeraTamanho(){
    tamanho = 0;
}
void Snake::addTamanho(){
    tamanho ++;
}
void Snake::setPos(int l, int c){
    local.linha = l;
    local.coluna = c;
}
void Snake::Move(int movimento){
    int aux;
    if(movimento == 1)
        local.direcao = (((local.direcao - 1) %4) +4) %4;
    
    else if(movimento == 2)
        local.direcao = (local.direcao + 1) %4;
    
    switch(local.direcao){
        case 0:
            local.linha--;
            break;
        case 1:
            local.coluna++;
            break;
        case 2:
            local.linha++;
            break;
        default:
            local.coluna--;
    }
}
void Snake::voltaInicio(Pos inicio){
    local.linha = inicio.linha;
    local.coluna = inicio.coluna;
    local.direcao = 0;
}