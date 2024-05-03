#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"

void runaway_cover()
{
  fillRectangle(14,100, 100, 100, COLOR_RED);
  fillRectangle(34, 80, 60, 60, COLOR_YELLOW);
}

void draw_cd()
{
  int centerX = screenWidth/2; // X-coordinate of circle center
  int centerY = screenHeight/2; // Y-coordinate of circle center
  int radius = 50;  // Radius of the circle

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
	      drawPixel(x, y, COLOR_GRAY); // Yellow face
	    }
	}
    }
}
