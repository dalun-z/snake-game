#include <math.h>
#include <stdio.h>

#include <cstdarg>
#include <signal.h>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
using namespace std;

#include "gui.h"

Gui::Gui() {
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    curs_set(0);

    lastcolorindex = 1;
}

Gui::~Gui() {
    endwin();

    for (vector<string>::iterator it = loglines.begin(); it != loglines.end(); it++) {
        cout << *it << endl;
    }
}

void Gui::clear() {
    ::clear();
}

void Gui::refresh() {
    wrefresh(stdscr);
}

int Gui::screenHeight() {
    int h, w;
    getmaxyx(stdscr, h, w);
    return h;
}

int Gui::screenWidth() {
    int h, w;
    getmaxyx(stdscr, h, w);
    return w;
}

void Gui::logf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buf[1024];
    vsnprintf(buf, 1024, fmt, args);
    va_end(args);

    loglines.push_back(buf);
}

int Gui::getKeypress() {
    return getch();
}

void Gui::drawText(const string& text, int x, int y,
                   short foregroundColor,
                   short backgroundColor) {
    // mvwaddch(stdscr, y, x, text[0]);
    stringstream ss;
    ss << foregroundColor << ":" << backgroundColor;
    string key = ss.str();
    int colorindex;
    map<string, int>::iterator it = colorpairs.find(key);
    if (it == colorpairs.end()) {
        init_pair(lastcolorindex, foregroundColor, backgroundColor);
        colorpairs[key] = lastcolorindex;
        colorindex = lastcolorindex++;
    } else {
        colorindex = it->second;
    }

    attron(COLOR_PAIR(colorindex));
    mvaddstr(y, x, text.c_str());
    move(0, 0);
    attroff(COLOR_PAIR(colorindex));
}

void Gui::sleep(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void swap(int& x1, int& y1, int& x2, int& y2) {
    int tempx1 = x1;
    int tempy1 = y1;
    x1 = x2;
    y1 = y2;
    x2 = tempx1;
    y2 = tempy1;
}

void Gui::drawLine(const string& text, int x1, int y1, int x2, int y2,
                   short foregroundColor, short backgroundColor) {
    if (x1 == x2) {
        // Draw vertical line
        if (y1 > y2) {
            swap(x1, y1, x2, y2);
        }
        for (int y = y1; y <= y2; y++) {
            drawText(text, x1, y, foregroundColor, backgroundColor);
        }
    } else {
        if (x1 > x2) {
            swap(x1, y1, x2, y2);
        }
        float dx = x2 - y1;
        float dy = y2 - y1;
        for (int x = x1; x <= x2; x++) {
            int y = round(y1 + dy * (x - x1) / dx);
            drawText(text, x, y, foregroundColor, backgroundColor);
        }
    }
}
