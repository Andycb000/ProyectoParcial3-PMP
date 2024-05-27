#include "Rectangle.hpp"
#include "Niveles.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

int Wsizex = 1700;
int Wsizey = 900;
int level = 1;
int Lplay = level;
int collisions = 0;
bool enemigos = 0;
bool ok=0;

int main()
{
    sf::Texture Tbala;
    Tbala.loadFromFile("./Bala4.png");
    sf::Sprite Sbala(Tbala);  //BALA    BALA    BALA    BALA    BALA
    Sbala.setOrigin(16,16);
    vector <sf::Sprite> niveles;


    sf::Texture Bloque;
    Bloque.loadFromFile("./Block.png");
    sf::Sprite Estructures(Bloque);   //BLOCK   BLOCK   BLOCK   BLOCK   BLOCK 

    sf::Texture BloqueArenaTop;
    BloqueArenaTop.loadFromFile("./Block_middle_top.png");
    sf::Sprite EstructuresMidTop(BloqueArenaTop);   //BLOCK   BLOCK   BLOCK   BLOCK   BLOCK MIDTOP

    sf::Texture BloqueArenaFill;
    BloqueArenaFill.loadFromFile("./Block_Fill.png");
    sf::Sprite EstructuresFill(BloqueArenaFill);   //BLOCK   BLOCK   BLOCK   BLOCK   BLOCK Fill

    sf::Texture Alien;
    Alien.loadFromFile("./Alien2.png");
    sf::Sprite Enemigo(Alien);

    // setup
    RenderWindow window(VideoMode(Wsizex, Wsizey), "SFML works!");
    window.setFramerateLimit(60);
    Bullet rect(Vector2f(20,20));
    rect.bala.setOrigin(10,10);
    // loop

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {


            if (event.type == Event::Closed)
                window.close();

             if(event.type == Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    rect.setObjective(Vector2f(x,y));
                }
                if(event.mouseButton.button == Mouse::Right)
                {
                    int Xx = event.mouseButton.x;
                    int Yy = event.mouseButton.y;
                    if (1){
                    rect.setOrigin(Vector2f(Xx,Yy));
                    }
                }
            }
        
            
        
            

        }
        if (rect.go == false){
                for (int i=0;i<Tilset.size();i++){
                    if (Sbala.getGlobalBounds().intersects(Tilset[i].getGlobalBounds())){
                        collisions++;
                        std::cout<<collisions<<"| COLLISION"<<std::endl<<std::endl;
                        rect.Reset();
                        Lplay++;
                        break;
                    }
                }

            }

            //movimiento de enemigos (Andy)

            if (enemigos==1){ //si hay un enemigo, evita bug

                if (level==2){
                    if (ok==0){
                        Enemies[0].defineMoveY(-1);
                        Enemies[1].defineMove(Vector2f(-3.f,-2.f));
                    ok=1;
                    }
                    Enemies[0].movimientoY();
                    Enemies[1].movimientoDiagonal();
                }

                if (level==3){

                    if (ok==0){
                    Enemies[0].defineMoveY(-1);
                    ok=1;
                    }
                    Enemies[0].movimientoY();
                }
            }
        window.clear();
        rect.update(Wsizex,Wsizey);
        if (level==Lplay){
        updateTiles(level, Enemigo, Estructures, EstructuresMidTop, EstructuresFill);
        rect.setOrigin(Vector2f(nivels[level].Pposx,nivels[level].Pposy));
        level++;
        ok=0;
        }
        TilesetDrawTo(window, enemigos);
        rect.drawTo(window);
        Sbala.setPosition(rect.bala.getPosition().x, rect.bala.getPosition().y);
        Sbala.setRotation(rect.angle);
        window.draw(Sbala);
        window.display();
    }

    return 0;
}