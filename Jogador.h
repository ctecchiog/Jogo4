#pragma once
#include "stdafx.h"
#include "Personagem.h"
#include <SFML/Graphics.hpp>

class Jogador: public Personagem
{
private:
    bool pulando;
public:
    Jogador(sf::Vector2f position, sf::Vector2f size);
    ~Jogador();
    void update();
    void pular();
    void aplicarGravidade();
    bool getPulando();
};