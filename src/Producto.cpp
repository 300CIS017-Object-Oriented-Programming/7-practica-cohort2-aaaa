#include "Producto.h"

Producto::Producto(string cod, string nom, float prec, int stk)
    : codigo(cod), nombre(nom), precio(prec), stock(stk) {}

bool Producto::descontarStock(int cantidad) {
    if (cantidad > stock) {
        return false;
    }
    stock -= cantidad;
    return true;
}

void Producto::agregarStock(int cantidad) {
    stock += cantidad;
}

string Producto::getCodigo() const { return codigo; }
string Producto::getNombre() const { return nombre; }
float Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }

