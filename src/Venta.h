#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include "Producto.h"  // Necesitamos usar la clase Producto

using namespace std;

class Cliente; // Para que no haya errores de referencia circular

class Venta {
private:
    int id;  // Identificación de la venta
    Cliente* cliente;  // Cliente que hizo la compra
    vector<pair<Producto*, int>> listaDeProductos; // Lista de productos y cantidades

public:
    Venta(int id, Cliente* cliente);  // Constructor
    ~Venta();  // Destructor para limpiar la lista de productos vendidos

    void agregarProductoVendido(Producto* producto, int cantidad); // Agregar producto a la venta
    float calcularTotal(); // Método para calcular el total de la venta
    void mostrarDetalleVenta(); // Muestra información de la venta
};

#endif
