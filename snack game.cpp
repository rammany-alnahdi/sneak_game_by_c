#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;
enum Dir {up=1,dn,rt,lt};
int diff ;
int checkk[2]= {8,8};
struct Map
{
	int hight ,wid ,frux , fruy;
};

struct Snack
{
	int headx,heady,tail,tailx[50],taily[50];
	Dir dir;
};

struct Player
{
	int score;
	bool chek;
};

Map mp; Snack sk;Player pl;

int add()
{
	int x;
	cin>>x;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(50, '\n');
		cout<<"\n Error you most enter integer : ";
		cin>>x;
	}
	return x;
}

void shiftR(int arr[] ,int x)
{
	//save tail locaiton
	for(int i= x-2 ;i>=0;i--)	
		arr[i+1]=arr[i];
}

void locmap1T()
{
	srand(time(0));
	mp.frux = (rand()% (mp.wid-2)+1);
	mp.fruy = (rand()% (mp.hight-2)+1);
}

void locmap2T()
{
	bool ff = true;
	while(ff)
	{
		srand(time(0));
		mp.frux = (rand()% (mp.wid-2)+1);
		mp.fruy = (rand()% (mp.hight-2)+1);
		ff=false;
		if((mp.fruy==3) && (mp.frux>=6 && mp.frux<=17))
			ff =true;
		else if((mp.fruy==3) && (mp.frux>=24 && mp.frux<=35))
			ff =true;
		else if((mp.fruy==15) && (mp.frux>=6 && mp.frux<=17))
			ff =true;
		else if((mp.fruy==15) && (mp.frux>=24 &&mp.frux<=35))
			ff=true;	
		else if(mp.frux==6  && (mp.fruy>=3 && mp.fruy<=6 ))
			ff=true;
		else if(mp.frux==6  && (mp.fruy>=11 && mp.fruy<=15 ))
			ff=true;
		else if(mp.frux==35  && (mp.fruy>=3 && mp.fruy<=6 ))
			ff=true;
		else if(mp.frux==35  && (mp.fruy>=11 && mp.fruy<=15 ))
			ff=true;	
		
	}
}

void setupgame()
{
	//map
	mp.hight = 20;
	mp.wid = 50;
	
	
	//snack
	sk.headx= mp.wid/2;
	sk.heady=mp.hight/2;
	sk.tail=0;
	
	//player
	pl.score=0;
	diff=80;
	pl.chek = false;

}

void Amap()
{
	system("cls");
	//Drow
	for(int i=0 ; i < mp.hight;i++){
		for(int j = 0 ; j < mp.wid ;j++)
		{
			if( i== 0  || i == mp.hight-1 || j==0  || j == mp.wid-1)
				cout<<"*";
			else if(i == sk.heady && j == sk.headx)
			cout<<"O";
				else if(i == mp.fruy && j== mp.frux)
			cout<<"T";
			else
			{
				bool tru = false;
				for(int ch=0;ch<sk.tail;ch++)
					if(sk.tailx[ch]==j && sk.taily[ch]==i)
					{
						cout<<"o";
						tru = true;
						break;
					}
				if(!tru)
				cout<<" ";	
			}
			
		}
		cout<<endl;
	}	
	//Roles
		if(sk.headx<=0 || sk.heady <=0 || sk.headx>=mp.wid-1 ||sk.heady>=mp.hight-1)
		pl.chek = true;
	if(sk.headx==mp.frux && sk.heady==mp.fruy)
	{
		locmap1T();
		pl.score+=1;	
		sk.tail++; 
		if(diff>=10)
			diff=diff-5;
		
	}
	for(int i =1 ;i<=sk.tail;i++)
		if(sk.headx ==sk.tailx[i] && sk.heady ==sk.taily[i])	
		{
			pl.chek=true;
		}	
}


