#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#define RED  "\x1b[31m"
#define YELLOW  "\x1b[33m"
#define CUSTOM  "\x1b[38;5;57m"
#define GREY  "\x1b[38;5;8m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"
#define size 100

// board
int a[size][size];
// distance 
int b[size][size];
//level 1
int lvl1x=30;
int lvl1y=30;
int c[30][30]=
{
{ 0, 0, 0, 0, 0,-1, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0, 0,-1, 0, 0,-1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0,-1, 0,-1, 0, 0, 0, 0,-1, 0, 0,-1, 0, 0, 0,-1, 0, 0,-1, 0, 0,-1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0,-1, 0,-1, 0,-1, 0, 0,-1, 0, 0,-1, 0, 0, 0,-1, 0, 0,-1, 0, 0,-1,-1,-1,-1,-1,-1, 0},
{ 0, 0, 0,-1, 0,-1, 0,-1, 0, 0,-1, 0, 0,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0},
{ 0,-1,-1,-1, 0,-1, 0,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0,-1, 0, 0,-1,-1,-1, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0,-1, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0,-1, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0,-1, 0, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0,-1,-1,-1,-1},
{-1,-1,-1,-1, 0,-1, 0,-1,-1,-1,-1, 0, 0, 0,-1, 0, 0,-1,-1,-1,-1,-1, 0,-1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0,-1, 0, 0, 0, 0,-1, 0, 0, 0,-1, 0, 0,-1, 0, 0, 0,-1, 0,-1, 0, 0, 0, 0, 0, 0},
{ 0,-1, 0, 0, 0,-1, 0,-1, 0, 0,-1,-1,-1,-1,-1, 0, 0,-1, 0, 0, 0,-1, 0,-1, 0,-1,-1,-1, 0, 0},
{ 0,-1, 0, 0, 0,-1, 0,-1, 0, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0,-1, 0, 0},
{ 0,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0,-1, 0,-1, 0,-1, 0,-1, 0, 0, 0,-1, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0,-1,-1,-1,-1,-1, 0,-1,-1,-1, 0,-1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1, 0, 0},
{ 0, 0, 0, 0,-1, 0, 0,-1, 0, 0,-1, 0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0},
{ 0,-1,-1,-1,-1, 0, 0,-1, 0, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0,-1, 0,-1,-1,-1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0,-1, 0, 0,-1,-1,-1,-1, 0, 0,-1, 0, 0, 0,-1, 0,-1, 0, 0, 0,-1, 0,-1,-1,-1, 0, 0},
{ 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0,-1,-1,-1, 0,-1, 0,-1, 0,-1,-1,-1, 0, 0, 0,-1, 0, 0},
{ 0, 0,-1,-1,-1, 0, 0, 0,-1, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0,-1, 0, 0, 0,-1, 0, 0, 0,-1, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0,-1, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0,-1,-1,-1, 0,-1, 0, 0, 0,-1, 0, 0},
{ 0, 0, 0, 0,-1,-1,-1, 0,-1, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0},
{-1,-1,-1,-1,-1, 0, 0, 0,-1, 0,-1,-1,-1,-1,-1, 0, 0,-1, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1, 0, 0},
{ 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0,-1, 0, 0,-1,-1, 0, 0,-1,-1,-1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0,-1, 0,-1,-1,-1,-1,-1, 0, 0, 0,-1, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0},
{ 0,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0,-1,-1,-1, 0,-1, 0,-1,-1,-1,-1, 0},
{ 0,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 0,-1, 0,-1,-1,-1, 0,-1, 0,-1,-1,-1, 0, 0,-1, 0, 0, 0,-1, 0, 0, 0,-1, 0, 0, 0, 0},
{ 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0}
};
//move one square according to shortest path within two coordinates
void shortestpath(int a[][size],int b[][size],int *px,int *py,int *ex,int *ey,int dimx,int dimy);
//print map
void screen(int a[][size],int dimx,int dimy,int *px,int *py,int *ex,int *ey,int *gx,int *gy,int *state,int *dif,int *ex2,int *ey2,int *state2,int *ex3,int *ey3,int *state3,int *ex4,int *ey4,int *state4);
//generate game map
void generate(int a[][size],int *px,int *py,int *ex,int *ey,int *gx,int *gy,int dimx,int dimy,int *dif,int *ex2,int *ey2,int *ex3,int *ey3,int *ex4,int *ey4);
//player movement
void move(int a[][size],int *px,int *py,int dimx,int dimy);
//enemy movement 
void enemyai(int a[][size],int b[][size],int *px,
int *py,int *ex,int *ey,int *range,int *chx,int *chy,int *state,
int *rx,int *ry,int *rstate,int dimx,int dimy,int *count,int *aware,int *turn,int *outerrange);
//check if the enemy see the player return 1 else return 0 
int line(int *x1,int *y1,int *x2,int *y2,int a[][size],int dimx,int dimy);
//check ending
void gameover(int *px,int *py,int *ex,int *ey,int *gx,int *gy,int *win,int *end,int *ex2,int *ey2,int *ex3,int *ey3,int *dif,int *ex4,int *ey4);



