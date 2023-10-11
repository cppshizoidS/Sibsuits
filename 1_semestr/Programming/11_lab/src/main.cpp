#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
int main() {
  const int SIZE = 600;
  float h = 0.5;
  float x = -100;
  int zoom = 30;
  RenderWindow window(VideoMode(SIZE, SIZE), "lab11");
  VertexArray line1(LinesStrip, SIZE);
  VertexArray line2(LinesStrip, SIZE);
  for (int i = 0; i < SIZE; i++, x += h) {
    line1[i].position = Vector2f(SIZE / 2 + x * zoom, SIZE / 2 - x * x * zoom);
    line1[i].color = Color::White;
    line2[i].position = Vector2f(SIZE / 2 + x * zoom, SIZE / 2 - cos(x) * zoom);
    line2[i].color = Color::Green;
  }
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event))
      if (event.type == Event::Closed)
        window.close();
    window.clear();
    window.draw(line1);
    window.draw(line2);
    window.display();
  }
}
