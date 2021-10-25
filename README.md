# Maze project

## Desciption

The goal of this project is to create a game in 3D using raycasting. Ray-casting is a techniques that transform a limited form of data (a very simplified map or floor plan) into a 3D projection by tracing rays from the view point into the viewing volume.

![maze using raycasting](/images/maze1.png)

## General Requirements

    * All your files will be compiled on Ubuntu 14.04 LTS, using gcc (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4
    * We will use the gcc flags -Wall -Werror -Wextra and -pedantic
    * All your functions must be commented
    * Your functions should be maximum 40 lines long (one statement per line)
    * Your functions should be maximum 80 columns long
    * No more than 5 functions per file
    * Your entire repository will be checked using Betty
   
<p align="center">
    <img src="https://github.com/BeniyamL/Maze/blob/master/images/maze22.png">
</p>

## Task 0. Walls !
    * Create a window with SDL2
    * Use raycasting to draw walls on your window !
    
## Task 1. Orientation
    * In this part, you must draw a different color depending on the orientation of the walls.
    * You must at least draw walls facing NORTH and SOUTH in a different color from walls facing EAST and WEST.

## Task 2. Rotation
   * You must provide a way to rotate the camera during the execution.

## Task 3. Move
   * You must provide a way to move the camera during the execution.

## Task 4. Ouch !
   * In this part, you must handle the collisions of the player (yes, let’s call the camera player now, it’s getting serious) with the walls.
   * The player must not be able to enter walls
   * You can make the player slide on the walls instead of just stop it.

## Task 5. Parser
   * In this part you must implement a parser to get the map from a file.

   *  You are free to define the standards of your map (The character for a wall, the character for nothing, the extension of the file if you want, …)
  
## Task 6 Draw the map
   * In this part, you must draw the map on the window.
   * You’re free to draw the map where you want, with the color you want, …
   * You must provide a way to enable/disable it during the execution
   * Include the player’s line of sight in the map

## Task 7. Coding style + Documentation
   * Check if you code fits the Holberton School coding style.
   * Check if your code is well documented and respect the Holberton School documentation format

## Task 8. Textures
   * In this part you have to add textures on your walls !

## Task 9. Multi task !
   * Add a way to move on several directions and rotate in the same time. Basically in this part you’ll have to handle multiple events on the same frame.

## Tak 10. Ground textures
   * In this part you have to add textures on the ground and/or on the ceiling !

## Task 11. Weapons
   * Add weapons textures !


## Task 12. Enemies
   * Add some enemies !

## Task 13. Make it rain
   * Add rain and a possibility to stop / start the rain with a key

![door_open](/images/maze44.png)

## How the project works
   * the project first creates the window and initialize the game with some default value
   * It then displays the map and the game zone to the user
   * the user use some keys (like w, a, s, d, e & arrow keyes) to move & rotate the player
   * the system continuesly check the input key provided by the user
   * if an Escape key or Quit buttom clicked, it quite the game and destroy the window

## System Usage

   * Download the source file from the githbub.com into your local machine
   * naviagete to the Maze folder
   * compile all source doe ending with .c extension using the following flag
       gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm $(sdl2-config --cflags --libs) -lSDL"_image -o maze
   * launch the executable file like ./maze if you want to use the deafualt map
   * launch the executabel file by passing the name of the map file if you want to provide your own map like ./maze map  here map if the name of the file
   * the system then displays the map & the game zone on the screen
   * Press Upper arrow key or w key to move the player to upper positon
   * press down arrow key or s key to move to the player to down postion
   * press left arrow key or a key to rotate the player in counter clock wise direction
   * press right arrow key or d key to rotate the player in clock wise direction
   * press e key to open the door
   * press Escape key or click Quit button to exit the game

![door_open](/images/maze33.png)

## content of the Maze project
| File name       | Description |
---               | ---    |
main.c            | a c file which contains the main method and the display function
cast.c            | a c filw which defines main component of casting throug the methods ray_cast, horizontal collision , vertical collistion
drow.c            | a c file which contains methods used to draw a map, player, wall, roof & floor
map.c             | a c file which defines a map coordinates and method to access them
texture           | a c file which defines a texture value and method to access them
window            | a c file which contains method used to define the window and input keyboards

--- 


## Author
Beniyam Legesse(https://github.com/BeniyamL)
