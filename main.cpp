#include <iostream>
#include "Game.hpp"

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "");
    Game().main(window);
    return 0;
}
