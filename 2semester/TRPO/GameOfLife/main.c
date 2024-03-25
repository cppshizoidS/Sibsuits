#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h> // Include time.h for nanosleep

#define WIDTH 80
#define HEIGHT 25

void draw(int arena[HEIGHT - 2][WIDTH - 2]);
int initConf(int state, int (*arena)[HEIGHT - 2][WIDTH - 2]);
void logic(int (*arena)[HEIGHT - 2][WIDTH - 2]);
int getspeed(int time);
int delayMicroseconds(long microseconds);

int main() {
  int state, delay = 0;
  int arena[HEIGHT - 2][WIDTH - 2];

  initscr();

  scanw("%d", &state);

  if (!initConf(state, &arena)) {
    refresh();
    endwin();
    printf("No search directory!");
    exit(1);
  }

  noecho();
  cbreak();
  halfdelay(1);

  while (1) {
    clear();

    draw(arena);
    logic(&arena);
    delay = getspeed(delay);

    if (delay == -1)
      break;

    delayMicroseconds(delay); // Using the delayMicroseconds function
    refresh();
  }

  refresh();
  endwin();

  return 0;
}

void draw(int arena[HEIGHT - 2][WIDTH - 2]) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (i % (HEIGHT - 1) == 0 && j % (WIDTH - 1) == 0)
        printw("o");
      else if (i % (HEIGHT - 1) == 0 && j % (WIDTH - 1) != 0)
        printw("-");
      else if (i % (HEIGHT - 1) != 0 && j % (WIDTH - 1) == 0)
        printw("|");
      else if (arena[i - 1][j - 1] == 1)
        printw("*");
      else
        printw(" ");
    }

    printw("\n");
  }
}

int initConf(int state, int (*arena)[HEIGHT - 2][WIDTH - 2]) {
  FILE *file = NULL;
  int res = 1;
  if (state == 1)
    file = freopen("conf/1.txt", "r", stdin);
  else if (state == 2)
    file = freopen("conf/2.txt", "r", stdin);
  else if (state == 3)
    file = freopen("conf/3.txt", "r", stdin);
  else if (state == 4)
    file = freopen("conf/4.txt", "r", stdin);
  else if (state == 5)
    file = freopen("conf/5.txt", "r", stdin);

  if (file == NULL)
    res = 0;
  else {
    int i = 0, j = 0;
    int c;

    while ((c = getc(stdin)) != EOF) {
      if (c == '1' || c == '0') {
        j++;
        (*arena)[i][j] = c - 48;
      } else if (c == '\n' || c == 2) {
        j = 0;
        i++;
      }
    }

    file = freopen("/dev/tty", "r", stdin);
    if (file == NULL)
      res = 0;
  }

  return res;
}

void logic(int (*arena)[HEIGHT - 2][WIDTH - 2]) {
  int buffer[HEIGHT - 2][WIDTH - 2] = {{0}};
  for (int i = 0; i < HEIGHT - 2; i++) {
    for (int j = 0; j < WIDTH - 2; j++) {
      int sum = 0;
      int bi[8], bj[8];
      if (i == 0) {
        bi[0] = bi[1] = bi[2] = HEIGHT - 3;
        bi[5] = bi[6] = bi[7] = i + 1;
      } else if (i == HEIGHT - 3) {
        bi[0] = bi[1] = bi[2] = i - 1;
        bi[5] = bi[6] = bi[7] = 0;
      } else {
        bi[0] = bi[1] = bi[2] = i - 1;
        bi[5] = bi[6] = bi[7] = i + 1;
      }
      bi[3] = bi[4] = i;
      if (j == 0) {
        bj[0] = bj[3] = bj[5] = WIDTH - 3;
        bj[2] = bj[4] = bj[7] = j + 1;
      } else if (j == WIDTH - 3) {
        bj[0] = bj[3] = bj[5] = j - 1;
        bj[2] = bj[4] = bj[7] = 0;
      } else {
        bj[0] = bj[3] = bj[5] = j - 1;
        bj[2] = bj[4] = bj[7] = j + 1;
      }
      bj[1] = bj[6] = j;
      for (int k = 0; k < 8; k++)
        sum += (*arena)[bi[k]][bj[k]];
      buffer[i][j] = (*arena)[i][j];
      if (sum == 3 && (*arena)[i][j] == 0)
        buffer[i][j] = 1;
      else if ((sum < 2 || sum > 3) && (*arena)[i][j] == 1)
        buffer[i][j] = 0;
    }
  }
  for (int i = 0; i < HEIGHT - 2; i++)
    for (int j = 0; j < WIDTH - 2; j++)
      (*arena)[i][j] = buffer[i][j];
}

int getspeed(int time) {
  int ch;
  int res = time;

  if ((ch = getch())) {
    if (ch == '=') {
      time -= 100000;
      res = time;
    } else if (ch == '-') {
      time += 100000;
      res = time;
    } else if (ch == 'q' || ch == 'Q')
      res = -1;

    if (time < 0)
      res = 0;
  }
  return res;
}

int delayMicroseconds(long microseconds) {
  struct timespec delay;
  delay.tv_sec = microseconds / 1000000;
  delay.tv_nsec = (microseconds % 1000000) * 1000;

  return nanosleep(&delay, NULL);
}
