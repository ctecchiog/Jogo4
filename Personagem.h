#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

class Personagem
{
protected:
	sf::RectangleShape forma;
	sf::Vector2f velocidade;
public:
	Personagem(sf::Vector2f position, sf::Vector2f size);
	~Personagem();
	sf::RectangleShape getForma();
	void setVelocidade(sf::Vector2f vel);
	sf::Vector2f getVelocidade();

};