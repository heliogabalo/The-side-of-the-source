#include "curses_head.h"


char *choices[] = {
  "1-Mover Ventana",
  "2-Redimensionar V.",
  "3-Choice",
  "4-Choice",
  "Exit",
};


int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);


void select_loop(){
  WIN win;
  
  win.startx = 0;
  win.starty = 0;

  WINDOW *menu_win;
  int highlight = 1;
  int choice = 0;
  int c, i;

  win.startx = (COLS - WIDTH) / 2;
  win.starty = (LINES - HEIGHT) / 2;

  menu_win = newwin(HEIGHT, WIDTH, win.starty, win.startx);
  keypad(menu_win, TRUE);
  mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");

  refresh();
  print_menu(menu_win, highlight);

  
    while(1)
    {       c = wgetch(menu_win);
            switch(c)
            {       case KEY_UP:
                            if(highlight == 1)
                                    highlight = n_choices;
                            else
                                    --highlight;
                            break;
                    case KEY_DOWN:
                            if(highlight == n_choices)
                                    highlight = 1;
                            else
                                    ++highlight;
                            break;
                    case 10:
                            choice = highlight;
                            break;
  
                    default:
                            mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                            refresh();
                            break;
            }

            print_menu(menu_win, highlight);
            if(choice != 0){  /* User did a choice come out */
              exec_function();
              break;
                
              }
    }
                  

        mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice -1]);
        clrtoeol();
        refresh();
    

        

}

void print_menu(WINDOW *menu_win, int highlight)
{
        int x, y, i;

        x = 2;
        y = 2;
        box(menu_win, 0, 0);
          for(i = 0; i < n_choices; ++i)
          {       if(highlight == i + 1) /* High light the present choice */
                  {       wattron(menu_win, A_REVERSE);
                          mvwprintw(menu_win, y, x, "%s", choices[i]);
                          wattroff(menu_win, A_REVERSE);
                  }
                  else
                          mvwprintw(menu_win, y, x, "%s", choices[i]);
                  ++y;
          }
          wrefresh(menu_win);
        }

void exec_function(){
  int c, i;
  
  for(i = 0; i <= 4; ++i){
//    while(1){
      if(*choices[i] == *choices[0])
        redraw_loop(c, NULL, TRUE);
      else if(*choices[i] == *choices[1])
        redraw_loop(c, NULL, FALSE);
      else if(*choices[i] == *choices[2])
        break;
      else if(*choices[i] == *choices[3])
        break;
      else
        break;
//    }
  }
  



}
