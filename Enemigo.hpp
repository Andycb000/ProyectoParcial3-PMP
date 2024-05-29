#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;

class Enemigo
{
    public:
    sf::Sprite sprite;
    Vector2f velocity;
    Vector2f posicionMax;
    Vector2f posicionMin;
    bool alife;

    void movimientoY();
    void movimientoX();
    void defineMoveX(int bloques);
    void defineMoveY(int bloques);
    void movimientoDiagonal();
    void defineMove(Vector2f bloques);

};