#include <iostream>
#include <Box2d/Box2d.h>

int main(){
    //Creación del mundo y de la gravedad
    b2Vec2 gravity(0.0f,-1.62f);
    b2World world(gravity);

    //Características del cuerpo
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f,-10.0f);

    //Creamos el cuerpo, osea el piso
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    //Crear su forma
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f,1.0f);

    groundBody->CreateFixture(&groundBox, 0.0f);

    //Definimos un nuevo cuerpo, diciendo que es dinámico y su posición
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 20.0f);
    //Creamos el cuerpo
    b2Body*body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    //Definimos sus características como su forma de caja, densidad y fricción
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;

    body ->CreateFixture(&fixtureDef);

    float timeStep = 1.0f/60.0f;

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int i = 0; i < 150; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }

}