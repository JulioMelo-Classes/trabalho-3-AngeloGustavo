#include "Player.h"
#include "Pos.h"

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

Pos Player::setFrente(Pos atual){
    switch(atual.direcao){
        case 0:
            atual.linha--;
            break;
        case 1:
            atual.coluna++;
            break;
        case 2:
            atual.linha++;
            break;
        default:
            atual.coluna--;
    }
    return atual;
}
Pos Player::setEsquerda(Pos atual){
    switch(atual.direcao){
        case 0:
            atual.coluna--;
            break;
        case 1:
            atual.linha--;
            break;
        case 2:
            atual.coluna++;
            break;
        default:
            atual.linha++;
    } 
    atual.direcao = (((atual.direcao-1)%4)+4)%4;
    return atual;
}
Pos Player::setDireita(Pos atual){
    switch(atual.direcao){
        case 0:
            atual.coluna++;
            break;
        case 1:
            atual.linha++;
            break;
        case 2:
            atual.coluna--;
            break;
        default:
            atual.linha--;
    }  
    atual.direcao = (atual.direcao+1)%4;
    return atual;
}
void Player::clearSolucao(){
    solucao.clear();
    visitado.clear();
}
bool Player::find_solution(Pos atual, vector<string> mapa){
    Pos frente, esquerda, direita;
    frente = setFrente(atual);
    esquerda = setEsquerda(atual);
    direita = setDireita(atual);

    visitado.push_back(atual);
    
    if(mapa[atual.linha][atual.coluna]=='F'){
        movimento = solucao.size();
        return true;
    }
    else if(mapa[frente.linha][frente.coluna] != '#' && naoVisitado(frente) && find_solution(frente, mapa)){
        solucao.push_back(0);
        return true;
    }
    else if(mapa[esquerda.linha][esquerda.coluna] != '#' && naoVisitado(esquerda) && find_solution(esquerda, mapa)){
        solucao.push_back(1);
        return true;
    }
    else if(mapa[direita.linha][direita.coluna] != '#' && naoVisitado(direita) && find_solution(direita,  mapa)){
        solucao.push_back(2);
        return true;
    }
    visitado.pop_back();
    return false;
}
int Player::next_move(){
    movimento--;
    return solucao[movimento];
}

int Player::getSolucaoTam(){
    return solucao.size();
}
void Player::setMovimento(){
    movimento = getSolucaoTam();
}
bool Player::naoVisitado(Pos local){
    for(auto itr=visitado.begin(); itr!=visitado.end(); itr++)
        if(itr->linha == local.linha && itr->coluna == local.coluna && itr->direcao == local.direcao )
            return false;
    return true;
}