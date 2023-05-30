#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

class Jogador
{
public:
    sf::RectangleShape forma;
    sf::Vector2f velocidade;
    bool pulando;

    Jogador(sf::Vector2f position, sf::Vector2f size);
    ~Jogador();
    void update();
    void pular();
    void aplicarGravidade();
};