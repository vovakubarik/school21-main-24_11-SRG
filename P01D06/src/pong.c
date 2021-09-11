// "Copyright [2021] <team23>"
#include <stdio.h>
#define startb_y 12
#define startb_x1 2
#define startb_x2 77
#define startr1_x 1
#define startr_y 12
#define startr2_x 78


void display(int r1_x, int r1_y, int r2_x, int r2_y,
             int b_x, int b_y, int scr1, int scr2);
void draw_winnig_screen(int a);

int main() {
    int r1_x = 1, r1_y = 12, r2_x = 78, r2_y = 12;
    int b_x = 2, b_y = 12;
    int scr1 = 0, scr2 = 0;
    int winF = 0;
    int moveb_x = 1, moveb_y = 1;

    display(r1_x, r1_y, r2_x, r2_y, b_x, b_y, scr1, scr2);

    while (1) {
        char comd;
        comd = getc(stdin);

        if ((comd == 'A' || comd == 'Z' || comd == 'K'
             || comd == 'M' || comd == ' ') && comd != '\n') {
                 int goalF = 0;
            if (b_y == 1 || b_y == 23) {
                moveb_y *= -1;
            }
            b_x += moveb_x; b_y += moveb_y;

            if ((((b_y == r1_y - 1) || (b_y == r1_y) || (b_y == r1_y + 1))
                 || ((b_y == r2_y - 1) || (b_y == r2_y)
                     || (b_y == r2_y + 1))) && (b_x == 2 || b_x == 77)  ) {
        moveb_x *= -1;
    } else if (b_x == 1) {
        scr2++;
        b_x = startb_x1; b_y = startb_y;
        r1_y = startr_y, r2_y = startr_y;
        moveb_x = 1;
        goalF = 1;
    } else if (b_x == 78) {
        scr1++;
        b_x = startb_x2; b_y = startb_y;
        r1_y = startr_y, r2_y = startr_y;
        moveb_x = -1;
        goalF = 1;
    }
    if (goalF != 1) {
                if (comd == 'A' && r1_y - 2 > 0) {
                        r1_y--;
                    } else if (comd == 'Z' && r1_y + 2 < 24) {
                            r1_y++;
                        } else if (comd == 'K' && r2_y - 2 > 0) {
                                r2_y--;
                        } else if (comd == 'M' && r2_y + 2 < 24) {
                                r2_y++;
                        }
    }
        if (scr1 == 21) {
            winF = 1;
        }
        if (scr2 == 21) {
            winF = 2;
        }
        if (winF == 1) {
            draw_winnig_screen(winF);
            return 0;
        } else if (winF == 2) {
            draw_winnig_screen(winF);
            return 0;
        }
            display(r1_x, r1_y, r2_x, r2_y, b_x, b_y, scr1, scr2);
    } else {
        continue;
    }
    }
    return 0;
}


void display(int r1_x, int r1_y, int r2_x, int r2_y,
            int b_x, int b_y, int scr1, int scr2) {
    char vert = '|';
    char hor = '-';
    char space = ' ';
    char r1 = ']', r2 = '[';
    char ball = 'O';

    printf("              Player 1                 ");
    printf("                   Player 2\n");

    if (scr1 < 10) {
        for (int i = 0; i < 80; i++) {
            if (i == 35) {
                printf("%d", scr1);
            } else if (i == 45) {
                printf("%d", scr2);
            } else if (i == 40) {
                printf(":");
            } else {
                printf("%c", space);
            }
        }
    } else {
        for (int i = 0; i < 80; i++) {
            if (i == 34) {
                printf("%d", scr1);
            } else if (i == 44) {
                printf("%d", scr2);
            } else if (i == 39) {
                printf(":");
            } else {
                printf("%c", space);
            }
        }
    }
    printf("\n");
    for (int y = 0; y <= 24; y++) {
        for (int x = 0; x <= 79; x++) {
            if (y == 0 || y == 24) {
                    printf("%c", hor);
            } else if (x == b_x && y == b_y) {
                printf("%c", ball);
            } else if (x == 0 || x == 39 || x == 40 || x == 79) {
                        printf("%c", vert);
                } else if ((x == r1_x && y == r1_y)
                           || (x == r1_x && y-1 == r1_y)
                           || (x == r1_x && y+1 == r1_y)) {
                    printf("%c", r1);
                } else if ((x == r2_x && y == r2_y)
                           || (x == r2_x && y-1 == r2_y)
                           || (x == r2_x && y+1 == r2_y)) {
                    printf("%c", r2);
                } else {
                    printf("%c", space);
                }
            }
        printf("\n");
    }
}

void draw_winnig_screen(int a) {
    if (a == 1) {
        printf("        ****      **  **       ");
        printf("              **    ***      ***       **\n");
        printf("        *   *    ***   **     ");
        printf("              **    *   *     ** **     **\n");
        printf("        *   *   ****    **     ");
        printf("            **    *     *    **  **    **\n");
        printf("        ****      **     **   ");
        printf("   ***      **    *       *   **   **   **\n");
        printf("        **        **      **   ");
        printf(" ** **    **      *     *    **    **  **\n");
        printf("        **        **       ");
        printf("**  **   **  **        *   *     **     ** **\n");
        printf("        **        **        **** ");
        printf("    ****          ***      **       ***\n");
    } else {
        printf("       ****    ******  **        ");
        printf("             **    ***      ***       **\n");
        printf("       *   *        *   **      ");
        printf("             **    *   *     ** **     **\n");
        printf("       *   *        *    **        ");
        printf("         **    *     *    **  **    **\n");
        printf("       ****    ******     **      ");
        printf("***      **    *       *   **   **   **\n");
        printf("       **      *           **    ");
        printf("** **    **      *     *    **    **  **\n");
        printf("       **      *            **  ** ");
        printf("  **  **        *   *     **     ** **\n");
        printf("       **      ******        ****");
        printf("     ****          ***      **       ***\n");
    }
}
