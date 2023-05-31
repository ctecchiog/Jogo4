#include "Personagem.h"

Personagem::Personagem(sf::Vector2f position, sf::Vector2f size):
    velocidade (0.0f,0.0f)
{
    forma.setPosition(position);
    forma.setSize(size);
    forma.setFillColor(sf::Color(255, 128, 128));
    //velocidade.x = 0.0f;
    //velocidade.y = 0.0f;
}

Personagem::~Personagem()
{
}

sf::RectangleShape Personagem::getForma()
{
    return forma;
}

void Personagem::setVelocidade(sf::Vector2f vel)
{
    velocidade = vel;
}

sf::Vector2f Personagem::getVelocidade()
{
    return velocidade;
}
