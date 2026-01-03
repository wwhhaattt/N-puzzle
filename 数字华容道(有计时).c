#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#define N 10
const int n=4;//n阶数字华容道
int map[N][N],arrow;
COORD blank={n-1,n-1};
time_t start,end;
float diff;
void cursor(int x,int y){
	COORD pos;
	pos.X=1+3*x;
	pos.Y=1+2*y;
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,pos);
}
void color(int key){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),key);}
void typeblank(){putchar(' ');putchar(' ');fflush(stdout);}
void typenum(int n){
	if(n>9){
		putchar((n/10)+'0');
		putchar(n%10+'0');
	}else putchar(' '),putchar(n%10+'0');
	fflush(stdout);
}
void up(){
	if(blank.Y<n-1){
		map[blank.X][blank.Y]=map[blank.X][blank.Y+1];
		map[blank.X][blank.Y+1]=0;
		cursor(blank.X,blank.Y);
		typenum(map[blank.X][blank.Y]);
		cursor(blank.X,blank.Y+1);
		typeblank();
		blank.Y++;
	}
}
void down(){
	if(blank.Y>0){
		map[blank.X][blank.Y]=map[blank.X][blank.Y-1];
		map[blank.X][blank.Y-1]=0;
		cursor(blank.X,blank.Y);
		typenum(map[blank.X][blank.Y]);
		cursor(blank.X,blank.Y-1);
		typeblank();
		blank.Y--;
	}
}
void left(){
	if(blank.X<n-1){
		map[blank.X][blank.Y]=map[blank.X+1][blank.Y];
		map[blank.X+1][blank.Y]=0;
		cursor(blank.X,blank.Y);
		typenum(map[blank.X][blank.Y]);
		cursor(blank.X+1,blank.Y);
		typeblank();
		blank.X++;
	}
}
void right(){
	if(blank.X>0){
		map[blank.X][blank.Y]=map[blank.X-1][blank.Y];
		map[blank.X-1][blank.Y]=0;
		cursor(blank.X,blank.Y);
		typenum(map[blank.X][blank.Y]);
		cursor(blank.X-1,blank.Y);
		typeblank();
		blank.X--;
	}
}
int main(){
	srand(time(NULL));
	system("cls");
	system("title n-puzzle");
	for(int i=0;i<n*n-1;i++){
		map[i%n][i/n]=i+1;
		cursor(i%n,i/n);
		typenum(i+1);
	}
	for(int i=0;i<25*n*n;i++){
		int r=rand()%4;
		if(r==0)up();
		else if(r==1)down();
		else if(r==2)left();
		else right();
	}
	time(&start);
	while(1){
		arrow=getch();
		if(arrow==72)up();
		else if(arrow==80)down();
		else if(arrow==75)left();
		else if(arrow==77)right();
		int gameover=1;
		for(int i=0;i<n*n-1;i++)if(map[i%n][i/n]!=i+1)gameover=0;
		if(gameover){cursor(0,n);time(&end);diff=difftime(end,start);printf("你失败了！\n共耗时%.0f秒\n:(",diff);getch();return 0;}
	}
	return 0;
}
