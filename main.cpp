#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "window.h"

using namespace sf;
using namespace std;

int main() {
    string route = "../img/";
    // Main
    RenderWindow main(VideoMode(500, 500), "League of Gems");
    main.setPosition(Vector2i(400, 100));

    // Fondo
    Texture background;
    background.loadFromFile(route + "background main.jpg");
    Sprite backgroundImage;
    backgroundImage.setTexture(background);

    // Logo
    Texture logo;
    logo.loadFromFile(route + "logo.png");
    Sprite logoS;
    logoS.setTexture(logo);
    logoS.setPosition(Vector2f(140, 50));

    // Boton Facil
    Texture easyButton;
    easyButton.loadFromFile(route + "easy.png");
    Sprite easyButtonImage;
    easyButtonImage.setTexture(easyButton);
    easyButtonImage.setPosition(Vector2f(225, 300));

    // Boton Normal
    Texture normalButton;
    normalButton.loadFromFile(route + "normal.png");
    Sprite normalButtonImage;
    normalButtonImage.setTexture(normalButton);
    normalButtonImage.setPosition(Vector2f(225, 350));

    // Boton Dificil
    Texture hardButton;
    hardButton.loadFromFile(route + "hard.png");
    Sprite hardButtonImage;
    hardButtonImage.setTexture(hardButton);
    hardButtonImage.setPosition(Vector2f(225, 400));

    while (main.isOpen()) {
        Event event;
        while (main.pollEvent(event)) {
            switch (event.type) {
                // Se cierra la ventana
                case Event::Closed:
                    main.close();
                    break;
                // Movimiento del mouse
                case Event::MouseMoved: {
                    Vector2i mousePos = Mouse::getPosition(main);
                    Vector2f mousePosF(static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ));
                    if ( easyButtonImage.getGlobalBounds().contains(mousePosF)) {
                        easyButtonImage.setColor(Color(250, 20, 20));
                    } else {
                        easyButtonImage.setColor(Color(255, 255, 255));
                    }
                    if ( normalButtonImage.getGlobalBounds().contains(mousePosF)) {
                        normalButtonImage.setColor(Color(250, 20, 20));
                    } else {
                        normalButtonImage.setColor(Color(255, 255, 255));
                    }
                    if ( hardButtonImage.getGlobalBounds().contains(mousePosF)) {
                        hardButtonImage.setColor(Color(250, 20, 20));
                    } else {
                        hardButtonImage.setColor(Color(255, 255, 255));
                    }
                }
                    break;
                // Hacer click
                case Event::MouseButtonPressed: {
                    Vector2i mousePos = Mouse::getPosition(main);
                    Vector2f mousePosF(static_cast<float>( mousePos.x), static_cast<float>( mousePos.y ));
                    if ( easyButtonImage.getGlobalBounds().contains(mousePosF)) {
                        cout << "Easy" << endl;
                        window window;
                        main.close();
                        window.iniciar(20, route);
                    }
                    if ( normalButtonImage.getGlobalBounds().contains(mousePosF)) {
                        cout << "Normal" << endl;
                        window window;
                        main.close();
                        window.iniciar(25, route);
                    }
                    if ( hardButtonImage.getGlobalBounds().contains(mousePosF)) {
                        cout << "Hard" << endl;
                        window window;
                        main.close();
                        window.iniciar(35, route);
                    }
                }
                    break;
            }
        }
        // Dibuja en  pantalla
        main.clear();
        main.draw(backgroundImage);
        main.draw(logoS);
        main.draw(easyButtonImage);
        main.draw(normalButtonImage);
        main.draw(hardButtonImage);
        main.display();
    }
    return 0;
}
