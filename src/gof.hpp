#ifndef APP_HPP
#define APP_HPP

#include "cell.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

namespace gof {
class GameOfLife {
    sf::RenderWindow m_window;
    std::vector<Cell> m_cells;
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