void Bmap()
{
	system("cls");
	//Drow
	for(int i=0 ; i < mp.hight;i++){
		for(int j = 0 ; j < mp.wid ;j++)
		{
			if( i== 0  || i == mp.hight-1 || j==0  || j == mp.wid-1)
				cout<<"*";
				else if((i==3) && (j>=6 && j<=17))
			cout<<"*";	
			else if((i==3) && (j>=24 && j<=35))
			cout<<"*";
			else if((i==15) && (j>=6 && j<=17))
			cout<<"*";
			else if((i==15) && (j>=24 && j<=35))
			cout<<"*";
			else if(j==6  && (i>=3 && i<=6 ))
			cout<<"*";
			else if(j==6  && (i>=11 && i<=15 ))
			cout<<"*";
			else if(j==35  && (i>=3 && i<=6 ))
			cout<<"*";
			else if(j==35  && (i>=11 && i<=15 ))
			cout<<"*";					
			else if(i == sk.heady && j == sk.headx)
			cout<<"O";
				else if(i == mp.fruy && j== mp.frux)
			cout<<"T";
			else
			{
				bool tru = false;
				for(int ch=0;ch<sk.tail;ch++)
					if(sk.tailx[ch]==j && sk.taily[ch]==i)
					{
						cout<<"o";
						tru = true;
						break;
					}
				if(!tru)
				cout<<" ";	
			}
			
		}
		cout<<endl;
	}	
	//Roles
		if(sk.headx<=0 || sk.heady <=0 || sk.headx>=mp.wid-1 ||sk.heady>=mp.hight-1)
			pl.chek = true;
		else if((sk.heady==3) && (sk.headx>=6 && sk.headx<=17))
			pl.chek =true;
		else if((sk.heady==3) && (sk.headx>=24 && sk.headx<=35))
			pl.chek =true;
		else if((sk.heady==15) && (sk.headx>=6 && sk.headx<=17))
			pl.chek =true;
		else if((sk.heady==15) && (sk.headx>=24 && sk.headx<=35))
			pl.chek =true;	
		else if(sk.headx==6  && (sk.heady>=3 && sk.heady<=6 ))
			pl.chek=true;
		else if(sk.headx==6  && (sk.heady>=11 && sk.heady<=15 ))
			pl.chek=true;
		else if(sk.headx==35  && (sk.heady>=3 && sk.heady<=6 ))
			pl.chek=true;
		else if(sk.headx==35  && (sk.heady>=11 && sk.heady<=15 ))
			pl.chek=true;	
				
	if(sk.headx==mp.frux && sk.heady==mp.fruy)
	{
		locmap2T();
		pl.score+=1;	
		sk.tail++; 
		if(diff>=10)
			diff=diff-5;
		
	}
	for(int i =1 ;i<=sk.tail;i++)
		if(sk.headx ==sk.tailx[i] && sk.heady ==sk.taily[i])	
		{
			pl.chek=true;
		}	
}

void input()
{
	if(_kbhit())
	{
		char chek1= _getch();
		
		switch(chek1)
		{
			case 'w':
			sk.dir=up;
			break;
			case 's':
			sk.dir=dn;
			break;	
			case 'd':
			sk.dir = rt;
			break;
			case 'a':
			sk.dir=lt;
			break;
			case 'o':
			exit(0);
			break;
		}
	}
	
}

void movment()
{
	shiftR(sk.tailx,50);
	shiftR(sk.taily,50);
	sk.tailx[0]=sk.headx;
	sk.taily[0]=sk.heady;
	
	checkk[0]=sk.dir;
	if(checkk[0] == 1 && checkk [1] ==2)
		sk.dir=dn;
		else if(checkk[0] ==2  && checkk [1] ==1)
		sk.dir=up;
		else if(checkk[0] ==3 && checkk [1] ==4)
		sk.dir=lt;
		else if(checkk[0] ==4  && checkk [1] ==3)
		sk.dir=rt;
		
	switch(sk.dir)
	{
		case up: sk.heady--;
		break;
		case dn : sk.heady++;
		break;
		case rt : sk.headx++;
		break;
		case lt : sk.headx--;
		break;
	}

	checkk [1]=sk.dir;	
}
void map1()
{
	setupgame();
	locmap1T();
	while(!(pl.chek))
	{
		Amap();
		cout<<"\n\tpress o to exit ";
		input();
		movment();
		Sleep(diff);
	}
	cout<<"\n\t your score is = "<<pl.score<<endl;
	system("pause");
}
void map2()
{
	setupgame();
	locmap2T();
	while(!(pl.chek))
	{
		Bmap();
		cout<<"\n\tpress o to exit ";
		input();
		movment();
		Sleep(diff);
	}
	cout<<"\n\t your score is = "<<pl.score<<endl;
	system("pause");
}
		


int main(){
	
	while(1)
	{
		system("cls");
		cout<<"\t\t Press 1 for map 1 \n";
		cout<<"\t\t Press 2 for map 2 \n";
		cout<<"\t\t Press 3 for exit \n";
		int choose = add();
		switch(choose)
		{
			case 1:
			map1();	
			break;
			case 2:
			map2();	
			break;
			case 3:
			exit(0);
			break;	
		}
	}
	
	
	return 0;
}
