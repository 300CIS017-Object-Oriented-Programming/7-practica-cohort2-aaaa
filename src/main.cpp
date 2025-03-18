#include <iostream>
#include "Tienda.h"

using namespace std;

int main() {
    Tienda tienda;

    tienda.agregarProducto("P001", "Bolsa Biodegradable", 5.0, 50);
    tienda.agregarProducto("P002", "Botella Reutilizable", 15.0, 30);

    cout << "Bienvenido a la Tienda Ecologica" << endl;
    tienda.listarProductos();

    return 0;
}
