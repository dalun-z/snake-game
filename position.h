#if !defined(POSITION_H)
#define POSITION_H

class Position {
public:
    int x;
    int y;

    Position() {
        x = 0;
        y = 0;
    }

    Position(int a, int b) {
        x = a;
        y = b;
    };

    Position(const Position& p) {
        x = p.x;
        y = p.y;
    }
};

#endif
