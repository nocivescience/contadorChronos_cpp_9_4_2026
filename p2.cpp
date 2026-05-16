#include <iostream>
#include <chrono>
#include <thread>
#include <string>

int main() {
    std::string palabra = "BIENVENIDO";
    std::cout << palabra << std::endl;
    int contador =0;
    while(true) {
        std::cout << "Este es mi reloj: "<< contador << std::endl;
        std::cout << "\rSegundo Actual" << std::endl;
        std::cout << "\nEsto esta muy aburrido" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        contador++;
    }
    return 0;
}