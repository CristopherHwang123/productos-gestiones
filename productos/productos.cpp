#include <iostream>
#include <vector>
using namespace std;
class Producto {
private:
	string nombre;
	int codigo;
	float precio;
	int stock;
public:
	Producto(string nom, int cod, float prec, int stk) {
		nombre = nom;
		codigo = cod;
		precio = prec;
		stock = stk;
	}
	void mostrar() {
		cout << "Código: " << codigo << ", Producto: " << nombre
			<< ", Precio: Q" << precio << ", Stock: " << stock << endl;
	}
	int obtenerCodigo() {
		return codigo;
	}
	int obtenerStock() {
		return stock;
	}
	void actualizarStock(int cantidad) {
		if (cantidad > stock) {
			cout << "No hay suficiente stock disponible." << endl;
		}
		else {
			stock -= cantidad;
			cout << "Stock actualizado. Nuevo stock: " << stock << endl;
		}
	}
	float obtenerValor() {
		return stock * precio;
	}
};

//*************************************************************************************************************

void agregarProducto(vector<Producto>& inventario) {
	string nombre;
	int codigo, stock;
	float precio;
	cout << "Ingrese el nombre del producto: ";
	cin >> ws; // Limpia el buffer de entrada
	getline(cin, nombre);
	cout << "Ingrese el código: ";
	cin >> codigo;
	cout << "Ingrese el precio: ";
	cin >> precio;
	cout << "Ingrese la cantidad en stock: ";
	cin >> stock;
	inventario.push_back(Producto(nombre, codigo, precio, stock));
}
void mostrarInventario(vector<Producto>& inventario) {
	if (inventario.empty()) {
		cout << "No hay productos en el inventario." << endl;
		return;
	}
	for (Producto& producto : inventario) {
		producto.mostrar();
	}
}
void buscarProducto(vector<Producto>& inventario) {
	int codigo;
	cout << "Ingrese el código del producto a buscar: ";
	cin >> codigo;
	for (Producto& producto : inventario) {
		if (producto.obtenerCodigo() == codigo) {
			cout << "Producto encontrado: ";
			producto.mostrar();
			return;
		}
	}
	cout << "Producto no encontrado." << endl;
}
void actualizarStock(vector<Producto>& inventario) {
	int codigo, cantidad;
	cout << "Ingrese el código del producto a actualizar: ";
	cin >> codigo;
	for (Producto& producto : inventario) {
		if (producto.obtenerCodigo() == codigo) {
			cout << "Ingrese la cantidad a restar del stock: ";
			cin >> cantidad;
			producto.actualizarStock(cantidad);
			return;
		}
	}
	cout << "Producto no encontrado." << endl;
}
void calcularValorTotal(vector<Producto>& inventario) {
	float total = 0;
	for (Producto& producto : inventario) {
		total += producto.obtenerValor();
	}
	cout << "Valor total del inventario: Q" << total << endl;
}

//**********************************************************************************************************arreglado
#include <iostream>
#include <vector>
#include <limits> // Para limpiar el buffer en caso de error
#include <iomanip> // Para mejorar la precisión en la salida

using namespace std;

class Producto {
private:
    string nombre;
    int codigo;
    float precio;
    int stock;
public:
    Producto(string nom, int cod, float prec, int stk) {
        nombre = nom;
        codigo = cod;
        precio = prec;
        stock = stk;
    }
    void mostrar() {
        cout << fixed << setprecision(2); // Formato para dos decimales
        cout << "Código: " << codigo << ", Producto: " << nombre
            << ", Precio: Q" << precio << ", Stock: " << stock << endl;
    }
    int obtenerCodigo() {
        return codigo;
    }
    int obtenerStock() {
        return stock;
    }
    void actualizarStock(int cantidad) {
        if (cantidad <= 0) {
            cout << "Error: La cantidad debe ser mayor que 0." << endl;
            return;
        }
        if (cantidad > stock) {
            cout << "No hay suficiente stock disponible." << endl;
        }
        else {
            stock -= cantidad;
            cout << "Stock actualizado. Nuevo stock: " << stock << endl;
        }
    }
    float obtenerValor() {
        return stock * precio;
    }
};


void limpiarBuffer() {
    cin.clear(); // Limpia errores
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta entrada incorrecta
}

void agregarProducto(vector<Producto>& inventario) {
    string nombre;
    int codigo, stock;
    float precio;

    cout << "Ingrese el nombre del producto: ";
    cin.ignore(); // Asegurar que no haya basura en el buffer
    getline(cin, nombre);

    cout << "Ingrese el código: ";
    while (!(cin >> codigo)) {
        cout << "Error: Ingrese un número válido para el código: ";
        limpiarBuffer();
    }

    cout << "Ingrese el precio: ";
    while (!(cin >> precio) || precio < 0) {
        cout << "Error: Ingrese un precio válido: ";
        limpiarBuffer();
    }

    cout << "Ingrese la cantidad en stock: ";
    while (!(cin >> stock) || stock < 0) {
        cout << "Error: Ingrese una cantidad válida en stock: ";
        limpiarBuffer();
    }

    inventario.push_back(Producto(nombre, codigo, precio, stock));
}

void mostrarInventario(vector<Producto>& inventario) {
    if (inventario.empty()) {
        cout << "No hay productos en el inventario." << endl;
        return;
    }
    for (Producto& producto : inventario) {
        producto.mostrar();
    }
}

void buscarProducto(vector<Producto>& inventario) {
    int codigo;
    cout << "Ingrese el código del producto a buscar: ";
    while (!(cin >> codigo)) {
        cout << "Error: Ingrese un código válido: ";
        limpiarBuffer();
    }

    for (Producto& producto : inventario) {
        if (producto.obtenerCodigo() == codigo) {
            cout << "Producto encontrado: ";
            producto.mostrar();
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void actualizarStock(vector<Producto>& inventario) {
    int codigo, cantidad;
    cout << "Ingrese el código del producto a actualizar: ";
    while (!(cin >> codigo)) {
        cout << "Error: Ingrese un código válido: ";
        limpiarBuffer();
    }

    for (Producto& producto : inventario) {
        if (producto.obtenerCodigo() == codigo) {
            cout << "Ingrese la cantidad a restar del stock: ";
            while (!(cin >> cantidad) || cantidad <= 0) {
                cout << "Error: Ingrese una cantidad válida: ";
                limpiarBuffer();
            }
            producto.actualizarStock(cantidad);
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void calcularValorTotal(vector<Producto>& inventario) {
    float total = 0;
    for (Producto& producto : inventario) {
        total += producto.obtenerValor();
    }
    cout << fixed << setprecision(2);
    cout << "Valor total del inventario: Q" << total << endl;
}
