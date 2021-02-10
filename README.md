# CPPND: Capstone Snake Game - Modified by Lidia Cabanillas

This is the final project of the c++ Nanodegree at Udacity. The goal was to implement new features for a snake game.
These are the changes that I have done to the base code: 

- In game.h I have declared a class called "Food" which contains the coordinates, also the type of food, and constructor and some setter/getter functions. The implementation of this class is in game.cpp. Each type of food represents a color and an speed increment. The type of food is given randomly.
  green: do not increase speed of the snake. 
  blue: increase speed +0.02
  yellow: increase speed +0.04
  red: increase speed +0.08
    
- The class game.cpp, instead of having only the food as a SDL_Point. It has now a vector of shared_ptr of type Food, and several function of the game.pp class and also of the class renderer.cpp has been accordantly modified. 

- When user start the game, he/she can select which level they want to play (beginners, intermediate or advanced).

My project satisfies the following criteria: 
Loops/Functions I/O
- A variety of control structures are used in the project: I used several loops (in game.cpp and rendered.cpp) to manage the vectorFood.
- The project code is clearly organized into functions: I created a new class Food and several functions, I also added some functions to the class Game.
- The project accepts input from a user as part of the necessary operation of the program. User set the initial level of the game.
Object Oriented Programming
- The project uses Object Oriented Programming techniques: I created a new class Food and several functions, I also added some functions to the class Game.
- Classes use appropriate access specifiers for class members: For class food it is specified if the memebrs are public or private.
- Class constructors utilize member initialization lists: there are two constructor for food class, one with memeber initialization list and one without.
- Overloaded functions allow the same function to operate on different parameters: I overloaded the constructor of food and also the function Game::FoodHere.
Memory Management:
- The project makes use of references in function declarations: the following functions tkae referencs as paramenter, Game::FoodHere and renderer:render. 
- The project uses smart pointers instead of raw pointers: game class contains a vector of shared_pointers.
My Repo: 

https://github.com/lidia-sp/SnakeGame


Starter Repo: 

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
