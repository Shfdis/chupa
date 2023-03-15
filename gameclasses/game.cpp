//
// Created by artem on 17.12.22.
//

#include "game.h"
int Game::get_window_h() { return Window_h; }

int Game::get_window_w() { return Window_w; }

void Game::init(Player &player) {
    sf::Shader shader;
    shader.loadFromFile("/home/artem/chupa/gameclasses/KALGOVNA.frag", sf::Shader::Fragment);

    sf::Clock clock;
    float allTime;
    while (w.isOpen()) {
        //float now = ;
        Event event;
        while (w.pollEvent(event)) {
            if (event.type == Event::Closed) {
                w.close();
            }
        }
        float frame_time = clock.restart().asSeconds();
        allTime += frame_time;
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            player.jump(obs);
        } if (Keyboard::isKeyPressed(Keyboard::A)) {
            player.go_left(obs);
        } if (Keyboard::isKeyPressed(Keyboard::D)) {
            player.go_right(obs);
        }
        player.move(frame_time, obs);
        w.clear();
        shader.setUniform("time", allTime);
        w.draw(player.get_texture(), &shader);
        w.display();
    }
}

Game::Game() {
    obs.push_back(game_obj(1000000, 1, .0, Window_h));
    obs.push_back(game_obj(100, 1000, 500, 900));
    w.create(VideoMode(Window_w, Window_h), "Window");
    Player player(g, 100.f, w.getSize().y - 100.f);
    init(player);
}