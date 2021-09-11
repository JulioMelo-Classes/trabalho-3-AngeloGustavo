# LP1 Projeto 3: Snaze

## O que é o Snaze
Uma simulação do jogo clássico Snake arcade video game, porém com a cobra presa em um labirinto.

## Organização
Os arquivos ```.cpp``` estão na pasta  **<em>src</em>**, os ```.h``` na pasta **<em>include</em>**, os scripts em **<em>data</em>** e, após criado, os arquivos de compilação em **<em>build</em>**.

## Como compilar o projeto
Na pasta do projeto realize os próximos comandos para compilar o programa com cmake.
```
mkdir build
cd build
cmake ..
cmake --build .
```

## Como executar o projeto
Após o executavel ```./snaze``` o primeiro argumento deve ser o endereço de um arquivo de texto (```.txt```) com os dados de tamanho e comidas para cada nível e os seus mapas, e o segundo é o inteiro ```1``` (modo com rabo) ou ```0``` (modo sem rabo) que remetem aos modos do snaze.
```
./snaze ../data/maze0.txt 1
```
## Execução
### Menu
Antes e depois da execução dos níveis será impresso um menu com as oções de ```0``` a ```4```, tal que, *x* é o próximo nível a ser executado.
```
================ MENU ================
0 - Jogar fase {x}.
1 - Jogar fase {x} no modo Random Start.
2 - Finalizar jogo.
3 - Jogar fase novamente.
4 - Resetar jogo.
```
OBS: As opções ```2``` a ```4``` não aparecerão anteriormente a execução do nível 1 e as opções ```0``` e ```1``` não aparecerão posteriormente ao ultimo nível.
### Nível
Durante a execução dos níveis será renderizado uma tabela com informações do nível, o mapa, a posição da cobra e a posição da comida.
```
------------------------------------------------------
                       Nível 1                
------------------------------------------------------
Vidas: ♥♥♥♥♥ | Pontuação: 50 | Maçãs comidas: 1 de 2
------------------------------------------------------
###############################
#                         o<  #
# ########################### #
#●                            #
###############################
```
### Fim
Ao fim da execução do Snaze será impresso uma tela de *Game Over*.
```
============== GAME OVER ==============
```
## Autor

Angelo Gustavo Souza Marinho Morais de Sales -
[GitHub](https://github.com/AngeloGustavo)

## Contato

Angelo Gustavo Souza Marinho Morais de Sales -
*<angelo.sales.703@ufrn.edu.br>*

Link do projeto: [https://github.com/JulioMelo-Classes/trabalho-3-AngeloGustavo.git](https://github.com/JulioMelo-Classes/trabalho-3-AngeloGustavo.git)
