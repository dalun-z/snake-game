#if !defined(ROOM_H)
#define ROOM_H

#include "gui.h"

/**
 * This class represents the room in which the game is played
 */
class Room {
private:
    int width;
    int height;

public:
    Room(int screenWidth, int screenHeight);
    
    int getWidth();
    int getHeight();

    /**
     * Draw the four walls of the room using the Gui
     */
    void draw(Gui& gui);
};

#endif
