#include <allegro.h>

using namespace std;
#ifndef warcaby_h
#define warcaby_h


struct pz{
int x;
int y;


};
class pionek{
public:
pionek(){

}


pz pozycja;
bool krolowka;

~pionek(){

}



};

//ruch
struct rc{

pz pole;
int rodzaj;
};

class pl{

public:
    pl(){


    }











	int tab2[8][8]={{1,3,1,3,1,3,1,3},
                    {3,1,3,1,3,1,3,1},
                    {0,3,0,3,0,3,0,3},
                    {3,0,3,0,3,0,3,0},
                    {0,3,0,3,0,3,0,3},
                    {3,0,3,0,3,0,3,0},
                    {2,3,2,3,2,3,2,3},
                    {3,2,3,2,3,2,3,2}
	};

	pionek biale[8];
	pionek czerwone[8];
    int aktywny_pionek;
int aktywny_gracz;
bool wykonano_ruch=false;
bool wygrana=false;

int lr=0; //liczba ruchow
rc ruchy[10];

void bicie(int x,int y){
if(aktywny_gracz==2){

    for(int i=0;i<pb;i++){

if(biale[i].pozycja.x==x&&biale[i].pozycja.y==y){
 pb--;
 if(pb>=0){
 biale[i].pozycja.x=biale[pb].pozycja.x;
     biale[i].pozycja.y=biale[pb].pozycja.y;
 biale[i].krolowka=biale[pb].krolowka;
 tab2[y][x]=0;
 }


 i=8;
}

    }
}


if(aktywny_gracz==1){

    for(int i=0;i<pc;i++){

if(czerwone[i].pozycja.x==x&&czerwone[i].pozycja.y==y){
pc--;
if(pc>=0){

 czerwone[i].pozycja.x=czerwone[pc].pozycja.x;
     czerwone[i].pozycja.y=czerwone[pc].pozycja.y;
 czerwone[i].krolowka=czerwone[pc].krolowka;
 tab2[y][x]=0;
}


 i=8;
}

    }
}

}

void sprawdz_ruchy(){

lr=0;
if(aktywny_gracz==1){



    if(biale[aktywny_pionek].pozycja.y>=0&&biale[aktywny_pionek].pozycja.x<8){
        if(tab2[biale[aktywny_pionek].pozycja.y+1][biale[aktywny_pionek].pozycja.x-1]==0){
ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y+1;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x-1;
ruchy[lr].rodzaj=1;
    lr++;

}
    }

    if(biale[aktywny_pionek].pozycja.y<7&&biale[aktywny_pionek].pozycja.x<8){
        if(tab2[biale[aktywny_pionek].pozycja.y+1][biale[aktywny_pionek].pozycja.x+1]==0){
ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y+1;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x+1;
ruchy[lr].rodzaj=1;
    lr++;

}
    }



//bicie
if(biale[aktywny_pionek].pozycja.y>=0&&biale[aktywny_pionek].pozycja.x<8){
        if((tab2[biale[aktywny_pionek].pozycja.y+1][biale[aktywny_pionek].pozycja.x-1]==2) && (tab2[biale[aktywny_pionek].pozycja.y+2][biale[aktywny_pionek].pozycja.x-2]==0)){
ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y+1;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x-1;
ruchy[lr].rodzaj=3;
    lr++;

ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y+2;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x-2;
ruchy[lr].rodzaj=2;
    lr++;

}
    }

    if(biale[aktywny_pionek].pozycja.y<7&&biale[aktywny_pionek].pozycja.x<8){
        if((tab2[biale[aktywny_pionek].pozycja.y+1][biale[aktywny_pionek].pozycja.x+1]==2) && (tab2[biale[aktywny_pionek].pozycja.y+2][biale[aktywny_pionek].pozycja.x+2]==0)){
ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y+1;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x+1;
ruchy[lr].rodzaj=3;
    lr++;

ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y+2;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x+2;
ruchy[lr].rodzaj=2;
    lr++;

}
    }



//koniec bicia biale zwykle






     if(biale[aktywny_pionek].krolowka==true){

    if(biale[aktywny_pionek].pozycja.y>0&&biale[aktywny_pionek].pozycja.x<8){
        if(tab2[biale[aktywny_pionek].pozycja.y-1][biale[aktywny_pionek].pozycja.x-1]==0){
ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y-1;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x-1;
ruchy[lr].rodzaj=1;
    lr++;

}
    }

    if(biale[aktywny_pionek].pozycja.y>0&&biale[aktywny_pionek].pozycja.x<7){
        if(tab2[biale[aktywny_pionek].pozycja.y-1][biale[aktywny_pionek].pozycja.x+1]==0){
ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y-1;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x+1;
ruchy[lr].rodzaj=1;
    lr++;

}
    }

//krolowka bicie



if(biale[aktywny_pionek].pozycja.y>1&&biale[aktywny_pionek].pozycja.x<8){
        if((tab2[biale[aktywny_pionek].pozycja.y-1][biale[aktywny_pionek].pozycja.x-1]==2) && (tab2[biale[aktywny_pionek].pozycja.y-2][biale[aktywny_pionek].pozycja.x-2]==0)){
ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y-1;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x-1;
ruchy[lr].rodzaj=3;
    lr++;

ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y-2;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x-2;
ruchy[lr].rodzaj=2;
    lr++;

}
    }

    if(biale[aktywny_pionek].pozycja.y>1&&biale[aktywny_pionek].pozycja.x<8){
        if((tab2[biale[aktywny_pionek].pozycja.y-1][biale[aktywny_pionek].pozycja.x+1]==2) && (tab2[biale[aktywny_pionek].pozycja.y-2][biale[aktywny_pionek].pozycja.x+2]==0)){
ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y-1;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x+1;
ruchy[lr].rodzaj=3;
    lr++;

ruchy[lr].pole.x=biale[aktywny_pionek].pozycja.y-2;
ruchy[lr].pole.y=biale[aktywny_pionek].pozycja.x+2;
ruchy[lr].rodzaj=2;
    lr++;

}
    }


//koniec krolowka bicie
     }
}





if(aktywny_gracz==2){



    if(czerwone[aktywny_pionek].pozycja.y>=0&&czerwone[aktywny_pionek].pozycja.x<8){
        if(tab2[czerwone[aktywny_pionek].pozycja.y-1][czerwone[aktywny_pionek].pozycja.x-1]==0){
ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y-1;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x-1;
ruchy[lr].rodzaj=1;
    lr++;

}
    }

    if(czerwone[aktywny_pionek].pozycja.y<8&&czerwone[aktywny_pionek].pozycja.x<8){
        if(tab2[czerwone[aktywny_pionek].pozycja.y-1][czerwone[aktywny_pionek].pozycja.x+1]==0){
ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y-1;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x+1;
ruchy[lr].rodzaj=1;
    lr++;

}
    }

    //czerwone bicie

if(czerwone[aktywny_pionek].pozycja.y>1&&czerwone[aktywny_pionek].pozycja.x<8){
        if((tab2[czerwone[aktywny_pionek].pozycja.y-1][czerwone[aktywny_pionek].pozycja.x-1]==1) && (tab2[czerwone[aktywny_pionek].pozycja.y-2][czerwone[aktywny_pionek].pozycja.x-2]==0)){
ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y-1;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x-1;
ruchy[lr].rodzaj=3;
    lr++;

ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y-2;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x-2;
ruchy[lr].rodzaj=2;
    lr++;

}
    }

    if(czerwone[aktywny_pionek].pozycja.y>1&&czerwone[aktywny_pionek].pozycja.x<8){
        if((tab2[czerwone[aktywny_pionek].pozycja.y-1][czerwone[aktywny_pionek].pozycja.x+1]==1) && (tab2[czerwone[aktywny_pionek].pozycja.y-2][czerwone[aktywny_pionek].pozycja.x+2]==0)){
ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y-1;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x+1;
ruchy[lr].rodzaj=3;
    lr++;

ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y-2;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x+2;
ruchy[lr].rodzaj=2;
    lr++;

}
    }


    //koniec czerwone bicie

     if(czerwone[aktywny_pionek].krolowka==true){
  if(czerwone[aktywny_pionek].pozycja.y>=0&&czerwone[aktywny_pionek].pozycja.x<8){
        if(tab2[czerwone[aktywny_pionek].pozycja.y+1][czerwone[aktywny_pionek].pozycja.x-1]==0){
ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y+1;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x-1;
ruchy[lr].rodzaj=1;
    lr++;

}
    }

    if(czerwone[aktywny_pionek].pozycja.y<8&&czerwone[aktywny_pionek].pozycja.x<8){
        if(tab2[czerwone[aktywny_pionek].pozycja.y+1][czerwone[aktywny_pionek].pozycja.x+1]==0){
ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y+1;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x+1;
ruchy[lr].rodzaj=1;
    lr++;

}
    }
    //bicie


    if(czerwone[aktywny_pionek].pozycja.y<7&&czerwone[aktywny_pionek].pozycja.x<8){
        if((tab2[czerwone[aktywny_pionek].pozycja.y+1][czerwone[aktywny_pionek].pozycja.x-1]==1) && (tab2[czerwone[aktywny_pionek].pozycja.y+2][czerwone[aktywny_pionek].pozycja.x-2]==0)){
ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y+1;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x-1;
ruchy[lr].rodzaj=3;
    lr++;

ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y+2;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x-2;
ruchy[lr].rodzaj=2;
    lr++;

}
    }

    if(czerwone[aktywny_pionek].pozycja.y<7&&czerwone[aktywny_pionek].pozycja.x<8){
        if((tab2[czerwone[aktywny_pionek].pozycja.y+1][czerwone[aktywny_pionek].pozycja.x+1]==1) && (tab2[czerwone[aktywny_pionek].pozycja.y+2][czerwone[aktywny_pionek].pozycja.x+2]==0)){
ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y+1;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x+1;
ruchy[lr].rodzaj=3;
    lr++;

ruchy[lr].pole.x=czerwone[aktywny_pionek].pozycja.y+2;
ruchy[lr].pole.y=czerwone[aktywny_pionek].pozycja.x+2;
ruchy[lr].rodzaj=2;
    lr++;

}
    }

    //koniec krolowka bicie
}
}


}



void rusz_pionek(int x,int y){

if(aktywny_gracz==1){

tab2[biale[aktywny_pionek].pozycja.y][biale[aktywny_pionek].pozycja.x]=0;
    biale[aktywny_pionek].pozycja.x=y;
    biale[aktywny_pionek].pozycja.y=x;
    tab2[x][y]=1;

}

if(aktywny_gracz==2){

tab2[czerwone[aktywny_pionek].pozycja.y][czerwone[aktywny_pionek].pozycja.x]=0;
    czerwone[aktywny_pionek].pozycja.x=y;
    czerwone[aktywny_pionek].pozycja.y=x;
    tab2[x][y]=2;

}

}


