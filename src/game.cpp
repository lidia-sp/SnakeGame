#include "game.h"
#include <iostream>
#include "SDL.h"
#include <random>
class SDL_Point;
Food::Food (){};
 Food::Food (FoodType type, int x, int y):_type(type),x(x),y(y){
    if (_type==FoodType::yellow){
      _speedIncr=0.04;
    }else if (_type==FoodType::red){
      _speedIncr=0.08;
    }else if(_type==FoodType::blue){
      _speedIncr=0.02;
    }else if (_type==FoodType::green){
      _speedIncr=0;
    }
  }
//Set the type of the food and also the increment of Speed related to the type
void Food::SetType (FoodType type){
 
  _type=type;
   
  if (_type==FoodType::yellow){
      _speedIncr=0.04;     
    }else if (_type==FoodType::red){
      _speedIncr=0.08;    
    }else if(_type==FoodType::blue){
      _speedIncr=0.02;    
    }else if (_type==FoodType::green){
      _speedIncr=0.00;
    }
}
float Food::GetSpeed() const{
  return _speedIncr;
} 
  FoodType Food::GetType() const{ 
    return _type;
}

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, vectorFood);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}


//Update the vectorfood, remove the existing food and creates new one  color/type

void Game::PlaceFood() { 
  vectorFood.clear();  //remove all the Food in the vector
  int x, y;
  //get randomly how many food will be displayed
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_real_distribution<> distr(1, 4);
  int NumFood = distr(eng);
  for (int i=0;i<NumFood;i++){
  std::shared_ptr<Food> food(new Food);
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
  
    // Check that the location is not occupied by a snake item before placing
    // or by another food
    
    if (!snake.SnakeCell(x, y) && !FoodHere(x,y))  {
      (*food).x = x;
      (*food).y = y;
      //Give a new FoodType randomly
      std::random_device rd;
      std::mt19937 eng(rd());
      std::uniform_real_distribution<> distr(1, 5);
      int newvalue = distr(eng);
      //std::cout<<"new random value= " <<newvalue <<"\n";
      if (newvalue==1){
       (*food).SetType(FoodType::green);
      }else if (newvalue==2){
        (*food).SetType(FoodType::blue);
      }else if (newvalue==3){
        (*food).SetType(FoodType::yellow);
      }else if (newvalue ==4){
        (*food).SetType(FoodType::red);
      }
      vectorFood.push_back(food); //include the Food in the vectorFood
      break; //exit the while(true) loop
      }
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  int i;
  // Check if there's food over here
  if (FoodHere(new_x, new_y, i)) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += (*vectorFood[i]).GetSpeed();
  }
}
bool Game::FoodHere(int x, int y, int &i){
  for (i=0; i<vectorFood.size(); i++){
    if ((*vectorFood[i]).x==x and (*vectorFood[i]).y==y){
      return true;
    }
  }
  return false;
}
bool Game::FoodHere(int x, int y){
  for (auto i:vectorFood){
    if ((*i).x==x and (*i).y==y){
      return true;
    }
  }
  return false;
}
int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }