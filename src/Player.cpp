#include "Player.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

Player::Player(){
    //movimento=0;
}
Posicao Player::setFrente(Posicao _atual, int dir){
    Posicao aux;
    switch(dir){
        case 0:
            aux.linha = _atual.linha-1;
            aux.coluna = _atual.coluna;
            break;
        case 1:
            aux.linha = _atual.linha;
            aux.coluna = _atual.coluna+1;
            break;
        case 2:
            aux.linha = _atual.linha+1;
            aux.coluna = _atual.coluna;
            break;
        default:
            aux.linha = _atual.linha;
            aux.coluna = _atual.coluna-1;
    }
    return aux;
}
Posicao Player::setEsquerda(Posicao _atual, int dir){
    Posicao aux;
    switch(dir){
        case 0:
            aux.linha = _atual.linha;
            aux.coluna = _atual.coluna-1;
            break;
        case 1:
            aux.linha = _atual.linha-1;
            aux.coluna = _atual.coluna;
            break;
        case 2:
            aux.linha = _atual.linha;
            aux.coluna = _atual.coluna+1;
            break;
        default:
            aux.linha = _atual.linha+1;
            aux.coluna = _atual.coluna;
    } 
    return aux;
}
Posicao Player::setDireita(Posicao _atual, int dir){
    Posicao aux;
    switch(dir){
        case 0:
            aux.linha = _atual.linha;
            aux.coluna = _atual.coluna+1;
            break;
        case 1:
            aux.linha = _atual.linha+1;
            aux.coluna = _atual.coluna;
            break;
        case 2:
            aux.linha = _atual.linha;
            aux.coluna = _atual.coluna-1;
            break;
        default:
            aux.linha = _atual.linha-1;
            aux.coluna = _atual.coluna;
    }  
    return aux;
}
int Player::next_move(int linha, int coluna, int direcao, vector<string> mapa){
    Posicao frente, esquerda, direita;
    Posicao aux;
    aux.linha = linha;
    aux.coluna = coluna;

    frente = setFrente(aux, direcao);
    esquerda = setEsquerda(aux, direcao);
    direita = setDireita(aux, direcao);

    if(mapa[frente.linha][frente.coluna] == ' ')
        return 0;
    else if(mapa[esquerda.linha][esquerda.coluna] == ' ')
        return 1;
    else if(mapa[direita.linha][direita.coluna] == ' ')
        return 2;
    else    
        return 0;
    /*Checkpoint 2
    movimento++; 
    return solucao[movimento-1];*/
}
/*Checkpoint 2
bool Player::naoVisitado(Posicao local){
    for(int i=0; i<visitado.size(); i++)
        if(visitado[i].linha==local.linha && visitado[i].coluna==local.coluna)
            return false;
    return true;
}
bool Player::find_solution(int l, int c, int dir, vector<string> mapa, int flinha, int fcoluna){    
    Posicao frente, esquerda, direita;
    Posicao atual;
    atual.linha=l;
    atual.coluna=c;
    bool aux;
    int diraux;

    frente = setFrente(atual, dir);
    esquerda = setEsquerda(atual, dir);
    direita = setDireita(atual, dir);
    if(solucao.size()>0)
        cout<<solucao[solucao.size()-1];

    if(l==flinha && c==fcoluna)
        return true;
    else if(mapa[frente.linha][frente.coluna] != '#' && naoVisitado(frente)){
        visitado.push_back(frente);
        solucao.push_back(0);

        if(find_solution(frente.linha, frente.coluna, dir, mapa, flinha, fcoluna)){
            //solucao.push_back(0);
            return true;
        }
        solucao.pop_back();
        return false;
    }   
    else if(mapa[esquerda.linha][esquerda.coluna] != '#' && naoVisitado(esquerda)){
        visitado.push_back(esquerda);
        solucao.push_back(1);
        
        diraux = dir-1;
        if(diraux<0)
            diraux=3;

        if(find_solution(esquerda.linha, esquerda.coluna, diraux, mapa, flinha, fcoluna)){
            //solucao.push_back(1);
            return true;
        }
        solucao.pop_back();
        return false;
    }   
    else if(mapa[direita.linha][direita.coluna] != '#' && naoVisitado(direita)){
        visitado.push_back(direita);
        solucao.push_back(2);

        diraux = dir+1;
        if(diraux>3)
            diraux=0;

        if(find_solution(direita.linha, direita.coluna, diraux, mapa, flinha, fcoluna)){
            //solucao.push_back(2);
            return true;
        }
        solucao.pop_back();
        return false;
    }   
    return false;
}*/