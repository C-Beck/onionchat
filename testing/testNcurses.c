#include <ncurses.h>
#include <stdio.h>
#include "network.h"
int main()
{
char ip[16];
get_ip(ip);

initscr();
if(has_colors()==false)
{
endwin();
return(1);
}
start_color();
use_default_colors();
init_pair(1,233,COLOR_RED);
init_pair(2,COLOR_WHITE,233);
WINDOW *head,*chat,*usr,*foot,*entry;
head = newwin(1,COLS,0,0);
chat = newwin(LINES-3,COLS-15,1,0);
usr = newwin(LINES-3,15,1,COLS-15);
foot = newwin(1,COLS,LINES-2,0);
entry = newwin(1,COLS,LINES-1,0);
wbkgd(head,COLOR_PAIR(1));
wbkgd(chat,COLOR_PAIR(2));
wbkgd(usr,COLOR_PAIR(2));
wbkgd(foot,COLOR_PAIR(1));
wbkgd(entry,COLOR_PAIR(2));
wprintw(head,"Hello World !!!");
short r,g,b;
color_content(COLOR_BLACK,&r,&g,&b);
wprintw(chat,"%d,%d,%d",r,g,b);
wprintw(foot,ip);
refresh();
wrefresh(head);
wrefresh(chat);
wrefresh(usr);
wrefresh(foot);
wrefresh(entry);
wgetch(entry);
endwin();

return 0;
}
