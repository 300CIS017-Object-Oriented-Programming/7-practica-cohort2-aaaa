#include <iostream>
#include "Venta.h"
#include "Producto.h"
#include "Cliente.h"

using namespace std;

int main() {
    Cliente cliente1(1, "Juan Perez");  // Crear un cliente
    Venta venta1(1001, &cliente1);  // Crear una venta para ese cliente

    Producto producto1("P001", "Bolsa Biodegradable", 5.0, 50);
    Producto producto2("P002", "Botella Reutilizable", 15.0, 30);

    // Agregar productos a la venta
    venta1.agregarProductoVendido(&producto1, 2); // 2 bolsas
    venta1.agregarProductoVendido(&producto2, 1); // 1 botella

    // Mostrar el total de la venta
    cout << "El total de la venta es: $" << venta1.calcularTotal() << endl;

    return 0;
}
