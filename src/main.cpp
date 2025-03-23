#include <iostream>
#include "Tienda.h"

using namespace std;

void mostrarMenu(Tienda &tienda) {
    int opcion;
    string codigo, nombre; // Mover la declaración aquí
    int cantidad, idCliente;
    float precio;

    do {
        cout << "\n===== MENÚ DE LA TIENDA =====\n";
        cout << "1. Agregar producto\n";
        cout << "2. Listar productos\n";
        cout << "3. Registrar venta\n";
        cout << "4. Mostrar ventas\n";
        cout << "5. Calcular valor del inventario\n";
        cout << "6. Reabastecer producto\n";
        cout << "7. Salir\n";
        cout << "=============================\n";
        cout << "Seleccione una opción: ";

        cin >> opcion;

        while (cin.fail()) {  // Validación en caso de que el usuario ingrese texto
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida. Intente de nuevo: ";
            cin >> opcion;
        }

        switch (opcion) {
            case 1:
                cout << "Ingrese código del producto: ";
                cin >> codigo;
                cout << "Ingrese nombre del producto: ";
                cin.ignore(); // Para evitar problemas con getline()
                getline(cin, nombre);
                cout << "Ingrese precio: ";
                cin >> precio;
                cout << "Ingrese stock inicial: ";
                cin >> cantidad;
                tienda.agregarProducto(codigo, nombre, precio, cantidad);
                cout << "Producto agregado correctamente.\n";
                break;

            case 2:
                tienda.listarProductos();
                break;

            case 3:
                cout << "Ingrese el ID del cliente: ";
                cin >> idCliente;
                tienda.registrarVenta(idCliente);
                break;

            case 4:
                tienda.mostrarVentas();
                break;

            case 5:
                cout << "Valor total del inventario: $" << tienda.calcularValorInventario() << endl;
                break;

            case 6:
                cout << "Ingrese código del producto a reabastecer: ";
                cin >> codigo;
                cout << "Ingrese cantidad: ";
                cin >> cantidad;
                tienda.reabastecerProducto(codigo, cantidad);
                break;

            case 7:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 7);
}

int main() {
    Tienda tienda;  // Se crea la tienda
    mostrarMenu(tienda);
    cout << "\nMemoria liberada correctamente. Fin del programa.\n"; // Mensaje para verificar que todo se cerró bien
    return 0;
}
