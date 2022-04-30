#include <allegro.h>
#include <stdlib.h>
#include "warcaby.h"
void init();
void deinit();

int wysokos=800;
int szerokosc=800;

BITMAP * plansza;
BITMAP * pole_biale;
BITMAP * pole_czarne;
BITMAP * pionek_bialy;
BITMAP * pionek_czerwony;
BITMAP * bufor;
BITMAP * aktywny;
BITMAP * ruch;
BITMAP * bicie;
BITMAP * krolowka_biala;
BITMAP * krolowka_czerwona;

void intit_gr(){
bufor = create_bitmap( szerokosc, wysokos);
	plansza = create_bitmap( 800, 800);
	pole_biale = create_bitmap( 100, 100);
	pole_czarne = create_bitmap( 100, 100);
	pionek_bialy = create_bitmap( 100, 100);
	pionek_czerwony = create_bitmap( 100, 100);
aktywny= create_bitmap( 100, 100);
bicie= create_bitmap( 100, 100);
ruch= create_bitmap( 100, 100);
krolowka_biala= create_bitmap( 100, 100);
krolowka_czerwona= create_bitmap( 100, 100);

	clear_to_color( plansza, makecol(0, 0, 0 ) );
	clear_to_color( pole_biale, makecol(255, 255, 255 ) );
	clear_to_color( pole_czarne, makecol(0, 0, 0 ) );
	clear_to_color( pionek_bialy, makecol(255, 0, 255 ) );
clear_to_color( pionek_czerwony, makecol(255, 0, 255 ) );

	clear_to_color( krolowka_biala, makecol(255, 0, 255 ) );
	clear_to_color( krolowka_czerwona, makecol(255, 0, 255 ) );

	clear_to_color( aktywny, makecol(0, 0, 255 ) );
	clear_to_color( ruch, makecol(0, 255, 0 ) );
	clear_to_color( bicie, makecol(255, 0, 0 ) );

	circlefill( pionek_bialy, 50, 50, 45, makecol( 255, 255, 255 ) );
	circlefill( pionek_czerwony, 50, 50, 45, makecol( 255, 0, 0 ) );

	circlefill( krolowka_biala, 50, 50, 45, makecol( 255, 255, 255 ) );
	circlefill( krolowka_czerwona, 50, 50, 45, makecol( 255, 0, 0 ) );

	circlefill( krolowka_biala, 50, 50, 20, makecol( 255, 255, 0 ) );
	circlefill( krolowka_czerwona, 50, 50, 20, makecol( 255, 255, 0 ) );

rectfill( aktywny, 10, 10, 90, 90, makecol( 255, 0, 255 ) );
rectfill( ruch, 10, 10, 90, 90, makecol( 255, 0, 255 ) );
rectfill( bicie, 10, 10, 90, 90, makecol( 255, 0, 255 ) );
	bool p=false;
	for(int i=0;i<8;i++){


		for(int j=0;j<8;j++){
			if(p)
			blit(pole_biale, plansza, 0, 0, i*100, j*100, 100, 100);
			else
			blit(pole_czarne, plansza, 0, 0, i*100, j*100, 100, 100);
			p=!p;
		}
		p=!p;
	}



}

int main() {
	init();



//test
intit_gr();

show_mouse( screen );
pl warcaby;


warcaby.ustaw_pionki();


	while (!warcaby.wygrana) {




	if(mouse_b==1)
    {
         warcaby.wybierz_pionek(mouse_x,mouse_y);


    }


blit(plansza, bufor, 0, 0, 0, 0, 800, 800);

if(warcaby.aktywny_pionek!=-1){

if(warcaby.aktywny_gracz==1){

     masked_blit(aktywny, bufor, 0, 0, warcaby.biale[warcaby.aktywny_pionek].pozycja.y*100, warcaby.biale[warcaby.aktywny_pionek].pozycja.x*100, 100, 100);
}

    if(warcaby.aktywny_gracz==2){
        masked_blit(aktywny, bufor, 0, 0, warcaby.czerwone[warcaby.aktywny_pionek].pozycja.y*100, warcaby.czerwone[warcaby.aktywny_pionek].pozycja.x*100, 100, 100);
    }

}

if(warcaby.lr>0){

    for(int i=0;i<warcaby.lr;i++){

if(warcaby.ruchy[i].rodzaj==1 || warcaby.ruchy[i].rodzaj==2)masked_blit(ruch, bufor, 0, 0, warcaby.ruchy[i].pole.x*100, warcaby.ruchy[i].pole.y*100, 100, 100);
if(warcaby.ruchy[i].rodzaj==3)masked_blit(bicie, bufor, 0, 0, warcaby.ruchy[i].pole.x*100, warcaby.ruchy[i].pole.y*100, 100, 100);
    }
}

for(int i=0;i<warcaby.pb;i++){

    if(warcaby.biale[i].krolowka)masked_blit(krolowka_biala, bufor, 0, 0, warcaby.biale[i].pozycja.y*100, warcaby.biale[i].pozycja.x*100, 100, 100);
       else masked_blit(pionek_bialy, bufor, 0, 0, warcaby.biale[i].pozycja.y*100, warcaby.biale[i].pozycja.x*100, 100, 100);
}
for(int i=0;i<warcaby.pc;i++){

    if(warcaby.czerwone[i].krolowka)masked_blit(krolowka_czerwona, bufor, 0, 0, warcaby.czerwone[i].pozycja.y*100, warcaby.czerwone[i].pozycja.x*100, 100, 100);
        else masked_blit(pionek_czerwony, bufor, 0, 0, warcaby.czerwone[i].pozycja.y*100, warcaby.czerwone[i].pozycja.x*100, 100, 100);
}

textprintf_ex( bufor, font, 200, 30, makecol( 125, 255, 0 ), - 1, "Myszka x = %d, y = %d, klawisz = %d !", mouse_x, mouse_y, mouse_b );
textprintf_ex( bufor, font, 200, 60, makecol( 125, 255, 0 ), - 1, "aktywny gracz = %d, aktywny pionek = %d", warcaby.aktywny_gracz, warcaby.aktywny_pionek );
textprintf_ex( bufor, font, 200, 90, makecol( 125, 255, 0 ), - 1, "x = %d, y = %d", warcaby.czerwone[warcaby.aktywny_pionek].pozycja.x*100, warcaby.czerwone[warcaby.aktywny_pionek].pozycja.y*100 );


for(int i=0;i<8;i++){

    for(int j=0;j<8;j++){

        textprintf_ex( bufor, font, i*100+45, j*100+45, makecol( 125, 255, 0 ), - 1, "%d", warcaby.tab2[i][j] );

    }
}


blit(bufor, screen, 0, 0, 0, 0, 800, 800);
clear_to_color( bufor, makecol(255, 255, 255 ) );
	}

	deinit();
	warcaby.~pl();

allegro_message("Koniec Gry ;)");

	return 0;
}
END_OF_MAIN()

void init() {

	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, wysokos, szerokosc, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();

}

void deinit() {

	clear_keybuf();
delete plansza;
delete pole_biale;
delete pole_czarne;
delete pionek_bialy;
delete pionek_czerwony;
delete bufor;
delete aktywny;
delete ruch;
delete bicie;
delete krolowka_biala;
delete krolowka_czerwona;
}
