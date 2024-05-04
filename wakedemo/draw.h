#ifndef draw_included
#define draw_included

void runaway_cover();
void draw_cd();
void draw_Cake();
void draw_level();
void draw_Piano();
void update_screen( int cd_sate);
void draw_shine1();
void draw_shine2();
void restore_vynil();
void draw_Play_Button();
void draw_stars();
void drawTriangle(int startCol, int startRow, int width);
void drawLine(unsigned char col, unsigned char row, unsigned char size, unsigned int color);
void drawPix(unsigned char col, unsigned char row);
void draw_Box(unsigned char col, unsigned char row, unsigned char size);

extern int cd_state;
extern int cd_spin;
extern int line;
extern int runaway;
extern int mario;
extern int hbd;
extern int fur_elis;
extern int line;
#endif