int main(){
	srand(time(0));
	int i,j;
	// in suspicious state aware increases if enemy keeps seeing player resulting entering alarm state
	int aware=0;
	int aware2=0;
	int aware3=0;
	int aware4=0;
	// p player   e enemy    g goal 
	int px=0,py=1,ex=0,ey=2,gx=0,gy=3;
	int ex2=0,ey2=4;
	int ex3=0,ey3=5;
	int ex4=0,ey4=6;
	//enemy number increase
	int difficulty;
	int difcontrol=0;
	printf("choose a difficulty\n");
	printf("1. easy    2.medium    3.hard    4.Insane\n");
	while(difcontrol==0){
		scanf("%d",&difficulty);
		if(difficulty>=1 && difficulty<=4){
			difcontrol=1;
		}
	}
	int dimx,dimy;
	int win=0;
	//in wander state enemy moves slower
	int turn=1;
	int turn2=1;
	int turn3=1;
	int turn4=1;	
	//if distance between player and enemy smaller than range and enemy sees the player enter alarm state
	int range=5;
	int outerrange=12;
	// suspicious state go check last spot that enemy saw player
	int checkx,checky;
	int checkx2,checky2;
	int checkx3,checky3;
	int checkx4,checky4;
	//if the enemy reached the random destination in wander state randstate 0 choose a new random location
	int randstate=0;
	int randstate2=0;
	int randstate3=0;
	int randstate4=0;
	//random location
	int rx,ry;
	int rx2,ry2;
	int rx3,ry3;
	int rx4,ry4;
	int state=0;
	int state2=0;
	int state3=0;
	int state4=0;
	//enemy stays in alarm state for counts value
	int count=10;
	int end=0;
	
	char lvl;
	printf("Do you want to play level?\n");
	printf("y   or    n\n");
	lvl=getch();
	if(lvl=='y'){
		dimx=30;
		dimy=30;
		for(i=0;i<dimx;i++){
    	    for(j=0;j<dimy;j++){
    			a[i][j]=c[i][j];
			}
		}
		px=0;
		py=0;
		ex=20;
		ey=1;
		gx=0;
		gy=25;
		ex2=0;
		ey2=20;
		ex3=0;
		ey3=26;
		ex4=10;
		ey4=5;
	}else{
		printf("enter map size\n");
       	scanf("%d %d",&dimx,&dimy);
    	for(i=0;i<dimx;i++){
    	    for(j=0;j<dimy;j++){
    			a[i][j]=0;
			}
		}
		generate(a,&px,&py,&ex,&ey,&gx,&gy,dimx,dimy,&difficulty,&ex2,&ey2,&ex3,&ey3,&ex4,&ey4);
	}
	
	
	while(end==0){    
		if(kbhit()){
			move(a,&px,&py,dimx,dimy); 
		}
		enemyai(a,b,&px,&py,&ex,&ey,&range,&checkx,&checky,&state,&rx,&ry,&randstate,dimx,dimy,&count,&aware,&turn,&outerrange);
		if(difficulty>=2){
			enemyai(a,b,&px,&py,&ex2,&ey2,&range,&checkx2,&checky2,&state2,&rx2,&ry2,&randstate2,dimx,dimy,&count,&aware2,&turn2,&outerrange);
			if(difficulty>=3){
				enemyai(a,b,&px,&py,&ex3,&ey3,&range,&checkx3,&checky3,&state3,&rx3,&ry3,&randstate3,dimx,dimy,&count,&aware3,&turn3,&outerrange);
				if(difficulty==4){
				    enemyai(a,b,&px,&py,&ex4,&ey4,&range,&checkx4,&checky4,&state4,&rx4,&ry4,&randstate4,dimx,dimy,&count,&aware4,&turn4,&outerrange);
		    	}
			}
		}
		screen(a,dimx,dimy,&px,&py,&ex,&ey,&gx,&gy,&state,&difficulty,&ex2,&ey2,&state2,&ex3,&ey3,&state3,&ex4,&ey4,&state4);
		gameover(&px,&py,&ex,&ey,&gx,&gy,&win,&end,&ex2,&ey2,&ex3,&ey3,&difficulty,&ex4,&ey4);
		usleep(60000);
	}
	
	
	
	printf("DO YOU WANT TO PLAY AGAIN?\n");
	printf("y    n\n");
	int check=0;
	char replay;
	while(check==0){
		replay=getch();
		if(replay=='y' || replay=='n'){
			check=1;
		}
	}
	if(replay=='y'){
	   main();
	}else{
		return 0;
	}
	
	
	
	
}



