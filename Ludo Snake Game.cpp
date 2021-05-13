#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
char square[101];
char square2[101];
struct Location
{
	int previous;
	int player_Dice,count;
}player1,player2;

void gameBoard();
int Obstacles(int);
int checkWin(int);
int random();
void shapes(int);
void play();
void intro();

int main()
{
	int player=1,dice,move=0,i;
	intro();
	gameBoard();
	do
	{
	if(player%2==0)
		player=2;
	else
		player=1;
	printf("\nPlayer %d Turn: ",player);
	do{
		play();
		dice=random();
		shapes(dice);
		Sleep(1000);
		move+=dice;
	}while(dice==6);
	if(player==1)
	player1.player_Dice=move;
	else
	player2.player_Dice=move;
	
	
		if(player==1)
		{
			player1.count+=player1.player_Dice;
			player1.player_Dice=Obstacles(player1.count);
			player1.count=player1.player_Dice;
			square[player1.previous]=0;
			square[player1.player_Dice]='X';
			i=checkWin(player1.count);
		}
		else
		{
			player2.count+=player2.player_Dice;
			player2.player_Dice=Obstacles(player2.count);
			player2.count=player2.player_Dice;
			square2[player2.previous]=0;
			square2[player2.player_Dice]='O';
			i=checkWin(player2.count);
		}
	gameBoard();
	player1.previous=player1.player_Dice;
	player2.previous=player2.player_Dice;
	player++;
	move=0;
	}while(i==1);
	printf("\nPlayer %d Won!",--player);
}

int random()
{
	int number;
	int lower=1,upper=6;
	srand(time(NULL));
	number=(rand() % (upper-lower+1)+lower);
	return number;
}

int checkWin(int a)
{
	if(a>100)
	return -1;
	else
	return 1;
}

int Obstacles(int a)
{
	switch(a)
	{
		case 4:
			{
				return 25;
				break;
			}
		case 10:
			{
				return 29;
				break;
			}
		case 15:
			{
				return 34;
				break;
			}
		case 21:
			{
				return 42;
				break;
			}
		case 33:
			{
				return 7;
				break;
			}
		case 44:
			{
				return 22;
				break;
			}
		case 57:
			{
				return 85;
				break;
			}
		case 89:
			{
				return 52;
				break;
			}
		case 94:
			{
				return 66;
				break;
			}
		case 98:
			{
				return 62;
				break;
			}
		case 88:
			{
				return 92;
				break;
			}
		default:
		return a;
	}
}

void play()
{
	char a;
	a=getch();
	if(a=='x'|| a=='X')
	return;
	printf("\nPlease press 'X' to roll the dice");
	play();
}

void shapes(int a)
{
	if(a==1)
	printf("\n\n *\n *\n *\n *\n *\n *");
	else if(a==2)
	printf("\n\n*****\n    *\n    *\n*****\n*\n*\n*****");
	else if(a==3)
	printf("\n\n*****\n    *\n    *\n*****\n    *\n    *\n*****");
	else if(a==4)
	printf("\n\n*    *\n*    *\n*    *\n******\n     *\n     *\n     *");
	else if(a==5)
	printf("\n\n******\n*\n*\n******\n     *\n     *\n******");
	else
	printf("\n\n******\n*\n*\n******\n*    *\n*    *\n******");
}

