#include <stdlib.h>
#include "apple.h"
#include "room.h"
#include "position.h"
using namespace std;

void Apple::appleLocation(Room& room, vector<Position>& snakeLocation) {
    int appleX, appleY;
    bool sameSpot = false;
    
    while(!sameSpot) {
        appleX = rand() % room.getWidth();
        appleY = rand() % room.getHeight();
        for (int i = 0; i < snakeLocation.size(); i++) {
            if (snakeLocation[i].x == appleX && snakeLocation[i].y == appleY) {
                sameSpot = false;
            } else {
                sameSpot = true;
            }
        }
    }
    
    lilApple.x = appleX;
    lilApple.y = appleY;
}

Apple::Apple(Room& room, vector<Position>& snakeLocation) {
    appleLocation(room, snakeLocation);
    
}

// Check if the apple is eaten or not.
bool Apple::isEaten(Position& snakeLocation) {
    if (lilApple.x == snakeLocation.x && lilApple.y == snakeLocation.y) {
        return true;
    }
    return false;
}

void Apple::newApple(Room& room, vector<Position>& snakeLocation) {
    appleLocation(room, snakeLocation);
}

void Apple::draw(Gui& gui) {
    gui.drawText(appleIcon, lilApple.x, lilApple.y, COLOR_RED, COLOR_RED);
}