void generate(int a[][size],int *px,int *py,int *ex,int *ey,int *gx,int *gy,int dimx,int dimy,int *dif,int *ex2,int *ey2,int *ex3,int *ey3,int *ex4,int *ey4){
	int finish=0;
	char way;
	int cx=0,cy=0;
	int wall=0;
	int i,j;
	while(finish==0){
		way=getch();
		if(way=='a' && cy>0) {
            cy-=1;
        }
        if(way=='w'&& cx>0) {
            cx-=1;
        }
    	if(way=='s' && cx<dimx-1) {
            cx+=1;
        }
        if(way=='d' && cy<dimy-1) {
            cy+=1;
        }
        if(way=='p') {
        	*px=cx;
        	*py=cy;
        }
        if(way=='e') {
            *ex=cx;
            *ey=cy;
        }
        if(way=='g'){
        	*gx=cx;
        	*gy=cy;
		}
		if(*dif>=2 && way=='m'){
			*ex2=cx;
			*ey2=cy;
		}
		if(*dif>=3 && way=='h'){
			*ex3=cx;
			*ey3=cy;
		}
		if(*dif==4 && way=='i'){
			*ex4=cx;
			*ey4=cy;
		}
		if(way=='x'){
			wall+=1;
			if(wall>2){
				wall=0;
			}
		}
		if(wall==1){
			a[cx][cy]=-1;
		}
		if(wall==2){
			a[cx][cy]=0;
		}
		if(way=='l'){
			finish=1;
		}
		//print matris here !!!!!!!!!!!
		system("cls");
		for(i=0;i<dimx;i++){
			for(j=0;j<dimy;j++){
				if(i==*px && j==*py){
					printf(" P");
				}else if(i==*ex && j==*ey){
					printf(" E");
				}else if(i==*ex2 && j==*ey2 && *dif>=2){
					printf(" M");
				}else if(i==*ex3 && j==*ey3 && *dif>=3){
					printf(" H");
				}else if(i==*ex4 && j==*ey4 && *dif>=4){
					printf(" I");
				}else if(i==*gx && j==*gy){
					printf(" G");
				}else if(i==cx && j==cy){
					printf(" C");
				}else if(a[i][j]==-1){
					printf("[]");
				}else{
					printf(" .");
				}
			}
			printf("\n");
		}
	}
}


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
void move(int a[][size],int *px,int *py,int dimx,int dimy){
	char dir=getch();
	if(dir=='w' && a[*px-1][*py]==0 && *px>0){
		*px-=1;
	}
	if(dir=='a' && a[*px][*py-1]==0 && *py>0){
		*py-=1;
	}
	if(dir=='s' && a[*px+1][*py]==0 && *px<dimx-1){
		*px+=1;
	}
	if(dir=='d' && a[*px][*py+1]==0 && *py<dimy-1){
		*py+=1;
	}
}


