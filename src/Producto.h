#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
using namespace std;

class Producto {
private:
    string codigo;
    string nombre;
    float precio;
    int stock;
public:
    Producto(string cod, string nom, float prec, int stk);
    bool descontarStock(int cantidad);
    void agregarStock(int cantidad);
    string getCodigo() const;
    string getNombre() const;
    float getPrecio() const;
    int getStock() const;
};

#endif

