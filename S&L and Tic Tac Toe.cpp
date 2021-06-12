//PROGRAM TO PLAY GAME - SNAKE & LADDER AND TIK TAC TOE

//HEARDER FILES

#include <iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

//FUNCTIONS DECLARATION FOR SNAKE & LADDER GAME 
    void snake_ladder();
    void board();
    void gamescore(char name1[], char name2[], int p1, int p2);
    void play_dice(int & score);
    int random();
    
//FUNCTIONS DECLARATION FOR TIK TAC TOE GAME    
    void Tic_Tac_Toe();
    void draw_line(int n, char ch);
    int checkwin();
   	void display_board();
    
//THE MAIN FUNCTION
int main()
{
int choice;
draw_line(120, '=');
cout<<"\n\n\n\t\t\t\t\t   WELCOME TO THE NSDA GAMING     \n\n\n";
draw_line(120, '=');
cout<<"\n\n\nENTER YOUR CHOICE\n\n";
draw_line(120, '=');
cout<<"\n\n\t\t\t\t\t      1. SNAKE AND LADDER\n\n";
draw_line(120, '=');
cout<<"\n\n\t\t\t\t\t      2. TIK TAC TOE\n\n";
draw_line(120, '=');
cout<<"\n\n\t\t\t\t\t      3.EXIT  \n\n";
draw_line(120, '=');
cout<<endl;
cout<<"\n\n\t\t\tENTER YOUR CHOICE......\t\n";
cin>>choice;
   switch(choice)
   {   
  case 1: snake_ladder();
         break;
  case 2 : Tic_Tac_Toe();
         break;
  case 3 : exit(0);
         break;
  default : cout<<"\n\n\n\t\t\t INVALID CHOICE\n";
        break;		        
		        
   }
}

        
                //FUNCTION FOR SNAKE & LADDER 	
 				void snake_ladder()
  				{  
  				
    				char player1name[80], player2name[80];
                    system("cls");
    				draw_line(50, '=');
    				cout << "\n\n\n\n\t\tSNAKE LADDER GAME\n\n\n\n";
    				draw_line(50, '=');
   					cout << "\n\n\nEnter Name of player 1 :";
    				cin>>player1name;
    				cout << "\n\n\Enter Name of player 2 :";
    				cin>>player2name;
        
					int player1 = 0, player2 = 0, lastposition;
    
    				while (player1 < 100 && player2 < 100) 
					{
       				 	board();
        				gamescore(player1name, player2name, player1, player2);
        				cout << "\n\n--->" << player1name << " Now your Turn >> Press any key to play ";
        				getch();
        				lastposition = player1;
        				play_dice(player1);
        				if (player1 < lastposition)
            			cout << "\n\nOops!! Snake found !! You are at postion " << player1 << "\n";
        				else if (player1 > lastposition + 6)
            			cout << "\nGreat!! you got a ladder !! You are at position " << player1;
            			cout << "\n\n--->" << player2name << " Now your Turn >> Press any key to play ";
        				getch();
        				lastposition = player2;
        				play_dice(player2);
        				if (player2 < lastposition)
            			cout << "\n\nOops!! Snake found !! You are at position " << player2 << "\n";
        				else if (player2 > lastposition + 6)
            			cout << "\n\nGreat!! you got a ladder !! You are at position " << player2 << "\n";
        				getch();
    				}
    				system("cls");
	    			cout << "\n\n\n";
    				draw_line(50, '+');
    				cout << "\n\n\t\tRESULT\n\n";
    				draw_line(50, '+');
    				cout << endl;
    				gamescore(player1name, player2name, player1, player2);
    				cout << "\n\n\n";
   					 if (player1 >= player2)
       				 cout << player1name << " !! You are the winner of the game\n\n";
    				else
        			cout << player2name << " !! You are the winner of the game\n\n";
    				draw_line(50, '+');
    				getch();
  				}
  				//TO DRAW A STRAIGHT BOLD LINE
  				void draw_line(int n, char ch) 
  				{
   					 for (int i = 0; i < n; i++)
        				cout << ch;
  				}
                //TO DISPLAY INFORMATION ABOUT SNAKES AND LADDER
 				 void board() 
 				{  
   					system("cls");
    				cout << "\n\n";
    				draw_line(50, '-');
    				cout << "\n\t\tSNAKE AT POSITION\n";
    				draw_line(50, '-');
    				cout << "\n\tFrom 98 to 28 \n\tFrom 95 to 24\n\tFrom 92 to 51\n\tFrom 83 to 19\n\tFrom 73 to 1\n\tFrom 69 to 33\n\tFrom 64 to 36\n\tFrom 59 to 17\n\tFrom 55 to 7\n\tFrom 52 to 11\n\tFrom 48 to 9\n\tFrom 46 to 5\n\tFrom 44 to 22\n\n";
    				draw_line(50, '-');
    				cout << "\n\t\t LADDER AT POSITION\n";
    				draw_line(50, '-');
    				cout << "\n\tFrom 8 to 26\n\tFrom 21 to 82\n\tFrom 43 to 77\n\tFrom 50 to 91\n\tFrom 62 to 96\n\tFrom 66 to 87\n\tFrom 80 to 100\n";
    				draw_line(50, '-');
    				cout << endl;
  				}
  				
  				
				//TO GIVE THE STATUS OF THE GAME
   				void gamescore(char name1[], char name2[], int p1, int p2) 
   				{
    				cout << "\n";
    				draw_line(50, '~');
    				cout << "\n\t\tGAME STATUS\n";
    				draw_line(50, '~');
    				cout << "\n\t--->" << name1 << " is at position " << p1 << endl;
    				cout << "\t--->" << name2 << " is at position " << p2 << endl;
    				draw_line(50, '_');
    				cout << endl;
  				}
 				//TO ROLE THE DICE
 				
   				void play_dice(int & score) 
   				{
    				int dice;
    				dice = random();
    				cout << "\nYou got " << dice << " Point !! ";
    				score = score + dice;
    				cout << "Now you are at position " << score;
    				switch (score)                                  //SWITCH CASE FOR BOTH SNAKE AND LADDER
					{
    					case 98:
        					score = 28;
        					break;
    					case 95:
        					score = 24;
        					break;
   						case 92:
        					score = 51;
        					break;
    					case 83:
        					score = 19;
        					break;
    					case 73:
        					score = 1;
        					break;
    					case 69:
        					score = 33;
        					break;
    					case 64:
        					score = 36;
        					break;
    					case 59:
        					score = 17;
        					break;
    					case 55:
        					score = 7;
        					break;
    					case 52:
        					score = 11;
        					break;
    					case 48:
        					score = 9;
        					break;
    					case 46:
        					score = 5;
        					break;
    					case 44:
       						score = 22;
    						break;
    					case 8:
        					score = 26;
        					break;
    					case 21:
        					score = 82;
        					break;
    					case 43:
        					score = 77;
        					break;
    					case 50:
        					score = 91;
        					break;
    					case 54:
        					score = 93;
        					break;
    					case 62:
        					score = 96;
        					break;
    					case 66:
        					score = 87;
        					break;
    					case 80:
    					    score = 100;
    				}
  				}
  				//RANDOM NUMBER GENERATION
  				int random()
  				{
  					 srand((unsigned) time(0));    // TO GENERATE DIFFERENT SEQUENCE FOR EVERY LOOP
   					 int result = 1 + (rand() % 6);
   					 return result;
 				}
 	    //GLOBAL DECLARATIONS FOR TIK TAC TOE GAME
	
     			char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
                char player1name[50],player2name[50];
    			
   		//PROGRAM FOR TIK TAC TOE GAME		

  				void Tic_Tac_Toe()
   				{
   					
					draw_line(50, '=');
    				cout << "\n\n\n\n\t\tTIK TAC TOE GAME\n\n\n\n";
    				draw_line(50, '=');
   					cout << "\n\n\nEnter Name of player 1 :";
    				cin>>player1name;
    				cout << "\n\n\Enter Name of player 2 :";
    				cin>>player2name;
        
				    int player = 1,i,choice;

    				char mark;
    				do
    				{
       					display_board();
        				player=(player%2)?1:2;
        				
                        if(player==1)
        				cout <<player1name<< ", enter a number:  ";
        				else
        				cout <<player2name<< ", enter a number:  ";
        				cin >> choice;

        				mark=(player == 1) ? 'X' : 'O';

        				if (choice == 1 && square[1] == '1')

            			square[1] = mark;
       					else if (choice == 2 && square[2] == '2')

            			square[2] = mark;
        				else if (choice == 3 && square[3] == '3')

            			square[3] = mark;
       					 else if (choice == 4 && square[4] == '4')

            			square[4] = mark;
       				 	else if (choice == 5 && square[5] == '5')

            			square[5] = mark;
        				else if (choice == 6 && square[6] == '6')

            			square[6] = mark;
        				else if (choice == 7 && square[7] == '7')

            			square[7] = mark;
        				else if (choice == 8 && square[8] == '8')

            			square[8] = mark;
        				else if (choice == 9 && square[9] == '9')

            			square[9] = mark;
        				else
        				{
            				cout<<"Invalid move ";
		    				player--;
        				}
        				i=checkwin();

        				player++;
    				}while(i==-1);
    
    				display_board();
    				cout << "\n\n\n";
    				draw_line(50, '+');
    				cout << "\n\n\t\tRESULT\n\n";
    				draw_line(50, '+');
    				cout << endl;
    				if(i==1)

        			cout<<"\n\n==>\aPlayer "<<--player<<" win ";
    				else
        			cout<<"==>\aGame draw";
        
    			
   					}

			

    				int checkwin()
  					{
    				if (square[1] == square[2] && square[2] == square[3])

        			return 1;
    				else if (square[4] == square[5] && square[5] == square[6])

        			return 1;
    				else if (square[7] == square[8] && square[8] == square[9])

        			return 1;
    				else if (square[1] == square[4] && square[4] == square[7])

       	 			return 1;
   					 else if (square[2] == square[5] && square[5] == square[8])

        			return 1;
    				else if (square[3] == square[6] && square[6] == square[9])

        			return 1;
    				else if (square[1] == square[5] && square[5] == square[9])

       				return 1;
   					else if (square[3] == square[5] && square[5] == square[7])

        			return 1;
    				else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    		&& square[4] != '4' && square[5] != '5' && square[6] != '6' 
                 			 && square[7] != '7' && square[8] != '8' && square[9] != '9')

       			 	return 0;
    				else
        			return -1;
   				} 


				//FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK

   				void display_board()
    			{
   					 system("cls");
   					draw_line(50, '=');
    				cout << "\n\n\n\n\t\tTIK TAC TOE GAME\n\n\n\n";
    				draw_line(50, '=');
    				cout<<endl;
   				

  					 cout <<"\n\n\n\n\t"<<player1name<<"\t (X)  - \t"<<player2name<<" (O)" << endl << endl;
    				 cout << endl;

   					cout << "     |     |     " << endl;
    				cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    				cout << "_____|_____|_____" << endl;
    				cout << "     |     |     " << endl;

    				cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    				cout << "_____|_____|_____" << endl;
    				cout << "     |     |     " << endl;

    				cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    				cout << "     |     |     " << endl << endl;
  				}