//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
int line(int *x1,int *y1,int *x2,int *y2,int a[][size],int dimx,int dimy){
	int dx=*x2-*x1;
	int dy=*y2-*y1;


	int i,j;
	int x=*x1;
	int y=*y1;
	int end;
	int signx=1,signy=1;
	if(dx<0){
		signx=-1;
	}
	if(dy<0){
		signy=-1;
	}
	int collision=0;
	if(abs(dx)>abs(dy)){
	    int pk = (2 * abs(dy)) - abs(dx);
        i=0;
        while(i<abs(dx) && collision==0  && x>=0 && x<dimx && y>=0 && y<dimy){
            x+=(1*signx);
            if(pk < 0){
                pk = pk + (2 * abs(dy));
			}else {
                if(dy!=0){
                	y+=(1*signy);
				}
                pk = pk + (2 * abs(dy)) - (2 * abs(dx));
            }
            if(a[x][y]!=0){
				collision=1;
			}
			i+=1;
        }
    }else{
        int pk = (2 * abs(dx)) - abs(dy);
        i=0; 
        while(i<abs(dy) && collision==0 && x>=0 && x<dimx && y>=0 && y<dimy){
            y+=(1*signy);
            if(pk < 0){
                pk = pk + (2 * abs(dx));
            }else{
                if(dx!=0){
                	x+=(1*signx);
				}
                pk = pk + (2 * abs(dx)) - (2 *abs(dy));
            }  
            if(a[x][y]!=0){
				collision=1;
			}
			i+=1;
        } 
    }

    if(collision==0 && x==*x2 && y==*y2){
        return 1;
	}else{
		return 0;
	}
}



