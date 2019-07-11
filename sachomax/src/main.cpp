/*!
 \mainpage Semestrial project AntWars
 
 \section info_sec General info
 Project have 2 levels.
 Player can upload his own maps, just name it map_x.txt where x from 0 to 9.
 Program use terminal as screen, make you termianl as big as you can.
 \warning
 libncurses were used for implementation, make sure, it have been installed.
 
 \section controls_sec Game controls
 SPACE- for make turn or enter the game
 CODES like N 0 X or N 1 X where N,X from 0 to 9. N 0 X close road from N to X , N 1 X open road from N to X.
 CTRL+C- leave game.
 SAV-for make save(you can lose all your warriors that are out of clan)
 */
#include <ncurses.h>
#include "Headers/game.h"
#include <iostream>

using namespace std;
/*!
 Initialized screen and start the game
 */

int main() {
    initscr();
    noecho();
    while(menu())
    {
        if(!game())
        {
            erase();
            mvprintw(0,0,"Loser");
            refresh();
            getchar();
            erase();
        }
        else
        {
            erase();
            mvprintw(0,0,"Winner");
            refresh();
            getchar();
            erase();
        }
    }
    erase();
    endwin();
    return 0;
}
