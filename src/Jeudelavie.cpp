#include <SFML/Graphics.hpp>
#include "Grille.hpp"
#include <iostream>
#include <string>

int main() {

    int GRID_SIZE = 20;
    int BUTTON_SIZE = 20;
    sf::RenderWindow window(sf::VideoMode(GRID_SIZE * BUTTON_SIZE, (GRID_SIZE * BUTTON_SIZE)), "Jeu de la vie");
    window.setFramerateLimit(30);

    Grille g =Grille(GRID_SIZE,GRID_SIZE,false);

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

                    if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) { //si les co de la souris sont sur une case
                        g.getCase(x,y).setStatus(!g.getCase(x,y).getStatus()); //on change le status de la case
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                g.nextIteration();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                g =Grille(GRID_SIZE,GRID_SIZE,false);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                g =Grille(GRID_SIZE,GRID_SIZE,false,"random");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                g =Grille(GRID_SIZE,GRID_SIZE,false,"damier");
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                g =Grille(GRID_SIZE,GRID_SIZE,false,"pleine");
            }
        }

        window.clear(sf::Color::White);

        // Dessiner la grille de boutons
        for (int i = 0; i < GRID_SIZE; ++i) {
            for (int j = 0; j < GRID_SIZE; ++j) {
                sf::RectangleShape button(sf::Vector2f(BUTTON_SIZE, BUTTON_SIZE));
                
                button.setPosition(j * BUTTON_SIZE, i * BUTTON_SIZE);
                button.setOutlineThickness(1);
                button.setOutlineColor(sf::Color(50,50,50,255)); //sa fe du gri

                if (g.getCase(j,i).getStatus()) {
                    button.setFillColor(sf::Color::Black);
                } else {
                    button.setFillColor(sf::Color::White);
                }
                window.draw(button);
            }
        }
        window.display();
    }

    return 0;
}