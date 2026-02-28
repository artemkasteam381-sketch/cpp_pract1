#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <string_view>
#include <sstream>
enum class ShapeType { Circle, Rect };
class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual ShapeType type() const noexcept = 0;
    virtual std::string name() const = 0;
};
class Circle final : public Shape {
public:
    explicit Circle(double r) : r_(r) {}
    double area() const override {
      return r_ * r_ * 3.14159265; }
    ShapeType type() const noexcept override {
      return ShapeType::Circle; }
    std::string name() const override {
      return "Circle"; }
private:
    double r_;
};
class Rect final : public Shape {
public:
    Rect(double w, double h) : w_(w), h_(h) {}
    double area() const override {
      return w_ * h_; }
    ShapeType type() const noexcept override {
      return ShapeType::Rect; }
    std::string name() const override {
      return "Rect"; }
private:
    double w_, h_;
};
double total_area(const std::vector<std::unique_ptr<Shape>>& v) {
    double sum = 0;
    for (const auto& shape : v) {
        if (shape) sum += shape->area();
    }
    return sum;
}
int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    while (std::getline(std::cin, line) && line != "exit") {
        std::istringstream iss(line);
        std::string name;
        if (!(iss >> name)) continue;
        std::unique_ptr<Shape> new_shape = nullptr;
        if (name == "Circle" || name == "circle") {
            double r;
            if (iss >> r) new_shape = std::make_unique<Circle>(r);
        } else if (name == "Rect" || name == "rect") {
            double w, h;
            if (iss >> w >> h) new_shape = std::make_unique<Rect>(w, h);
        }
        if (new_shape) shapes.push_back(std::move(new_shape));
    }
    for (const auto& s : shapes) {
        std::cout << s->name() << " " << s->area() << std::endl;
    }
    std::cout << total_area(shapes) << std::endl;
    return 0;
}
