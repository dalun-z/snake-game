#include "snake.h"
#include "gui.h"
#include "room.h"

Snake::Snake(Room& room) {
    // give enough space for the head and body '++>'
    positions.push_back( {room.getWidth()/2, room.getHeight()/2} );
    positions.push_back( {room.getWidth()/2-1, room.getHeight()/2} );
    positions.push_back( {room.getWidth()/2-2, room.getHeight()/2} );
    direction = Direction::RIGHT;
}

 vector<Position>& Snake::getPositions() {
     return positions;
 }
 

 void Snake::move() {
    for (int i = positions.size() - 1; i > 0; i--) {
        positions[i] = positions[i - 1];
    }
    switch(direction) {
        case Direction::RIGHT:
            positions[0].x++;
            break;
        
        case Direction::UP:
            positions[0].y--;
            break;
        
        case Direction::DOWN:
            positions[0].y++;
            break;
        
        case Direction::LEFT:
            positions[0].x--;
            break;
    }
 }

void Snake::changeDirection(Direction newDirection) {
    if (newDirection == Direction::RIGHT) {
        direction = newDirection;
    } else if (newDirection == Direction::UP) {
        direction = newDirection;
    } else if (newDirection == Direction::DOWN) {
        direction = newDirection;
    } else if (newDirection == Direction::LEFT) {
        direction = newDirection;
    }
}


void Snake::draw(Gui& gui) {
    switch(direction) {
        case Direction::RIGHT:
            gui.drawText(">", positions[0].x, positions[0].y, COLOR_YELLOW, COLOR_WHITE);
            break;
        
        case Direction::UP:
            gui.drawText("^", positions[0].x, positions[0].y, COLOR_YELLOW, COLOR_WHITE);
            break;
        
        case Direction::DOWN:
            gui.drawText("v", positions[0].x, positions[0].y, COLOR_YELLOW, COLOR_WHITE);
            break;
        
        case Direction::LEFT:
            gui.drawText("<", positions[0].x, positions[0].y, COLOR_YELLOW, COLOR_WHITE);
            break;
    }
    
    for (int i = 1; i < positions.size(); i++) {
        gui.drawText(body, positions[i].x, positions[i].y, COLOR_RED, COLOR_YELLOW);
    }
}

void Snake::grow(int num) {
    for (int i = 1; i <= num; i++) {
        positions.push_back( {positions[positions.size()-1].x, positions[positions.size()-1].y} );
    }
}

bool Snake::isHittingTail() {
    for(int i = 1; i < positions.size(); i++) {
        if (positions[0].x == positions[i].x &&
            positions[0].y == positions[i].y)
        return true;
    }
    return false;
}

bool Snake::isColliding(Room& room) {
    for (Position i : positions) {
        if (i.x == 0 || i.x == room.getWidth()-1
            || i.y == 0 || i.y == room.getHeight()-1)
        return true;
    }
    return false;
}
