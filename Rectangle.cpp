#include "Rectangle.hpp"
#include <math.h>
#include <iostream>
using namespace std;

Bullet::Bullet(Vector2f Bsize)
{
    this->angle=0;
    this->go = true;
    this->next = false;
    this->playerSize = 25;

    this->bala = RectangleShape(Bsize);
    this->bala.setFillColor(Color::Red);

    this->speed = Vector2f(0.f,0.f);
    this->objective = Vector2f(0.f,0.f);
    this->origin = Vector2f(0.f,0.f);

    this->player = CircleShape(25.f);
    this->player.setFillColor(Color::Cyan);
    this->player.setOutlineThickness(2);
    this->player.setOutlineColor(Color::Red);
    //this->player.setPosition(origin.x - (this->bala.getSize().x/2), origin.y - (this->bala.getSize().y/2));
    this->player.setPosition(origin.x, origin.y);
    player.setOrigin(playerSize,playerSize);
}

Bullet::Bullet(Vector2f size, Vector2i position)
{
    this->angle=0;
    this->go = true;
    this->next = false;
    this->playerSize = 25;

    this->bala = RectangleShape(size);
    this->bala.setFillColor(Color::Cyan);

    this->speed = Vector2f(0.f,0.f);
    this->objective = Vector2f(0.f,0.f);
    this->bala.setPosition(Vector2f(position));

    this->player = CircleShape(20.f);
    this->player.setFillColor(Color::Cyan);
    this->player.setPosition(this->origin.x - (this->bala.getSize().x/2), this->origin.y - (this->bala.getSize().y/2));
}

void Bullet::Reset(){
        this->bala.setPosition(this->origin);
        this->speed = Vector2f(0.f,0.f);
        this->player.setFillColor(Color::Transparent);
        this->player.setOutlineColor(Color::Red);
        this->go = true;
        this->angle = -90;
}

void Bullet::update(int Wsizex, int Wsizey)
{
    if (go == false){
        this->bala.move(speed);
        this->player.setFillColor(Color::Red);
    }
    if (this->bala.getPosition().x >= Wsizex - this->bala.getSize().x || this->bala.getPosition().x <= 0 || this->bala.getPosition().y >= Wsizey - this->bala.getSize().y || this->bala.getPosition().y <= 0){
        this->Reset();
    }
    
}

void Bullet::setObjective(Vector2f objective)
{
    if (go == true){
    this->go = false; 
    this->vel = 30;
    this->objective.x = objective.x;
    this->objective.y = objective.y;
    this->difx= this->objective.x - this->bala.getPosition().x;
    this->dify= this->objective.y - this->bala.getPosition().y;
    if (difx!=0 && dify!=0){
    this->distot = sqrt (pow(difx,2) + pow(dify,2));
    this->speed.x = (difx/distot) * vel;
    this->speed.y = (dify/distot) * vel;
    }else{
        this->go=true;
    }

    if (difx > 0 && dify < 0){
        this->dify=this->dify * -1;
        this->angle = atan(this->dify/this->difx);
        this->angle= -1 * ((this->angle*180)/3.1416);
    }else{
        if (difx < 0 && dify > 0){
            this->difx=this->difx * -1;
            this->angle = atan(this->dify/this->difx);
            this->angle= 180 - ((this->angle*180)/3.1416);
        }else{
            if (difx < 0 && dify < 0){
                this->angle = atan(this->dify/this->difx);
                this->angle= 180 + ((this->angle*180)/3.1416);
            }else {
                if(difx > 0 && dify > 0){
                    this->angle = atan(this->dify/this->difx);
                    this->angle=((this->angle*180)/3.1416);
                }
            }
        }
    }
    if (difx == 0 && dify < 0){
        this->angle=-90;
        this->player.setOutlineColor(Color::Magenta);
        this->speed.y = 20;
    }
    if (difx == 0 && dify > 0){
        this->angle=90;
        this->player.setOutlineColor(Color::Magenta);
        this->speed.y = 20;
    }
    if (difx < 0 && dify == 0){
        this->angle=180;
        this->player.setOutlineColor(Color::Magenta);
        this->speed.x = 20;
    }
    if (difx > 0 && dify == 0){
        this->angle=0;
        this->player.setOutlineColor(Color::Magenta);
        this->speed.x = 20;
    }
}
}

void Bullet::setOrigin(Vector2f origin)
{
    this->origin = origin;
    this->player.setPosition(this->origin.x, this->origin.y);
    if (go==true){
    this->bala.setPosition(this->origin.x,this->origin.y);
    }
}

void Bullet::drawTo(RenderWindow &window)
{
    window.draw(this->bala);
    window.draw(this->player);
}
