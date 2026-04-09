#include <iostream>
#include <chrono> // Para manejar el tiempo
#include <thread> // Para la función sleep

int main() {
    int contador = 0;

    std::cout << "Iniciando conteo por segundo..." << std::endl;
    std::cout << "esto es algo unico" << std::endl;

    while (true) {
        // \r mueve el cursor al inicio de la línea actual
        std::cout << "\rSegundo actual: " << contador << std::flush;
        std::cout << "\nesto es aburrido"  << std::endl;
        
        // Pausa la ejecución por 1 segundo
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        contador++;
    }

    return 0;
}