#ifndef Rectangle_h
#define Rectangle_h

#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet{
public:


    Vector2f speed;
    Vector2f objective;
    Vector2f origin;
    RectangleShape bala;
    CircleShape player;
    float vel;
    float difx;
    float dify;
    float distot;
    float angle;
    float playerSize;
    bool go;

    Bullet(Vector2f Bsize);
    Bullet(Vector2f size, Vector2i position);

    void update(int Wsizex, int Wsizey);
    void setObjective(Vector2f objective);
    void setOrigin(Vector2f origin);
    void drawTo(RenderWindow &window);
    void Reset();
};

#endif