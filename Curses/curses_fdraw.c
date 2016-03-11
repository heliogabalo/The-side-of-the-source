//#include <ncurses.h>
#include "curses_head.h"


typedef struct _win_border_struct WIN_BORDER;
typedef struct _WIN_struct WIN;

void init_win_params(WIN *p_win);
void create_box(WIN *p_win, bool flag);
void redraw_loop(int argc, char *argv[], bool flag);



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

void print_win_params(WIN *p_win){
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

void redraw_loop(int argc, char *argv[], bool flag) {
  WIN win;
  int max_y =0, max_x =0;
  int ch;

  keypad(stdscr, TRUE);

  //-2 INITIALIZE PARAMS
  init_win_params(&win);
  print_win_params(&win);
                 
  attron(COLOR_PAIR(1));
  clear();
  printw("Press F1 to exit");                        
  refresh();  
  attroff(COLOR_PAIR(1));

  getmaxyx(stdscr, max_y, max_x);  
  create_box(&win, TRUE);  
  //end -2

        while((ch = getch()) != KEY_F(1)) {

               switch(ch)
                {       case KEY_LEFT:
                                if ( win.startx + 180  == max_x ){
                                    break;
                                 }
                                create_box(&win, FALSE);
                                if (flag == TRUE){
                                  --win.startx;
                                }
                                else if (flag == FALSE)
                                  --win.width;

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
        endwin();
        clear();
        return select_loop();
}

