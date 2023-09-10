#include "gof.hpp"

namespace gof {
void GameOfLife::handle_event(sf::Event const& event)
{
    if (event.type == sf::Event::Closed) {
        m_window.close();
    }
}

void GameOfLife::update()
{
}

void GameOfLife::render()
{
}

GameOfLife::GameOfLife(unsigned int width, unsigned int height)
    : m_window { sf::VideoMode { width, height }, "Game Of Life" }
{
}

void GameOfLife::run()
{
    sf::Event event;
    while (m_window.isOpen()) {
        while (m_window.pollEvent(event)) {
            handle_event(event);
        }
        update();
        m_window.clear(sf::Color::Black);
        render();
        m_window.display();
    }
}

} // namespace gof