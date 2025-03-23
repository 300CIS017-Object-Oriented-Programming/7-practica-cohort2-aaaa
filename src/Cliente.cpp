#include "Cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente(int id, string nombre) : id(id), nombre(nombre) {}

// Destructor para liberar memoria de las compras
Cliente::~Cliente() {
    for (int i = 0; i < compras.size(); i++) {
        delete compras[i]; // Liberar memoria de cada venta almacenada
    }
}

// Devuelve el ID del cliente
int Cliente::getId() {
    return id;
}

// Devuelve el nombre del cliente
string Cliente::getNombre() {
    return nombre;
}

// Agrega una venta al historial de compras del cliente
void Cliente::agregarCompra(Venta* venta) {
    compras.push_back(venta); // Se guarda la venta en el historial
}

// Muestra todas las compras realizadas por el cliente
void Cliente::mostrarHistorialCompras() {
    cout << "Historial de compras de " << nombre << ":" << endl;

    if (compras.empty()) {
        cout << "No hay compras registradas." << endl;
        return;
    }

    for (int i = 0; i < compras.size(); i++) {
        compras[i]->mostrarDetalleVenta(); // Llama al método que muestra los detalles de la venta
    }
}
