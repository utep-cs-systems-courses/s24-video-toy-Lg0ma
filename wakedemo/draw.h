#ifndef draw_included
#define draw_included

void runaway_cover();
void draw_cd();
void draw_Cake();
void draw_level();
void draw_Piano();
void update_screen(u_char cd_sate);
void draw_shine1();
void draw_shine2();
void restore_vynil();
void draw_Play_Button();

extern u_char cd_state;
extern u_char cd_spin;
extern u_char line;
extern u_char runaway;
extern u_char mario;
extern u_char hbd;
extern u_char fur_elis;
#endif
