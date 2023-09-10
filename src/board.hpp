#ifndef BOARD_HPP
#define BOARD_HPP

#include <cassert>
#include <vector>

namespace gof {
template <typename T>
class Board {
  struct Size {
    size_t cols;
    size_t rows;
  };
  Size m_size;
  std::vector<T> m_board;

  public:
  Board() = default;
  Board(size_t width, size_t height)
    : m_size { width, height }
    , m_board {
      width + height
    }
  {
  }

  void resize(size_t width, size_t height)
  {
    m_size.cols = width;
    m_size.rows = height;
    m_board.resize(width * height);
  }

  void reserve(size_t width, size_t height)
  {
    m_board.reserve(width * height);
  }

  [[nodiscard]] Size size() const
  {
    return m_size;
  }

  T& at(size_t x, size_t y)
  {
    return m_board[x + y * m_size.cols];
  }

  T& back()
  {
    return m_board.back();
  }

  auto begin()
  {
    return m_board.begin();
  }

  auto end()
  {
    return m_board.end();
  }
};
} // namespace gof

#endif // BOARD_HPP