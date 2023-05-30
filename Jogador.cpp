#include "Jogador.h"

Jogador::Jogador(sf::Vector2f position, sf::Vector2f size)
{
    forma.setPosition(position);
    forma.setSize(size);
    forma.setFillColor(sf::Color(255, 128, 128));
    velocidade.x = 0.0f;
    velocidade.y = 0.0f;
    pulando = false;
}

Jogador::~Jogador()
{
}
void Jogador::update() 
{
    forma.move(velocidade);
}

void Jogador::pular() 
{
    if (!pulando) {
        velocidade.y = -FORCA_PULO;
        pulando = true;
    }
}

void Jogador::aplicarGravidade() 
{
    velocidade.y += GRAVIDADE;
}