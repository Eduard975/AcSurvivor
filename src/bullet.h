#pragma once
#include <SFML/Graphics.hpp>

class bullet {
private:
  sf::Sprite spr;
  sf::Vector2f vel;

public:
  bullet(sf::Texture *tex, sf::Vector2f vel, sf::Vector2f pos,
         sf::IntRect rect) {
    this->vel = vel;
    spr.setTexture(*tex);
    spr.setTextureRect(rect);
    spr.setPosition(pos);
  }

  void update(double timp) {
    spr.setPosition(spr.getPosition().x + timp * vel.x,
                    spr.getPosition().y + timp * vel.y);
  }

  sf::Sprite *getSprite() { return &spr; }
};