#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <optional>

int main() {
    // 1. Crear la ventana (Sintaxis SFML 3 con llaves para VideoMode)
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Contador de Clicks - SFML 3");

    // 2. Cargar la fuente (En SFML 3 es openFromFile)
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error: Coloca un archivo 'arial.ttf' junto al ejecutable." << std::endl;
        // No retornamos -1 para que al menos veas el triangulo si no hay fuente
    }

    // 3. Configurar el Texto
    int contador = 0;
    sf::Text texto(font);
    texto.setString("Clicks: 0");
    texto.setCharacterSize(40);
    texto.setFillColor(sf::Color::White);
    texto.setPosition({20.f, 20.f});

    // 4. Configurar el Triángulo
    sf::CircleShape triangulo(80.f, 3);
    triangulo.setFillColor(sf::Color::Green);
    triangulo.setOutlineThickness(5.f);
    triangulo.setOutlineColor(sf::Color::Red);
    triangulo.setOrigin({80.f, 80.f}); // Centrar el origen
    triangulo.setPosition({400.f, 300.f});

    // Bucle principal
    while (window.isOpen()) {
        // --- PROCESAR EVENTOS (Estilo SFML 3) ---
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            
            // Cerrar ventana
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Detectar Clic
            if (const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseClick->button == sf::Mouse::Button::Left) {
                    contador++;
                    texto.setString("Clicks: " + std::to_string(contador));
                    
                    // Efecto visual: cambiar color al hacer click
                    triangulo.setFillColor(sf::Color::Yellow);
                }
            }
            
            // Volver al color original al soltar el click
            if (event->is<sf::Event::MouseButtonReleased>()) {
                triangulo.setFillColor(sf::Color::Green);
            }
        }

        // --- RENDERIZADO ---
        window.clear(sf::Color::Black);
        
        window.draw(triangulo);
        window.draw(texto);
        
        window.display();
    }

    return 0;
}