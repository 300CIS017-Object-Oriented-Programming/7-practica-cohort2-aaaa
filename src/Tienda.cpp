#include "Tienda.h"
#include <iostream>

void Tienda::agregarProducto(string codigo, string nombre, float precio, int stockInicial) {
    productos.push_back(new Producto(codigo, nombre, precio, stockInicial));
}

void Tienda::listarProductos() {
    cout << "Lista de productos:\n";
    for (auto producto : productos) {
        cout << "Codigo: " << producto->getCodigo()
             << ", Nombre: " << producto->getNombre()
             << ", Precio: " << producto->getPrecio()
             << ", Stock: " << producto->getStock() << endl;
    }
}
