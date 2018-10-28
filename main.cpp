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
    main.setPosition(Vector2i(400,100));

    Texture background;
    Sprite backgroundImage;

    Texture logo;
    logo.loadFromFile("../img/logo.png");
    Sprite logoS;
    logoS.setTexture(logo);
    logoS.setPosition(Vector2f(140, 50));

    if ( !background.loadFromFile( route + "background main.jpg" ) )
        cout << "Can't find the image" << endl;

    backgroundImage.setTexture( background );

    Texture easyButton;
    Sprite easyButtonImage;
    if ( !easyButton.loadFromFile(route + "easy.png"))
        cout << "Can't find the image" << endl;
    easyButtonImage.setTexture(easyButton);
    easyButtonImage.setPosition(Vector2f(225, 300));

    Texture normalButton;
    Sprite normalButtonImage;
    if ( !normalButton.loadFromFile(route + "normal.png"))
        cout << "Can't find the image" << endl;
    normalButtonImage.setTexture(normalButton);
    normalButtonImage.setPosition(Vector2f(225, 350));

    Texture hardButton;
    Sprite hardButtonImage;
    if ( !hardButton.loadFromFile(route + "hard.png"))
        cout << "Can't find the image" << endl;
    hardButtonImage.setTexture(hardButton);
    hardButtonImage.setPosition(Vector2f(225, 400));

    while (main.isOpen()) {
        Event event;
        while (main.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed:
                    main.close();
                    break;
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
                case Event::MouseButtonPressed: {
                    Vector2i mousePos = Mouse::getPosition(main);
                    Vector2f mousePosF(static_cast<float>( mousePos.x), static_cast<float>( mousePos.y ));
                    if ( easyButtonImage.getGlobalBounds().contains(mousePosF)) {
                        cout << "Easy" << endl;
                        window window;
                        main.close();
                        window.iniciar(20,route);
                    }
                    if ( normalButtonImage.getGlobalBounds().contains(mousePosF)) {
                        cout << "Normal" << endl;
                        window window;
                        main.close();
                        window.iniciar(25,route);
                    }
                    if ( hardButtonImage.getGlobalBounds().contains(mousePosF)) {
                        cout << "Hard" << endl;
                        window window;
                        main.close();
                        window.iniciar(35,route);
                    }
                }
                    break;
            }
        }
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
