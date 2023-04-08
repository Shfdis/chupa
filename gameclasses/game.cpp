//
// Created by artem on 17.12.22.
//

#include "game.h"
int Game::get_window_h() { return Window_h; }

int Game::get_window_w() { return Window_w; }

void Game::draw(Player& player) {
    w.clear();
    for (auto& i : obs) {
        w.draw(i.get_texture());
    }
    w.draw(player.get_texture());
    for (auto& i : player.get_fireballs()) {
        w.draw(i.get_texture());
    }
}

void Game::init(Player &player) {
    sf::Clock clock;
    float allTime;
    while (w.isOpen()) {
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
            cerr << 1 << '\n';
            player.go_right(obs);
        } if (Keyboard::isKeyPressed(Keyboard::Space)) {
            player.cast();
        }
        player.move(frame_time, obs);
        // w.clear();
        // w.draw(player.get_texture());
        draw(player);
        w.display();
    }
}

Game::Game() {
    obs.push_back(game_obj(1000000, 1, .0, Window_h));
    obs.push_back(game_obj(100, 100, 500, 700));
    w.create(VideoMode(Window_w, Window_h), "Window");
    Player player(g, 100, w.getSize().y - 100);
    init(player);
}