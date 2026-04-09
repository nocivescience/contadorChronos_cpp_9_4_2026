#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono> // Para manejar el tiempo
#include <thread> // Para la función sleep

int main(){
    sf::RenderWindow window(sf::VideoMode({800, 600}), "mi hermosa ventana");
    sf::CircleShape triangulo(80.f, 3);
    triangulo.setFillColor(sf::Color::Green);
    triangulo.setOutlineThickness(5.f); // Grosor del borde
    triangulo.setOutlineColor(sf::Color::Red); // Color del borde
    triangulo.setPosition({200.f, 150.f});
    while (window.isOpen()){
        while (const std::optional<sf::Event> event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
            window.clear(sf::Color::Black);
            window.draw(triangulo);
            window.display();
        }
        window.clear(sf::Color::Black);
        window.display();
    }
}