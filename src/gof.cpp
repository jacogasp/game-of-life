#include "gof.hpp"

namespace gof {
GameOfLife::GameOfLife(unsigned int width, unsigned int height)
    : m_window { sf::VideoMode { width, height }, "Game Of Life" }
{
}

void GameOfLife::run()
{
    sf::Event event;
    while (m_window.isOpen()) {
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
            }
        }
        m_window.clear(sf::Color::Black);
        m_window.display();
    }
}
} // namespace gof