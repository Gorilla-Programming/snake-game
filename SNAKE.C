#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
int i,width=61,height=20;
int foodX,foodY,gO=1;
int tailX[100],tailY[100];
char ch;
int snakeX,snakeY,life,flag,score=0,count=1,prev2X,prev2Y;
int prevX,prevY;
void input();
void border();
void setup();
void pattern();
void game();
void frame();
void intro();


void frame()
{
 int i;
 clrscr();
 textcolor(GREEN);
 textbackground(BLACK);
 for(i=3;i<=24;i++)
 {
  gotoxy(77,i);
  cprintf("*");
  gotoxy(2,i);
  cprintf("*");
 }
 for(i=4;i<=76;i++)
 {
  gotoxy(i,24);
  cprintf("_");
  gotoxy(i,2);
  cprintf("_");
 }
}




void intro()
{
 char s[100]="Hi! There Welcome Back to SNAKE GAME";
 char s1[100]="CREDIT - GORILLA PROGRAMMING || Mr - StOrM";
 char s2[100]="Enjoy the game !! CLick to continue";
 int i=0;
 frame();
 gotoxy(22,12);
 while(s[i]!='\0')
 {
  sound(200);
  cprintf("%c",s[i]);
  delay(5);
  nosound();
  delay(100);
  i++;
 }
 delay(1000);
 i=0;
 frame();
 gotoxy(19,12);
 while(s1[i]!='\0')
 {
  sound(200);
  cprintf("%c",s1[i]);
  delay(5);
  nosound();
  delay(100);
  i++;
 }
 delay(1000);
 i=0;
 frame();
 gotoxy(21,12);
 while(s2[i]!='\0')
 {
  sound(200);
  cprintf("%c",s2[i]);
  delay(5);
  nosound();
  delay(100);
  i++;
 }
 getch();
 for(i=3;i>=0;i--)
 {
  frame();
  gotoxy(28,12);
  cprintf("Loading...Please Wait");
  delay(500);
  gotoxy(28,12);
  cprintf("Loading...Please Wait.");
  delay(500);
  gotoxy(28,12);
  cprintf("Loading...Please Wait..");
  delay(500);
  gotoxy(28,12);
  cprintf("Loading...Please Wait...");
  delay(500);

 }

}




void input()
{
 if(kbhit())
  {
   switch(getch())
   {
    case 75:  //LEFT
	      flag =1 ;
	      break;
    case 77:  //RIGHT
	      flag=2;
	      break;
    case 80:  //DOWN
	      flag=3;
	      break;
    case 72:  //UP
	      flag=4;
	      break;
    case 8:   //BKSP
	     flag=5;
	     break;
   }
}
}




void setup()
{
 snakeX = width/2;
 snakeY = height/2;
 foodX=rand()%78;
 foodY=rand()%24;
 life=3;
}




void game()
{
 prevX=tailX[0];
 prevY=tailY[0];
 tailX[0]=snakeX;
 tailY[0]=snakeY;

 for(i=1;i<count;i++)
 {
  prev2X=tailX[i];
  prev2Y=tailY[i];
  tailX[i]=prevX;
  tailY[i]=prevY;
  prevX=prev2X;
  prevY=prev2Y;

 }
 switch(flag)
  {
    case 1:  //LEFT
	      snakeX--;
	      break;
    case 2:  //RIGHT
	      snakeX++;
	      break;
    case 3:  //DOWN
	      snakeY++;
	      delay(40);
	      break;
    case 4:  //UP
	      snakeY--;
	      delay(40);
	      break;
    case 5:   //BKSP
	     gO=0;
  }
   if(snakeX==width+1 ||snakeX==20||snakeY==4||snakeY==height+1)
   {
     life--;
     if(life==0)
     {
      gO=0;
     }
     else
     {
       snakeX=width/2;
       snakeY=height/2;
     }
   }
}






void border()
{
  clrscr();
  textcolor(WHITE);
  gotoxy(32,4);
  cprintf("GORILLA PROGRAMMING");
  gotoxy(21,21);
  cprintf("SCORE - %d",score);
  gotoxy(51,21);
  cprintf("SNAKE GAME");
  gotoxy(38,21);
  cprintf("LIFE-%d",life);
  textcolor(GREEN);
  for(i=17;i<=width+4;i++)
  {

   gotoxy(i,3);
   cprintf("*");
   gotoxy(i,22);
   cprintf("*");


  }


  for(i=21;i<=width;i++)
  {

   gotoxy(i,5);
   cprintf("*");
   gotoxy(i,20);
   cprintf("*");


  }

  for(i=3;i<=height+1;i++)
  {

   gotoxy(17,i);
   cprintf("*");
   gotoxy(65,i);
   cprintf("*");

  }


  for(i=5;i<=height;i++)
  {

   gotoxy(21,i);
   cprintf("*");
   gotoxy(61,i);
   cprintf("*");

  }
}

void pattern()
{
  border();
  textcolor(WHITE);
  for(i=0;i<count;i++)
  {
  gotoxy(tailX[i],tailY[i]);
  cprintf("*");
  }
  textcolor(GREEN);
  if(foodX==snakeX && foodY==snakeY)
  {
  A:
  foodX=(rand()%(61-21))+21;
  if(foodX<2)
  {
   goto A;
  }
  B :
  foodY=(rand()%(20-5))+5;
  if(foodY<2)
  {
   goto B;
  }
  count++;
  score=score+5;
  }



  else
  {
  gotoxy(foodX,foodY);
  cprintf("+");
  }



}
void main()
{
  int j;
  textcolor(GREEN);
  frame();
  intro();
  border();
  setup();
  while(gO==1)
  {
  pattern();
  input();
  delay(80);
  game();
  }
  frame();
  gotoxy(25,12);
  cprintf("GAME OVER | YOU SCORED - %d",score);
  getch();

 getch();
}