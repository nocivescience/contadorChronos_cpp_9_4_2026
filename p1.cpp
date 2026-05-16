#include <iostream>
#include <chrono>
#include <thread>

int main() {
    int contador =0;
    std::cout << "Comenzando con el reloj" << std::endl;
    std::cout << "esto es increible" << std::endl;
    while(true){
        std::cout << "\rSegundo actual: " << contador << std::flush;
        std::cout<<"Esto es fantástico"<< std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        contador++;
    }
    return 0;
}