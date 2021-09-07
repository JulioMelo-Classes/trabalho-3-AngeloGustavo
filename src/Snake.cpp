#include "Snake.h"

#include <iostream>

using namespace std;

Snake::Snake(){
    direcao = 0;
    tamanho = 0;
}
Pos Snake::getPos(){
    Pos aux;
    aux.linha = linha;
    aux.coluna = coluna;
    return aux;
}
int Snake::getLinha(){
    return linha;
}
int Snake::getColuna(){
    return coluna;
}
int Snake::getDirecao(){
    return direcao;
}
int Snake::getTamanho(){
    return tamanho;
}
void Snake::zeraTamanho(){
    tamanho = 0;
}
void Snake::setTamanho(int t){
    tamanho = t;
}
void Snake::addTamanho(){
    tamanho ++;
}
void Snake::setPos(int l, int c){
    linha = l;
    coluna = c;
}
void Snake::turnLeft(){
    direcao--;
    if(direcao<0)
        direcao = 3;
}
void Snake::turnRight(){
    direcao++;
    if(direcao>3)
        direcao = 0;
}
void Snake::Move(int movimento){
    if(movimento == 1)
        turnLeft();
        //direcao = (direcao - 1)%4;

    else if(movimento == 2)
        turnRight();
        //direcao = (direcao + 1)%4;

    switch(direcao){
        case 0:
            linha--;
            break;
        case 1:
            coluna++;
            break;
        case 2:
            linha++;
            break;
        default:
            coluna--;
    }
}
void Snake::voltaInicio(Pos inicio){
    linha = inicio.linha;
    coluna = inicio.coluna;
    direcao = 0;
}