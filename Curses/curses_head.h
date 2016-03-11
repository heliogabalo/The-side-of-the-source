#include <ncurses.h>

#ifndef _CURSES_LOG_
#define _CURSES_LOG_


#define WIDTH  30
#define HEIGHT 10

#endif


#ifndef _CURSES_FDRAW_
#define _CURSES_FDRAW_


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
void create_box(WIN *p_win, bool flag);
int redraw_loop();

#endif

#ifndef _CURSES_FSELECT_
#define _CURSES_FSELECT_


int n_choices;

int print_menu(WINDOW *win_menu, int highlight);
int select_loop(bool flag_select);
bool gflag;

#endif
