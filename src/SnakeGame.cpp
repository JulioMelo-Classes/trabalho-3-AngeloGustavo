#include "SnakeGame.h"
#include "Pos.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

using namespace std;


SnakeGame::SnakeGame(string arg1, bool arg2){
    arquivo = arg1;
    temRabo = arg2;
    cabecas = {'v','<','^','>'};
    vidas = {"","♥    ","♥♥   ","♥♥♥  ","♥♥♥♥ ", "♥♥♥♥♥"};
    lvl = 0;
    frameCount = 0;
    initialize_game();
}

void SnakeGame::initialize_game(){
    //carrega o nivel ou os níveis
    ifstream levelFile(arquivo); 
    string line;
    stringstream ss;
    if(levelFile.is_open()){
        while(getline(levelFile, line)){ //pega cada linha do arquivo
            vector<string> mapaaux;
            int linhas, colunas, comidas;
            
            ss.clear();
            ss << line;
            ss >> linhas;
            ss >> colunas;
            ss >> comidas;
            
            for(int i=0; i<linhas; i++){
                getline(levelFile, line);
                mapaaux.push_back(line);
            }
            
            Level levelaux(linhas, colunas, comidas, mapaaux);
            niveis.push_back(levelaux);
        }
    }

    state = WAITING_USER;
}

