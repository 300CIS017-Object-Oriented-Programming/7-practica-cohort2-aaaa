cmake_minimum_required(VERSION 3.30)
project(TiendaEcologica_)

set(CMAKE_CXX_STANDARD 20)


add_executable(TiendaEcologica_
        src/main.cpp
        src/Producto.cpp
        src/Cliente.cpp
        src/Venta.cpp
        src/Tienda.cpp
)
