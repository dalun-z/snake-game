#if !defined(SNAKE_H)
#define SNAKE_H

#include <vector>
using namespace std;

#include "gui.h"
#include "position.h"
#include "room.h"

enum class Direction { RIGHT, UP, DOWN, LEFT };

/**
 * This class represents a snake on the screen
 */
class Snake {
private:
    vector<Position> positions;
    Direction direction;

public:
    /**
     * Initialize the snake to the center of the screen
     */
    Snake(Room& room);
    
    string body = "+";
    
    void move();
    
    void grow(int num);
    
    void changeDirection(Direction newDirection);
    
    int getCurrentDirection();

    /**
     * Return the positions occupied by the snake
     */
    vector<Position>& getPositions();
    
    bool isColliding(Room& room);
    
    bool isHittingTail();

    /**
     * Draw the snake on the screen using the GUI
     */
    void draw(Gui& gui);
};

#endif
