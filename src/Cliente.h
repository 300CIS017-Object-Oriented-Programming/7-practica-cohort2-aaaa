#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Venta.h"  // Asegurar que se incluye Venta.h

using namespace std;

class Cliente {
private:
    int id;
    string nombre;
    vector<Venta*> compras;

public:
    Cliente(int id, string nombre);
    ~Cliente(); // Destructor para liberar memoria de las compras
    void agregarCompra(Venta* venta);
    void mostrarHistorialCompras();

    // Métodos necesarios para evitar errores
    int getId();       // Devuelve el ID del cliente
    string getNombre(); // Devuelve el nombre del cliente
};

#endif // CLIENTE_H
