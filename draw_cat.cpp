#include <ncurses.h>

//compile with command:
//g++ -o draw_cat draw_cat.cpp -lncurses


int main() {
    // Initialize ncurses
    initscr();
    // Don't display cursor
    curs_set(0);

    // Draw the cat
    mvprintw(1, 5, " /\\_/\\ ");
    mvprintw(2, 5, "( o.o )");
    mvprintw(3, 5, " > ^ < ");
    mvprintw(5, 5, " /\\_/\\ ");
    mvprintw(6, 5, "( o.o )");
    mvprintw(7, 5, " > ^ < ");
    mvprintw(9, 5, " /\\_/\\ ");
    mvprintw(10, 5, "( o.o )");
    mvprintw(11, 5, " > ^ < ");
    mvprintw(13, 5, " /\\_/\\ ");
    mvprintw(14, 5, "( o.o )");
    mvprintw(15, 5, " > ^ < ");

    // Refresh the screen
    refresh();
    
    // Wait for user input
    getch();

    // Clean up and exit
    endwin();

    return 0;
}

