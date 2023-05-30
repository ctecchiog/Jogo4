#include "Jogo.h"

    Jogo::Jogo() : 
        jogador(Jogador(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(50.0f, 50.0f))),
        pGrafico(pGrafico->getGerenciadorGrafico())
    {
        sf::RectangleShape plataforma1(sf::Vector2f(200.0f, 20.0f));
        plataforma1.setPosition(400.0f, 500.0f);
        plataformas.push_back(plataforma1);

        sf::RectangleShape plataforma2(sf::Vector2f(200.0f, 20.0f));
        plataforma2.setPosition(600.0f, 400.0f);
        plataformas.push_back(plataforma2);

        sf::RectangleShape plataforma3(sf::Vector2f(200.0f, 20.0f));
        plataforma3.setPosition(800.0f, 300.0f);
        plataformas.push_back(plataforma3);

        sf::RectangleShape plataforma4(sf::Vector2f(200.0f, 20.0f));
        plataforma4.setPosition(100.0f, 550.0f);
        plataformas.push_back(plataforma4);

        sf::RectangleShape plataforma5(sf::Vector2f(1500.0f, 100.0f));
        plataforma5.setPosition(0.0f, 680.0f);
        plataformas.push_back(plataforma5);

        sf::RectangleShape plataforma6(sf::Vector2f(100.0f, 100.0f));
        plataforma6.setPosition(600.0f, 600.0f);
        plataformas.push_back(plataforma6);

        sf::RectangleShape plataforma7(sf::Vector2f(100.0f, 200.0f));
        plataforma7.setPosition(1000.0f, 550.0f);
        plataformas.push_back(plataforma7);
    }
    
    Jogo::~Jogo()
    {
    }
    
    void Jogo::inputuser() 
    {
        sf::Event event;
        while (pGrafico->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGrafico->fechaJanela();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    pGrafico->fechaJanela();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space)
                    atirar();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            jogador.velocidade.x = -MOVER;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            jogador.velocidade.x = MOVER;
        else
            jogador.velocidade.x = 0.0f;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            jogador.pular();
    }

    void Jogo::update() 
    {
        jogador.aplicarGravidade();
        jogador.update();

        // Colisao plataforma jogador
        for (const auto& platforma : plataformas) {
            if (jogador.forma.getGlobalBounds().intersects(platforma.getGlobalBounds())) {
                jogador.velocidade.y = 0.0f;
                jogador.forma.setPosition(jogador.forma.getPosition().x, platforma.getPosition().y - jogador.forma.getSize().y);
                jogador.pulando = false;
            }
        }

        //projeteis movimento
        for (auto& projetil : projeteis) {
            projetil.move(5.0f, 0.0f);

            // Fazer parte de colisão com inimigos aqui
        }
    }

    void Jogo::render() 
    {
        pGrafico->limpaJanela();;

        pGrafico->desenhaElemento(jogador.forma);

        for (const auto& plataforma : plataformas)
            pGrafico->desenhaElemento(plataforma);

        for (const auto& projetil : projeteis)
            pGrafico->desenhaElemento(projetil);

        pGrafico->mostraElementos();
    }

    void Jogo::atirar() 
    {
        sf::RectangleShape projetil(sf::Vector2f(10.0f, 5.0f));
        projetil.setPosition(jogador.forma.getPosition().x + jogador.forma.getSize().x, jogador.forma.getPosition().y + jogador.forma.getSize().y / 2.0f);
        projetil.setFillColor(sf::Color::Red);
        projeteis.push_back(projetil);
    }

    bool Jogo::jogadornochao() 
    {
        // Colisao com plataformas
        for (const auto& plataforma : plataformas) 
{
            sf::FloatRect limitesjogador = jogador.forma.getGlobalBounds();
            sf::FloatRect limitesplataforma = plataforma.getGlobalBounds();
            sf::FloatRect intersection;
            if (limitesjogador.intersects((limitesplataforma), intersection)) {
                if (jogador.velocidade.y >= 0 && intersection.height <= 2.0f) {
                    return true;
                }
            }
        }
        return false;
    }

    void Jogo::run() 
    {
        while (pGrafico->verificaJanelaAberta()) {
            inputuser();
            update();
            render();
        }
    }


