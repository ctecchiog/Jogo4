#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

	class Gerenciador_Grafico
	{
		private:
			sf::RenderWindow* window;
			static Gerenciador_Grafico* pGrafico;
			Gerenciador_Grafico();
		public:

			~Gerenciador_Grafico();
			static Gerenciador_Grafico* getGerenciadorGrafico();
			sf::RenderWindow* getWindow();
			void limpaJanela();
			void desenhaElemento(sf::RectangleShape corpo);
			void mostraElementos();
			void fechaJanela();
			const bool verificaJanelaAberta();
	};
