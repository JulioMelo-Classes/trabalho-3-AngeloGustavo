#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Player.h"
#include "Level.h"

class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING, //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER, //<! quando o jogador para antes do fim
            WAITING_USER //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
        };
        enum OverCauses{
            WIN, //<! quando o jogador passa de todas as fases
            HIT //<! quando a cobra bate a cabeça ou na parede ou no próprio rabo
        };

    private:
        Snake cobra;
        Player jogador;
        //<! atributos adicione outros se quiser
        std::vector<std::string> maze; //<! vector contendo o labirinto atual, pode ser interpretado como uma matriz
        int frameCount; //<! contador de frames, usado apenas como exemplo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo
        OverCauses overstates;  //<! guarda o estado pós fim do jogo 

        std::vector<Level> niveis;//niveis
        int lvl;//nivel atual
        vector<char> cabecas;//animacao da cabeca
        bool temRabo;//diz se a cobra é com ou sem rabo
        string arquivo;//string do arquivo de mapa e dados

    public:
        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame(bool arg1, string arg2);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

        void print_placar();

    private:
        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game();

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h