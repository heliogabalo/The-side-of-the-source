#include <ncurses.h>




typedef struct _win_border_struct {
        chtype  ls, rs, ts, bs,
                tl, tr, bl, br;
}WIN_BORDER;

typedef struct _WIN_struct {

        int startx, starty;
        int height, width;
        WIN_BORDER border;
}WIN;


void init_win_params(WIN *p_win);
void print_win_params(WIN *p_win);
void create_box(WIN *win, bool flag);

int main(int argc, char *argv[])
{       WIN win;
        int ch;
        int max_y = 0, max_x = 0;

        initscr();                      /* Start curses mode            */
        start_color();                  /* Start the color functionality */
        cbreak();                       /* Line buffering disabled, Pass on
                                         * everty thing to me           */
        keypad(stdscr, TRUE);           /* I need that nifty F1         */
        noecho();
        init_pair(1, COLOR_CYAN, COLOR_BLACK);

        /* Initialize the window parameters */
        init_win_params(&win);
        print_win_params(&win);

        attron(COLOR_PAIR(1));
        printw("Press F1 to exit");
        refresh();
        attroff(COLOR_PAIR(1));
        

        getmaxyx(stdscr, max_y, max_x);
        mvprintw(max_y-56,141,"This screen has %d rows and %d columns\n",max_y,max_x);
        create_box(&win, TRUE);
        while((ch = getch()) != KEY_F(1)) {
            

               switch(ch)
                {       case KEY_LEFT:
                                if ( win.startx + 180  == max_x ){
                                    break;
                                 }
                                create_box(&win, FALSE);
                                --win.startx;
                                create_box(&win, TRUE);
                                break;
                        case KEY_RIGHT:
                                if (win.startx + win.width + 1 == max_x  ){
                                    break;
                                 }
                                create_box(&win, FALSE);
                                ++win.startx;
                                create_box(&win, TRUE);
                                if (win.width == COLS){
                                    create_box(&win, FALSE);
                                 } 
                                break;
                        case KEY_UP:
                                if (win.starty - 0 == max_y - 56 ){
                                    break;
                                 }
                                else {
                                  create_box(&win, FALSE);
                                  --win.starty;
                                  create_box(&win, TRUE);
                                  break;
                                }                                
                        case KEY_DOWN:
                                if (win.starty + win.height + 1 == max_y ){
                                    break;
                                }
                                else {
                                   create_box(&win, FALSE);
                                   ++win.starty;
                                   create_box(&win, TRUE);
                                   break;
                                }
                            
                }
        }
        endwin();                       /* End curses mode                */
        return 0;
}

void init_win_params(WIN *p_win)
{
        p_win->height = 10;
        p_win->width = 30;
        p_win->starty = (LINES - p_win->height)/2;
        p_win->startx = (COLS - p_win->width)/2;

        p_win->border.ls = (ACS_VLINE);
        p_win->border.rs = (ACS_VLINE);
        p_win->border.ts = (ACS_HLINE);
        p_win->border.bs = (ACS_HLINE);
        p_win->border.tl = (ACS_ULCORNER);
        p_win->border.tr = (ACS_URCORNER);
        p_win->border.bl = (ACS_LLCORNER);
        p_win->border.br = (ACS_LRCORNER);

}
void print_win_params(WIN *p_win)
{
#ifdef _DEBUG
        mvprintw(25, 0, "%d %d %d %d", p_win->startx, p_win->starty,
                                p_win->width, p_win->height);
        refresh();
#endif
}
void create_box(WIN *p_win, bool flag)
{       int i, j;
        int x, y, w, h;

        x = p_win->startx;
        y = p_win->starty;
        w = p_win->width;
        h = p_win->height;


        if(flag == TRUE)
        {       mvaddch(y, x, p_win->border.tl);
                mvaddch(y, x + w, p_win->border.tr);
                mvaddch(y + h, x, p_win->border.bl);
                mvaddch(y + h, x + w, p_win->border.br);

                mvhline(y, x + 1, p_win->border.ts, w - 1);
                mvhline(y + h, x + 1, p_win->border.bs, w - 1);
                mvvline(y + 1, x, p_win->border.ls, h - 1);
                mvvline(y + 1, x + w, p_win->border.rs, h - 1);
        }

        else
                for(j = y; j <= y + h; ++j)
                        for(i = x; i <= x + w; ++i)
                                mvaddch(j, i, ' ');

        refresh();

}



