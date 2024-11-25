#pragma once
#include<vector>
#include <SFML/Graphics.hpp>

class Shape {
public:
    void draw(std::shared_ptr<sf::RenderWindow> window) const;

    void SetColor(const sf::Color& color);

    virtual void SetPosition(const sf::Vector2f& centre) = 0;

    static void SetDefaultPosition(const sf::Vector2f& upperLeftCorner);

protected:
    static sf::Vector2f defaultPostion_;
    std::shared_ptr<sf::Shape> shape_;
    sf::Color color_ = sf::Color::Green;
};


class Circle : public Shape {
public:
    Circle(float radius = 30, const sf::Vector2f& centre = defaultPostion_);

    void SetPosition(const sf::Vector2f& centre) override;

protected:
    sf::Vector2f centre_;
    float radius_;
};

class Triangle : public Circle {
public:
    Triangle(float height = 30, const sf::Vector2f& centre = defaultPostion_);

protected:
    float height_;
};


class Square : public Shape {
public:
    Square(float height = 50, const sf::Vector2f& upperLeftCorner = defaultPostion_);

    void SetPosition(const sf::Vector2f& upperLeftCorner) override;

protected:
    sf::Vector2f upperLeftCorner_;
    float height_;
};


class Rectangle : public Square {
public:
    Rectangle(float height = 50, float width = 100, const sf::Vector2f& upperLeftCorner = defaultPostion_);

protected:
    float width_;
};

class Window {
public:
    Window();

    void draw(const Shape* shape);

    void display();

private:
    std::vector<const Shape*> shapes_;
    std::shared_ptr<sf::RenderWindow> window_;
    unsigned int width_ = 1000;
    unsigned int height_ = 1000;
};