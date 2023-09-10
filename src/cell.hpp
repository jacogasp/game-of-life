#ifndef CELL_HPP
#define CELL_HPP

#include <SFML/Graphics.hpp>

namespace gof {
class Cell : public sf::Drawable {
    sf::RectangleShape m_shape;
    bool m_is_active;

public:
    explicit Cell (float size = 5);
    void set_position(sf::Vector2f const& position);
    [[nodiscard]] bool is_active() const;
    void set_is_active(bool is_active);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
} // namespace gof
#endif // CELL_HPP