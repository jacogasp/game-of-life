#include "gof/gof.hpp"
#include <iostream>

int main(int, char**)
{
    auto game = gof::GameOfLife();
    game.run();
}
