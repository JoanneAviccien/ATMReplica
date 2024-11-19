#include <curses.h>
#include <stdlib.h>

int main()
{
    initscr();
    int tinggi, lebar, awaly, awalx;
    tinggi = 28;
    lebar = 50;
    awaly = awalx = 1;
    WINDOW * tampilanawal = newwin(tinggi, lebar, awaly, awalx);
    refresh();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    //wcolor_set(tampilanawal);
    box(tampilanawal, 0, 0);
    mvwprintw(tampilanawal, 0, 4, "ATM Bank Cuan Aman");
    mvwprintw(tampilanawal, 2, 1, "1. Transfer");
    mvwprintw(tampilanawal, 4, 1, "2. Setor");
    mvwprintw(tampilanawal, 26, 1, "Masukan Nomor: ");
    wrefresh(tampilanawal);
    int input = mvwgetch(tampilanawal, 26, 16);
    wclear(tampilanawal);
    if(input == '1')
    {
        mvwprintw(tampilanawal, 1, 8, "Transfer brp?");
        box(tampilanawal, 0, 0);
        wrefresh(tampilanawal);
        int input = mvwgetch(tampilanawal, 26, 16);
    }
    else if(input == '2')
    {
        mvwprintw(tampilanawal, 1, 8, "Mau setor brp?");
        box(tampilanawal, 0, 0);
        wrefresh(tampilanawal);
        getch();
    }
    else
    {
        endwin();
    }

    endwin();

    return 0;
}
