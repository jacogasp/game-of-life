#ifndef APP_HPP
#define APP_HPP

#include "board.hpp"
#include "cell.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace gof {
class GameOfLife {
  sf::RenderWindow m_window;
  Board<Cell> m_cells;
  bool m_run;

  void init();
  void handle_event(sf::Event const&);
  void update();
  void render();

  public:
  GameOfLife(unsigned int width = 800, unsigned int height = 600);
  void run();
};
} // namespace gof
#endif // APP_HPP