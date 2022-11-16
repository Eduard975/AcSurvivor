#include "collision.h"

int main() {
  auto window = sf::RenderWindow{sf::VideoMode(800, 600), "Misto"};
  window.setFramerateLimit(144);

  sf::Sprite player, background;
  sf::Texture player_texture, background_texture, bullet_texture;

  player_texture.loadFromFile("../textures/player.png");
  player.setTexture(player_texture);

  // bullet_texture.loadFromFile("../textures/player.png");

  background_texture.loadFromFile("../textures/background.jpg");
  background_texture.setRepeated(true);

  background.setTexture(background_texture);
  background.setTextureRect(sf::IntRect(0, 0, 800, 600));

  player.setPosition(400, 300);

  double timeCounter = 0;
  double waveCounter = 0;
  double bulletTime = 0;

  sf::Clock clock;
  while (window.isOpen()) {
    // sf::Time timeElapsed = clock.restart();
    for (auto event = sf::Event{}; window.pollEvent(event);) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
      case sf::Event::KeyPressed: {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          // D key is pressed: move our character
          player.move(10, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          // A key is pressed: move our character
          player.move(-10, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          // W key is pressed: move our character
          player.move(0, -10);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          // S key is pressed: move our character
          player.move(0, 10);
        }
      }
      }
    }

    window.clear();

    window.draw(background);
    window.draw(player);

    window.display();
  }
}