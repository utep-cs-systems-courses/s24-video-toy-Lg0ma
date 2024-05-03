#include <msp430.h>
#include <math.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw.h"

void runaway_cover()
{
  fillRectangle(14,100, 100, 100, COLOR_RED);
  fillRectangle(34, 80, 60, 60, COLOR_YELLOW);
}


void drawCakeWithCandles()
{
	int baseCol = (screenWidth - 60) / 2; 
    int baseRow = screenHeight / 2;         

    int topCol = (screenWidth - 40) / 2;  
    int topRow = baseRow - 15;       

    // Draw base layer
    fillRectangle(baseCol, baseRow, 60, 20, COLOR_TAN);
    fillRectangle(topCol, topRow, 40, 15, COLOR_TAN);
    fillRectangle(topCol, topRow-10, 40, 5, COLOR_YELLOW);

    int candleSpacing = 40 / (3 + 1);
    for(int i = 1; i <= 3; i++) {
        int candleCol = topCol + i * candleSpacing - 2 / 2;
        for(int j = 0; j < 9; j++) {
            fillRectangle(candleCol, topRow - j, 2, 1, COLOR_BLUE); 
        }
    }
    drawPixel(topCol + 40/2, topRow, COLOR_RED); // Middle cherry
    drawPixel(topCol + 40/3, topRow, COLOR_RED); // Left cherry
    drawPixel(topCol + 2*40/3, topRow, COLOR_RED); // Right cherry
}

void draw_level()
{
	fillRectangle(14,100, 100, 100, COLOR_LIGHT_BLUE);
	fillRectangle(14,100, 100, 20, COLOR_BROWN);
}
void draw_piano()
{
	return;
}

//cd radius == 50 color gray
//cd punchout radius = 15 color ==background
void draw_circle(int radius, u_int color)
{
  int centerX = screenWidth/2; // X-coordinate of circle center
  int centerY = screenHeight/2; // Y-coordinate of circle center
  int radius = radius;  // Radius of the circle

  for (int x = centerX - radius; x <= centerX + radius; x++)
    {
      for (int y = centerY - radius; y <= centerY + radius; y++)
	{
	  // Calculate squared distance from the center
	  int distanceSquared = (x - centerX) * (x - centerX) + (y - centerY) * (y - centerY);
	  // Check if the squared distance is less than or equal to the squared radius
	  if (distanceSquared <= radius * radius)
	    {
	      // Inside the circle, draw a pixel
	      drawPixel(x, y, color); // Yellow face
	    }
	}
    }
}

void draw_shine1()
{
	fillRectangle(71,50,14,10,COLOR_BLUE);

}

void draw_shine2()
{
	fillRectangle(71,50,14,10,COLOR_WHITE);
	fillRectangle(71,50,14,10,COLOR_RED);


}


void restore_vynil()
{
	draw_circle(50, COLOR_BLACK);
	draw_circle(20, COLOR_GRAY);
	draw_circle(15, COLOR_WHITE);
	drawString5x7(16,140,"Choose a Tune", BLACK, COLOR_WHITE);
}
