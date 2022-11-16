#include <SFML/Graphics.hpp>

// smartMove(sf::Sprite&,int,int,int,int);
// usage: smartMove(sprite you are controlling, move x, move y, window width,
// window height); example: smartMove(Player,1,0,400,250) tip: subtract the
// sprite height and sprite width from the window height and window width

bool smartMove(sf::Sprite &obj, int moveX, int moveY, int windowWidth,
               int windowHeight) {
  sf::Vector2f pos = obj.getPosition();
  sf::Vector2f scl = obj.getScale();
  // position from sprites base point
  int posX = pos.x;
  int posY = pos.y;

  if (moveX > 0 || moveY > 0) {
    if (posX + moveX >= windowWidth || posY + moveY >= windowHeight) {
      // Good luck moving there, YOU REBEL!!
      return false;
    }
  }
  if (moveX < 0 || moveY < 0) {
    if (posX - moveX <= 0 || posY - moveY <= 0) {
      // You want to move your sprite there? NO!!!
      return false;
    }
  }
  if (moveX == 0 && moveY == 0)
    return false;
  // if you want to handle moving in the function
  obj.move(moveX, moveY);

  // go ahead, Mr.Sprite
  return true;
}