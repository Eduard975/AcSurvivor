#include <SFML/Graphics.hpp>

int main() {
  auto window = sf::RenderWindow{sf::VideoMode(728, 455), "Misto"};
  window.setFramerateLimit(144);

  sf::Sprite player, background;
  sf::Texture player_texture, background_texture;

  player_texture.loadFromFile("../textures/player.png");
  player.setTexture(player_texture);

  background_texture.loadFromFile("../textures/background.jpg");
  background.setTexture(background_texture);

  player.setPosition(300, 400);

  while (window.isOpen()) {
    for (auto event = sf::Event{}; window.pollEvent(event);) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
      case sf::Event::KeyPressed:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          // W key is pressed: move our character
          player.move(0, -10);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          // A key is pressed: move our character
          player.move(-10, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          // S key is pressed: move our character
          player.move(0, 10);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          // D key is pressed: move our character
          player.move(10, 0);
        }
      }
    }

    window.clear();

    window.draw(background);
    window.draw(player);

    window.display();
  }
}