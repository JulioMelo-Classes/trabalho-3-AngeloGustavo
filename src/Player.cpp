#include "Player.h"
#include "Pos.h"

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

Player::Player(){
    //movimento=0;
}
Pos Player::setFrente(Pos _atual, int dir){
    switch(dir){
        case 0:
            _atual.linha--;
            break;
        case 1:
            _atual.coluna++;
            break;
        case 2:
            _atual.linha++;
            break;
        default:
            _atual.coluna--;
    }
    return _atual;
}
Pos Player::setEsquerda(Pos _atual, int dir){
    switch(dir){
        case 0:
            _atual.coluna--;
            break;
        case 1:
            _atual.linha--;
            break;
        case 2:
            _atual.coluna++;
            break;
        default:
            _atual.linha++;
    } 
    _atual.direcao = (dir-1)%4;
    return _atual;
}
Pos Player::setDireita(Pos _atual, int dir){
    switch(dir){
        case 0:
            _atual.coluna++;
            break;
        case 1:
            _atual.linha++;
            break;
        case 2:
            _atual.coluna--;
            break;
        default:
            _atual.linha--;
    }  
    _atual.direcao = (dir+1)%4;
    return _atual;
}
void Player::printSolucao(){
    //cout<<"movimento "<<solucao.size()-movimento<<": "<<solucao[movimento-1]<<endl;
    for(int i=solucao.size()-1; i>=0; i--){
        if(i==movimento-1)
            cout<<"["<<solucao[i]<<"]";
        else
            cout<<solucao[i];
    }
    cout<<endl;
    cout<<visitado.size()<<endl;
}
void Player::clearSolucao(){
    solucao.clear();
    visitado.clear();
}
bool Player::find_solution(Pos atual, int dir, vector<string> mapa){
    int diresq, dirdir;
    diresq = dir-1;
        if(diresq<0)
            diresq=3;
    dirdir = dir+1;
        if(dirdir>3)
            dirdir=0;

    Pos frente, esquerda, direita;
    frente = setFrente(atual, dir);
    esquerda = setEsquerda(atual, dir);
    direita = setDireita(atual, dir);

    atual.direcao=dir;
    visitado.push_back(atual);
    
    if(mapa[atual.linha][atual.coluna]=='F'){
        movimento = solucao.size();
        return true;
    }//ADICIONAR mapa[frente.linha][frente.coluna] != 'o'
    else if(mapa[frente.linha][frente.coluna] != '#' && naoVisitado(frente) && find_solution(frente, dir, mapa)){
        solucao.push_back(0);
        return true;
    }
    else if(mapa[esquerda.linha][esquerda.coluna] != '#' && naoVisitado(esquerda) && find_solution(esquerda, diresq, mapa)){
        solucao.push_back(1);
        return true;
    }
    else if(mapa[direita.linha][direita.coluna] != '#' && naoVisitado(direita) && find_solution(direita, dirdir, mapa)){
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

bool Player::naoVisitado(Pos _local){
    for(auto itr=visitado.begin(); itr!=visitado.end(); itr++)
        if(itr->linha == _local.linha && itr->coluna == _local.coluna && itr->direcao == _local.direcao )
            return false;
    return true;
}