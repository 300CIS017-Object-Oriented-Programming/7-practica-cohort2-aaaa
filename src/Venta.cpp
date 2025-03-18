#include "Venta.h"
#include "Cliente.h"
#include <iostream>

Venta::Venta(int id, Cliente* cliente) : id(id), cliente(cliente) {}

void Venta::agregarProductoVendido(Producto* producto, int cantidad) {
    productosVendidos.push_back(make_pair(producto, cantidad));
}

float Venta::calcularTotal() {

    }


void Venta::mostrarDetalleVenta() {

}

