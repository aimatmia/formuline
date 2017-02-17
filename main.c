#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {
  screen s;
  color c;

  c.red = MAX_COLOR/2;
  c.green = MAX_COLOR/4;
  c.blue = MAX_COLOR/2;

  int mid = 250;
  clear_screen(s);

  //octants
  draw_line(mid, mid, 499, mid, s, c);
  draw_line(mid, mid, 499, 499, s, c);
  draw_line(mid, mid, 499, 1, s, c);
  draw_line(mid, mid, 0, 499, s, c);
  draw_line(mid, mid, 0, 0, s, c);
  draw_line(mid, mid, 1, 499, s, c);
  draw_line(mid, mid, 1, mid, s, c);
  draw_line(mid, mid, mid, 1, s, c);
  draw_line(mid, mid, mid, 499, s, c);

  int x[4] = {3, 497, 497, 3};
  int y[4] = {3, 3, 497, 497};
  int n = 0;
  int i, index;

  //squares
  while (n<8){
    c.red = MAX_COLOR - (n*n*50);
    c.green = MAX_COLOR - (n*10);
    c.blue = MAX_COLOR - 75*n;
    for(i=0; i<4; i++){
      index= (i+1)%4;
      draw_line(x[i], y[i], x[index], y[index], s, c);
    }
    int xsave = (x[0] + x[1])/2;
    int ysave = (y[0] + y[1])/2;
    for (i=1; i<4;i++)  {
      index =  (i+1)%4;
      x[i] = (x[i] + x[index])/2;
      y[i] = (y[i] + y[index])/2;
    }
    x[0] = xsave;
    y[0] = ysave;
    n++;
  }

  display(s);
  save_extension(s, "finish.png");
}
