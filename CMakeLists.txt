cmake_minimum_required(VERSION 3.5)
project(concordo VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .h
include_directories( include )

# Cria um executável com nome "snaze", adiciona neste executável os arquivos src/Snaze.cpp, src/SnakeGame.cpp, src/Snake.cpp, src/Player.cpp e src/Level.cpp
add_executable( snaze
                src/Snaze.cpp
                src/SnakeGame.cpp
                src/Snake.cpp
                src/Player.cpp
                src/Level.cpp)

# The end
