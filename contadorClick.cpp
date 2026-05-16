#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <optional>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Modo Magico Temporal");

    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error: No se pudo cargar arial.ttf" << std::endl;
    }

    int contador = 0;
    
    sf::Text texto(font, "Clicks: 0", 40);
    sf::Text mensajeModoMagico(font, "¡Modo Mágico Activado!", 30);
    texto.setFillColor(sf::Color::White);
    texto.setPosition({20.f, 20.f});
    mensajeModoMagico.setFillColor(sf::Color::Magenta);
    mensajeModoMagico.setPosition({20.f, 70.f});

    sf::CircleShape triangulo(80.f, 3);
    triangulo.setFillColor(sf::Color::Green);
    triangulo.setOutlineThickness(5.f);
    triangulo.setOutlineColor(sf::Color::Red);
    triangulo.setOrigin({80.f, 80.f});
    triangulo.setPosition({400.f, 300.f});

    // --- VARIABLES PARA EL MODO MAGICO ---
    sf::Clock relojMagico;
    bool modoMagicoActivo = false;

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // Click del mouse
            if (const auto* mouseClick = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseClick->button == sf::Mouse::Button::Left) {
                    contador++;
                    texto.setString("Clicks: " + std::to_string(contador));
                    // Solo cambia a amarillo si NO estamos en modo mágico
                    if (!modoMagicoActivo) triangulo.setFillColor(sf::Color::Yellow);
                }
            }

            if (event->is<sf::Event::MouseButtonReleased>()) {
                if (!modoMagicoActivo) triangulo.setFillColor(sf::Color::Green);
            }

            // Teclado
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::R) {
                    contador = 0;
                    texto.setString("Clicks: " + std::to_string(contador));
                }
                
                if (keyPressed->code == sf::Keyboard::Key::M) {
                    std::cout << "¡Modo Mágico Activado por 2 segundos!" << std::endl;
                    triangulo.setFillColor(sf::Color::Magenta);
                    mensajeModoMagico.setString("Modo Magico Activado");
                    modoMagicoActivo = true;
                    relojMagico.restart(); // Empezamos a contar los 2 segundos
                }
            }
        }

        // --- LÓGICA TEMPORAL (Fuera del pollEvent) ---
        if (modoMagicoActivo) {
            // Si el tiempo transcurrido es mayor a 2 segundos
            if (relojMagico.getElapsedTime() >= sf::seconds(2.0f)) {
                modoMagicoActivo = false;
                triangulo.setFillColor(sf::Color::Green); // Volver al estado previo
                std::cout << "Modo Mágico Finalizado." << std::endl;
            }
        }

        window.clear(sf::Color::Black);
        window.draw(triangulo);
        window.draw(texto);
        if (modoMagicoActivo) {
            window.draw(mensajeModoMagico);
        }
        window.display();
    }

    return 0;
}