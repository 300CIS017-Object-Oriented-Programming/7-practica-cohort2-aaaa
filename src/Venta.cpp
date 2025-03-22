#include "Venta.h"
#include "Cliente.h"
#include <iostream>

using namespace std;

// Constructor que inicializa la venta con un ID y un cliente
Venta::Venta(int id, Cliente* cliente) {
    this->id = id;
    this->cliente = cliente;
}

// Método para agregar productos a la venta
void Venta::agregarProductoVendido(Producto* producto, int cantidad) {
    listaDeProductos.push_back(make_pair(producto, cantidad));
}

// Método que calcula el total de la venta sumando los precios de los productos
float Venta::calcularTotal() {
    float total = 0; // Inicializar total en 0

    // Recorremos la lista de productos vendidos
    for (int i = 0; i < listaDeProductos.size(); i++) {
        Producto* prod = listaDeProductos[i].first; // Obtenemos el producto
        int cant = listaDeProductos[i].second;      // Obtenemos la cantidad
        total = total + (prod->getPrecio() * cant); // Sumamos al total
    }

    return total; // Devolvemos el total de la venta
}


