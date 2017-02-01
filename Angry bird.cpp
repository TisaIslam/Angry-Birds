#include "graphics.h"
#include<math.h>
#include<string.h>
#define pi 3.1416
#define g 9.81
int flag[4],bar_flag[4],move[2],score,level,scr[8],cage,pigflag;
int pig_point[4][2]={0,0,785,575,875,575,770,445};
char s[50],r[50],nam[8][10];
void readimagefile(
    const char* title,
    int left, int top, int right, int bottom
);
void background1();
void background2();
void cloud();
int projectile(double x,double angle,double v)
{
	double c,a,b;
	c=tan((double) angle);
	c=c*x;
	b=cos((double)angle)*v;
	b=b*b;
	a=(g*x*x)/(2*b);
	return c-a;
}
void cage_pig()
{
	readimagefile("pig.gif",560,185,610,250);
	setcolor(COLOR(187,94,0));
	setlinestyle(0,USERBIT_LINE,6);
	line(600-20,0,600-20,125);
	setcolor(8);
	setfillstyle(SOLID_FILL,8);
	bar(580-40,170,670-40,175);
	bar(580-40,170,575-40,255);
	bar(580-40,250,670-40,255);
	bar(665-40,170,670-40,255);
	bar(590-40,170,595-40,255);
	bar(605-40,170,610-40,255);
	bar(620-40,170,625-40,255);
	bar(635-40,170,640-40,255);
	bar(650-40,170,655-40,255);
	int cage1[]={570-40,175,670-40,175,625-40,130,615-40,120};
	fillpoly(4,cage1);
	int cage2[]={615-40,120,620-40,110,675-40,175,660-40,175};
	fillpoly(4,cage2);
	setlinestyle(0,USERBIT_LINE,1);
}
void remove_cage()
{
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	setlinestyle(0,USERBIT_LINE,6);
	line(600-20,0,600-20,125);
	bar(580-40,170,670-40,175);
	bar(580-40,170,575-40,255);
	bar(580-40,250,670-40,255);
	bar(665-40,170,670-40,255);
	bar(590-40,170,595-40,255);
	bar(605-40,170,610-40,255);
	bar(620-40,170,625-40,255);
	bar(635-40,170,640-40,255);
	bar(650-40,170,655-40,255);
	int cage1[]={570-40,175,670-40,175,625-40,130,615-40,120};
	fillpoly(4,cage1);
	int cage2[]={615-40,120,620-40,110,675-40,175,660-40,175};
	fillpoly(4,cage2);
	setlinestyle(0,USERBIT_LINE,1);
}
void remove_pig(int x,int y)
{
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(x,y,37,37);
}

