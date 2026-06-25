#include <iostream>
#include <string>
using namespace std;

// Variables globales básicas
string nombreCliente, generoCliente;
int edadCliente, puntosAcumulados;
int opcion;

// Inventario inicial
int cantidadAlgodones = 20, cantidadGasas = 20, cantidadPovidine = 20;
int cantidadPanadol = 20, cantidadAcetaminofen = 20, cantidadVitaminasB = 20;

// Totales
float totalVentaLibre = 0;
float totalVentaControlada = 0;

// Prototipos
void registrarCliente();
void menuVentaLibre();
void menuVentaControlada();
void menuInventario();
void mostrarFactura();

int main() {
    registrarCliente();

    do {
        cout << "\n===== FARMACIA LA TOXICA =====\n";
        cout << "1. Venta libre\n";
        cout << "2. Venta controlada\n";
        cout << "3. Inventario\n";
        cout << "4. Factura\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuVentaLibre(); break;
            case 2: menuVentaControlada(); break;
            case 3: menuInventario(); break;
            case 4: mostrarFactura(); break;
            case 5: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opcion no valida.\n";
        }

    } while (opcion != 5);

    return 0;
}

// Módulos iniciales temporales
void registrarCliente() {
    cout << "\n===== REGISTRO DEL CLIENTE =====\n";

    cout << "Ingrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, nombreCliente);

    do {
        cout << "Ingrese la edad del cliente: ";
        cin >> edadCliente;

        if (edadCliente < 18) {
            cout << "El cliente debe ser mayor de edad.\n";
        } else if (edadCliente > 110) {
            cout << "Edad no valida.\n";
        }

    } while (edadCliente < 18 || edadCliente > 110);

    do {
        cout << "Ingrese genero del cliente (M/F): ";
        cin >> generoCliente;

        if (generoCliente != "M" && generoCliente != "F" &&
            generoCliente != "m" && generoCliente != "f") {
            cout << "Genero no valido.\n";
        }

    } while (generoCliente != "M" && generoCliente != "F" &&
             generoCliente != "m" && generoCliente != "f");

    do {
        cout << "Ingrese puntos acumulados del cliente (0 - 500): ";
        cin >> puntosAcumulados;

        if (puntosAcumulados < 0 || puntosAcumulados > 500) {
            cout << "Los puntos deben estar entre 0 y 500.\n";
        }

    } while (puntosAcumulados < 0 || puntosAcumulados > 500);

    cout << "\nCliente registrado correctamente.\n";
}

/*
Estudiante 1 — Rama feature/clientes
git add .
git commit -m "Agrega modulo de registro de clientes"
git push origin feature/clientes
*/

void menuVentaLibre() {
    int opcionVL, cantidad;

    cout << "\n===== MEDICAMENTOS DE VENTA LIBRE =====\n";
    cout << "1. Algodones - L.50 - Disponible: " << cantidadAlgodones << endl;
    cout << "2. Gasas     - L.80 - Disponible: " << cantidadGasas << endl;
    cout << "3. Povidine  - L.40 - Disponible: " << cantidadPovidine << endl;
    cout << "Seleccione producto: ";
    cin >> opcionVL;

    cout << "Ingrese cantidad: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "Cantidad no valida.\n";
        return;
    }

    switch (opcionVL) {
        case 1:
            if (cantidad <= cantidadAlgodones) {
                cantidadAlgodones -= cantidad;
                totalVentaLibre += cantidad * 50;
                cout << "Algodones agregados correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 2:
            if (cantidad <= cantidadGasas) {
                cantidadGasas -= cantidad;
                totalVentaLibre += cantidad * 80;
                cout << "Gasas agregadas correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 3:
            if (cantidad <= cantidadPovidine) {
                cantidadPovidine -= cantidad;
                totalVentaLibre += cantidad * 40;
                cout << "Povidine agregado correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        default:
            cout << "Opcion no valida.\n";
    }
}

void menuVentaControlada() {
    int opcionVC, cantidad;

    cout << "\n===== MEDICAMENTOS DE VENTA CONTROLADA =====\n";
    cout << "1. Panadol       - L.30  - Disponible: " << cantidadPanadol << endl;
    cout << "2. Acetaminofen  - L.60  - Disponible: " << cantidadAcetaminofen << endl;
    cout << "3. Vitaminas B   - L.200 - Disponible: " << cantidadVitaminasB << endl;
    cout << "Seleccione producto: ";
    cin >> opcionVC;

    cout << "Ingrese cantidad: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "Cantidad no valida.\n";
        return;
    }

    switch (opcionVC) {
        case 1:
            if (cantidad <= cantidadPanadol) {
                cantidadPanadol -= cantidad;
                totalVentaControlada += cantidad * 30;
                cout << "Panadol agregado correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 2:
            if (cantidad <= cantidadAcetaminofen) {
                cantidadAcetaminofen -= cantidad;
                totalVentaControlada += cantidad * 60;
                cout << "Acetaminofen agregado correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        case 3:
            if (cantidad <= cantidadVitaminasB) {
                cantidadVitaminasB -= cantidad;
                totalVentaControlada += cantidad * 200;
                cout << "Vitaminas B agregadas correctamente.\n";
            } else {
                cout << "No hay suficiente inventario.\n";
            }
            break;

        default:
            cout << "Opcion no valida.\n";
    }
}

/*
git add .
git commit -m "Agrega modulo de venta controlada"
git push origin feature/venta-controlada
*/

void menuInventario() {
    cout << "Modulo inventario pendiente de desarrollo.\n";
}

void mostrarFactura() {
    float subtotal = totalVentaLibre + totalVentaControlada;
    float impuesto = subtotal * 0.15;
    float descuento = 0;

    if (puntosAcumulados >= 100) {
        descuento = subtotal * 0.05;
    }

    if (edadCliente >= 60) {
        descuento += subtotal * 0.10;
    }

    float totalPagar = subtotal + impuesto - descuento;

    cout << "\n===== FACTURA FINAL =====\n";
    cout << "Cliente: " << nombreCliente << endl;
    cout << "Edad: " << edadCliente << endl;
    cout << "Genero: " << generoCliente << endl;
    cout << "Puntos: " << puntosAcumulados << endl;

    cout << "\nSubtotal venta libre:       L." << totalVentaLibre << endl;
    cout << "Subtotal venta controlada:  L." << totalVentaControlada << endl;
    cout << "Subtotal general:           L." << subtotal << endl;
    cout << "Impuesto 15%:               L." << impuesto << endl;
    cout << "Descuento aplicado:         L." << descuento << endl;
    cout << "Total a pagar:              L." << totalPagar << endl;
}


/*
git add .
git commit -m "Crea estructura base del sistema farmacia"
git push origin develop

*/