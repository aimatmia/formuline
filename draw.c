#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

  int x = x0;
  int y = y0;
  int dx = x1 - x0;
  int dy = y1 - y0;
  int B = -dx;
  int A = dy;
   //octant one
   if(dx >= 0){
     if (dy >= 0){
       if( dx > dy){ //dy/dx < 1 & dx positive & dy positive
                     //octant 1 or 5
         //midpt: x+1, y+1/2
         int d = (2*A) + B; //2dy -dx
         while(x < x1){
           plot(s,c,x,y);
           if (d > 0){ // dy/dx>1/2, go right and up
             // midpt: x+2, y+3/2
             // above line
             x++;
             y++;
             d += 2*(A+B);
           }
           else {
           // dy/dx<1/2, go right
           // midpt: x+2, y+1/2
           // below line
              x++;
              d+= (2*A);
           }
         }
       }
       else { //dy/dx > 1 & dx positive & dy positive
         // octant 2 or 6
         // midpt: x+1, y+
         int d = (2*B) + A; // dy-2dx
         while(y < y1){
           plot(s,c,x,y);
           if (d < 0){ //dy/dx < 2, go right and up
             // above line
             x++;
             y++;
             d += (2*(A+B));
           }
           else {
             //dy/dx > 2, go right
             // below line
             y++;
             d+= (2*B);
           }
         }
        }
       }
       else{ //dy < 0 & dx positive
         // octant 8 or 3
         if (dx > dy * -1){
           int d = (2*A) - B; //2dy+dx
           while(x < x1){
             plot(s,c,x,y);
             if (d < 0){ //dy/dx < -2, go right and up
               //above line
               x++;
               y--;
               d += (2*(A-B));
             }
             else{//dy/dx > -2, go right
               // below line
               x++;
               d+= (2*A);
             }
           }
         }
         else{ //dx < 0 & dy < 0
           // octant 7 or 4
           int d = A -(2* B);  //dy +2dx
           while(y > y1) {
             plot(s,c,x,y);
             if (d > 0){ //dy/dx > -2, go right and up
               //above line
               x++;
               y--;
               d += (2*(A-B));
             }
             else{//dy/dx < -2, go right and up
               //below line
               y--;
               d-= (2*B);
             }
           }


         }
       }
     }
     else{ // recursive call switching points x0,y0 and x1,y1 to get the other 4 octants (5,6,3,4)
       draw_line(x1,y1,x0,y0,s,c);
     }
   }
