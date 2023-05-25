cmake_minimum_required(VERSION 3.19)
project(TPPOO)

set(CMAKE_CXX_STANDARD 14)

add_executable(TPPOO
        main.cpp
        cpp/utils.cpp
        headers/utils.h
        cpp/engine.cpp
        headers/engine.h
        cpp/interface.cpp
        headers/interface.h
        cpp/ilha.cpp
        headers/ilha.h
        cpp/Edificio.cpp
        headers/Edificio.h
        cpp/Trabalhador.cpp
        headers/Trabalhador.h
        cpp/Zona.cpp
        headers/Zona.h
        comandos.txt
        ficheiroConfig.txt)