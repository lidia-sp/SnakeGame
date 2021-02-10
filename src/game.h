#ifndef GAME_H
#define GAME_H
#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <memory>
class Renderer;
class SDL_Point;
enum FoodType {green, blue, yellow, red};
class Food /*: public SDL_Point*/{
  public:
  Food ();
  Food (FoodType type, int x, int y);
  int x,y;
  //getter & setter
  void SetType(FoodType type);
  float GetSpeed() const;
  FoodType GetType() const;
  private:
  FoodType _type{FoodType::yellow};
  float _speedIncr{0};
 };
  
      
  
  
class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  std::vector<std::shared_ptr<Food>> vectorFood;
 private:
  Snake snake;
  

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
  bool FoodHere(int x, int y, int &i); //return true if any of the food of vectorFood is placed in the given coordinates also gives i the value of the food position in the vector 
  bool FoodHere(int x, int y);
};

#endif