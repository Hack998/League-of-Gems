//
// Created by samuel on 16/10/18.
//

#include "window.h"
#include <random>
#include "soldado.h"
#include "Enemigo.h"
#include "Inicio.h"

typedef soldado ejercito;

void buscar(int cant, Enemigo *gy){
    std::cout << "Dentro" << std::endl;
    for (int i = 0; i < cant; i++) {
        std::cout << gy[i].x << std::endl;
        if(gy[i].x == 11){
            std::cout << "YES!" << std::endl;
        }
    }
}

void window::iniciar(int cant, string route) {
    RenderWindow window(VideoMode(1200, 680), "League of Gems");
    RectangleShape rect4(Vector2f(1200, 680));
    rect4.setFillColor(Color::White);

    // Laberinto
    Texture lab;
    Sprite labImage;
    lab.loadFromFile(route + "lab.png");
    labImage.setTexture(lab);

    // Logo
    Texture logo;
    logo.loadFromFile(route + "logo.png");
    Sprite logoS;
    logoS.setTexture(logo);
    logoS.setPosition(Vector2f(1000, 75));

    ///****************** CONSOLA *******************
    ///**********************************************
    RectangleShape console(Vector2f(193,337));
    console.setFillColor(Color::Black);
    console.setOutlineColor(Color::Cyan);
    console.setOutlineThickness(3);
    console.setPosition(Vector2f(1003,340));

    Font font;
    font.loadFromFile("../font/cour.ttf");

    Text csTitle;
    csTitle.setFont(font);
    csTitle.setCharacterSize(12);
    csTitle.setColor(Color::White);
    csTitle.setStyle(Text::Bold);
    csTitle.setString("Console:");
    csTitle.setPosition(Vector2f(1010,345));

    Text text;
    text.setFont(font);
    string impresion = "";

    Text algUso;
    algUso.setFont(font);
    ///**********************************************

    ///****************** ATAQUES *******************
    ///**********************************************
    Texture punch;
    punch.loadFromFile(route + "punch.png");
    Sprite punchS;
    punchS.setTexture(punch);
    punchS.setPosition(Vector2f(0, 600));

    Texture uppercut;
    uppercut.loadFromFile(route + "uppercut.png");
    Sprite uppercutS;
    uppercutS.setTexture(uppercut);
    uppercutS.setPosition(Vector2f(100, 600));

    Texture fPunch;
    fPunch.loadFromFile(route + "fastPunch.png");
    Sprite fPunchS;
    fPunchS.setTexture(fPunch);
    fPunchS.setPosition(Vector2f(200, 600));

    Texture kick;
    kick.loadFromFile(route + "kick.png");
    Sprite kickS;
    kickS.setTexture(kick);
    kickS.setPosition(Vector2f(300, 600));

    Texture fastKick;
    fastKick.loadFromFile(route + "fastKick.png");
    Sprite fastKickS;
    fastKickS.setTexture(fastKick);
    fastKickS.setPosition(Vector2f(400, 600));

    Texture reverseKick;
    reverseKick.loadFromFile(route + "reverseKick.png");
    Sprite reverseKickS;
    reverseKickS.setTexture(reverseKick);
    reverseKickS.setPosition(Vector2f(500, 600));

    Texture knife;
    knife.loadFromFile(route + "knife.png");
    Sprite knifeS;
    knifeS.setTexture(knife);
    knifeS.setPosition(Vector2f(600, 600));

    Texture hammer;
    hammer.loadFromFile(route + "hammer.png");
    Sprite hammerS;
    hammerS.setTexture(hammer);
    hammerS.setPosition(Vector2f(700, 600));

    Texture sword;
    sword.loadFromFile(route + "sword.png");
    Sprite swordS;
    swordS.setTexture(sword);
    swordS.setPosition(Vector2f(800, 600));

    Texture arrow;
    arrow.loadFromFile(route + "arrow.png");
    Sprite arrowS;
    arrowS.setTexture(arrow);
    arrowS.setPosition(Vector2f(900, 600));
    ///**********************************************

    matriz matriz1 = iniciar_matriz();

    // Aliados
    ejercito array[15];
    int x = 3;
    for (int i = 0; i < 15; i++) {
        if ( i + 3 == 10 )
            x = 5;
        ejercito temp;
        temp.crear(std::rand() % 50 + 20, std::rand() % 5 + 2, i + x, 0);
        matriz1.matriz_pos[i + x][0] = 1;
        array[i] = temp;
    }

    // Enemigos
    Enemigo em;
    Enemigo array_e[cant];
    em.crearPoblacion(cant, array_e);
    int cant_1 = 0;
    int y = 10;
    int h = 41;
    int fghj = ((cant - 8) / 2);
    for (int i = 0; i < cant; i++) {
        if ( cant_1 < 5 ) {
            matriz1.matriz_pos[y][h] = 2;
            array_e[i].setPosicion(y,h);
            std::cout << "X: " << array_e[i].x << " Y: " << array_e[i].y << std::endl;
            cant_1++;
            y++;
            if ( cant_1 == 3 ) {
                y = 10;
                h++;
            }
            if ( cant_1 == 4 )
                y = 12;
        }
        if ( cant_1 > 4 && cant_1 < 8 ) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, 1);
            uniform_int_distribution<> dis_1(0, 2);
            y = dis_1(gen);
            h = dis(gen);
            while (matriz1.matriz_pos[10 + y][39 + h] == 2) {
                y = dis_1(gen);
                h = dis(gen);
            }
            matriz1.matriz_pos[10 + y][39 + h] = 2;
            array_e[i].setPosicion(10 + y,39 + h);
            std::cout << "X: " << array_e[i].x << " Y: " << array_e[i].y << std::endl;
            cant_1++;
        }
        if ( cant_1 > 7 && cant_1 < cant ) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, 3);
            uniform_int_distribution<> dis_1(0, 9);
            y = dis_1(gen);
            h = dis(gen);
            if ( fghj != 0 ) {
                while (matriz1.matriz_pos[0 + y][39 + h] == 2) {
                    y = dis_1(gen);
                    h = dis(gen);
                }
                matriz1.matriz_pos[0 + y][39 + h] = 2;
                array_e[i].setPosicion(0 + y,39 + h);
                std::cout << "X: " << array_e[i].x << " Y: " << array_e[i].y << std::endl;
                fghj--;
            } else {
                while (matriz1.matriz_pos[13 + y][39 + h] == 2) {
                    y = dis_1(gen);
                    h = dis(gen);
                }
                matriz1.matriz_pos[13 + y][39 + h] = 2;
                array_e[i].setPosicion(13 + y,39 + h);
                std::cout << "X: " << array_e[i].x << " Y: " << array_e[i].y << std::endl;
            }
            cant_1++;
        }
    }

    // *****************
    /*for (int i = 0; i <= 22; i++) {
        cout << "" << endl;
        for (int j = 0; j <= 42; j++) {
            cout << matriz1.matriz_pos[i][j] << ",";
        }
    }*/

    int lines = 0;
    int attack = 0;
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                // Se cierra la ventana
                case Event::Closed: {
                    window.close();
                }
                    break;
                // Hacer click
                case Event::MouseButtonPressed: {

                    this->checkLines(&lines, &impresion);
                    impresion += "\nClick!";

                    Vector2i mousePos = Mouse::getPosition(window);
                    Vector2f mousePosF(static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ));
                    Vector2f mousePosF2(mousePosF.x - 78, mousePosF.y);
                    cout << "Mouse X: " << mousePosF.x << "; Mouse Y:" << mousePosF.y << endl;
                    cout << "Lab X: " << labImage.getGlobalBounds().width << "; Lab Y:"
                         << labImage.getGlobalBounds().height << endl;

                    ///************************ COMPRUEBA CLICK EN ATAQUES ************************
                    ///****************************************************************************
                    if ( punchS.getGlobalBounds().contains(mousePosF2) && !uppercutS.getGlobalBounds().contains(mousePosF2)) {
                        punchS.setColor(Color::Green);
                        attack = 1;
                    }
                    if ( !punchS.getGlobalBounds().contains(mousePosF2) && uppercutS.getGlobalBounds().contains(mousePosF2) && !fPunchS.getGlobalBounds().contains(mousePosF2)) {
                        uppercutS.setColor(Color::Green);
                        attack = 2;
                    }
                    if ( (!uppercutS.getGlobalBounds().contains(mousePosF2) && fPunchS.getGlobalBounds().contains(mousePosF2) && !kickS.getGlobalBounds().contains(mousePosF2)) && this->screen >= 2 ) {
                        fPunchS.setColor(Color::Green);
                        attack = 3;
                    }
                    if ( (!fPunchS.getGlobalBounds().contains(mousePosF2) && kickS.getGlobalBounds().contains(mousePosF2) && !fastKickS.getGlobalBounds().contains(mousePosF2)) && this->screen >= 2 ) {
                        kickS.setColor(Color::Green);
                        attack = 4;
                    }
                    if ( (!kickS.getGlobalBounds().contains(mousePosF2) && fastKickS.getGlobalBounds().contains(mousePosF2) && !reverseKickS.getGlobalBounds().contains(mousePosF2)) && this->screen >= 3 ) {
                        fastKickS.setColor(Color::Green);
                        attack = 5;
                    }
                    if ( (!fastKickS.getGlobalBounds().contains(mousePosF2) && reverseKickS.getGlobalBounds().contains(mousePosF2) && !knifeS.getGlobalBounds().contains(mousePosF2))&& this->screen >= 3 ) {
                        reverseKickS.setColor(Color::Green);
                        attack = 6;
                    }
                    if ( (!reverseKickS.getGlobalBounds().contains(mousePosF2) && knifeS.getGlobalBounds().contains(mousePosF2) && !hammerS.getGlobalBounds().contains(mousePosF2)) && this->screen >= 4 ) {
                        knifeS.setColor(Color::Green);
                        attack = 7;
                    }
                    if ( (!knifeS.getGlobalBounds().contains(mousePosF2) && hammerS.getGlobalBounds().contains(mousePosF2) && !swordS.getGlobalBounds().contains(mousePosF2)) && this->screen >= 4 ) {
                        hammerS.setColor(Color::Green);
                        attack = 8;
                    }
                    if ( (!hammerS.getGlobalBounds().contains(mousePosF2) && swordS.getGlobalBounds().contains(mousePosF2) && !arrowS.getGlobalBounds().contains(mousePosF2)) && this->screen >= 5 ) {
                        swordS.setColor(Color::Green);
                        attack = 9;
                    }
                    if ( (!swordS.getGlobalBounds().contains(mousePosF2) && arrowS.getGlobalBounds().contains(mousePosF2)) && this->screen >= 5 ) {
                        arrowS.setColor(Color::Green);
                        attack = 10;
                    }

                    Sprite* attacks[10] = {&punchS, &uppercutS, &fPunchS, &kickS, &fastKickS, &reverseKickS, &knifeS, &hammerS, &swordS, &arrowS};
                    for (int l = 0; l < 10; ++l) {
                        if(l+1 != attack){
                            attacks[l]->setColor(Color::White);
                        }
                    }
                    ///****************************************************************************

                    /// Valida que el click este dentro del laberinto
                    if ( labImage.getGlobalBounds().contains(mousePosF2) ||
                         labImage.getGlobalBounds().contains(mousePosF)) {
                        int pos_mouse[2];
                        /// Localiza hasta que posicion de la matriz debe moverse el sprite
                        for (int i = 0; i <= 42; i++) {
                            if ((matriz1.matriz_pixels[0][i].x < mousePosF.x - (i * 3) &&
                                 matriz1.matriz_pixels[0][i + 1].x > mousePosF.x - (i * 3)) ||
                                (matriz1.matriz_pixels[0][i].x < mousePosF.x && mousePosF.x >= 971 && i == 42)) {
                                pos_mouse[0] = i;
                                for (int j = 0; j <= 22; j++) {
                                    if ((matriz1.matriz_pixels[j][i].y < mousePosF.y &&
                                         matriz1.matriz_pixels[j + 1][i].y > mousePosF.y) ||
                                        (matriz1.matriz_pixels[j][i].y < mousePosF.y && mousePosF.y >= 571 &&
                                         j == 22)) {
                                        cout << "Pixel X: " << matriz1.matriz_pixels[j][i].x << "; Pixel Y:"
                                             << matriz1.matriz_pixels[j][i].y << endl;
                                        cout << "Pos X: " << j << "; Pos Y:" << i << endl;
                                        pos_mouse[1] = j;
                                        break;
                                    }
                                }
                                break;
                            }
                        }

                        /// Ejecuta el movimiento de cada sprite
                        for (int k = 0; k < 15; k++) {
                            int xz = array[k].cuerpo.x; /// Posicion inicial del sprite en x
                            int yz = array[k].cuerpo.y; /// Posicion inicial del sprite en y
                            string path = Inicio::pathFind(Location(xz, yz), Location(pos_mouse[1], pos_mouse[0]),
                                                           matriz1);
                            cout << path << endl;
                            for (int b = 0; b < path.length(); b++) {
                                if ( path.substr(b, 1) == "0" ) {
                                    array[k].agregar(xz + 1, yz);
                                    xz++;
                                } else if ( path.substr(b, 1) == "1" ) {
                                    array[k].agregar(xz, yz + 1);
                                    yz++;
                                } else if ( path.substr(b, 1) == "2" ) {
                                    array[k].agregar(xz - 1, yz);
                                    xz--;
                                } else if ( path.substr(b, 1) == "3" ) {
                                    array[k].agregar(xz, yz - 1);
                                    yz--;
                                }
                            }
                        }

                        ejercito *mu = array;
                        int gh = 0;
                        while (ismove(mu)) {
                            for (int v = 0; v < 15; v++) {
                                if ( array[v].cabeza != nullptr &&
                                     matriz1.matriz_pos[array[v].cabeza->x][array[v].cabeza->y] != 1 ) {
                                    matriz1.matriz_pos[array[v].cuerpo.x][array[v].cuerpo.y] = 0;
                                    array[v].cuerpo.x = array[v].cabeza->x;
                                    array[v].cuerpo.y = array[v].cabeza->y;matriz1.matriz_pos[array[v].cuerpo.x][array[v].cuerpo.y] = 1;
                                    array[v].eliminar();
                                    gh++;
                                }
                            }

                            if ( gh == 0 ) {
                                for (int v = 0; v < 15; v++) {
                                    array[v].total_eliminacion();
                                }
                                break;
                            } else
                                gh = 0;
                        }

                        ///********************* COMPRUEBA ENEMIGOS CERCA **************************
                        ///*************************************************************************
                        for(int i = 0; i < 15; i++) {
                            int pos[2] = {-1,-1};
                            if (matriz1.matriz_pos[array[i].cuerpo.x][array[i].cuerpo.y - 1] == 2) {
                                pos[0] = array[i].cuerpo.x;
                                pos[1] = array[i].cuerpo.y-1;
                            }
                            else if (matriz1.matriz_pos[array[i].cuerpo.x - 1][array[i].cuerpo.y] == 2){
                                pos[0] = array[i].cuerpo.x-1;
                                pos[1] = array[i].cuerpo.y;
                            }
                            else if (matriz1.matriz_pos[array[i].cuerpo.x][array[i].cuerpo.y + 1] == 2){
                                pos[0] = array[i].cuerpo.x;
                                pos[1] = array[i].cuerpo.y+1;
                            }
                            else if (matriz1.matriz_pos[array[i].cuerpo.x + 1][array[i].cuerpo.y] == 2){
                                pos[0] = array[i].cuerpo.x+1;
                                pos[1] = array[i].cuerpo.y;
                            }

                            if(pos[0] != -1 && pos[1] != -1) {
                                this->checkLines(&lines, &impresion);
                                impresion += "\nEnemigo se acerca!";
                                Enemigo tempE = em.buscarPorPos(pos[0], pos[1], array_e, cant);
                                while(tempE.vida > 0 && array[i].cuerpo.vida > 0){
                                    std::cout << "Vida Enemigo Antes: " << tempE.vida << std::endl;
                                    array[i].atacar(attack, &tempE);
                                    std::cout << "Vida Enemigo Despues: " << tempE.vida << std::endl;

                                    std::cout << "Vida Soldado Antes: " << array[i].cuerpo.vida << std::endl;
                                    tempE.atacar(&array[i]);
                                    std::cout << "Vida Soldado Despues: " << array[i].cuerpo.vida << std::endl;
                                }
                                if(tempE.vida <= 0){
                                    matriz1.matriz_pos[pos[0]][pos[1]] = 0;
                                }else if(array[i].cuerpo.vida <= 0){
                                    matriz1.matriz_pos[array[i].cuerpo.x][array[i].cuerpo.y] = 0;
                                }
                            }
                        }
                        ///*************************************************************************

                        this->checkLines(&lines, &impresion);
                        impresion += "\nSoldados reunidos...";
                    }
                }
                    break;
                // Movimiento del mouse
                case Event::MouseMoved: {
                    Vector2i mousePos = Mouse::getPosition(window);
                    Vector2f mousePosF(static_cast<float>(mousePos.x-78), static_cast<float>(mousePos.y));
                    if ( punchS.getGlobalBounds().contains(mousePosF) && !uppercutS.getGlobalBounds().contains(mousePosF)) {
                        punchS.setPosition(Vector2f(0, 598));
                    } else {
                        punchS.setPosition(Vector2f(0, 600));
                    }
                    if ( !punchS.getGlobalBounds().contains(mousePosF) && uppercutS.getGlobalBounds().contains(mousePosF) && !fPunchS.getGlobalBounds().contains(mousePosF)) {
                        uppercutS.setPosition(Vector2f(100, 598));
                    } else {
                        uppercutS.setPosition(Vector2f(100, 600));
                    }
                    if ( (!uppercutS.getGlobalBounds().contains(mousePosF) && fPunchS.getGlobalBounds().contains(mousePosF) && !kickS.getGlobalBounds().contains(mousePosF)) && this->screen >= 2 ) {
                        fPunchS.setPosition(Vector2f(200, 598));
                    } else {
                        fPunchS.setPosition(Vector2f(200, 600));
                    }
                    if ( (!fPunchS.getGlobalBounds().contains(mousePosF) && kickS.getGlobalBounds().contains(mousePosF) && !fastKickS.getGlobalBounds().contains(mousePosF)) && this->screen >= 2 ) {
                        kickS.setPosition(Vector2f(300, 598));
                    } else {
                        kickS.setPosition(Vector2f(300, 600));
                    }
                    if ( (!kickS.getGlobalBounds().contains(mousePosF) && fastKickS.getGlobalBounds().contains(mousePosF) && !reverseKickS.getGlobalBounds().contains(mousePosF)) && this->screen >= 3 ) {
                        fastKickS.setPosition(Vector2f(400, 598));
                    } else {
                        fastKickS.setPosition(Vector2f(400, 600));
                    }
                    if ( (!fastKickS.getGlobalBounds().contains(mousePosF) && reverseKickS.getGlobalBounds().contains(mousePosF) && !knifeS.getGlobalBounds().contains(mousePosF))&& this->screen >= 3 ) {
                        reverseKickS.setPosition(Vector2f(500, 598));
                    } else {
                        reverseKickS.setPosition(Vector2f(500, 600));
                    }
                    if ( (!reverseKickS.getGlobalBounds().contains(mousePosF) && knifeS.getGlobalBounds().contains(mousePosF) && !hammerS.getGlobalBounds().contains(mousePosF)) && this->screen >= 4 ) {
                        knifeS.setPosition(Vector2f(600, 598));
                    } else {
                        knifeS.setPosition(Vector2f(600, 600));
                    }
                    if ( (!knifeS.getGlobalBounds().contains(mousePosF) && hammerS.getGlobalBounds().contains(mousePosF) && !swordS.getGlobalBounds().contains(mousePosF)) && this->screen >= 4 ) {
                        hammerS.setPosition(Vector2f(700, 598));
                    } else {
                        hammerS.setPosition(Vector2f(700, 600));
                    }
                    if ( (!hammerS.getGlobalBounds().contains(mousePosF) && swordS.getGlobalBounds().contains(mousePosF) && !arrowS.getGlobalBounds().contains(mousePosF)) && this->screen >= 5 ) {
                        swordS.setPosition(Vector2f(800, 598));
                    } else {
                        swordS.setPosition(Vector2f(800, 600));
                    }
                    if ( (!swordS.getGlobalBounds().contains(mousePosF) && arrowS.getGlobalBounds().contains(mousePosF)) && this->screen >= 5 ) {
                        arrowS.setPosition(Vector2f(900, 598));
                    } else {
                        arrowS.setPosition(Vector2f(900, 600));
                    }
                }
                    break;
            }
        }

        // Dibujar en pantalla.
        window.clear();
        window.draw(rect4);
        window.draw(console);

        switch (screen) {
            case 1:
                fPunchS.setColor(Color(80, 80, 80, 225));
                kickS.setColor(Color(80, 80, 80, 225));
                fastKickS.setColor(Color(80, 80, 80, 225));
                reverseKickS.setColor(Color(80, 80, 80, 225));
                knifeS.setColor(Color(80, 80, 80, 225));
                hammerS.setColor(Color(80, 80, 80, 225));
                swordS.setColor(Color(80, 80, 80, 225));
                arrowS.setColor(Color(80, 80, 80, 225));

                algUso.setString("Algoritmo en uso: \nInicio?");
                break;
            case 2:
                fastKickS.setColor(Color(80, 80, 80, 225));
                reverseKickS.setColor(Color(80, 80, 80, 225));
                knifeS.setColor(Color(80, 80, 80, 225));
                hammerS.setColor(Color(80, 80, 80, 225));
                swordS.setColor(Color(80, 80, 80, 225));
                arrowS.setColor(Color(80, 80, 80, 225));

                algUso.setString("Algoritmo en uso: \nPrim");
                break;
            case 3:
                knifeS.setColor(Color(80, 80, 80, 225));
                hammerS.setColor(Color(80, 80, 80, 225));
                swordS.setColor(Color(80, 80, 80, 225));
                arrowS.setColor(Color(80, 80, 80, 225));

                algUso.setString("Algoritmo en uso: \nKruskal");
                break;
            case 4:
                swordS.setColor(Color(80, 80, 80, 225));
                arrowS.setColor(Color(80, 80, 80, 225));

                algUso.setString("Algoritmo en uso: \nDijkstra");
                break;
            case 5:
                algUso.setString("Algoritmo en uso: \nPathFinding");
                break;
        }

        ///*************** IMPRESION ********************
        ///**********************************************
        algUso.setCharacterSize(12);
        algUso.setColor(Color::White);
        algUso.setPosition(Vector2f(1010,360));

        text.setString(impresion);
        text.setCharacterSize(12);
        text.setColor(Color::White);
        text.setPosition(Vector2f(1010,375));
        ///**********************************************

        window.draw(csTitle);
        window.draw(algUso);
        window.draw(text);
        window.draw(logoS);
        window.draw(punchS);
        window.draw(uppercutS);
        window.draw(fPunchS);
        window.draw(kickS);
        window.draw(fastKickS);
        window.draw(reverseKickS);
        window.draw(knifeS);
        window.draw(hammerS);
        window.draw(swordS);
        window.draw(arrowS);
        window.draw(labImage);

        for (int i = 0; i <= 22; i++) {
            for (int j = 0; j <= 42; j++) {

                Texture grass;
                Sprite grassS;
                if ( !grass.loadFromFile(route + "grass.png"))
                    cout << "Can't find the image" << endl;
                grassS.setPosition(matriz1.matriz_pixels[i][j]);
                grassS.setTexture(grass);
                window.draw(grassS);

                if ( matriz1.matriz_pos[i][j] == -1 ) {
                    Sprite obstaculo;
                    Texture texture;
                    if ( !texture.loadFromFile(route + "bush.png"))
                        cout << "Can't find the image" << endl;
                    obstaculo.setPosition(matriz1.matriz_pixels[i][j]);
                    obstaculo.setTexture(texture);
                    window.draw(obstaculo);
                }
                if(matriz1.matriz_pos[i][j] == 0){
                    window.draw(grassS);
                }
                if ( matriz1.matriz_pos[i][j] == 1 ) {
                    Sprite aliado;
                    Texture texture;
                    if ( !texture.loadFromFile(route + "happy.png"))
                        cout << "Can't find the image" << endl;
                    Vector2f vector2f = matriz1.matriz_pixels[i][j];
                    aliado.setPosition(Vector2f(vector2f.x, vector2f.y + 2));
                    aliado.setTexture(texture);
                    window.draw(aliado);
                }
                if ( matriz1.matriz_pos[i][j] == 2 ) {
                    Sprite enemigo;
                    Texture texture;
                    if ( !texture.loadFromFile(route + "angry.png"))
                        cout << "Can't find the image" << endl;
                    Vector2f vector2f = matriz1.matriz_pixels[i][j];
                    enemigo.setPosition(Vector2f(vector2f.x, vector2f.y + 2));
                    enemigo.setTexture(texture);
                    window.draw(enemigo);
                }
                if( matriz1.matriz_pos[i][j] == 4){
                    Texture gem;
                    Sprite gemS;
                    switch(this->screen){
                        case 1:
                            if(!gem.loadFromFile(route + "gem1.png")){
                                std::cout << "Can't find the image" << std::endl;
                            }
                            break;
                        case 2:
                            if(!gem.loadFromFile(route + "gem2.png")){
                                std::cout << "Can't find the image" << std::endl;
                            }
                            break;
                        case 3:
                            if(!gem.loadFromFile(route + "gem3.png")){
                                std::cout << "Can't find the image" << std::endl;
                            }
                            break;
                        case 4:
                            if(!gem.loadFromFile(route + "gem4.png")){
                                std::cout << "Can't find the image" << std::endl;
                            }
                            break;
                        case 5:
                            if(!gem.loadFromFile(route + "gem5.png")){
                                std::cout << "Can't find the image" << std::endl;
                            }
                            break;
                    }
                    gemS.setPosition(matriz1.matriz_pixels[i][j]);
                    gemS.setTexture(gem);
                    window.draw(gemS);
                }
            }
        }
        window.display();

    }
}