    void wybierz_pionek(int mx, int my){
    int x=int(mx/100);
    int y=int(my/100);
    bool wybrano=false;
    if(tab2[x][y]==aktywny_gracz){

        if(aktywny_gracz==1){

            for(int i=0;i<pb;i++){
                if(biale[i].pozycja.x==y&&biale[i].pozycja.y==x)
{
    aktywny_pionek=i;
    wybrano=true;

}
            }
        }
        else{
for(int i=0;i<pc;i++){
                if(czerwone[i].pozycja.x==y&&czerwone[i].pozycja.y==x)
{
    aktywny_pionek=i;
    wybrano=true;

}
            }

        }
    }

if(wybrano){
    sprawdz_ruchy();

}
else{

for(int i=0;i<lr;i++){

    if(ruchy[i].pole.x==x&&ruchy[i].pole.y==y&& ruchy[i].rodzaj!=3){

    if(aktywny_gracz==1&&ruchy[i].rodzaj==2){

            bicie((biale[aktywny_pionek].pozycja.x+y)/2,(biale[aktywny_pionek].pozycja.y+x)/2);
            if(pc==0)wygrana=true;
    }
if(aktywny_gracz==2&&ruchy[i].rodzaj==2){

        bicie((czerwone[aktywny_pionek].pozycja.x+y)/2,(czerwone[aktywny_pionek].pozycja.y+x)/2);
         if(pb==0)wygrana=true;
}

rusz_pionek(x,y);




if(aktywny_gracz==1){

  for(int i=0;i<pb;i++)if(biale[i].pozycja.y==7)biale[i].krolowka=true;
}
if(aktywny_gracz==2){

  for(int i=0;i<pc;i++)if(czerwone[i].pozycja.y==0)czerwone[i].krolowka=true;
}

wykonano_ruch=true;
    }
}

}

if(wykonano_ruch){
    wykonano_ruch=false;
    if(aktywny_gracz==1)aktywny_gracz=2;
    else aktywny_gracz=1;

    lr=-1;
    aktywny_pionek=-1;
}
    }



	int pb; //pionki biale
	int pc; //pionki czerwone
	void ustaw_pionki(){
	    aktywny_gracz=1;
	    aktywny_pionek=-1;
pc=0;
pb=0;
for(int i=0;i<8;i++){


    for(int j=0;j<8;j++){

if(tab2[i][j]==1){
    biale[pb].pozycja.x=j;
    biale[pb].pozycja.y=i;
    biale[pb].krolowka=false;
    pb++;
}

if(tab2[i][j]==2){
    czerwone[pc].pozycja.x=j;
    czerwone[pc].pozycja.y=i;
    czerwone[pc].krolowka=false;
    pc++;
}
    }
}

	}





	~pl(){

delete tab2;
delete biale;
delete czerwone;


}
};

#endif
