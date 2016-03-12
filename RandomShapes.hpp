#ifndef RANDOMSHAPES_HPP_INCLUDED
#define RANDOMSHAPES_HPP_INCLUDED

int random(double limit, int base)
{
    int r = rand() % int(limit) + base;
    if(r >= limit)
    {
        r = limit;
    }
    return r;
}

class RandomShape
{
protected:
    sf::Color cLimit;
public:
    RandomShape()
    {
        reset();
    }
    void reset()
    {
        cLimit = sf::Color(random(225, 5), random(225, 5), random(225, 5), random(225, 25));
    }
};

class RandomRect:public RandomShape
{
    sf::Vector2f sLimit, wSize;
public:
    RandomRect(sf::Vector2f windowSize)
    {
        sLimit = sf::Vector2f(random(windowSize.x/4, 5), random(windowSize.y/4, 5));
        wSize = windowSize;
    }

    void update()
    {
        sLimit.x = random(sLimit.x*1.25, 15);
        sLimit.y = random(sLimit.y*1.25, 15);
    }

    sf::RectangleShape* create()
    {
        sf::RectangleShape* rect = new sf::RectangleShape();

        sf::Vector2f rSize( random(sLimit.x, 5), random(sLimit.y, 5) );
        rect->setSize(rSize);

        sf::Vector2f rPos( random(wSize.x, -50), random(wSize.y, -50) );
        rect->setPosition(rPos);

        sf::Color rFill( random(cLimit.r, 5), random(cLimit.g, 5), random(cLimit.b, 5), random(cLimit.a, 5) );
        rect->setFillColor(rFill);

        sf::Color rOutline( random(cLimit.r, 5), random(cLimit.g, 5), random(cLimit.b, 5), random(cLimit.a, 5) );
        rect->setOutlineColor(rOutline);

        int rThickness = random( (rSize.x + rSize.y)/2, 5);
        rect->setOutlineThickness(rThickness);

        return rect;
    }
};

class RandomCircle: public RandomShape
{
    float sLimit;
    sf::Vector2f wSize;
public:
    RandomCircle(sf::Vector2f windowSize)
    {
        sLimit = random(windowSize.x/4, 5);
        wSize = windowSize;
    }

    void update()
    {
        sLimit = random(sLimit*1.25, 15);
    }

    sf::CircleShape* create()
    {
        sf::CircleShape* circle = new sf::CircleShape();

        float cSize = random(sLimit, 5);
        circle->setRadius(cSize);

        sf::Vector2f cPos( random(wSize.x, -50), random(wSize.y, -50) );
        circle->setPosition(cPos);

        sf::Color cFill( random(cLimit.b, 5), random(cLimit.r, 5), random(cLimit.g, 5), random(cLimit.a, 5) );
        circle->setFillColor(cFill);

        sf::Color cOutline( random(cLimit.b, 5), random(cLimit.r, 5), random(cLimit.g, 5), random(cLimit.a, 5) );
        circle->setOutlineColor(cOutline);

        int cThickness = random(cSize*2, 5);
        circle->setOutlineThickness(cThickness);

        return circle;
    }
};


#endif // RANDOMSHAPES_HPP_INCLUDED
