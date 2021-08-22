#include "Player.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

Posicao Player::setFrente(int l, int c, int dir){
    Posicao saida;
    switch(dir){
        case 0:
            saida.linha = l-1;
            saida.coluna = c;
            break;
        case 1:
            saida.linha = l;
            saida.coluna = c+1;
            break;
        case 2:
            saida.linha = l+1;
            saida.coluna = c;
            break;
        default:
            saida.linha = l;
            saida.coluna = c-1;
    }
    return saida;
}
Posicao Player::setEsquerda(int l, int c, int dir){
    Posicao saida;
    switch(dir){
        case 0:
            saida.linha = l;
            saida.coluna = c-1;
            break;
        case 1:
            saida.linha = l-1;
            saida.coluna = c;
            break;
        case 2:
            saida.linha = l;
            saida.coluna = c+1;
            break;
        default:
            saida.linha = l+1;
            saida.coluna = c;
    }
    return saida;    
}
Posicao Player::setDireita(int l, int c, int dir){
    Posicao saida;
    switch(dir){
        case 0:
            saida.linha = l;
            saida.coluna = c+1;
            break;
        case 1:
            saida.linha = l+1;
            saida.coluna = c;
            break;
        case 2:
            saida.linha = l;
            saida.coluna = c-1;
            break;
        default:
            saida.linha = l-1;
            saida.coluna = c;
    }
    return saida;   
}
void Player::setPos(int l, int c){
    atual.linha = l;
    atual.coluna = c;
}
void Player::setDir(int dir){
    direcao = dir;
}
Player::Player(){
    movimento=0;
}
bool Player::find_solution(vector<string> mapa){
    Posicao frente,esquerda,direita;    
    for(int i=0; i<9; i++){
        frente = setFrente(atual.linha,atual.coluna,direcao);
        direita = setDireita(atual.linha,atual.coluna,direcao);
        esquerda = setEsquerda(atual.linha,atual.coluna,direcao);
        
        if(mapa[frente.linha][frente.coluna] == ' '){
            solucao.push_back(0);
        }
        else if(mapa[esquerda.linha][esquerda.coluna] == ' '){
            solucao.push_back(1);
            direcao--;
            if(direcao<0)
                direcao=3;
        }
        else if(mapa[direita.linha][direita.coluna] == ' '){
            solucao.push_back(2);
            direcao++;
            if(direcao>3)
                direcao=0;
        }
        else
            return false;

        atual = setFrente(atual.linha, atual.coluna, direcao);        
    }
    return true;
}
int Player::next_move(){
    movimento++;
    return solucao[movimento-1];
}

using namespace std;