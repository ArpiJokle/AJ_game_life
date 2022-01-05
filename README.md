# AJ_game_life
The game "Life" (a cellular automaton invented by the English mathematician John Conway in 1970) which is written in c++ using the graphics library SFML
Now only works for windows
How to play:
  Use the left mouse button to change the state of the cell
  Use the right mouse button for one move
  Use the C key to clear the field
  Use the spacebar to turn/off auto mode
  Use the up/down keys to change the speed of automatic mode
How to compile:
  You will need g++ installed to compile this project. After installing it, you can simply run cmpile.cmd and it will build the project.
If you need to resize the window, go to source/main.h and change W_HEIGHT and W_WIDTH manually.
If you need to change the size of the cells go to source/cell.h and change the _size manually.
The number of cells depends on the size of the window and the size of the cells themselves.
