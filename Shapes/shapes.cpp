#include "Shapes.h"

sf::Vector2f Shape::defaultPostion_ = sf::Vector2f(0.0f, 0.0f);

void Shape::draw(std::shared_ptr<sf::RenderWindow> window) const {
    window->draw(*shape_);
}

void Shape::SetColor(const sf::Color& color) {
    color_ = color;
    shape_->setFillColor(color_);
}

void Shape::SetDefaultPosition(const sf::Vector2f& upperLeftCorner) {
    defaultPostion_ = upperLeftCorner;
}

Circle::Circle(float radius, const sf::Vector2f& centre) : radius_(radius), centre_(centre) {
    shape_ = std::make_shared<sf::CircleShape>(radius_);
    shape_->setPosition(centre_);
    shape_->setFillColor(color_);
}

void Circle::SetPosition(const sf::Vector2f& centre) {
    centre_ = centre;
    shape_->setPosition(centre_);
}

Triangle::Triangle(float height, const sf::Vector2f& centre) : height_(height) {
    centre_ = centre;
    radius_ = height / (pow(3, 1 / 2));
    shape_ = std::make_shared<sf::CircleShape>(radius_, 3);
    shape_->setPosition(centre_);
    shape_->setFillColor(color_);
}

Square::Square(float height, const sf::Vector2f& upperLeftCorner) : height_(height), upperLeftCorner_(upperLeftCorner) {
    shape_ = std::make_shared<sf::RectangleShape>(sf::Vector2f(height_, height_));
    shape_->setPosition(upperLeftCorner_);
    shape_->setFillColor(color_);
}

void Square::SetPosition(const sf::Vector2f& upperLeftCorner) {
    this->upperLeftCorner_ = upperLeftCorner;
    shape_->setPosition(upperLeftCorner);
}

Rectangle::Rectangle(float height, float width, const sf::Vector2f& upperLeftCorner)
                                                        : Square(height, upperLeftCorner)
                                                        , width_(width) {
    shape_ = std::make_shared<sf::RectangleShape>(sf::Vector2f(height_, width_));
    shape_->setPosition(upperLeftCorner_);
    shape_->setFillColor(color_);
}

Window::Window() {
    window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(width_, height_), L"", sf::Style::Default);
    window_->setVerticalSyncEnabled(true);
}

void Window::draw(const Shape* shape) {
    shapes_.push_back(shape);
}

void Window::display() {
    while (window_->isOpen()) {
        sf::Event event;
        while (window_->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_->close();
        }

        window_->clear();
        for (auto s : shapes_) {
            s->draw(window_);
        }
        window_->display();
    }
}