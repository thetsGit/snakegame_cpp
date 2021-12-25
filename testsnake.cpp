#include<iostream>
#include<ctime>
#include<windows.h>
#include<stdio.h>
#include<conio.h>

using namespace std;
bool Gameover;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
enum eDirection{STOP,LEFT,RIGHT,UP,DOWN};
eDirection dir;
int tailX[100];
int tailY[100];
int ntail;

void setup(){
    srand(time(0));
    Gameover =false;
    score=0;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
tailX[0]=x;
tailY[0]=y;
}
void draw(){
    system("CLS");
for (int a=0;a<width+1;a++){
    cout<<"#";

}  cout<<endl;
   for (int a=0;a<height;a++){

    for (int b=0;b<width;b++){

        if (b==0){
            cout <<"#";
        }else
        if (x==a&&y==b){
            cout <<"O";
        }else
        if (fruitX==a&&fruitY==b){
            cout <<"F";
        }else
        {
            bool print;
            for (int z=0;z<ntail;z++){
                if(tailX[z]==a&&tailY[z]==b){
                    cout <<"o";
                    print =true;}
                }

                    if (!print)
                    cout <<" ";
        if (b==width-1){
            cout <<"#";
        }
        }
        }
cout<<endl;


   }
for (int a=0;a<width+1;a++){
    cout<<"#";
}

}
void input(){
    if (_kbhit()){
     switch (getch()){

     case 'a':
    dir=LEFT;
    break;
      case 'd':
    dir=RIGHT;
     break;
     case 'w':
    dir=UP;
     break;
     case 's':
    dir=DOWN;
     break;
    case 'x':
    Gameover =true;
    cout <<"You are loser";
         break;


     if(x==fruitX&&y==fruitY){
        score+=10;
         fruitX=rand()%width;
         fruitY=rand()%height;
       ntail ++;

     }



     }
    }

}

void logic(){
    int preX=tailX[0];
    int preY=tailY[0];
    int pre2X;
    int pre2Y;
    for(int d=1;d<=ntail;d++){
        pre2X=tailX[d];
        pre2Y=tailY[d];
        tailX[d]=preX;
        tailY[d]=preY;
        pre2X=preX;
        pre2Y=preY;
    }

    switch (dir){

case LEFT:
    x--;
     break;
case RIGHT:
    x++;
     break;
case UP:
    y--;
     break;
case DOWN:
    y++;
break;
    }
for (int v=1;v<=ntail;v++){
    if (x==tailX[v]&&y==tailY[v]){
        Gameover =true;
    }
}
 if (x<0) {
        x=width-1;
    }else
    if (x>width-1){
        x=0;
    }
    if (y<0) {
        y=width-1;
    }else
    if (y>width-1){
        y=0;}














}
int main(){


    setup();
while(!Gameover){

    draw();
    input();
    logic();
}

return 10;
}

