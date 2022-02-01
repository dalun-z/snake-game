#if !defined(GUI_H)
#define GUI_H

#include <curses.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

/**
 * The Gui class provides a simplified interface to text graphics.
 *
 *
 */
class Gui {
private:
    vector<string> loglines;
    map<string, int> colorpairs;
    int lastcolorindex;

public:
    /**
     * Creating a GUI object clears the screen and starts the drawing process.
     */
    Gui();

    /**
     * The destructor cleans up and prints the lines logged, if any
     */
    ~Gui();

    /**
     * Return the height of the screen, i.e. number of rows
     */
    int screenHeight();

    /**
     * Return the width of the screen, i.e. number of columns
     */
    int screenWidth();

    /**
     * Clear the screen to begin drawing. Call this function before you start
     * drawing so you get a clear slate
     */
    void clear();

    /**
     * Show all the things you've drawn to the offscreen buffer all at once.
     * Call this after you finish drawing.
     */
    void refresh();

    /**
     * Pause execution for the given amount of time.
     */
    void sleep(int milliseconds);

    /**
     * Log a string in printf format. This will get printed out to the console
     * at the end when the program stops running
     */
    void logf(const char* fmt, ...);

    /**
     * Get a key press. If the user pressed 'a', then this function returns 'a'.
     * If the user doesn't press a key, this function returns 0.
     */
    int getKeypress();

    /**
     * Draw the text  at the given location in the given color
     */
    void drawText(const string& text, int x, int y,
        short foregroundColor, short backgroundColor);

    /**
     * Draw a line with the given text from (x1, y2) to (x2, y2) in the
     * given color
     */
    void drawLine(const string& text, int x1, int y1, int x2, int y2,
        short foregroundColor, short backgroundColor);
};

#endif