// Inicia las matrices
window::Matriz window::iniciar_matriz() {
    window::matriz matriz1;
    for (int i = 0; i <= 22; i++) {
        for (int j = 0; j <= 42; j++) {
            matriz1.matriz_pixels[i][j] = Vector2f(5 + (j * 24) - (j * 1), 10 + (i * 26) - (i * 1));
        }
    }
    int contador = 0;
    for (int i = 0; i <= 42; i++) {
        contador = 0;
        for (int j = 0; j <= 22; j++) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0, 1);
            int random = dis(gen);
            if ( contador == 10 )
                random = 0;
            if ( random == 1 && i % 2 != 0 && i != 41 && i != 39 ) {
                matriz1.matriz_pos[j][i] = -1;
                contador++;
            } else
                matriz1.matriz_pos[j][i] = 0;
        }
    } //revisar
    matriz1.matriz_pos[10][0] = 3;
    matriz1.matriz_pos[11][0] = 3;
    matriz1.matriz_pos[11][42] = 4;

    return matriz1;
}

// Pregunta si alguien se esta moviendo
bool window::ismove(ejercito *lo) {
    for (int i = 0; i < 15; i++) {
        if ( lo[i].cabeza != nullptr ) {
            return true;
        }
    }
    return false;
}

// Busca la posicion del mouse al hacer click
int* window::buscarMouse() {

}

void window::checkLines(int* lines, string* impresion){
    if(*lines <= 20) {
        *lines += 1;
    }else{
        *impresion = "";
        *lines = 0;
    }
}
