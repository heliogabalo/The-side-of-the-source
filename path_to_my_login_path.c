#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>


int curse_init(){

    char mesg[]="Enter a command-line app: ";
    char str[4];
    int row,col;

    initscr();
    echo();
    getmaxyx(stdscr,row,col);
    mvprintw(row/2,(col-strlen(mesg))/2, "%s", "%s", mesg, str);

    getstr(str);
    getch();
    endwin();

    return 0;
}

int main(int argc, char *argv[]){
    
    curse_init();
    
    
    char *newargv[] = { NULL, curse_init.str, NULL };
    char *newenviron[] = { NULL };

    if (argc !=2){
        fprint(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    newargv[0] = argv[1];

    execve(argv[1], newargv, newenviron);
    perror("execve"); /* execve() only returns on error */
    exit(EXIT_FAILURE);
}

//int execve(const char *filename, char *const argv[], char *const envp[]){}

//int my_login(){}

