#include "gui.h"
#include "room.h"
#include "snake.h"
#include "apple.h"


int main() {
    // Create the new Gui and start it. This clears the screen
    // and the Gui now controls the screen
    Gui gui;
    int score = 0;
    int tails = 0;
    int screenHeight = gui.screenHeight();
    int screenWidth = gui.screenWidth();

    // Create the room, the snake and the apple.
    // You will need to change the constructors later to pass more
    // information to the Snake and Apple constructors
    Room room(screenWidth, screenHeight);
    Snake snake(room);
    Apple apple(room, snake.getPositions());

    // Enter main loop of the game. Use "break" to break out of the loop
    for (;;) {
        // handle key presses
        int c = gui.getKeypress();
        // Do something with the key press
         if (c == 'q') {
             exit(0);
         } else if (c == KEY_UP) {
             snake.changeDirection(Direction::UP);
         } else if (c == KEY_DOWN) {
             snake.changeDirection(Direction::DOWN);
         } else if (c == KEY_LEFT) {
             snake.changeDirection(Direction::LEFT);
         } else if (c == KEY_RIGHT) {
             snake.changeDirection(Direction::RIGHT);
         }

        // Add your code to move the snake around the screen here.
        snake.move();

        // Clear the screen
        gui.clear();

        // Redraw everything on the screen into an offscreen buffer,
        // including the room, the Snake and the apple
        room.draw(gui);
        snake.draw(gui);
        apple.draw(gui);
        gui.drawText("Socre: " + to_string(score), 1, 1, COLOR_WHITE, COLOR_RED);
        // Display the new drawing all at once
        gui.refresh();

        // Detect whether the snake ate the apple, or it hit the wall
        // or it hit its own tail here
        if (snake.isColliding(room) || snake.isHittingTail()) {
           break;
        }
        
        if (apple.isEaten(snake.getPositions()[0])){
            score += 10;
            tails += 1;
            snake.grow(tails);
            apple.newApple(room, snake.getPositions());
        }
        

        // This call makes the program go quiescent for some time, so
        // that it doesn't run so fast. If the value in the call to
        // sleep is decreased, the game will speed up.
        gui.sleep(100);
    }
}
