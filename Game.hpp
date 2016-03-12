#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Toolkit.hpp"
#include "RandomShapes.hpp"

class Game
{
public:
    void main(sf::RenderWindow& window)
    {
        float timer = 0;
        float time_limit = 2;

        int counter = 0;
        sf::Clock clock;

        RandomRect randRect(sf::Vector2f(window.getSize()));
        std::vector<sf::RectangleShape*> rects;

        RandomCircle randCircle(sf::Vector2f(window.getSize()));
        std::vector<sf::CircleShape*> circles;

        bool next = true;
        std::vector<sf::Image> screenshots;

        sf::Color bg(random(255, 5), random(255, 5), random(255, 5));

        while (window.isOpen())
        {
            float dt = clock.restart().asSeconds();

            if(next)
            {
                next = false;
                counter ++;

                int update = 1;
                if(counter % update == 0)
                {
                    srand(time(NULL));

                    randRect.update();
                    randCircle.update();

                    randRect.reset();
                    randCircle.reset();
                }

                rects.clear();
                circles.clear();

                int sLimit = random(1200, 25);   /* Max number of each shape */

                /* Generate rectangles */
                int rLimit = random(sLimit, 5);
                for(int i = 0; i < rLimit; i++)
                {
                    sf::RectangleShape* rect = randRect.create();
                    rects.push_back(rect);
                }

                /* Generate Circles */
                int cLimit = random(sLimit-rLimit+1, 5);
                for(int i = 0; i < cLimit; i++)
                {
                    sf::CircleShape* circle = randCircle.create();
                    circles.push_back(circle);
                }

                bg = sf::Color(random(15, 5), random(15, 5), random(15, 5));
            }

            timer += dt;

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
            }

            window.clear(bg);

            for(int i = 0; i < rects.size(); i++)
            {
                window.draw(*rects[i]);
            }

            for(int i = 0; i < circles.size(); i++)
            {
                window.draw(*circles[i]);
            }

            window.display();

            if(timer > time_limit)
            {
                timer = 0;
                next = true;

                sf::Image ss = window.capture();
                screenshots.push_back(ss);
            }
            else
            {
                if(screenshots.size() > 0)
                {
                    std::string filename = to_string(counter) + "_" + to_string(rand()%1000) + to_string(rand()%1000);
                    screenshots.back().saveToFile("../../images/" + filename + ".png");

                    screenshots.erase(screenshots.end());
                }
            }
        }
    }
};

#endif // GAME_HPP_INCLUDED
