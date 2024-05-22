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
};