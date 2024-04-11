/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void drawSquare(int startCol, int startRow, int width, int height)
{
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){
      drawPixel(startCol + i, startRow + j ,COLOR_PINK);
    }
  }
}

void drawTriangle1(int startCol, int startRow, int width, int height)
{
  for(int i = 0; i < width; i++){
    for(int j = 0; j < i; j++){
      drawPixel(startCol + i, startRow + j ,COLOR_PINK);
    }
  }
}

void drawTriangle1(int startCol, int startRow, int width, int height)
{
  for(int i = 0; i < width; i++){
    for(int j = 0; j < i; j++){
      drawPixel(startCol - i, startRow - j ,COLOR_PINK);
    }
  }
}



/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(COLOR_NAVY);

   drawString5x7(20,60, "Im Goma", COLOR_GREEN, COLOR_NAVY);


  // fillRectangle(30,30, 90, 90, COLOR_ORANGE);

  short centerRow = screenHeight >> 1;
  short centerCol = screenWidth >> 1;

  int x = 0;
  int y = 0;
  int speed = 6;
  
  for(short i = 0; i < screenWidth; i++){
      drawPixel(x, centerRow - y, COLOR_PINK);
      drawPixel(x, centerRow - speed, COLOR_GREEN);
      x++;
      y += speed;
      speed -= 1;
      if(y <= 0)
	{
	  speed = -speed;
	}
  }
  drawSquare(20,20,20,20);
  drawTriangle(40,40,20,20);
}


