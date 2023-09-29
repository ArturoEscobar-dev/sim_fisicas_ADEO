//Disparar en la luna de una bala de cañon (densidad libre) a velocidad de 900km/h a un angulo de 60°

#include <iostream>
#include <Box2D/Box2D.h>
#include <cmath>
//Definimos PI
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    // Definimos el vector de la gravedad.
    b2Vec2 gravity(0.0f, -1.62f);

    // Construimos un pbjeto mundo, que contendrá y simulará los objetos rígidos y dinámicos
    b2World world(gravity);

    // Creamos un cuerpo dinámico para la bala
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    // Definimos una forma de caja para el cuerpo de la bala
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.2f, 0.05f);

    // Definimos la fixture dinámica del cuerpo
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 6354.81f;
    fixtureDef.friction = 0.3f;

    // Añadimos la forma al cuerpo
    body->CreateFixture(&fixtureDef);

    // Colocamos la velocidad inicial de la bala
    float angle = 60.0f; // Angle in degrees
    //Simplemente convertí los 900km/h a m/s antes, porque 900km/h es igual a 250m/s
    float speed = 250.0f; // Speed in m/s
    float vx = speed * std::cos(angle * M_PI / 180.0f);
    float vy = speed * std::sin(angle * M_PI / 180.0f);

    body->SetLinearVelocity(b2Vec2(vx, vy));

    // Aquí simulamos el mundo
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        std::cout << body->GetPosition().x << " " << body->GetPosition().y << std::endl;

    }

    // Limpiamos el programa
    world.DestroyBody(body);

    return 0;
}
