#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

constexpr float SCALE = 30.0f;

class Cube {
public:
    Cube(b2World &world, float x, float y) {
        b2BodyDef bodydef;
        bodydef.position.Set(x / SCALE, y / SCALE);
        bodydef.type = b2_dynamicBody;
        body = world.CreateBody(&bodydef);

        b2PolygonShape shape;
        shape.SetAsBox((10.f / 2) / SCALE, (10.f / 2) / SCALE);

        b2FixtureDef fixturedef;
        fixturedef.shape = &shape;
        fixturedef.density = 1.0f;
        body->CreateFixture(&fixturedef);

        box.setSize(sf::Vector2f(10.f, 10.f));
        box.setFillColor(sf::Color::Red);
        box.setOrigin(5.f, 5.f);
    }

    void update() {
        box.setPosition(SCALE * body->GetPosition().x, SCALE * body->GetPosition().y);
        box.setRotation(body->GetAngle() * 180 / b2_pi);
    }

    void draw(sf::RenderWindow &win) const {
        win.draw(box);
    }

    void resetPosition() {
        body->SetTransform(b2Vec2(0, 0), body->GetAngle());
    }

    void stop() {
        body->SetLinearVelocity(b2Vec2(0, 0));
    }

    b2Body *getBody() {
        return body;
    }

private:
    sf::RectangleShape box;
    b2Body *body;
};

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 900), "SFML works!");

    b2Vec2 gravity(0.0f, 0.0f);
    b2World world(gravity);

    Cube cube(world, 400, 300);

    Cube cube2(world, 200, 300);

    /*
        //para tener menos cpodigo
        #Pragma region Nombre
          #Pragma endregion

     //Definiciones
    //Mundo, posX, posY, Dinamico, densidad
    Cube plataforma1(world,520,440, true,1);
    Cube plataforma2(world,220,750, true,1);
    Cube ancla1(world,520,100, false,0);
    Cube ancla2(world,220,500, false,0);
//Joint

 b2PulleyJointDef jointPulley;

jointPulley.Initialize(plataforma1.getBody(),plataforma2.getBody(),ancla1.getBody()->GetWorldCenter(),ancla2.getBody()->GetWorldCenter(),plataforma1.getBody()->GetWorldCenter(),plataforma2.getBody()->GetWorldCenter(), 1);
    world.CreateJoint(&jointPulley);
     */

    b2DistanceJointDef jointDef;

    jointDef.Initialize(cube.getBody(), cube2.getBody(),cube.getBody() -> GetWorldCenter(),cube2.getBody() -> GetWorldCenter() );
    jointDef.collideConnected = true;
    float frequencyHz = 30.0f;
    float dampingRatio = 0.0f;
    b2LinearStiffness(jointDef.stiffness, jointDef.damping,frequencyHz, dampingRatio,
                      jointDef.bodyA, jointDef.bodyB);

    world.CreateJoint(&jointDef    );


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                cube.getBody()->ApplyForceToCenter(b2Vec2(0.1f, 0.0f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                cube.getBody()->ApplyForceToCenter(b2Vec2(-0.1f, 0.0f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                cube.getBody()->ApplyForceToCenter(b2Vec2(0.0f, -0.1f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                cube.getBody()->ApplyForceToCenter(b2Vec2(0.0f, 0.1f), true);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                cube.resetPosition();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                cube.stop();
            }

            // The Z key event to close the window
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                window.close();
                return 0; // return from the main function, effectively ending the program
            }
        }

        world.Step(1 / 60.f, 8, 3);
        cube.update();
        cube2.update();
        window.clear();
        cube.draw(window);
        cube2.draw(window);
        window.display();
    }
    return 0;
}
