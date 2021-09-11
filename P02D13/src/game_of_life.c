#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#define SIZE_X 25
#define SIZE_Y 80
#define FULL 'O'
#define EMPTY '.'
#define PRINT_EMPTY " "
#define PRINT_FULL "\u2588"
#define TURNBASED 's'
#define INTERACTIVE 'i'
#define SLOWER 'd'
#define FASTER 'f'
#define EXIT 'q'


void init_matrix(char **matrix, int x, int y);
char **memoryAlocate(int x_n, int y_n);
void output(char **matrix, int n, int m);
int input_array(char **buffer, int x_n, int y_n);
void char_to_int(char **buffer, int x_n, int y_n);
char *output_help(char i);
int next_frame(char **buffer, int x_n, int y_n);
void copy_array(char **buffer, int x_n, int y_n, char **new_matrix);
int count_neighbours(char **buffer, int x, int y);
int closure(int i, int o, int b);
int clamp(int a);
int exitRun(void);

int main() {
    char **matrix = NULL;
    int n = SIZE_X, m = SIZE_Y;
    char GameType;
    int TickRate = 110000, fd;
    FILE * fp;

    matrix = memoryAlocate(n, m);
    if (matrix == NULL)
        return exitRun();

    if (!input_array(matrix, n, m)) {
        free(matrix);
        return exitRun();
    }

    char_to_int(matrix, n, m);

    fd = dup(fileno(stdin));
    fp = fdopen(fd, "r");
    (void) freopen("/dev/tty", "r", stdin);

    puts("Press 's' for a step-by-step mode");
    puts("Enter 'i' for an interactive mode");
    puts("Enter 'f' to increase speed");
    puts("Enter 'd' to decrease speed");
    puts("Use 'q' to exit the game");
    scanf("%c", &GameType);

    struct termios termios_p;
    tcgetattr(0, &termios_p);
    termios_p.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(0, 0, &termios_p);

    if (GameType == EXIT) {
        free(matrix);
        return exitRun();
    }
    if (GameType == INTERACTIVE) {
        fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL) | O_NONBLOCK);
    } else {
        if (GameType != TURNBASED) {
            free(matrix);
            return exitRun();
        }
    }

    do {
        printf("\e[1;1H\e[2J");
        output(matrix, n, m);
        if (GameType == INTERACTIVE) usleep(TickRate);
        char input = getchar();

        if (input == EXIT || input == 4) break;
        if (input == FASTER) TickRate = clamp(TickRate - 10000);
        if (input == SLOWER) TickRate = clamp(TickRate + 10000);
        if (GameType == TURNBASED && input != ' ') continue;
        if (!next_frame(matrix, n, m)) break;
    } while (1);
    free(matrix);
    return 0;
}

int clamp(int a) {
    if (a < 20000)
        return 20000;
    if (a > 1000000)
        return 1000000;
    return a;
}

void copy_array(char **buffer, int x_n, int y_n, char **new_matrix) {
    for (int i = 0; i < x_n; i++)
        for (int j = 0; j < y_n; j++)
            new_matrix[i][j] = buffer[i][j];
}

int closure(int i, int o, int b) {
    return (i + o + b) % b;
}

int count_neighbours(char **buffer, int x, int y) {
    int sum = 0;
    int offset_x[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int offset_y[9] = {-1, 0, +1, -1, 0, +1, -1, 0, +1};

    for (int i = 0; i < 9; i++)
        if (i != 4)
            sum += buffer[closure(x, offset_x[i], SIZE_X)][closure(y, offset_y[i], SIZE_Y)];
    return sum;
}

int next_frame(char **buffer, int x_n, int y_n) {
    char **new_matrix = NULL;
    new_matrix = memoryAlocate(x_n, y_n);
    if (new_matrix == NULL)
        return 0;
    copy_array(buffer, x_n, y_n, new_matrix);

    int alive = 0;

    for (int i = 0; i < x_n; i++)
        for (int j = 0; j < y_n; j++) {
            int neighbours = count_neighbours(buffer, i, j);

            if (buffer[i][j]) {
                if (neighbours < 2 || neighbours > 3)
                    new_matrix[i][j] = 0;
            } else {
                if (neighbours == 3) {
                    new_matrix[i][j] = 1;
                    alive++;
                }
            }
        }
    copy_array(new_matrix, x_n, y_n, buffer);
    free(new_matrix);
    if (!alive) {
        return 0;
    }
    return 1;
}

char *output_help(char i) {
    return i == 0 ? PRINT_EMPTY : PRINT_FULL;
}

void char_to_int(char **buffer, int x_n, int y_n) {
    for (int i = 0; i < x_n; i++)
        for (int j = 0; j < y_n; j++)
            buffer[i][j] = buffer[i][j] == EMPTY ? 0 : 1;
}

int input_array(char **buffer, int x_n, int y_n) {
    char endl = 0;
    if (*buffer == NULL)
        return 0;
    for (int i = 0; i < x_n; i++) {
        for (int j = 0; j < y_n; j++) {
            char buf;
            if (!scanf("%c", &buf))
                return 0;
            if (j < y_n - 1 && buf == '\n')
                return 0;
            if (buf == EMPTY || buf == FULL)
                buffer[i][j] = buf;
            else
                return 0;
        }
        scanf("%c", &endl);
        if (endl != '\n')
            return 0;
    }
    return 1;
}

char **memoryAlocate(int x_n, int y_n) {
    char **matrix = (char**) malloc(sizeof(char*) * x_n + sizeof(char) * x_n * y_n);
    if (matrix != NULL) {
        init_matrix(matrix, x_n, y_n);
    }
    return matrix;
}

void init_matrix(char **matrix, int x, int y) {
    char *ptr = (char *) (matrix + x);
    for (int i = 0; i < x; i++)
        matrix[i] = (ptr + y * i);
}

void output(char **buffer, int x_n, int y_n) {
    for (int i = 0; i < x_n; i++) {
        for (int j = 0; j < y_n; j++)
            printf("%s", output_help(buffer[i][j]));
        printf("\n");
    }
}

int exitRun() {
    printf("n/a");
    return 1;
}
