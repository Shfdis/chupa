//
// Created by artem on 17.12.22.
//
#include "game.h"
int Game::get_window_h() { return Window_h; }

int Game::get_window_w() { return Window_w; }

void Game::draw(Player& player) {
    w.clear();
    for (auto& i : obs) {
        w.draw(i->get_texture());
    }
    w.draw(player.get_texture());
    for (auto& i : player.get_fireballs()) {
        w.draw(i.get_texture());
    }
    View view;
    view.setCenter(player.get_x() + player.get_w() / 2, player.get_y() - player.get_h() / 2);
    w.setView(view);
}

void Game::init(Player &player) {
    sf::Clock clock;
    float allTime = 0;
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
            player.go_right(obs);
        } if (Keyboard::isKeyPressed(Keyboard::Space)) {
            player.cast(allTime);
        }
        player.move(frame_time, obs);
        // w.clear();
        // w.draw(player.get_texture());
        draw(player);
        w.display();
    }
}

Game::Game() {
    chdir("..");
    obs.push_back(new game_obj(1000000, 1, .0, Window_h));
    // Texture txt;
    // txt.loadFromFile("./textures/wall.png");
    // const sf::Texture *pTexture = &txt;
    obs.push_back(new target(100, 100, 700, Window_h - 100));
    w.create(VideoMode(Window_w, Window_h), "Window");
    obs.push_back(new game_obj(100, 100, 500, 700));
    // obs[1]->get_texture().setTexture(pTexture, true);
    Player player(g, 100, w.getSize().y - 100);
    init(player);
}