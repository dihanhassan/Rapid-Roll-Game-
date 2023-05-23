#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>

using namespace std ;

void level(double plate_Speed);
void score_level (double score,int dif,int health);

int main(){
	initwindow(1000,600) ; // 600 x 600
    setbkcolor(0);
		while(true)
		{
		 level(3);
		 char ch=getch();
		} 
}

void score_level (double score ,int dif ,int life )
{
	char scr[100],diff[100],health[100];
    score=ceil(score);
    sprintf(scr,"%d",(int)score);
    sprintf(diff,"%d",dif);
    sprintf(health,"%d",life);
	settextstyle(1,0,3);
	setcolor(3);
	outtextxy(700+20,50,"Score : ");
	outtextxy(850+20,50,scr);
	outtextxy(700+20,100,"Difficulty : ");
	outtextxy(900+20,100,diff);
	outtextxy(700+20,150,"Health Left : ");
	outtextxy(900+40,150,health);
	
}

void level(double plate_Speed)
{

    int flag1 = 0 , flag2 = 0 , flag3 = 0 ;
    double temp ;

    double ax1 = 0 , ay1  = 0 , ax2 ,ay2 = 25;
    double bx1 = 0 , by1  = 0 , bx2 ,by2 = 25;
    double cx1 = 0 , cy1  = 0 , cx2 ,cy2 = 25;
    double x = 100, y = 100 , r = 20  ;
    float score=0;
    
    bool ck=true;
    int health=3;
    while(true)
    {
        score_level (score,(int) plate_Speed-2,health);
     	setcolor(BLACK);
     	setfillstyle(1,BLUE);
    	bar3d(30,0,50,700,10,1);
    	bar3d(680,0,700,700,10,1);
        
    	setcolor(RED);
    	setfillstyle(1,3);
        circle(x,y,r);
        floodfill(x+2,y+5,RED);
        setfillstyle(1,RED);
        if(flag1 == 0  &&  flag2 == 0 && flag3 == 0 ) 
		{
        	y+=plate_Speed;	
		}
        else y-=plate_Speed ;
        if(y>580 || (y<0 and !ck))
        {
        	--health;
        	if (health==0){
        		cleardevice();
	            outtextxy(300,300,"game over");
	            char scr[100];
	            score=ceil(score);
	            sprintf(scr,"%d",(int)score);
	            outtextxy(300,400,scr);
	            break;
			}
	           y = 50;
        }
        // ball controller
        if(kbhit())
        {

            char ch = getch();
            if(ch == 'd' || ch==77)
            {
            	if (x<610)
                x+=20;
            }
            else if(ch == 'a' || ch==75)
            {
            	if (x>90)
                 x-=20;
            }
        }

        // ball and plate  touch claculation

        temp = abs((ax1 +50 ) - x ) * abs((ax1 +50 ) - x ) + abs((ay1+20) - y) * abs ((ay1+20) - y );
        temp = sqrt(temp);
        if(temp< (r + 32))
        {
            flag1 = 1 ;
        }
        else
        {
            flag1 = 0 ;
        }

        temp = abs((bx1 +160 ) - x ) * abs((bx1 +160 ) - x ) + abs((by1+20) - y) * abs ((by1+20) - y );
        temp = sqrt(temp);
        if(temp< (r + 32))
        {
            flag2 = 1 ;
        }
        else
        {
            flag2 = 0 ;
        }
        temp = abs((cx1 +150 ) - x ) * abs((cx1 +150 ) - x ) + abs((cy1+20) - y) * abs ((cy1+20) - y );
        temp = sqrt(temp);
        if(temp< (r + 30))
        {
            flag3 = 1 ;
        }
        else
        {
            flag3 = 0 ;
        }
        // moving  plates
        bar3d(ax1,ay1,ax1+100,ay1+25,10,1); // a
//        circle(ax1+50,ay1+20,60);
        bar3d(bx1+100,by1,bx1+225,by1+25,10,1);
//        circle(bx1+160,by1+20,60);
        bar3d(cx1+100,cy1,cx1+200,cy1+25,10,1);
        
//        circle(cx1+150,cy1+20,60);
        ay1-=plate_Speed ;
        by1-=plate_Speed ;
        cy1-=plate_Speed ;
        
        if(ay1<0)
        {
            ay1 = 700 ;
            ax1 = rand() % 300 + 50 ;
        }

        if(by1<0)
        {
            by1 = 900 ;
            bx1 = rand() % 400;
        }
        if(cy1 < 0 )
        {
            cy1 = 1100  ;
            cx1 = rand() % 500 ;
        }
        ck=false;
        score+=0.01;
        delay(20);
        cleardevice();
    }


}