///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
void shortestpath(int a[][size],int b[][size],int *ex,int *ey,int *px,int *py,int dimx,int dimy){
	int search=1;
	int i,j;
    for(i=0; i<dimx; i++) {
        for(j=0; j<dimy; j++) {
            b[i][j]=a[i][j];
        }
    }
    /////////////////////////////////////////////////
    if(b[*ex-1][*ey]==0 && *ex>0) {
        b[*ex-1][*ey]=1;
    }
    if(b[*ex+1][*ey]==0 && *ex<dimx) {
        b[*ex+1][*ey]=1;
    }
    if(b[*ex][*ey-1]==0 && *ey>0) {
        b[*ex][*ey-1]=1;
    }
    if(b[*ex][*ey+1]==0 && *ey<dimy) {
        b[*ex][*ey+1]=1;
    }
    if(b[*ex-1][*ey-1]==0 && *ex>0 && *ey>0) {
     	b[*ex-1][*ey-1]=1;
   	}
    if(b[*ex+1][*ey-1]==0 && *ex<dimx && *ey>0) {
        b[*ex+1][*ey-1]=1;
    }
    if(b[*ex+1][*ey+1]==0 && *ey<dimy && *ex<dimx) {
    	b[*ex+1][*ey+1]=1;
    }
    if(b[*ex-1][*ey+1]==0 && *ey<dimy && *ex>0) {
        b[*ex-1][*ey+1]=1;
    }
	
    //////////////////////////////////////////////////
    int count=0;
    while(b[*px][*py]==0 && count<(dimx*dimy)) {
        for(i=0; i<dimx; i++) {
            for(j=0; j<dimy; j++) {
                if(b[i][j]==search) {
                    if(b[i-1][j]==0 && i>0) {
                        b[i-1][j]=search+1;
                    }
                    if(b[i+1][j]==0 && i<dimx) {
                        b[i+1][j]=search+1;
                    }
                    if(b[i][j-1]==0 && j>0) {
                        b[i][j-1]=search+1;
                    }
                    if(b[i][j+1]==0 && j<dimy) {
                        b[i][j+1]=search+1;
                    }
                    if(b[i-1][j-1]==0 && i>0 && j>0) {
                        b[i-1][j-1]=search+1;
                   	}
                    if(b[i+1][j-1]==0 && i<dimx && j>0) {
                        b[i+1][j-1]=search+1;
                    }
                    if(b[i-1][j+1]==0 && j<dimy && i>0) {
                        b[i-1][j+1]=search+1;
                    }
                    if(b[i+1][j+1]==0 && j<dimy && i<dimx) {
                        b[i+1][j+1]=search+1;
                    }
                }
            }
        }
        search+=1;
        count+=1;if(abs(*px-*ex)<=1 && abs(*py-*ey)<=1 && search==0){
        	*ex=*px;
         	*ey=*py;
    	}
    }
    
    b[*ex][*ey]=0;
    float dist,mindist;
    int tmpx=*px,tmpy=*py;
    int tx=*ex,ty=*ey;
    int cost;
    if(count<(dimx*dimy) && search>1) {
        search-=1;
        int found;
        while(search>0) {
        	mindist=100000; 
            for(i=tmpx-1;i<=tmpx+1;i++){
            	for(j=tmpy-1;j<=tmpy+1;j++){
            		if(b[i][j]==search && i>=0 && i<dimx && j>=0 && j<dimy){ 
            			cost=(abs(tmpx-i))+(abs(tmpy-j));
            			cost*=cost;
            			dist=(*px-i)*(*px-i)+(*py-j)*(*py-j);
            			dist=sqrt(dist);
            			if(dist+cost<mindist){
            				mindist=dist+cost;
            				tx=i;
            				ty=j;
						}
					}
				}
			}
			tmpx=tx;
			tmpy=ty;
			search-=1;
        }
        if(abs(tx-*ex)<=1 && abs(ty-*ey)<=1){
        *ex=tx;
        *ey=ty;   
        }else{ 
            printf("error occured code :0\n");
		}
    
		
    }else if(abs(*px-*ex)<=1 && abs(*py-*ey)<=1  && search==1 && count<(dimx*dimy)){
        *ex=*px;
        *ey=*py;
    }else{
    	printf("error occured code : 1\n");
    	sleep(3);
	}
}	


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
void enemyai(int a[][size],int b[][size],int *px,
int *py,int *ex,int *ey,int *range,int *chx,int *chy,int *state,
int *rx,int *ry,int *rstate,int dimx,int dimy,int *count,int *aware,int *turn,int *outerrange){
	int distance=(*px-*ex)*(*px-*ex)+(*py-*ey)*(*py-*ey);
	int randomcheck=0;
	if(line(&*ex,&*ey,&*px,&*py,a,dimx,dimy)==1){
		if(distance<=(*range)*(*range)){
			*state=2;
			*rstate=0;
		}else if(distance<=(*outerrange)*(*outerrange)){
			if(*state!=2){
				*state=1;
			}
			*chx=*px;
			*chy=*py;
			*aware+=1;
			if(*aware>=7){
				*aware=0;
				*state=2;
			}
		}
	}
	if(*state==0 && *turn==0){
		if(*rstate==0){
			while(randomcheck==0){
				*rx=rand()%dimx;
				*ry=rand()%dimy;
				if(a[*rx][*ry]==0){
					randomcheck=1;
				}
			}
			*rstate=1;
		}
		if(*rstate==1){
			shortestpath(a,b,&*ex,&*ey,&*rx,&*ry,dimx,dimy);
			if(*ex==*rx && *ey==*ry){
				*rstate=0;
			}
		}
	}
	if(*state==1){
		shortestpath(a,b,&*ex,&*ey,&*chx,&*chy,dimx,dimy);
		if(*ex==*chx && *ey==*chy){
		    *state=0;
		    *aware=0;
		}
    }
	if(*state==2){
		*aware=0;
		shortestpath(a,b,&*ex,&*ey,&*px,&*py,dimx,dimy);
		*count-=1;
		if(*count<=0){
			*count=10;
			*state=1;
		}
	}
	if(*turn==0){
	    *turn=3;
	}else{
		*turn-=1;
	}
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
void screen(int a[][size],int dimx,int dimy,int *px,int *py,int *ex,int *ey,int *gx,int *gy,int *state,int *dif,int *ex2,int *ey2,int *state2,int *ex3,int *ey3,int *state3,int *ex4,int *ey4,int *state4){
	int i,j;
	float dim;
	system("cls");
	for(i=0;i<dimx;i++){
		for(j=0;j<dimy;j++){
			dim=(i-*px)*(i-*px)+(j-*py)*(j-*py);
	        dim=sqrt(dim);
			if(i==*px && j==*py){
				printf(GREEN" P"RESET);
			}
			else if(i==*ex && j==*ey){
				if(*state==0){
					printf(CUSTOM" E"RESET);
				}else if(*state==1){
					printf(YELLOW" ?"RESET);
				}else{
					printf(RED" !"RESET);
				}
			}
			else if(i==*ex2 && j==*ey2 && *dif>=2){
				if(*state2==0){
					printf(CUSTOM" M"RESET);
				}else if(*state2==1){
					printf(YELLOW" ?"RESET);
				}else{
					printf(RED" !"RESET);
				}
			}else if(i==*ex3 && j==*ey3 && *dif>=3){
				if(*state3==0){
					printf(CUSTOM" H"RESET);
				}else if(*state3==1){
					printf(YELLOW" ?"RESET);
				}else{
					printf(RED" !"RESET);
				}
			}else if(i==*ex4 && j==*ey4 && *dif==4){
				if(*state4==0){
					printf(CUSTOM" I"RESET);
				}else if(*state4==1){
					printf(YELLOW" ?"RESET);
				}else{
					printf(RED" !"RESET);
				}
			}
			else if(i==*gx && j==*gy){
				printf(" G");
			}else if(a[i][j]==-1){
				if(dim<=5){
					printf("[]");
				}else{
					printf(GREY"[]"RESET);
				}
			}else if(a[i][j]==0){
				if(dim<=5){
					printf(" .");
				}else{
					printf(GREY" ."RESET);
				}
			}else{
				printf(" Q");
			}
		}
		printf("\n");
	}
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
void gameover(int *px,int *py,int *ex,int *ey,int *gx,int *gy,int *win,int *end,int *ex2,int *ey2,int *ex3,int *ey3,int *dif,int *ex4,int *ey4){
	if(*px==*ex && *py==*ey || *px==*ex2 && *py==*ey2 && *dif>=2 || *px==*ex3 && *py==*ey3 && *dif>=3 || *px==*ex4 && *py==*ey4 && *dif==4){
		*end=1;
		*win=0;
		printf("the enemy catched you\n");
	}else if(*px==*gx && *py==*gy){
		*end=1;
		*win=1;
		printf("you have reached the goal coordiantes\n");
	}
}
