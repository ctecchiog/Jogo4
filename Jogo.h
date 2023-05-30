#pragma once
#include "Jogador.h"
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
#include "stdafx.h"

class Jogo 
{
public:
    //sf::RenderWindow window;
    Jogador jogador;
    std::vector<sf::RectangleShape> plataformas;
    std::vector<sf::RectangleShape> projeteis;
    Gerenciador_Grafico* pGrafico;

    Jogo();
    ~Jogo();
    void inputuser();
    void update();
    void render();
    void atirar();
    bool jogadornochao();
    void run();
};