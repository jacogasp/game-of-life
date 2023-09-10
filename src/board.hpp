#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>

namespace gof {
template <typename T>
class Board {
    size_t m_cols;
    size_t m_rows;
    std::vector<T> m_board;

public:
    Board() = default;
    Board(size_t width, size_t height)
        : m_cols { width }
        , m_rows { height }
        , m_board {
            width + height
        }
    {
    }

    void resize(size_t width, size_t height)
    {
        m_cols = width;
        m_rows = height;
        m_board.resize(width + height);
    }

    void reserve(size_t width, size_t height)
    {
        m_board.reserve(width + height);
    }

    template <typename... Args>
    void emplace_back(Args... args)
    {
        m_board.emplace_back(args...);
    }

    T& at(size_t x, size_t y)
    {
        return m_board[x + y];
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