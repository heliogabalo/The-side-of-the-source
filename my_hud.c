#include <ncurses.h>

typedef struct _win_border_struct {
        chtype  lt, tt, vv, hh;
}WIN_BORDER;

typedef struct _WIN_struct {

        int startx, starty;
        int height, width;
        WIN_BORDER border;
}WIN;

void init_win_params(WIN *p_win);
void print_win_params(WIN *p_win);
void create_box(WIN *win, bool flag);

int main(int argc, char argv[]) {

    WIN win;
    int ch;
    int y = -2, x = 90;

    initscr();
    start_color();
    cbreak();


    getyx(curscr, y, x);
    printw("x = %d, y = %d", x, y);

    keypad(stdscr, TRUE);
    noecho();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);

    /* Inicializamos parametros de la ventana */
    init_win_params(&win);
    print_win_params(&win);

    attron(COLOR_PAIR(1));
    printw("Pulsa F1 para salir");
    refresh();
    attroff(COLOR_PAIR(1));

    create_box(&win, TRUE);

    while((ch = getch()) != KEY_F(1)) {

        endwin();
        return 0;
    }
}

void init_win_params(WIN *p_win) {
    p_win->height = 7;
    p_win->width = 180;
    p_win->starty = (0);
    p_win->startx = (0);

    p_win->border.lt = (ACS_LTEE);
    p_win->border.tt = (ACS_TTEE);
    p_win->border.vv = (ACS_VLINE);
    p_win->border.hh = (ACS_HLINE);

}

void print_win_params(WIN *p_win)
{
#ifdef _DEBUG
        mvprintw(25, 0, "%d %d %d %d", p_win->startx, p_win->starty,
                                p_win->width, p_win->height);
        refresh();
#endif
}


void create_box(WIN *p_win, bool flag) {

    int i, j; 
    int x, y, w, h;

    x = p_win->startx;
    y = p_win->starty;
    w = p_win->width;
    h = p_win->height;    

    if(flag == TRUE) {

        mvhline(y + h, x, p_win->border.hh, w);
    }
    else
        for(j = y; j <= y + h; ++j)
            for(i = x; i <= x + w; ++i)
                mvaddch(j ,i, ' ');

    refresh();
}













