#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include <utility>
#include "Producto.h"
using namespace std;

class Cliente;

class Venta {
private:
    int id;
    Cliente* cliente;
    vector<pair<Producto*, int>> productosVendidos;
public:
    Venta(int id, Cliente* cliente);
    void agregarProductoVendido(Producto* producto, int cantidad);
    float calcularTotal();
    void mostrarDetalleVenta();
};

#endif
