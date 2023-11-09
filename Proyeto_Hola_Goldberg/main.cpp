#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

constexpr float SCALE = 30.0f;
//Declaramos las dos clases que vamos a usar
class Cube {
public:
    Cube(b2World &world, float x, float y, bool Dynamic, float h,float w,float ang, float density) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        if(Dynamic) {
            bodydef.type = b2_dynamicBody;
        }
        bodydef.angle = ang * b2_pi;
        OrgAngle = ang * b2_pi;
        body = world.CreateBody(&bodydef);
        origin = b2Vec2(x/SCALE, y/SCALE);
        b2PolygonShape shape;
        shape.SetAsBox((h / 2) / SCALE, (w / 2) / SCALE);

        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.density = density;
        body->CreateFixture(&fixturedef);

        box.setSize(sf::Vector2f(h, w));

        box.setOrigin(h/2, w/2);
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
        box.setFillColor(sf::Color::Blue);
    }

    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    void color(sf::Color color){
        box.setFillColor(color);
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
    b2Vec2 origin;
    float OrgAngle;
};

class Circle {
public:
    Circle(b2World &world, float x, float y, bool Dynamic, float h,float w,float r,float density) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        if(Dynamic){
            bodydef.type = b2_dynamicBody;
        }

        body = world.CreateBody( &bodydef);
        origin = b2Vec2(x/SCALE, y/SCALE);
        b2CircleShape circle;
        circle.m_p.Set((h/2)/SCALE, (w/2)/SCALE);
        circle.m_radius = r/SCALE;

        b2FixtureDef fixturedef;
        fixturedef.shape = &circle;
        fixturedef.density = density;
        body->CreateFixture(&fixturedef);

        cir.setRadius(r);
        cir.setFillColor(sf::Color::Red);
        cir.setOrigin(h/2, w/2);
    }

    void update() {
        cir.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        cir.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(cir);
    }

    void color(sf::Color color){
        cir.setFillColor(color);
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::CircleShape cir;
    b2Body *body;
    b2Vec2 origin;
};






int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");
    b2Vec2 gravity(0.0f, 0.01f);
    b2World world(gravity);


    //Actores
    Circle circulo(world,75,75,true,10,10,10,1);
    Cube domino1(world, 450, 330,true,50,10,.5,2);
    Cube domino2(world, 440, 530,true,50,10,.5,5);
    Circle circulo2(world,745,590,true,10,10,10,1);

    domino1.color(sf::Color::White);
    circulo2.color(sf::Color::Green);

    //Plataformas
    Cube plataforma1(world, 10, 280,false,300,10,0.1,0);
    Cube plataforma2(world, 310, 350,false,300,10,0,0);
    Cube plataforma3(world, 700, 80,false,40,10,0,0);
    Cube plataforma4(world, 690, 150,false,10,1000,1,0);
    Cube plataforma5(world, 850, 350,false,150,10,0,0 );

    //PulleyJointComponents
    Cube elevador1(world, 530, 400,true,100,10,0,1);
    Cube elevador2(world, 700, 600, true,100,10,0,1);
    Cube anchor1(world, 530, 100,false,10,10,0,0);
    Cube anchor2(world, 720, 100,false,10,10,0,0);

    //Pulley
    b2PulleyJointDef jointPul;
    jointPul.Initialize(elevador1.getBody(),elevador2.getBody(),anchor1.getBody()->GetWorldCenter(),anchor2.getBody()->GetWorldCenter(),elevador1.getBody()->GetWorldCenter(),elevador2.getBody()->GetWorldCenter(), 1);
    world.CreateJoint(&jointPul);

    while (window.isOpen()) {
        sf::Event event;

        circulo.getBody()->ApplyForceToCenter(b2Vec2(0.f,0.2f), true);
        domino1.getBody()->ApplyForceToCenter(b2Vec2(0.f,0.07f), true);
        while (window.pollEvent(event)) {
            // The Z key event to close the window
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                window.close();
                return 0; // return from the main function, effectively ending the program
            }
        }


        world.Step(1 / 60.f, 8, 3);


        circulo2.update();
        elevador1.update();
        elevador2.update();
        circulo.update();
        domino1.update();
        domino2.update();
        window.clear();

        plataforma5.draw(window);
        plataforma4.draw(window);
        plataforma3.draw(window);
        circulo2.draw(window);
        anchor2.draw(window);
        anchor1.draw(window);
        elevador2.draw(window);
        elevador1.draw(window);
        domino1.draw(window);
        domino2.draw(window);
        plataforma1.draw(window);
        plataforma2.draw(window);
        circulo.draw(window);
        window.display();
    }

    return 0;
}