/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void drawPiano(){
  fillRectangle(11, 125, 110, 35, COLOR_BROWN);
  fillRectangle(16, 130, 100, 25, COLOR_WHITE);
  drawRectOutline(16, 130, 100, 25, COLOR_BLACK);
  // used to draw the lines to create piano keys
  for(int i = 15; i < 116; i++){
    if ((i % 10) == 0){
      for(int j = 130; j < 155; j++){
	      drawPixel(i, j, COLOR_BLACK);
      }
    }
  }
  fillRectangle(19, 130, 4, 15, COLOR_BLACK);
  fillRectangle(29, 130, 4, 15, COLOR_BLACK);
  fillRectangle(39, 130, 4, 15, COLOR_BLACK);
  fillRectangle(59, 130, 4, 15, COLOR_BLACK);
  fillRectangle(69, 130, 4, 15, COLOR_BLACK);
  fillRectangle(89, 130, 4, 15, COLOR_BLACK);
  fillRectangle(99, 130, 4, 15, COLOR_BLACK);
  fillRectangle(109, 130, 4, 15, COLOR_BLACK);
  fillRectangle(120, 130, 4, 15, COLOR_WHITE);
}

void restore_vynil()
{
	draw_circle(50, COLOR_BLACK);
	draw_circle(20, COLOR_RED);
	draw_circle(5, COLOR_WHITE);
  fillRectangle(74,28,50,10,COLOR_GRAY);
	drawString5x7(26,120,"Choose a Tune", BLACK, COLOR_WHITE);
}


void drawCake()
{
  fillRectangle(20,34,88, 88, COLOR_AQUAMARINE);
	int baseCol = (screenWidth - 60) / 2; //128-60/2 = 34
    int baseRow = screenHeight / 2;//80     

    int topCol = (screenWidth - 40) / 2;  //
    int topRow = baseRow - 15;       

    fillRectangle(baseCol, baseRow, 60, 20, COLOR_TAN);
    fillRectangle(topCol, topRow, 40, 15, COLOR_TAN);
    fillRectangle(topCol, topRow, 40, 5, COLOR_YELLOW);

    int candleSpacing = 40 / (3 + 1);
    for(int i = 1; i <= 3; i++) {
        int candleCol = topCol + i * candleSpacing - 2 / 2;
        for(int j = 0; j < 9; j++) {
            fillRectangle(candleCol, topRow - j, 2, 1, COLOR_BLUE); 
        }
    }
    drawPixel(topCol + 40/2, topRow, COLOR_RED); 
    drawPixel(topCol + 40/3, topRow, COLOR_RED); 
    drawPixel(topCol + 2*40/3, topRow, COLOR_RED); 
}


void drawSquare(int startCol, int startRow, int width, int height)
{
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){
      drawPixel(startCol + i, startRow + j ,COLOR_PINK);
    }
  }
}

void drawTriangle(int startCol, int startRow, int width) {
    for(int i = 0; i < width; i++) {
        for(int j = 0; j <= i; j++) {
            drawPixel(startCol - j, startRow + i, COLOR_BLACK);  
        }
    }

    for(int i = 0; i < width; i++) {
        for(int j = 0; j <= i; j++) {
            drawPixel(startCol + j, startRow + i, COLOR_BLACK);  
    }
}
}




void drawPlayButton()
 {
  int startX = 60;
  int startY = 120;
  int size = 10; 
  for (int i = 0; i < size; ++i) 
  {
    for (int j = 0; j < i; ++j) 
    {
      drawPixel(startX + j, startY + i, COLOR_BLACK); // Draw pixels from vertex to right
    }
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size - i; j++)
    {
      drawPixel(startX + j, startY + size + i, COLOR_BLACK); // Draw pixels from vertex to right
    }
    
  }
  
}

void draw_level()
{
	clearScreen(WHITE);
  fillRectangle(20,34,88, 88, COLOR_SKY_BLUE);
	fillRectangle(20,100, 88, 22, COLOR_BROWN);
  fillRectangle(30, 90, 15,10, COLOR_GREEN);
  fillRectangle(28,88,19,5,COLOR_GREEN);
  fillRectangle(57,75, 30,8, COLOR_BROWN);
  fillRectangle(67,60,8,8,COLOR_YELLOW);
  fillRectangle(33,82,7,6,COLOR_BLUE);
  fillRectangle(33,77,7,6,COLOR_RED);
  fillRectangle(30,44,12,6,WHITE);
  fillRectangle(55,48,11,6,WHITE);
  fillRectangle(75,46,11,6,WHITE);

}



void drawRunaway(){
  fillRectangle(20,34,88, 88, COLOR_RED);
  fillRectangle(39,53,50, 50, COLOR_YELLOW);
  fillRectangle(42,56,44,44,COLOR_AQUAMARINE);
  fillRectangle(65,93,10,7,COLOR_TAN);
  fillRectangle(50,73,20,5,COLOR_TAN);
  fillRectangle(68,65,5,5,COLOR_TAN);
  fillRectangle(67,58,7,7,COLOR_TAN);
  fillRectangle(65,70,10,15,COLOR_BLACK);
  drawTriangle(70,80,15);
}


/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;

  clearScreen(WHITE);

  //  drawString5x7(20,60, "Im Goma", COLOR_GREEN, COLOR_NAVY);


  // fillRectangle(30,30, 90, 90, COLOR_ORANGE);

  short centerRow = screenHeight >> 1;
  short centerCol = screenWidth >> 1;

  int x = 0;
  int y = 0;
  int speed = 6;
  
  // drawSquare(20,20,20,20);
  // drawPiano();
  // drawCake();
  // drawPlayButton();
  // restore_vynil();
  // drawPiano();
  // drawRunaway();
  draw_level();
}