void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tiPos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha 
            choice = 2;
            cin>>std::ws>>choice;
            break;
        case RUNNING:
            if(temSolucao)
                movimento = jogador.next_move(); 
            else    
                movimento = 0;
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}
void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case WAITING_USER:
         //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita   
            if((choice >= 0 && choice <= 1 && lvl<niveis.size())||
                (choice >= 3 && choice <= 4 && lvl>0)){    
                //começo do level
                maze.clear();
                cobra.zeraTamanho();
                while(!rabo.empty())
                    rabo.pop();
                    
                switch(choice){
                    case 0:
                        cobra.setPos(niveis[lvl].getInicio().linha, niveis[lvl].getInicio().coluna);
                        break;
                    case 1:
                        cobra.setPos(niveis[lvl].espacoAleatorio().linha, niveis[lvl].espacoAleatorio().coluna);
                        break;
                    case 3:
                        lvl--;
                        cobra.setPos(niveis[lvl].getInicio().linha, niveis[lvl].getInicio().coluna);
                        break;
                    case 4:
                        lvl=0;
                        cobra.setPos(niveis[lvl].getInicio().linha, niveis[lvl].getInicio().coluna);
                        break;
                }
                
                niveis[lvl].resetLevel();
                maze = niveis[lvl].getMapa();
                maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = 'F';
                
                jogador.clearSolucao();
                temSolucao = jogador.find_solution(cobra.getPos(), maze);
                jogador.movimento = jogador.getSolucaoTam();
                                
                state = RUNNING;
            }
            else{
                state = GAME_OVER;
                game_over();
            }
            break;
        case RUNNING:            
            cobra.Move(movimento);

            if(cobra.getLinha() == niveis[lvl].getPosComida().linha && cobra.getColuna() == niveis[lvl].getPosComida().coluna){    
                maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = ' ';
                cobra.addTamanho();//Adiciona unidade a tamanho da cobra
                niveis[lvl].nextFood(jogador.getSolucaoTam());//Próxima comida e adição de pontos por sucesso
                if((niveis[lvl].getPosComida()).linha == -1){
                    lvl++;
                    state = WAITING_USER;
                }
                else{
                    maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = 'F';

                    jogador.clearSolucao();
                    temSolucao = jogador.find_solution(cobra.getPos(), maze);
                    jogador.movimento = jogador.getSolucaoTam();
                }
            }
            else if(maze[cobra.getLinha()][cobra.getColuna()]=='#' || maze[cobra.getLinha()][cobra.getColuna()]=='o'){ 
                if(niveis[lvl].getVidaRes() > 1){
                    //Reseta nivel
                    niveis[lvl].perdeuLife();
                    cobra.voltaInicio(niveis[lvl].getInicio());
                    maze = niveis[lvl].getMapa();
                    maze[ (niveis[lvl].getPosComida()).linha ][ (niveis[lvl].getPosComida()).coluna ] = 'F';

                    jogador.clearSolucao();
                    temSolucao = jogador.find_solution(cobra.getPos(), maze);
                    jogador.movimento = jogador.getSolucaoTam();

                    cobra.zeraTamanho();
                    while(!rabo.empty())
                        rabo.pop();                   
                }
                else{
                    state = WAITING_USER;
                    overstates = HIT;
                }
            }

            //atualização do rabo
            if(temRabo == true){//Desenha unidade do corpo no local passado pela cabeça da cobra
                rabo.push(cobra.getPos());
                maze[cobra.getLinha()][cobra.getColuna()]='o';
            }
            if(rabo.size()>cobra.getTamanho()+1){//Apaga unidade da trás caso não tenha comido nesse frame
                maze[(rabo.front()).linha][(rabo.front()).coluna] = ' ';
                if(((rabo.front()).linha == (niveis[lvl].getPosComida().linha))&&
                   ((rabo.front()).coluna == (niveis[lvl].getPosComida().coluna)))
                   maze[(rabo.front()).linha][(rabo.front()).coluna] = 'F';//tirar espacos de rabo]]]]]]
                rabo.pop();
            }  
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void SnakeGame::menu(){
    clearScreen();
    switch(state){
        case WAITING_USER:
            if(lvl==0){
                cout<<"------------------------------------------------------"<<endl;
                cout<<"              ---> Bem vindo ao Snaze <---"<<endl;
                cout<<"------------------------------------------------------"<<endl;
                cout<<"                  "<<niveis.size()<<" níveis carregados"<<endl;
                cout<<"                       Boa sorte!!"<<endl;
                cout<<"------------------------------------------------------"<<endl<<endl;
            }
            cout<<"======================== MENU ========================"<<endl;
            if(lvl < niveis.size()){
                cout<<"0 - Jogar nível "<<lvl+1<<"."<<endl;
                cout<<"1 - Jogar nível "<<lvl+1<<" no modo Random Start."<<endl;
            }
            if(lvl > 0){   
                cout<<"2 - Finalizar jogo."<<endl;
                cout<<"3 - Jogar nível novamente."<<endl;
                cout<<"4 - Resetar jogo."<<endl;
            }
            break;
    }
}
void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:
            //desenho do menu
            cout<<"------------------------------------------------------"<<endl;
            cout<<"                       Nível "<<lvl+1<<""<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout<<"Vidas: "<<vidas[niveis[lvl].getVidaRes()]<<" | Pontuação: "<<niveis[lvl].getScore()<<" | Maçãs comidas: "<<niveis[lvl].getJaComidas()<<" de "<<niveis[lvl].getComidaTotal()<<endl;
            cout<<"------------------------------------------------------"<<endl;
            jogador.printSolucao();   

            //desenho do labirinto
            for(int i=0; i<maze.size(); i++){
                for(int j=0; j<maze[i].size(); j++){
                    if(i==cobra.getLinha() and j==cobra.getColuna()) cout<<cabecas[cobra.getDirecao()];
                    else if(maze[i][j]=='F')
                        cout<<"●";
                    else cout<<maze[i][j];
                }
                cout<<endl;
            }
            break;
    }
    
}

void SnakeGame::game_over(){            
    clearScreen();
    switch(overstates){
        case WIN:
            cout<<"Você passou de todas as fases. Parabéns!!"<<endl;
            break;
        case HIT:
            cout<<"Parece que sua cobra bateu a cabeça. XO"<<endl;
            break;
    }
    cout<<"===================== GAME OVER ======================"<<endl;
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        menu();
        process_actions();
        render();
        update();
        wait(50);// espera 1 segundo entre cada frame
    }
}