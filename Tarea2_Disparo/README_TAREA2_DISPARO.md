## Sinopsis
En este código simulamos el disparo de una bala de cañon en la luna. 
La densidad de la bala de cañon la decidí calculando la densidad de una bola de cañon de tamaño promedio usado en barcos de guerra, también fue disparado a una velocidad de 900km/s, que convertido a m/s sería 250m/s, y a un ángulo de 60°, la fricción fue un numero aleatorio.

## Explicación de temas físicos
### Gravedad 
La gravedad es un fenómeno natural por el cual los objetos y campos de materia dotados de masa o energía son atraídos entre sí, efecto mayormente observable en la interacción entre los planetas, galaxias y demás objetos del universo. Es una de las cuatro interacciones fundamentales que origina la fuerza que experimenta un cuerpo físico en las cercanías de un objeto astronómico. También se denomina interacción gravitatoria o gravitación.
### Densidad
El término “densidad” proviene del campo de la física y la química y alude a la relación que existe entre la masa de una sustancia (o de un cuerpo) y su volumen. Se trata de una propiedad intrínseca de la materia, ya que no depende de la cantidad de sustancia que se considere.
La densidad, propiedad que habitualmente se expresa en kilogramo por metro cúbico (kg/m3) o gramo por centímetro cúbico (g/cm3), varía en mayor o menor medida en función de la presión y la temperatura, y también con los cambios de estado.
### Fricción
La fuerza de fricción es la fuerza que existe entre dos superficies en contacto, que se opone al deslizamiento (fuerza de fricción estática y cinética).
### Velocidad
La velocidad es el cambio de posición de un objeto con respecto al tiempo.

## Código
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
    //Simplemente convertí los 900km/h a m/s antes, porque 900km/h es igual a 250m/s    float speed = 250.0f; // Speed in m/s  
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