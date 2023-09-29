
## Sinopsis
 En este código simulamos la caída de un objeto caja en un mundo con la gravedad de la tierra, también modificamos las propiedades físicas del objeto como su densidad y fricción, después de poner su altura, iniciamos la simulación y observamos que tanto cae durante un segundo.
## Explicación de temas físicos
### Gravedad 
La gravedad es un fenómeno natural por el cual los objetos y campos de materia dotados de masa o energía son atraídos entre sí, efecto mayormente observable en la interacción entre los planetas, galaxias y demás objetos del universo. Es una de las cuatro interacciones fundamentales que origina la fuerza que experimenta un cuerpo físico en las cercanías de un objeto astronómico. También se denomina interacción gravitatoria o gravitación.
### Densidad
El término “densidad” proviene del campo de la física y la química y alude a la relación que existe entre la masa de una sustancia (o de un cuerpo) y su volumen. Se trata de una propiedad intrínseca de la materia, ya que no depende de la cantidad de sustancia que se considere.
La densidad, propiedad que habitualmente se expresa en kilogramo por metro cúbico (kg/m3) o gramo por centímetro cúbico (g/cm3), varía en mayor o menor medida en función de la presión y la temperatura, y también con los cambios de estado.

### Fricción
La fuerza de fricción es la fuerza que existe entre dos superficies en contacto, que se opone al deslizamiento (fuerza de fricción estática y cinética).
## Código
#include <iostream>  
#include <Box2d/Box2d.h>  
  
int main(){  
    //Creación del mundo y de la gravedad  
    b2Vec2 gravity(0.0f,-9.81f);  
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
    fixtureDef.friction = 0.3f;  
  
    body ->CreateFixture(&fixtureDef);  
  //Definimos el ritmo al que el mundo dara un paso
    float timeStep = 1.0f/60.0f;  
  
    int32 velocityIterations = 6;  
    int32 positionIterations = 2;  
  
    for (int i = 0; i < 60; ++i)  
    {  
        world.Step(timeStep, velocityIterations, positionIterations);  
        b2Vec2 position = body->GetPosition();  
        float angle = body->GetAngle();  
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);  
    }  
}