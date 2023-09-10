#ifndef APP_HPP
#define APP_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace gof {
class GameOfLife {
    sf::RenderWindow m_window;

public:
    GameOfLife(unsigned int width = 800, unsigned int height = 600)
        : m_window { sf::VideoMode { width, height }, "Game Of Life" }
    {
    }

    void run()
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
};
}
#endif // APP_HPP