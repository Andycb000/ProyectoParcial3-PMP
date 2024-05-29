#include "Enemigo.hpp"
using namespace sf;
using namespace std;
#include <SFML/Graphics.hpp>


void Enemigo::movimientoY()
{
    this->sprite.move(this->velocity);
    if (this->sprite.getPosition().y == this->posicionMax.y)
    {
        this->velocity.y = this->velocity.y*-1;
    }
    if (this->sprite.getPosition().y == this->posicionMin.y)
    {
        this->velocity.y = this->velocity.y*-1;
    }
}

void Enemigo::defineMoveY(int bloques)
{
    this->velocity.y = -1;
    this->posicionMax = Vector2f(this->sprite.getPosition().x,this->sprite.getPosition().y+bloques*50);
    this->posicionMin = this->sprite.getPosition();
}

void Enemigo::movimientoX()
{
    this->sprite.move(this->velocity);
    if (this->sprite.getPosition().x == this->posicionMax.x)
    {
        this->velocity.x = this->velocity.x*-1;
    }
    if (this->sprite.getPosition().x == this->posicionMin.x)
    {
        this->velocity.x = this->velocity.x*-1;
    }
}

void Enemigo::defineMoveX(int bloques)
{
    this->velocity.x = -1;
    this->posicionMax = Vector2f(this->sprite.getPosition().x+bloques*50,this->sprite.getPosition().y);
    this->posicionMin = this->sprite.getPosition();
}

void Enemigo::movimientoDiagonal()
{
    this->sprite.move(this->velocity);
    if (this->sprite.getPosition().x == this->posicionMax.x)
    {
        this->velocity.x = this->velocity.x*-1;
        this->velocity.y = this->velocity.y*-1;
    }
    if (this->sprite.getPosition() == this->posicionMin)
    {
        this->velocity.x = this->velocity.x*-1;
        this->velocity.y = this->velocity.y*-1;
    }
}

void Enemigo::defineMove(Vector2f bloques)
{
    this->velocity = Vector2f(-1.f,-1.f);
    this->posicionMax = Vector2f(this->sprite.getPosition().x + bloques.x*50, this->sprite.getPosition().y+bloques.y*50);
    this->posicionMin = this->sprite.getPosition();
}
