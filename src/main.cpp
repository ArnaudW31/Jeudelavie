#include "SFML/Graphics.hpp"
#include "Grille.hpp"

const int GRID_SIZE = 5;
const int BUTTON_SIZE = 50;

int main() {
    sf::RenderWindow window(sf::VideoMode(GRID_SIZE * BUTTON_SIZE, GRID_SIZE * BUTTON_SIZE), "Grille de boutons SFML");

    Grille g = Grille();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x / BUTTON_SIZE;
                    int y = event.mouseButton.y / BUTTON_SIZE;
                    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
                        g.getGrid()[y][x].setStatus( !g.getGrid()[y][x].getStatus()); // Inverser l'état du bouton
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        // Dessiner la grille de boutons
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                sf::RectangleShape button(sf::Vector2f(BUTTON_SIZE, BUTTON_SIZE));
                button.setPosition(j * BUTTON_SIZE, i * BUTTON_SIZE);
                button.setOutlineThickness(1);
                button.setOutlineColor(sf::Color::Black);
                if (g.getGrid()[i][j].getStatus()) {
                    button.setFillColor(sf::Color::Green); // Bouton coché
                } else {
                    button.setFillColor(sf::Color::White); // Bouton décoché
                }
                window.draw(button);
            }
        }

        window.display();
    }

    return 0;
}
