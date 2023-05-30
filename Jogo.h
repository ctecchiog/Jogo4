#pragma once
#include "Jogador.h"
#include <SFML/Graphics.hpp>
#include "stdafx.h"

class Jogo 
{
public:
    sf::RenderWindow window;
    Jogador jogador;
    std::vector<sf::RectangleShape> plataformas;
    std::vector<sf::RectangleShape> projeteis;

    Jogo();
    ~Jogo();
    void inputuser();
    void update();
    void render();
    void atirar();
    bool jogadornochao();
    void run();
};