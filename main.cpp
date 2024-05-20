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

int checkX;
int checkY;

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
                        break;
                    }
                }
            }


        window.clear();
        rect.update(Wsizex,Wsizey);
        if (level==Lplay){
        updateTiles(level, Estructures, Enemigo);
        rect.setOrigin(Vector2f(nivels[level].Pposx,nivels[level].Pposy));
        level++;
        }
        TilesetDrawTo(window);
        rect.drawTo(window);
        Sbala.setPosition(rect.bala.getPosition().x, rect.bala.getPosition().y);
        Sbala.setRotation(rect.angle);
        window.draw(Sbala);
        window.display();
    }

    return 0;
}