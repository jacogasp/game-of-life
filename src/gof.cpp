#include "gof.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>

namespace gof {
void GameOfLife::init()
{
  auto window_size          = m_window.getSize();
  constexpr float cell_size = 20.0f;
  sf::Vector2i cell_counts {
    static_cast<int>(std::floor(window_size.x / cell_size)),
    static_cast<int>(std::floor(window_size.y / cell_size))
  };

  m_cells.resize(cell_counts.x, cell_counts.y);
  std::generate(m_cells.begin(), m_cells.end(), [cell_size] { return Cell(cell_size); });

  for (int i = 0; i < cell_counts.x; ++i) {
    for (int j = 0; j < cell_counts.y; ++j) {
      auto& cell = m_cells.at(i, j);
      cell.set_position(sf::Vector2f { i * cell_size, j * cell_size });
    }
  }
}

void GameOfLife::handle_event(sf::Event const& event)
{
  switch (event.type) {
  case sf::Event::Closed:
    m_window.close();
    break;
  case sf::Event::MouseButtonReleased: {
    auto coords = sf::Mouse::getPosition(m_window);
    int x       = m_cells.size().cols * coords.x / m_window.getSize().x;
    int y       = m_cells.size().rows * coords.y / m_window.getSize().y;
    std::cout << "Click at cell (" << x << ", " << y << ")\n";
    auto& cell = m_cells.at(x, y);
    cell.set_is_active(!cell.is_active());
    std::cout << (cell.is_active() ? "cell activated" : "cell deactivated") << '\n';
  } break;
  case sf::Event::KeyReleased: {
    if (event.key.code == sf::Keyboard::Enter) {
      std::cout << "start\n!";
      m_run = true;
    }
  } break;
  default:
    break;
  }
}

auto tp = std::chrono::high_resolution_clock::now();

void GameOfLife::update()
{

  if (!m_run) {
    return;
  }

  using namespace std::chrono;
  auto now      = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(now - tp).count();
  if (duration < 150) {
    return;
  }
  tp        = now;
  auto size = m_cells.size();

  auto begin = m_cells.begin();
  auto end   = m_cells.end();

  std::advance(begin, m_cells.size().cols);
  std::advance(end, -m_cells.size().cols);

  auto cols = m_cells.size().cols;
  int col   = 0;
  int row   = 1;

  std::for_each(begin, end, [&](auto& cell) {
    if (col == 0) {
      ++col;
      return;
    } else if (col == cols - 1) {
      col = 0;
      ++row;
      return;
    }

    std::vector<std::reference_wrapper<Cell>> neighbors {
      m_cells.at(col - 1, row - 1),
      m_cells.at(col - 1, row),
      m_cells.at(col - 1, row + 1),
      m_cells.at(col, row - 1),
      m_cells.at(col, row + 1),
      m_cells.at(col + 1, row - 1),
      m_cells.at(col + 1, row),
      m_cells.at(col + 1, row + 1),
    };

    int alive_neighbors = std::reduce(neighbors.begin(), neighbors.end(), 0,
      [](int current, Cell const& cell) {
        if (cell.is_active()) {
          ++current;
        }
        return current;
      });

    if (cell.is_active()) {
      if (alive_neighbors < 2 || alive_neighbors > 3) {
        cell.set_is_active(false);
      } else {
        cell.set_is_active(true);
      }
    } else {
      if (alive_neighbors == 3) {
        cell.set_is_active(true);
      }
    }
    ++col;
  });
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
