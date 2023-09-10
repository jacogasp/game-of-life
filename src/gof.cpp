#include "gof.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>

namespace gof {
void GameOfLife::init()
{
    auto size = m_window.getSize();
    constexpr float cell_size = 20.0f;
    sf::Vector2i cell_counts {
        static_cast<int>(std::floor(size.x / cell_size)),
        static_cast<int>(std::floor(size.y / cell_size))
    };
    auto total_cells = cell_counts.x + cell_counts.y;
    m_cells.reserve(total_cells);
    for (int i = 0; i < cell_counts.x; ++i) {
        for (int j = 0; j < cell_counts.y; ++j) {
            m_cells.emplace_back(cell_size);
            m_cells.back().set_position(sf::Vector2f { i * cell_size, j * cell_size });
            if ((i + j) % 2 == 0) {
                m_cells.back().set_is_active(true);
            }
        }
    }
}
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
    std::for_each(m_cells.begin(), m_cells.end(), [&](Cell const& cell) {
        m_window.draw(cell);
    });
}

GameOfLife::GameOfLife(unsigned int width, unsigned int height)
    : m_window { sf::VideoMode { width, height }, "Game Of Life" }
{
}

void GameOfLife::run()
{
    init();
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