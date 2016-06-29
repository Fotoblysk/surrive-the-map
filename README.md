# surrive-the-map
Simple game to get comfortable with design patterns and functional programming style.
Game ahve been written useing SFML-2.3.2 libary - dynamic linking, and Code::Blocks IDE. The game is originally made for a system Windows 8.1 64 bit, however compiled for 32 architecture.
ToDo list in main.cpp
#This branch is not ready to test, can have memory leaks, and may need refactoring.
### building on linux
First, you need sfml libraries installed. On debian-based distributions run:
```
sudo apt-get install libsfml-dev
```
In order to build the game with cmake, use an IDE or run from repo root:
```
mkdir build
cd build
cmake ../
make survive-the-map
```
