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
int Lplay = level-1;
int collisions = 0;
bool enemigos = 0;
int kills=0;
bool ok=0;

float difx;
float dify;
float intX;
float intY;

int main()
{
    sf::Texture Tbala;
    Tbala.loadFromFile("./Bala4.png");
//emilio
sf::Texture Fondo;
    Fondo.loadFromFile("./Bala4.png");

    sf::Sprite Sbala(Tbala);  //BALA    BALA    BALA    BALA    BALA
    Sbala.setOrigin(16,16);
    vector <sf::Sprite> niveles;

    sf::Texture RBloque;
    RBloque.loadFromFile("./Bloque3.png");
    sf::Sprite RBLOCK(RBloque);   //REBOTE  REBOTE  REBOTE  REBOTE  REBOTE 
    
    
        sf::Texture Fill;
        Fill.loadFromFile("sprites/Bb.png");
        sf::Sprite BlockBb(Fill);

        sf::Texture Out;
        Out.loadFromFile("sprites/O.png");
        sf::Sprite BlockO(Out);

        sf::Texture Up;
        Up.loadFromFile("sprites/GroundWall.png");
        sf::Sprite Blockl(Up);

        sf::Texture Up2;
        Up2.loadFromFile("sprites/NoTopBottom.png");
        sf::Sprite Blockl_l(Up2);

        sf::Texture Up3;
        Up3.loadFromFile("sprites/UpNoSides.png");
        sf::Sprite Blocklul(Up3);

        sf::Texture Up4;
        Up4.loadFromFile("sprites/Border.png");
        sf::Sprite Blockul(Up4);

        sf::Texture Up5d;
        Up5d.loadFromFile("sprites/BorderPoint.png");
        sf::Sprite Blockpul(Up5d);

        sf::Texture Dot1;
        Dot1.loadFromFile("sprites/Point1.png");
        sf::Sprite Blockp1(Dot1);

        sf::Texture Dot2;
        Dot2.loadFromFile("sprites/Point2.png");
        sf::Sprite Blockp2(Dot2);

        sf::Texture Dot3;
        Dot3.loadFromFile("sprites/Point3.png");
        sf::Sprite Blockp3(Dot3);

        sf::Texture Dot4;
        Dot4.loadFromFile("sprites/Point4.png");
        sf::Sprite Blockp4(Dot4);
    
     
    sf::Texture Bloque;
    Bloque.loadFromFile("./Block.png");
    sf::Sprite Estructures(Bloque);   //BLOCK   BLOCK   BLOCK   BLOCK   BLOCK 

    sf::Texture CosoRojo;
    CosoRojo.loadFromFile("./CosaMouse.png");
    sf::Texture juga;
    juga.loadFromFile("./Player1.png");

    sf::Mouse mouse;
    RectangleShape cursor;
    cursor.setSize(Vector2f(50,50));
    cursor.setTexture(&CosoRojo);
//Emilio
      sf::Texture AlienMuerto;
    AlienMuerto.loadFromFile("./AlienMuerto.png");
    sf::Sprite EnemigoDead(AlienMuerto);   //BLOCK   agregar el alien muerto

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
    rect.player.setTexture(&juga);
    window.setMouseCursorVisible(false);
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
                    rect.setObjective(Vector2f(x,y));//igual que la sumativa
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
        if (rect.go == false){//checa que la bala este fuera no se si si sirva para algo pero igual
                for (int i=0;i<Tilset.size();i++){
                    if (Sbala.getGlobalBounds().intersects(Tilset[i].getGlobalBounds())){
                        collisions++;
                        std::cout<<collisions<<"| COLLISION"<<std::endl<<std::endl;
                        rect.Reset();
                        break;
                    }
                }//checa colisiones con todos los bloques del nivel

            }
            for (int i=0;i<Enemies.size();i++){
                    if (Sbala.getGlobalBounds().intersects(Enemies[i].sprite.getGlobalBounds()) && Enemies[i].alife==1)
                    {
                        Enemies[i].alife=0;
                        rect.Reset();
                        kills++;
                         Enemies[i].sprite = EnemigoDead; //agregar el sprite muerto
                        break;
                                            
                    }
                }//checa colisiones con todos los enemigos
//Emilio
 for (int i=0;i<Rbloque.size();i++){
                    if (Sbala.getGlobalBounds().intersects(Rbloque[i].sprite.getGlobalBounds()))
                    {
                        difx = Sbala.getPosition().x - Rbloque[i].sprite.getPosition().x;
                        dify = Sbala.getPosition().y - Rbloque[i].sprite.getPosition().y;
                        intX = abs(difx) - 50;
                        intY = abs(dify) - 50;//para colisiones Y y X;

                        if (intX < intY){
                            Sbala.setScale(Sbala.getScale().x,Sbala.getScale().y*-1);
                            rect.speed.y=rect.speed.y*-1;
                        }else{
                            Sbala.setScale(Sbala.getScale().x*-1,Sbala.getScale().y);
                            rect.speed.x=rect.speed.x*-1;
                        }
                        break;
                    }
                }//checa colisiones con los slimes
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
        if (kills==nivels[level-1].toKill)
        {
            Lplay++;
            kills=0;
        }//cambia de nivel si ya mataste todos los enemigos
        if (level==Lplay && level<nivels.size()){
        updateTiles(level, Enemigo, BlockO, Blockl, BlockBb, RBLOCK);
        rect.setOrigin(Vector2f(nivels[level].Pposx,nivels[level].Pposy));
        level++;
        ok=0;
        }//cambia de nivel
        TilesetDrawTo(window, enemigos);
        Sbala.setPosition(rect.bala.getPosition().x, rect.bala.getPosition().y);
        Sbala.setRotation(rect.angle);
        window.draw(Sbala);
        if (rect.go == true)Sbala.setScale(1,1);
        for (int i=0;i<Rbloque.size();i++)
        {
            window.draw(Rbloque[i].sprite);
        }
        cursor.setOrigin(25,25);
        cursor.setPosition(mouse.getPosition().x - window.getPosition().x-10,mouse.getPosition().y - window.getPosition().y-40);
        rect.drawTo(window);
        window.draw(cursor);
        window.display();
    }

    return 0;
}
