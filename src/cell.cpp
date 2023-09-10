#include "cell.hpp"

namespace gof {
Cell::Cell(float size)
{
  m_shape.setSize(sf::Vector2f { size, size });
  m_shape.setFillColor(sf::Color::White);
  m_shape.setOutlineThickness(0.5f);
  m_shape.setFillColor(sf::Color::Black);
}

void Cell::set_position(sf::Vector2f const& position)
{
  m_shape.setPosition(position);
}

bool Cell::is_active() const
{
  return m_is_active;
}

void Cell::set_is_active(bool is_active)
{
  m_is_active = is_active;
  m_shape.setFillColor(m_is_active ? sf::Color::White : sf::Color::Black);
}

void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(m_shape);
}
} // namespace gof