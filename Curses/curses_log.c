#include <stdio.h>
#include "curses_head.h"


int main(){

        initscr();
        start_color(); // THAT IS FOR FDRAW -2
        clear();
        cbreak();
        noecho();
        init_pair(1, COLOR_CYAN, COLOR_BLACK); //-2

        select_loop(TRUE);

        refresh();
        endwin();
        return 0;



}
