#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Venta.h"
using namespace std;

class Cliente {
private:
    int id;
    string nombre;
    vector<Venta*> compras;
public:
    Cliente(int id, string nombre);
    void agregarCompra(Venta* venta);
    void mostrarHistorialCompras();
};

#endif
