#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono> // Para manejar el tiempo
#include <thread> // Para la función sleep
#include <random>

const int ancho = 800;
const int alto = 600;
const int radio = 10.f;

int main() {
    sf::RenderWindow window(sf::VideoMode({ancho, alto}), "Super ventana");
    window.setFramerateLimit(60);
    std::random_device rd;
    std::mt19937 gen(rd());
    sf::CircleShape triangulo(radio, 3);
    triangulo.setFillColor(sf::Color::Red);
    triangulo.setOutlineThickness(2.f);
    triangulo.setOutlineColor(sf::Color::Yellow);
    int contador = 0;
    window.clear(sf::Color::Black);
    while (true){
        std::uniform_real_distribution<float> posX(0+radio, static_cast<float>(ancho) -radio);
        std::uniform_real_distribution<float> posY(0+radio, static_cast<float>(alto)-radio);
        triangulo.setPosition({posX(gen), posY(gen)});
        std::this_thread::sleep_for(std::chrono::seconds());
        contador++;
        window.draw(triangulo);
        window.display();
    }
    return 0;
}