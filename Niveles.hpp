#include <SFML/Graphics.hpp>
#include "Enemigo.hpp"
#include "Rebote.hpp"
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

struct Niveles{
    int Pposx;
    int Pposy;
    int toKill;
    int mapa[18][34];
};

Enemigo firstENE;
vector <Rebote> Rbloque;
Rebote firstREB;

sf::Texture Tiles;
//Tiles.loadFromFile("./block.png");
vector <RectangleShape> tileset;
vector <sf::Sprite> Tilset;
vector <Enemigo> Enemies; 
//agregar niveles
  //NIVELES v v NIVELES v v NIVELES v v NIVELES v v NIVELES
vector <Niveles> nivels = {{100,100,0,{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
}
//LEVEL 0
},{875,175,0,{
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,0,0,0,0,2,1,1,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,}
}// LEVEL 1
},{825,625,0,{
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,},
{1,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1,1,},
{1,0,0,1,1,1,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,1,},
{1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,},
{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
{1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,},
{1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,0,0,1,},
{1,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,2,0,1,0,0,1,},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,}
}// LEVEL
}
};

void updateTiles(int level, sf::Sprite alienado, sf::Sprite arena, sf::Sprite arenaMidTop, sf::Sprite arenaFill, sf::Sprite rebote, sf:: AlienMuerto){
    Tilset.clear();
    Enemies.clear();
    Rbloque.clear();
    for (int y=0;y<18;y++){
        for (int x=0;x<34;x++){
            if (nivels[level].mapa[y][x]==1){
                /*
                tileset.push_back(RectangleShape());
                tileset.back().setSize(Vector2f(50,50));
                tileset.back().setPosition(x*50,y*50);
                tileset.back().setFillColor(Color::Black);
                tileset.back().setOutlineThickness(1);
                tileset.back().setOutlineColor(Color::Magenta);
                */
               if (nivels[level].mapa[y-1][x]==0 && nivels[level].mapa[y+1][x]==1 && nivels[level].mapa[y][x+1]==1 && nivels[level].mapa[y][x-1]==1 && y!=0 ){
                Tilset.push_back(arenaMidTop);
                Tilset.back().setPosition(x*50+25,y*50+25);
                Tilset.back().setOrigin(25,25);
               }else {
                if (nivels[level].mapa[y-1][x]==1 && nivels[level].mapa[y+1][x]==1 && nivels[level].mapa[y][x+1]==1 && nivels[level].mapa[y][x-1]==1){
                    Tilset.push_back(arenaFill);
                    Tilset.back().setPosition(x*50+25,y*50+25);
                    Tilset.back().setOrigin(25,25);
                }else {
                    Tilset.push_back(arena);
                    Tilset.back().setPosition(x*50+25,y*50+25);
                    Tilset.back().setOrigin(25,25);
                }
               }
            }

            //emilio
            if (nivels[level].mapa[y][x]==2){
                firstENE.sprite = alienado;
                firstENE.alife=1;
                Enemies.push_back(firstENE);
                Enemies.back().sprite.setPosition(x*50+25,y*50+25);
                Enemies.back().sprite.setOrigin(25,25);
                nivels[level].toKill++;
            }
            if (nivels[level].mapa[y][x]==3)
            {
                firstREB.sprite = rebote;
                Rbloque.push_back(firstREB);
                Rbloque.back().sprite.setPosition(x*50+25,y*50+25);
                Rbloque.back().sprite.setOrigin(25,25);
            }
        }   
    } 
}

void TilesetDrawTo(RenderWindow &window, bool &enemigos){
    for (int i=0;i<Tilset.size();i++){
        //window.draw(tileset[i]);
        window.draw(Tilset[i]);
    }
    for (int i=0;i<Enemies.size();i++){

        window.draw(Enemies[i].sprite);
        if (enemigos==0){
        enemigos=1;
        }
    }
}
