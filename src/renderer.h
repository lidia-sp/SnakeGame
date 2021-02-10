#ifndef RENDERER_H
#define RENDERER_H
#include "game.h"
#include <vector>
#include "SDL.h"
#include "snake.h"
#include <memory>
class Food;
class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake,std::vector<std::shared_ptr<Food>> const &vectorFood);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif