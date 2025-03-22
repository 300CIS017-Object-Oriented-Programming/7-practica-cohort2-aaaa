#include "Tienda.h"
#include <iostream>

using namespace std;

// Agrega un nuevo producto a la tienda
void Tienda::agregarProducto(string codigo, string nombre, float precio, int stockInicial) {
    productos.push_back(new Producto(codigo, nombre, precio, stockInicial));
}

// Lista todos los productos disponibles en la tienda
void Tienda::listarProductos() {
    cout << "Lista de productos:\n";

    if (productos.empty()) {
        cout << "No hay productos en la tienda.\n";
        return;
    }

    for (int i = 0; i < productos.size(); i++) {
        cout << "Codigo: " << productos[i]->getCodigo()
             << ", Nombre: " << productos[i]->getNombre()
             << ", Precio: " << productos[i]->getPrecio()
             << ", Stock: " << productos[i]->getStock() << endl;
    }
}

// Busca un producto por su código
Producto* Tienda::buscarProducto(string codigo) {
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i]->getCodigo() == codigo) {
            return productos[i]; // Retorna el producto encontrado
        }
    }
    return nullptr; // Si no encuentra el producto, devuelve nullptr
}

// Busca un cliente por su ID
Cliente* Tienda::buscarCliente(int idCliente) {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i]->getId() == idCliente) {
            return clientes[i]; // Retorna el cliente encontrado
        }
    }
    return nullptr; // Si no encuentra el cliente, devuelve nullptr
}

// Registra una venta para un cliente
void Tienda::registrarVenta(int idCliente) {
    Cliente* cliente = buscarCliente(idCliente);
    if (cliente == nullptr) {
        cout << "Cliente no encontrado.\n";
        return;
    }

    Venta* nuevaVenta = new Venta(ventas.size() + 1, cliente);

    string codigo;
    int cantidad;

    while (true) {
        cout << "Ingrese el código del producto (o 'fin' para terminar): ";
        cin >> codigo;
        if (codigo == "fin") break;

        Producto* producto = buscarProducto(codigo);
        if (producto == nullptr) {
            cout << "Producto no encontrado.\n";
            continue;
        }

        cout << "Ingrese la cantidad: ";
        cin >> cantidad;

        if (producto->descontarStock(cantidad)) {
            nuevaVenta->agregarProductoVendido(producto, cantidad);
        } else {
            cout << "Stock insuficiente.\n";
        }
    }

    if (nuevaVenta->calcularTotal() > 0) {
        ventas.push_back(nuevaVenta);
        cliente->agregarCompra(nuevaVenta);
        cout << "Venta registrada con éxito. Total: $" << nuevaVenta->calcularTotal() << endl;
    } else {
        delete nuevaVenta; // Si no se vendió nada, se elimina la venta
        cout << "No se vendió ningún producto.\n";
    }
}

// Muestra todas las ventas realizadas
void Tienda::mostrarVentas() {
    cout << "Historial de ventas:\n";

    if (ventas.empty()) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    for (int i = 0; i < ventas.size(); i++) {
        ventas[i]->mostrarDetalleVenta();
    }
}

// Reabastece un producto en la tienda
void Tienda::reabastecerProducto(string codigoProducto, int cantidad) {
    Producto* producto = buscarProducto(codigoProducto);
    if (producto != nullptr) {
        producto->agregarStock(cantidad);
        cout << "Stock actualizado.\n";
    } else {
        cout << "Producto no encontrado.\n";
    }
}

// Calcula el valor total del inventario
float Tienda::calcularValorInventario() {
    float total = 0;
    for (int i = 0; i < productos.size(); i++) {
        total += productos[i]->getPrecio() * productos[i]->getStock();
    }
    return total;
}
