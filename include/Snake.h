#ifndef Snake_h
#define Snake_h

#include <vector>
#include "Pos.h"

class Snake{
    public:
        /**
        * @brief Construtor de Snake
        * 
        */
        Snake();

        /**
         * @brief Retorna linha da posição da cobra
         * 
         * @return int 
         */
        int getLinha();

        /**
         * @brief Retorna coluna da posição da cobra
         * 
         * @return int 
         */
        int getColuna();

        /**
         * @brief Retorna direção da posição da cobra
         * 
         * @return int 
         */
        int getDirecao();

        /**
         * @brief Retorna tamanho do rabo da cobra
         * 
         * @return int 
         */
        int getTamanho();

        /**
         * @brief Adiciona uma unidade ao contador do rabo
         * 
         */
        void addTamanho();

        /**
         * @brief Zera contador do rabo
         * 
         */
        void zeraTamanho();

        /**
         * @brief Seta posição de cobra
         * 
         * @param l 
         * @param c 
         */
        void setPos(int l, int c);

        /**
         * @brief Função de movimento da cobra
         * 
         * @param movimento 
         */
        void Move(int movimento);

        /**
         * @brief Reseta métodos de cobra
         * 
         * @param inicio 
         */
        void voltaInicio(Pos inicio);

        /**
         * @brief Retorna posição da cobra
         * 
         * @return Pos 
         */
        Pos getPos();
    private:
        Pos local;//<!posição da cobra
        int tamanho;//<!tamanho do rabo
};
#endif