void intro()
{
	printf("\t\t\t*\n\t\t\t*\n\t\t\t*\n\t\t\t*\n\t\t\t*\n \t\t\t*******");
	Beep(600,400); 
	Sleep(500);
	system("cls");
	printf("\t\t\t\n\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t ******");//u
	Beep(500,400); 
	Sleep(500);
	system("cls");
	printf("\n\n\t\t\t*******\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*******");//d
	Beep(400,400); 
	Sleep(500);
	system("cls");
	printf("\n\n\t\t\t ******\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t*      *\n\t\t\t ******");//o
	Beep(300,400); 
	system("cls");
	Sleep(500);
	
	printf("\n\n\n\n\t\t*       *     *  *****    *****      *****  *   *      **         **   *****  ***  ******\n");
	Sleep(100);
	printf("\t\t*       *     *  *    *  *     *     *    *  * *       * *       * *  *     *  *       * \n");
	Sleep(100);
	printf("\t\t*       *     *  *    *  *     *     *****    *        *  *     *  *  *     *  *      *  \n");
	Sleep(100);
	printf("\t\t*       *     *  *    *  *     *     *    *   *        *   *   *   *  *     *  *     *   \n");
	Sleep(100);
	printf("\t\t*       *     *  *    *  *     *     *    *   *        *    * *    *  *     *  *    *    \n");
	Sleep(100);
	printf("\t\t *****   *****   *****    *****      *****    *        *     *     *   *****  ***  ******\n");
	Sleep(100);
	Beep(600,250); 
	Beep(500,250); 
	Beep(400,250); 
	Beep(300,250);
	Sleep(1500);
	
}
void gameBoard()
{
	system("cls");
	printf("  100  |  99   |98->62 |   97  |   96  |   95  |94->66 |   93  |   92  |   91  |\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[100],square2[100],square[99],square2[99],square[98],square2[98],square[97],square2[97],square[96],square2[96],square[95],square2[95],square[94],square2[94],square[93],square2[93],square[92],square2[92],square[91],square2[91]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
	printf("   81  |   82  |   83  |   84  |   85  |   86  |   87  |88->92 |89->52 |   90  |\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[81],square2[81],square[82],square2[82],square[83],square2[83],square[84],square2[84],square[85],square2[85],square[86],square2[86],square[87],square2[87],square[88],square2[88],square[89],square2[89],square[90],square2[90]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
	printf("   80  |   79  |   78  |   77  |   76  |   75  |   74  |   73  |   72  |   71  |\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[80],square2[80],square[79],square2[79],square[78],square2[78],square[77],square2[77],square[76],square2[76],square[75],square2[75],square[74],square2[74],square[73],square2[73],square[72],square2[72],square[71],square2[71]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
	printf("   61  |   62  |   63  |   64  |   65  |   66  |   67  |   68  |   69  |   70  |\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[61],square2[61],square[62],square2[62],square[63],square2[63],square[64],square2[64],square[65],square2[65],square[66],square2[66],square[67],square2[67],square[68],square2[68],square[69],square2[69],square[70],square2[70]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
	printf("   60  |   59  |   58  |57->85 |   56  |   55  |   54  |   53  |   52  |   51  |\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[60],square2[60],square[59],square2[59],square[58],square2[58],square[57],square2[57],square[56],square2[56],square[55],square2[55],square[54],square2[54],square[53],square2[53],square[52],square2[52],square[51],square2[51]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
	printf("   41  |   42  |   43  |44->22 |   45  |   46  |   47  |   48  |   49  |   50  |\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[41],square2[41],square[42],square2[42],square[43],square2[43],square[44],square2[44],square[45],square2[45],square[46],square2[46],square[47],square2[47],square[48],square2[48],square[49],square2[49],square[50],square2[50]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
	printf("   40  |   39  |   38  |   37  |   36  |   35  |   34  | 33->7 |   32  |   31  |\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[40],square2[40],square[39],square2[39],square[38],square2[38],square[37],square2[37],square[36],square2[36],square[35],square2[35],square[34],square2[34],square[33],square2[33],square[32],square2[32],square[31],square2[31]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
	printf("21->42 |   22  |   23  |   24  |   25  |   26  |   27  |   28  |   29  |   30  |\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[21],square2[21],square[22],square2[22],square[23],square2[23],square[24],square2[24],square[25],square2[25],square[26],square2[26],square[27],square2[27],square[28],square2[28],square[29],square2[29],square[30],square2[30]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
	printf("   20  |   19  |   18  |   17  |   16  |15->34 |   14  |   13  |   12  |   11  |\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[20],square2[20],square[19],square2[19],square[18],square2[18],square[17],square2[17],square[16],square2[16],square[15],square2[15],square[14],square2[14],square[13],square2[13],square[12],square2[12],square[11],square2[11]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
	printf("   1   |   2   |   3   | 4->25 |   5   |   6   |   7   |   8   |   9   | 10->29|\n");
	printf("  %c%c   |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |   %c%c  |\n",square[1],square2[1],square[2],square2[2],square[3],square2[3],square[4],square2[4],square[5],square2[5],square[6],square2[6],square[7],square2[7],square[8],square2[8],square[9],square2[9],square[10],square2[10]);
	printf("_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|\n");
}				
