//
// Created by artem on 17.12.22.
//
#include "game.h"
int Game::get_window_h() { return Window_h; }

int Game::get_window_w() { return Window_w; }

void Game::draw(Player& player, float t) {
    vector<int> to_del;
    for (int i = 0; i < obs.size(); i++) {
        if (obs[i]->explodes) {
            if (obs[i]->update(t)) to_del.push_back(i);
        }
    }
    to_dest -= to_del.size();
    for (int i = to_del.size() - 1; i >= 0; i--) {
        obs.erase(obs.begin() + to_del[i]);
    }
    w.clear();
    Vector2f tmp = (Vector2f(player.get_x(), player.get_y()) - Vector2f(100, w.getSize().y - 100));
    tmp *= (float)0.1;
    tmp = Vector2f(player.get_x() - 600, player.get_y() - 800) - tmp;
    bg->setPosition(tmp.x, tmp.y);
    w.draw(*bg);
    for (auto& i : obs) {
        w.draw(i->get_texture());
    }
    w.draw(player.get_texture());
    for (auto& i : player.get_fireballs()) {
        w.draw(i.get_texture());
    }
    View view;
    view.setCenter(player.get_x() + player.get_w() / 2,
                   player.get_y() - player.get_h() / 2);
    w.setView(view);
}

void Game::init(Player& player) {
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
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            player.go_left(obs);
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            player.go_right(obs);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            player.cast(allTime);
        }
        player.move(frame_time, obs);
        // w.clear();
        // w.draw(player.get_texture());
        draw(player, frame_time);
        if (to_dest == 0) {
            w.close();
        }
        w.display();
    }
}

Game::Game() {
    chdir("..");
    Handle = new handler();
    bg = new RectangleShape(Vector2f(1500, 1500));
    bg->move(-400, 200);
    bg->setTexture(Handle->background, true);
    for (int i = 0; i < 20; i++) {
        obs.push_back(new game_obj(100, 100, 100 * i, Window_h));
        obs.back()->get_texture().setTexture(Handle->wall);
    }
    for (int i = 0; i < 30; i++) {
        obs.push_back(new game_obj(100, 100, 0, Window_h - 100 * i));
        obs.back()->get_texture().setTexture(Handle->wall);
    }
    for (int i = 0; i < 30; i++) {
        obs.push_back(new game_obj(100, 100, 1900, Window_h - 100 * i));
        obs.back()->get_texture().setTexture(Handle->wall);
    }
    target* tg = new target(100, 100, 700, Window_h - 100);
    tg->hd = Handle;
    obs.push_back(tg);
    obs.back()->get_texture().setTexture(Handle->target);
    obs.push_back(new game_obj(100, 100, 500, 720));
    obs.back()->get_texture().setTexture(Handle->wall, true);
    obs.push_back(new game_obj(100, 100, 900, 600));
    obs.back()->get_texture().setTexture(Handle->wall, true);
    tg = new target(100, 100, 900, 500);
    tg->hd = Handle;
    obs.push_back(tg);
    obs.back()->get_texture().setTexture(Handle->target);
    for (int i = 1; i <= 8; i++) {
        obs.push_back(new game_obj(100, 100, 100 * i, 300));
        obs.back()->get_texture().setTexture(Handle->wall);
    }
    obs.push_back(new game_obj(100, 100, 1200, 430));
    obs.back()->get_texture().setTexture(Handle->wall);
    tg = new target(100, 100, 100, 200);
    tg->hd = Handle;
    obs.push_back(tg);
    obs.back()->get_texture().setTexture(Handle->target);
    for (float i = 1.5; i <= 6; i++) {
        obs.push_back(new game_obj(100, 100, 200 * i, 300 - 180 * i));
        obs.back()->get_texture().setTexture(Handle->wall);
    }
    for (int i = 1; i <= 3; i++) {
        obs.push_back(new game_obj(100, 100, 1800, Window_h - 250 * i));
        obs.back()->get_texture().setTexture(Handle->wall);
        tg = new target(100, 100, 1800, Window_h - 250 * i - 100);
        tg->hd = Handle;
        obs.push_back(tg);
        obs.back()->get_texture().setTexture(Handle->target);
    }
    w.create(VideoMode(Window_w, Window_h), "Window");
    Player player(g, 100, w.getSize().y - 100, Handle);
    init(player);
}

Game::~Game() {
    delete handler;
    delete bg;
    for (auto& i : obs) {
        delete i;
    }
}