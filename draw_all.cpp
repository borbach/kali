#include <ncurses.h>

//compile with:
//g++ -o draw_all draw_all.cpp -lncurses


void drawCat(int y, int x) {
    mvprintw(y, x, " /\\_/\\ ");
    mvprintw(y + 1, x, "( o.o )");
    mvprintw(y + 2, x, " > ^ < ");
}

void drawDog(int y, int x) {
    mvprintw(y, x, " / \\__");
    mvprintw(y + 1, x, "(    @\\___");
    mvprintw(y + 2, x, " /         O");
    mvprintw(y + 3, x, "/   (_____ /");
}

void drawPerson(int y, int x) {
    mvprintw(y, x, " O");
    mvprintw(y + 1, x, "/|\\");
    mvprintw(y + 2, x, "/ \\");
}

int main() {
    // Initialize ncurses
    initscr();
    // Don't display cursor
    curs_set(0);

    // Draw the cat, dog, and person
    drawCat(1, 5);
    drawDog(7, 5);
    drawPerson(13, 5);

    // Refresh the screen
    refresh();

    // Wait for user input
    getch();

    // Clean up and exit
    endwin();

    return 0;
}

