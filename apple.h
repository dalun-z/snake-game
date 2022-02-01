#if !defined(APPLE_H)
#define APPLE_H

#include "gui.h"
#include "position.h"
#include "room.h"
#include <string>
using namespace std;

/**
 * This class represents the apple on the screen that the snake has to eat.
 */
class Apple {
private:
    Position lilApple;   // Apple's position
    void appleLocation(Room& room, vector<Position>& snakeLocation);
public:

    string appleIcon = "@";
    /**
     * Construct an apple
     */
    Apple(Room& room, vector<Position>& snakeLocation);
    
    bool isEaten(Position& snakeLocation);
    
    void newApple(Room& room, vector<Position>& snakeLocation);
    /**
     * Draw the apple using the GUI
     */
    void draw(Gui& gui);
};

#endif
