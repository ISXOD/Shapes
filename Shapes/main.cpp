#include "shapes.h"

int main()
{   
    Window window;

    Square square(100.f);

    Rectangle rectangle(200.0f, 100.0f);
    rectangle.SetColor(sf::Color::Blue);
    rectangle.SetPosition(sf::Vector2f(100.f, 100.0f));

    Circle circle(50);
    circle.SetPosition(sf::Vector2f(200.f, 200.0f));
    circle.SetColor(sf::Color::Yellow);

    Triangle triangle(50, sf::Vector2f(300.f, 300.0f));

    window.draw(&triangle);
    window.draw(&circle);
    window.draw(&square);
    window.draw(&rectangle);

    window.display();

    return 0;
}