void pig(int x,int y)
{
	setcolor(COLOR(0,157,0));
	setlinestyle(0,USERBIT_LINE,1);
	setfillstyle(SOLID_FILL,COLOR(0,157,0));
	fillellipse(x,y,25,22);
	setfillstyle(SOLID_FILL,COLOR(0,157,0));
	fillellipse(x-12,y-23,5,6);
	setfillstyle(SOLID_FILL,COLOR(0,157,0));
	fillellipse(x+6,y-23,5,7);
	setcolor(COLOR(111,221,0));
	setfillstyle(SOLID_FILL,COLOR(111,221,0));
	fillellipse(x-12,y-23,2,3);
	setfillstyle(SOLID_FILL,COLOR(111,221,0));
	fillellipse(x+6,y-23,2,3);
	setcolor(COLOR(111,221,0));
	setfillstyle(SOLID_FILL,COLOR(111,221,0));
	fillellipse(x,y+2,13,10);
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	fillellipse(x-4,y+2,2,4);
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	fillellipse(x+4,y+2,2,4);
	setcolor(15);
	setfillstyle(SOLID_FILL,15);
	fillellipse(x-18,y+2,5,5);
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	fillellipse(x-20,y+2,2,2);
	setcolor(15);
	setfillstyle(SOLID_FILL,15);
	fillellipse(x+18,y+2,5,5);
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	fillellipse(x+20,y+2,2,2);
	setlinestyle(0,USERBIT_LINE,3);
	arc(x-15,y+2,90,110,13);
	setlinestyle(0,USERBIT_LINE,3);
	arc(x+14,y,70,90,12);
}
void clear_pig(int x,int y)
{
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(x,y,26,23);
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(x-12,y-23,6,7);
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(x+6,y-23,6,8);
}
void angry(int x,int y)
{
	setcolor(4);
	setlinestyle(0,0,1);
	setfillstyle(SOLID_FILL,4);
	fillellipse(x,y,20,20);
	setfillstyle(SOLID_FILL,4);
	pieslice(x+1,y-17,0,110,10);
	pieslice(x-10,y-17,0,110,10);
	setcolor(0);
	int vru1[]={x-8,y-7,x-6,y-11,x+5,y-2,x+3,y};
	int vru2[]={x+5,y-3,x+13,y-10,x+14,y-6,x+3,y};
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,vru1);
	setfillstyle(SOLID_FILL,0);
	fillpoly(4,vru2);
	setcolor(15);
	int chokh1[]={x-5,y-3,x+3,y+1,x+3,y+3,x-5,y+2};
	setfillstyle(SOLID_FILL,15);
	fillpoly(4,chokh1);
	int chokh2[]={x+3,y+1,x+11,y-3,x+11,y+1,x+3,y+3};
	setfillstyle(SOLID_FILL,15);
	fillpoly(4,chokh2);
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	fillellipse(x,y+2,2,2);
	fillellipse(x+6,y+2,2,2);
	setcolor(0);
	setfillstyle(SOLID_FILL,15);
	fillellipse(x,y+15,12,6);
	setcolor(14);
	setfillstyle(SOLID_FILL,14);
	int thot1[]={x+3,y+3,x+7,y+8,x+7,y+7,x-1,y+6};
	fillpoly(4,thot1);
	int thot2[]={x+1,y+7,x+7,y+15,x+8,y+7,x+1,y+7};
	fillpoly(4,thot2);
	delay(30);
}
void clear_angry(int x,int y)
{
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(x,y,20,20);
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	pieslice(x+1,y-17,0,110,10);
	pieslice(x-10,y-17,0,110,10);
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(x,y+15,13,7);
}
int hit_pig(int a,int b)
{
	int c,d;
	double temp,x,y;
	for(int i=1;i<=3;i++)
	{
		if(flag[i]==0)
		{
			c=pig_point[i][0];
			d=pig_point[i][1];
			x=(a-c)*(a-c);
			y=(b-d)*(b-d);
			temp=sqrt(x+y);
			if(temp<=44)
			{
				clear_pig(c,d);
				clear_angry(a,b);
				flag[i]=1;
				score++;
				int m=a,n=b,l;
				for(l=0;l<370;l=l+8)
				{
					int temp;
					temp=n-projectile(l,0.785,95)-10;
					angry(m+l,temp);
					delay(10);
					clear_angry(m+l,temp);
					if((m+l+20>=820 && m+l+20<=850 && temp+20>500) && bar_flag[3]!=1)
					{
						setcolor(COLOR(81,168,255));
						setfillstyle(SOLID_FILL,COLOR(81,168,255));
						bar(820,465,850,600);
						bar_flag[3]=1;
					}
					if(temp<200)
						cloud();
					if(m+l>1000)
						break;
				}
				return 1;
			}
		}
	}
	return 0;
}
void bar()
{
	setcolor(6);
	setfillstyle(SOLID_FILL,6);
	bar(700,465,820,500);
	bar(700,465,730,600);
	bar(820,465,850,600);
}
int hit_bar(int x,int y)
{
	int k;
	double p1,q1,p2,q2,r1,r2;
	if(level==2 && cage==0)
	{
		double a,b,c;
		a=(x-532)*(x-532);
		b=(y-255)*(y-255);
		c=sqrt(a+b);
		printf("x=%d y=%d c=%lf\n",x,y,c);
		if((x+20>=530 && y-20<=225) || c<=20)
		{
			remove_cage();
			clear_angry(x,y);
			int i;
			for(i=0;i<=350;i=i+7)
			{
				readimagefile("pig.gif",560,185+i,610,250+i);
				delay(18);
				remove_pig(560+27,185+i+33);
			}
			readimagefile("pig.gif",560,185+i,610,250+i);
			cage=1;
			return 1;
		}
	}
	if(level==2 && pigflag==0 && cage==1)
	{
		int c=587;
		int d=568;
		double p,q;
		double temp;
		p=(x-c)*(x-c);
		q=(y-d)*(y-d);
		temp=sqrt(p+q);
		if(temp<=44)
		{
			remove_pig(c,d);
			clear_angry(x,y);
			pigflag=1;
			score=score+2;
			setbkcolor(COLOR(81,168,255));
			setcolor(0);
			settextstyle(6,HORIZ_DIR,3);
			outtextxy(490,500,"BONUS!!");
			delay(250);
			bar(450,500,630,550);
			settextstyle(6,HORIZ_DIR,5);
			return 1;
		}
	}
	if(bar_flag[1]!=1)
	{
		if(move[0]==0)
		{
			p1=(x-700)*(x-700);
			q1=(y-465)*(y-465);
			r1=sqrt(p1+q1);
			p2=(x-850)*(x-850);
			q2=(y-465)*(y-465);
			r2=sqrt(p2+q2);
			if((r1<=20 || r2<=20 && y<500)|| (x+20>700 && x<850 && y+20>=465 && y<500))
			{
				setcolor(COLOR(81,168,255));
				setfillstyle(SOLID_FILL,COLOR(81,168,255));
				bar(700,465,850,500);
				clear_angry(x,y);
				bar_flag[1]=1;
				double i=0,j=0;
				if(bar_flag[2]==0)
				{
					for(i=0,j=0;i<=70;i=i+2,j++)
					{
						setcolor(6);
						setfillstyle(SOLID_FILL,6);
						int p[]={700,600,730,600,730+i,465+j,700+i,465+j,700,600};
						fillpoly(5,p);
						delay(10);
						setcolor(COLOR(81,168,255));
						setfillstyle(SOLID_FILL,COLOR(81,168,255));
						fillpoly(5,p);
					}
					setcolor(6);
					setfillstyle(SOLID_FILL,6);
					int p1[]={700,600,730,600,800,500,770,500,700,600};
					fillpoly(5,p1);
					if(flag[3]!=1)
					{
						clear_pig(pig_point[3][0],pig_point[3][1]);
						pig_point[3][0]=pig_point[3][0]-10;
						for(i=0;i<25;i++)
						{
							pig(pig_point[3][0],pig_point[3][1]+i);
							delay(10);
							clear_pig(pig_point[3][0],pig_point[3][1]+i);
						}
						pig_point[3][0]=pig_point[3][0];
						pig_point[3][1]=pig_point[3][1]+i;
						for(i=0;i<=63;i=i+2)
						{
							setcolor(6);
							setfillstyle(SOLID_FILL,6);
							int p1[]={700,600,730,600,800,500,770,500,700,600};
							fillpoly(5,p1);
							pig(pig_point[3][0]-i-20,pig_point[3][1]+i+45);
							delay(20);
							clear_pig(pig_point[3][0]-i-20,pig_point[3][1]+i+45);
						}
						pig(pig_point[3][0]-i-20,pig_point[3][1]+i+45);
						pig_point[3][0]=pig_point[3][0]-i-20;
						pig_point[3][1]=pig_point[3][1]+i+45;
					}
					move[1]=1;
				}
				return 1;
			}
		}
		else if(move[0]==1)
		{
			if(x+20>=700 && x<820 && y+20>=465 && y<600)
			{
				double temp1,temp2,d;
				temp1=(5*x)-(6*(600-y))-3290;
				temp2=sqrt(61.0);
				d= fabs(temp1/temp2);
				double p1,p2,p3,q1,q2,q3;
				p1=(x-820)*(x-820);
				p2=(y-465)*(y-465);
				p3=sqrt(p1+p2);
				q1=(x-700)*(x-700);
				q2=(y-565)*(y-565);
				q3=sqrt(q1+q2);
				if(d<=20 || p3<=20 || q3<=20)
				{
					bar_flag[1]=1;
					setcolor(COLOR(81,168,255));
					setfillstyle(SOLID_FILL,COLOR(81,168,255));
					int q[]={821,463,821,501,700,601,699,564,821,463};
					fillpoly(5,q);
					clear_angry(x,y);
					int m=x,n=y,l;
					for(l=0;l<270;l=l+8)
					{
						int temp;
						temp=n-projectile(l,0.785,95)-5;
						angry(m+l,temp);
						delay(10);
						clear_angry(m+l,temp);
					}
					return 1;
				}
			}
		}
	}
	if(bar_flag[2]!=1)
	{
		if(x+20>=700 &&  x<730 && y+20>=500 && y<600 && move[1]==0)
		{
			setcolor(COLOR(81,168,255));
			setfillstyle(SOLID_FILL,COLOR(81,168,255));
			bar(700,465,730,600);
			clear_angry(x,y);
			bar_flag[2]=1;
			if(bar_flag[1]!=1)
			{
				setcolor(COLOR(81,168,255));
				setfillstyle(SOLID_FILL,COLOR(81,168,255));
				bar(700,465,850,500);
				clear_pig(pig_point[3][0],pig_point[3][1]);
				int i;
				for(i=0;i<=100;i=i+10)
				{
					setcolor(6);
					setfillstyle(SOLID_FILL,6);
					int q[]={820,465,820,500,700,500+i,700,465+i,820,465};
					fillpoly(5,q);
					delay(10);
					if(i>5 && flag[3]!=1)
					{
						pig(pig_point[3][0]-i,pig_point[3][1]+i-3);
						delay(50);
						clear_pig(pig_point[3][0]-i,pig_point[3][1]+i-4);
						delay(10);
					}
					setcolor(COLOR(81,168,255));
					setfillstyle(SOLID_FILL,COLOR(81,168,255));
					fillpoly(5,q);
				}
				setcolor(6);
				setfillstyle(SOLID_FILL,6);
				int q[]={820,465,820,500,700,600,700,565,820,465};
				fillpoly(5,q);
				int j;
				for(j=0;j<25 && flag[3]!=1;j=j+5)
				{
					pig(pig_point[3][0]-i,pig_point[3][1]+i-3+j);
					delay(50);
					clear_pig(pig_point[3][0]-i,pig_point[3][1]+i-4+j);
					delay(10);
				}
				if(flag[3]!=1)
				{
					pig(pig_point[3][0]-i,pig_point[3][1]+i-3+j);
					pig_point[3][0]=pig_point[3][0]-i;
					pig_point[3][1]=pig_point[3][1]+i-3+j;
				}
				move[0]=1;
			}
			return 1;
		}
		else if(move[1]==1 && x+20>=700 && x<800 && y+20>=495 && y<600)
		{
			double temp1,temp2,d;
			temp1=(10*x)-(7*(600-y))-7000;
			temp2=sqrt(149.0);
			d= fabs(temp1/temp2);
			double x1,x2,x3;
			x1=(x-800)*(x-800);
			x2=(y-500)*(y-500);
			x3=sqrt(x1+x2);
			if(d<=20 || x3<=20)
			{
				bar_flag[2]=1;
				setcolor(COLOR(81,168,255));
				setfillstyle(SOLID_FILL,COLOR(81,168,255));
				int p[]={699,600,732,600,802,499,769,499,699,600};
				fillpoly(5,p);
				clear_angry(x,y);
				int m=x,n=y,l;
				for(l=0;l<270;l=l+8)
				{
					int temp;
					temp=n-projectile(l,0.785,95)-5;
					angry(m+l,temp);
					delay(10);
					clear_angry(m+l,temp);
				}
				return 1;
			}

		}
	}
	if(bar_flag[3]!=1)
	{
		double x1,x2,x3,q1,q2,q3;
		x1=(x-820)*(x-820);
		x2=(y-500)*(y-500);
		x3=sqrt(x1+x2);
		q1=(x-850)*(x-850);
		q2=(y-500)*(y-500);
		q3=sqrt(q1+q2);
		if( (x+20>=820 && x+20<=850 && y+20>500) || x3<=20 || q3<=20)
		{
			setcolor(COLOR(81,168,255));
			setfillstyle(SOLID_FILL,COLOR(81,168,255));
			bar(820,465,850,600);
			clear_angry(x,y);
			bar_flag[3]=1;
			int m=x,n=y,l;
			for(l=0;l<270;l=l+8)
			{
				int temp;
				temp=n-projectile(l,0.785,95)-5;
				angry(m+l,temp);
				delay(10);
				clear_angry(m+l,temp);
			}
			return 1;
		}
	}
	return 0;
}
void danda(int x,int y)
{

	setcolor(COLOR(179,58,0));
	setfillstyle(SOLID_FILL,COLOR(179,58,0));
	setlinestyle(0,USERBIT_LINE,9);
	arc(150,450,180,360,26);
	setcolor(COLOR(179,58,0));
	setfillstyle(SOLID_FILL,COLOR(179,58,0));
	setlinestyle(0,USERBIT_LINE,1);
	setcolor(COLOR(179,58,0));
	setfillstyle(SOLID_FILL,COLOR(179,58,0));
	bar(145,476,155,600);
}
void lboard()
{
	char temp[10],temp2[20]={0},name[10]={0};
	int i,j,k;
	FILE *fp;
	readimagefile("leaderboard.jpg",0,0,1000,676);
	setbkcolor(COLOR(198,235,254));
	setcolor(0);
	settextstyle(6,HORIZ_DIR,5);
	outtextxy(300,138,"LEADERBOARD:");
	settextstyle(6,HORIZ_DIR,4);
	fp=fopen("leaderboard.txt","r");
	for(i=0;i<7;i++)
	{
		setcolor(1+i);
		fscanf(fp,"%s%d",temp,&j);
		sprintf(temp2,"%s",temp);
		outtextxy(380,200+(40*i),temp2);
		sprintf(temp2,"%d",j);
		outtextxy(580,200+(40*i),temp2);
	}
	fclose(fp);
	setcolor(BLACK);
	outtextxy(450,550,"EXIT");
	while(!ismouseclick(WM_LBUTTONDOWN))
		delay(200);
	for(;;)
	{
		getmouseclick(WM_LBUTTONDOWN,i,j);
		if(i>=450 && i<=550 && j>=550 && j<=580)
			break;
	}
	background1();
}
void print_score()
{
	char temp[10],temp2[20]={0},name[10]={0};
	int i,j,k;
	FILE *fp;
	readimagefile("print.jpg",0,0,1000,676);
	setcolor(BLACK);
	setbkcolor(COLOR(153,217,234));
	settextstyle(8,HORIZ_DIR,6);
	score=score*1000;
	sprintf(s,"YOUR SCORE:%d",score);
	outtextxy(250,180,s);
	settextstyle(8,HORIZ_DIR,4);
	if(score<5000)
		outtextxy(250,250, "Better Luck Next Time!! :)");
	else
		outtextxy(250,250, "Good Job!! ^_^");
	settextstyle(8,HORIZ_DIR,6);
    outtextxy(250,350, "YOUR NAME:");
	settextstyle(8,HORIZ_DIR,5);
	for(i=0;i<7;i++)
	{
		char temp=getch();
		if(temp==8 && i>1)
		{
			name[i-1]=0;
			setcolor(COLOR(153,217,234));
			setfillstyle(SOLID_FILL,COLOR(153,217,234));
			bar(250,420,550,600);
			setcolor(0);
			outtextxy(330,430,name);
			i=i-2;
			continue;
		}
		else if(temp==8 && i<=1)
		{
			setcolor(COLOR(153,217,234));
			setfillstyle(SOLID_FILL,COLOR(153,217,234));
			bar(250,420,550,600);
			i=-1;
			continue;
		}
		if(temp=='\r')
			break;
		setcolor(0);
		name[i]=temp;
		name[i+1]=0;
		outtextxy(330,430,name);
	}
	name[i+1]=0;
	outtextxy(330,430,name);
	fp=fopen("leaderboard.txt","r");
	for(i=0;i<7;i++)
		fscanf(fp,"%s %d",nam[i],&scr[i]);
	fclose(fp);
	scr[7]=score;
	strcpy(nam[7],name);
	for(i=0;i<8;i++)
	{
		for(j=0;j<7;j++)
		{
			if(scr[j]<scr[j+1])
			{
				strcpy(temp2,nam[j]);
				strcpy(nam[j],nam[j+1]);
				strcpy(nam[j+1],temp2);
				k=scr[j];
				scr[j]=scr[j+1];
				scr[j+1]=k;
			}
		}
	}
	fp=fopen("leaderboard.txt","w");
	for(i=0;i<7;i++)
	{
		fprintf(fp,"%s %d\n",nam[i],scr[i]);
	}
	fclose(fp);
}
void cloud()
{
	readimagefile("cloud.jpg",150,100,280,166);
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(150,100,30,30);
	fillellipse(280,100,27,27);
	fillellipse(160,100,12,12);
	fillellipse(175,80,30,30);
	fillellipse(195,100,15,15);
	fillellipse(250,100,9,9);
	fillellipse(280,166,5,5);
	readimagefile("cloud2.jpg",500,80,566,120);
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(500,80,12,12);
	fillellipse(566,80,12,12);
	fillellipse(510,80,10,10);
	readimagefile("cloud.jpg",850,110,980,176);
	fillellipse(850,110,30,30);
	fillellipse(980,110,27,27);
	fillellipse(860,110,12,12);
	fillellipse(875,90,30,30);
	fillellipse(895,110,15,15);
	fillellipse(950,110,9,9);
	fillellipse(980,176,5,5);
}
void level1()
{
	int x=150,y=450,lombo,vumi,bx=0,by=0,i,a=0,b=0;
	int p=150,q=450;
	for(i=0;i<4;i++)
	{
		flag[i]=0;
		bar_flag[i]=0;
	}
	move[0]=0;
	move[1]=0;
	for(i=0;i<8;i++)
		scr[i]=0;
	pig_point[1][0]=785;
	pig_point[1][1]=575;
	pig_point[2][0]=875;
	pig_point[2][1]=575;
	pig_point[3][0]=770;
	pig_point[3][1]=445;
	double tt,theta;
	clearmouseclick(WM_LBUTTONDOWN);
	clearmouseclick(WM_LBUTTONUP);
	for(i=1;i<=6;i++)
	{
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			clear_angry(x,y);
			while(!ismouseclick(WM_LBUTTONUP))
			{
				bx=mousex();
				by=mousey();
				if(bx>250 || bx-22<0 || by>580 || by<200)
				{
					setcolor(COLOR(103,44,3));
					setlinestyle(0,USERBIT_LINE,5);
					line(177,450,p+20,q);
					angry(p,q);
					setcolor(COLOR(103,44,3));
					setlinestyle(0,USERBIT_LINE,5);
					line(125,455,p-20,q);
					danda(150,450);
					setcolor(COLOR(81,168,255));
					setfillstyle(SOLID_FILL,COLOR(81,168,255));
					bar(0,170,350,600);
				}
				if(bx<250 && bx-22>=0 && by<580 && by>200)
				{
					setcolor(COLOR(103,44,3));
					setlinestyle(0,USERBIT_LINE,5);
					line(177,450,bx+20,by);
					angry(mousex(),mousey());
					setcolor(COLOR(103,44,3));
					setlinestyle(0,USERBIT_LINE,5);
					line(125,455,bx-20,by);
					delay(50);
					danda(150,450);
					setcolor(COLOR(81,168,255));
					setfillstyle(SOLID_FILL,COLOR(81,168,255));
					bar(0,170,350,600);
					p=bx;
					q=by;
				}
				danda(150,450);
			}
			a=0;
			vumi=x-bx;
			lombo=by-y;
			tt=atan ((double)lombo/vumi);
			printf("tt = %lf\n",tt);
			if(tt>1.45 && tt<1.6)
				tt=1.2;
			sprintf(r,"x%d",6-i);
			setbkcolor(COLOR(81,168,255));
			setcolor(BLACK);
			outtextxy(46,33,r);
			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_LBUTTONUP);
			for(;bx<300 && by>200 &&a<=1000;)
			{
				int temp;
				temp=by-projectile(a,tt,95);
				printf("temp= %d\n",temp);
				if(temp>=581)
				{
					delay(30);
					break;
				}
				angry(bx+a,temp);
				int hit= hit_bar(bx+a,temp);
				if(hit==1)
					break;
				hit=hit_pig(bx+a,temp);
				if(temp<200)
					cloud();
				clear_angry(bx+a,temp);
				if(bx+a>50 && bx+a<200)
					danda(150,450);
				if(hit==1)
					break;
				a=a+9;
			}
		}
		if(score==3)
			break;
		angry(150,450);
	}
}
void level2()
{
	int x=150,y=450,lombo,vumi,bx=0,by=0,i,a=0,b=0;
	int p=150,q=450;
	for(i=0;i<4;i++)
	{
		flag[i]=0;
		bar_flag[i]=0;
	}
	move[0]=0;
	move[1]=0;
	for(i=0;i<8;i++)
		scr[i]=0;
	pig_point[1][0]=785;
	pig_point[1][1]=575;
	pig_point[2][0]=875;
	pig_point[2][1]=575;
	pig_point[3][0]=770;
	pig_point[3][1]=445;
	double tt,theta;
	clearmouseclick(WM_LBUTTONDOWN);
	clearmouseclick(WM_LBUTTONUP);
	for(i=1;i<=8;i++)
	{
		while(!ismouseclick(WM_LBUTTONDOWN))
		{
			delay(100);
		}
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			clear_angry(x,y);
			while(!ismouseclick(WM_LBUTTONUP))
			{
				bx=mousex();
				by=mousey();
				if(bx>180 || bx-22<0 || by>580 || by<200)
				{
					setcolor(COLOR(103,44,3));
					setlinestyle(0,USERBIT_LINE,5);
					line(177,450,p+20,q);
					angry(p,q);
					setcolor(COLOR(103,44,3));
					setlinestyle(0,USERBIT_LINE,5);
					line(125,455,p-20,q);
					danda(150,450);
					setcolor(COLOR(81,168,255));
					setfillstyle(SOLID_FILL,COLOR(81,168,255));
					bar(0,170,350,600);

				}
				if(bx<180 && bx-22>=0 && by<580 && by>200)
				{
					setcolor(COLOR(103,44,3));
					setlinestyle(0,USERBIT_LINE,5);
					line(177,450,bx+20,by);
					angry(mousex(),mousey());
					setcolor(COLOR(103,44,3));
					setlinestyle(0,USERBIT_LINE,5);
					line(125,455,bx-20,by);
					delay(50);
					danda(150,450);
					setcolor(COLOR(81,168,255));
					setfillstyle(SOLID_FILL,COLOR(81,168,255));
					bar(0,170,350,600);
					p=bx;
					q=by;
				}
				danda(150,450);
			}
			a=0;
			vumi=x-bx;
			lombo=by-y;
			tt=atan ((double)lombo/vumi);
			if(tt>1.45 && tt<1.6)
				tt=1.2;
			settextstyle(8,HORIZ_DIR,5);
			sprintf(r,"x%d",8-i);
			setbkcolor(COLOR(81,168,255));
			setcolor(BLACK);
			outtextxy(46,33,r);
			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_LBUTTONUP);
			for(;bx<300 && by>200 &&a<=1000;)
			{
				int temp;
				temp=by-projectile(a,tt,95);
				if(temp>=581)
				{
					delay(10);
					break;
				}
				angry(bx+a,temp);
				int hit= hit_bar(bx+a,temp);
				if(hit==1)
					break;
				hit=hit_pig(bx+a,temp);
				if(temp<200)
					cloud();
				clear_angry(bx+a,temp);
				if(bx+a>50 && bx+a<200)
					danda(150,450);
				if(hit==1)
					break;
				a=a+9;
			}
		}
		if(score==8)
			break;
		angry(150,450);
	}
}
void play()
{
	readimagefile("level1.jpg",0,0,1000,676);
	delay(1200);
	background2();
	level1();
	if(score>0)
	{
		level++;
		readimagefile("level2.jpg",0,0,1000,676);
		delay(1200);
		background2();
		level2();
	}
}
void background2()
{
	clearmouseclick(WM_LBUTTONDOWN);
	clearmouseclick(WM_LBUTTONUP);
	readimagefile("floor.jpg",0,590,1000,676);
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	bar(0,0,1000,600);
	setbkcolor(COLOR(81,168,255));
	setcolor(0);
	settextstyle(8,HORIZ_DIR,5);
	outtextxy(450,256, "3!");
	readimagefile("cloud.jpg",150,100,280,166);
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(150,100,30,30);
	fillellipse(280,100,27,27);
	fillellipse(160,100,12,12);
	fillellipse(175,80,30,30);
	fillellipse(195,100,15,15);
	fillellipse(250,100,9,9);
	fillellipse(280,166,5,5);
	readimagefile("cloud2.jpg",500,80,566,120);
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	fillellipse(500,80,12,12);
	fillellipse(566,80,12,12);
	fillellipse(510,80,10,10);
	readimagefile("cloud.jpg",850,110,980,176);
	fillellipse(850,110,30,30);
	fillellipse(980,110,27,27);
	fillellipse(860,110,12,12);
	fillellipse(875,90,30,30);
	fillellipse(895,110,15,15);
	fillellipse(950,110,9,9);
	fillellipse(980,176,5,5);
	if(level==2)
		cage_pig();
	delay(200);
	danda(100,450);
	bar();
	pig(785,575);
	pig(875,575);
	pig(770,445);
	angry(150,450);
	angry(25,45);
	if(level==1)
		sprintf(r,"x%d",6);
	else
		sprintf(r,"x%d",8);
	setbkcolor(COLOR(81,168,255));
	setcolor(BLACK);
	outtextxy(46,33,r);
	delay(200);
	setbkcolor(COLOR(81,168,255));
	setcolor(0);
	settextstyle(8,HORIZ_DIR,5);
	outtextxy(450,256, "2!");
	delay(400);
	outtextxy(450,256, "1!");
	delay(400);
	outtextxy(300,256, "Start Playing!");
	delay(200);
	setcolor(COLOR(81,168,255));
	setfillstyle(SOLID_FILL,COLOR(81,168,255));
	bar(300,256,800,295);
}
void background1()
{
	int m,n;
	readimagefile("print.jpg",0,0,1000,676);
	setcolor(0);
	setbkcolor(COLOR(153,217,234));
	settextstyle(8,HORIZ_DIR,6);
	outtextxy(260,250,"> New Game");
	outtextxy(260,320,"> Leaderboard");
	outtextxy(260,390,"> Exit");
	while(!ismouseclick(WM_LBUTTONDOWN))
    {
		delay(500);
    }
	for(;;)
	{
			getmouseclick(WM_LBUTTONDOWN,m,n);
			if( m>=260 && m<=600 && n>=250 && n<=300)
			{
				score=0;
				level=1;
				cage=0;
				pigflag=0;
				play();
				print_score();
				lboard();
				break;
			}
			else if(m>=260 && n>=320 && m<=690 && n<=370)
			{
				lboard();
				break;
			}
			else if(m>=260 && n>=390 && m<=460 && n<=440)
			{
				return;
			}
	}
}
void background()
{
	readimagefile("angry-birds.jpg",0,0,1000,676);
	delay(1200);
	background1();
}
int main()
{
	initwindow(1000,676,"PLAY");
	background();
	return 0;
}
