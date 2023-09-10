#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace gof {
class GameOfLife {
    sf::RenderWindow m_window;

public:
    GameOfLife(unsigned int width = 800, unsigned int height = 600);
    void run();
};
} // namespace gof
#endif // APP_HPP