#include "room.h"
#include "gui.h"

Room::Room(int screenWidth, int screenHeight) {
    width = screenWidth;
    height = screenHeight;
}

int Room::getWidth() {
    return width;
}

int Room::getHeight() {
    return height;
}

void Room::draw(Gui& gui) {
    gui.drawLine("#", 0, 0, width - 1, 0, COLOR_GREEN, COLOR_BLUE);
    gui.drawLine("#", width - 1, 0, width - 1, height - 1, COLOR_GREEN, COLOR_BLUE);
    gui.drawLine("#", width - 1, height - 1, 0, height - 1, COLOR_GREEN, COLOR_BLUE);
    gui.drawLine("#", 0, height - 1, 0, 0, COLOR_GREEN, COLOR_BLUE);
}
