    class Producto {
        - string codigo
        - string nombre
        - float precio
        - int stock
        + bool descontarStock(int cantidad)
        + void agregarStock(int cantidad)
    }

    class Cliente {
        - int id
        - string nombre
        - vector<Venta*> compras
        + void agregarCompra(Venta* venta)
        + void mostrarHistorialCompras()
    }

    class Venta {
        - int id
        - Cliente* cliente
        - vector<pair<Producto*, int>> productosVendidos
        + Venta(Cliente* cliente)
        + void agregarProductoVendido(Producto* producto, int cantidad)
        + float calcularTotal()
        + void mostrarDetalleVenta()
    }

    class Tienda {
        - vector<Producto*> productos
        - vector<Cliente*> clientes
        - vector<Venta*> ventas
        + void agregarProducto(string codigo, string nombre, float precio, int stockInicial)
        + void registrarVenta(int idCliente)
        + void reabastecerProducto(string codigoProducto, int cantidad)
        + Producto* buscarProducto(string codigo)
        + Cliente* buscarCliente(int idCliente)
        + void listarProductos()
        + void mostrarVentas()
        + float calcularValorInventario()
    }

    Cliente --> Venta : realiza
    Venta --> Producto : contiene
    Tienda --> Producto : gestiona
    Tienda --> Cliente : registra
    Tienda --> Venta : administra
