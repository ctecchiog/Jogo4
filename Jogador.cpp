#include "Jogador.h"

Jogador::Jogador(sf::Vector2f position, sf::Vector2f size): 
    Personagem (position, size), pulando (false)
{
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

bool Jogador::getPulando()
{
    return pulando;
}
