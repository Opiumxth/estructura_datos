#include <iostream>
#include "Lista.h"
#include "Persona.h"

using namespace std;
int main()
{
    Lista<Persona> miLista;

    // Cargar datos previos si existen

    miLista.cargarDesdeArchivo("datos.txt");
    std::cout << "--- Datos cargados ---\n";
    cout << miLista << endl;
    //cout <<"Elementos recuperados..." <<endl;
    //miLista.mostrar();
    /*
    // Agregar personas
    miLista.insertarFinal(Persona("Pepe", 3000.0));
    miLista.insertarFinal(Persona("Ronald", 5000.0));

    // Guardar cambios
    miLista.insertarFinal(Persona("Edith", 3500.0));
    miLista.guardarEnArchivo("datos.txt");
    */
    std::cout << "\n--- Datos actualizados y guardados ---" << std::endl;


    //system("pause");
    return 0;
}
