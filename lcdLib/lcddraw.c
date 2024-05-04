/** \file lcddraw.c
 *  \brief Adapted from RobG's EduKit
 */
#include "lcdutils.h"
#include "lcddraw.h"
#include <math.h>




/** Draw single pixel at x,row 
 *
 *  \param col Column to draw to
 *  \param row Row to draw to
 *  \param colorBGR Color of pixel in BGR
 */
void drawPixel(unsigned char col, unsigned char row, unsigned int colorBGR) 
{
  lcd_setArea(col, row, col, row);
  lcd_writeColor(colorBGR);
}

//screenWidth/2;
//screenHeight/2 - 20;
void draw_circle(unsigned char radiusx, unsigned char center_X, unsigned char center_Y, unsigned int color)
{
  int centerX = center_X;
  int centerY = center_Y;
  int radius = radiusx;  // Radius of the circle

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

/** Fill rectangle
 *
 *  \param colMin Column start
 *  \param rowMin Row start
 *  \param width Width of rectangle
 *  \param height height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void fillRectangle(unsigned char colMin, unsigned char rowMin, unsigned char width, unsigned char height, 
		   unsigned int colorBGR)
{
  unsigned char colLimit = colMin + width, rowLimit = rowMin + height;
  lcd_setArea(colMin, rowMin, colLimit - 1, rowLimit - 1);
  unsigned int total = width * height;
  unsigned int c = 0;
  while ((c++) < total) {
    lcd_writeColor(colorBGR);
  }
}

/** Clear screen (fill with color)
 *  
 *  \param colorBGR The color to fill screen
 */
void clearScreen(unsigned int colorBGR) 
{
  unsigned char w = screenWidth;
  unsigned char h = screenHeight;
  fillRectangle(0, 0, screenWidth, screenHeight, colorBGR);
}

/** 5x7 font - this function draws background pixels
 *  Adapted from RobG's EduKit
 */
void drawChar5x7(unsigned char rcol, unsigned char rrow, char c, 
     unsigned int fgColorBGR, unsigned int bgColorBGR) 
{
  unsigned char col = 0;
  unsigned char row = 0;
  unsigned char bit = 0x01;
  unsigned char oc = c - 0x20;

  lcd_setArea(rcol, rrow, rcol + 4, rrow + 7); /* relative to requested col/row */
  while (row < 8) {
    while (col < 5) {
      unsigned int colorBGR = (font_5x7[oc][col] & bit) ? fgColorBGR : bgColorBGR;
      lcd_writeColor(colorBGR);
      col++;
    }
    col = 0;
    bit <<= 1;
    row++;
  }
}

/** Draw string at col,row
 *  Type:
 *  FONT_SM - small (5x8,) FONT_MD - medium (8x12,) FONT_LG - large (11x16)
 *  FONT_SM_BKG, FONT_MD_BKG, FONT_LG_BKG - as above, but with background color
 *  Adapted from RobG's EduKit
 *
 *  \param col Column to start drawing string
 *  \param row Row to start drawing string
 *  \param string The string
 *  \param fgColorBGR Foreground color in BGR
 *  \param bgColorBGR Background color in BGR
 */
void drawString5x7(unsigned char col, unsigned char row, char *string,
		unsigned int fgColorBGR, unsigned int bgColorBGR)
{
  unsigned char cols = col;
  while (*string) {
    drawChar5x7(cols, row, *string++, fgColorBGR, bgColorBGR);
    cols += 6;
  }
}


/** Draw rectangle outline
 *  
 *  \param colMin Column start
 *  \param rowMin Row start 
 *  \param width Width of rectangle
 *  \param height Height of rectangle
 *  \param colorBGR Color of rectangle in BGR
 */
void drawRectOutline(unsigned char colMin, unsigned char rowMin, unsigned char width, unsigned char height,
		     unsigned int colorBGR)
{
  /**< top & bot */
  fillRectangle(colMin, rowMin, width, 1, colorBGR);
  fillRectangle(colMin, rowMin + height, width, 1, colorBGR);

  /**< left & right */
  fillRectangle(colMin, rowMin, 1, height, colorBGR);
  fillRectangle(colMin + width, rowMin, 1, height, colorBGR);
}

