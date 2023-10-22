#include<stdio.h>
#include<stdlib.h>

void selection();       //declaring functions//
void get();
void game();
void game2();
void file();
void file2();
void sr();
void high_s();
void help();
void reset();
void quit();


//declaring globle variables//

int sel;                //selection of user in main menu//
int sel_2;              //selction of user for 2nd round in sr function//
int YC;                 //user's answer selection in game1 & game 2//
int menue;              //selection for play again the game
int menue_help;         //User's selcetion for go to main menu from help function
int menue_highs;        //user's selction for go to main menu from high score function
int menue_reset;        //user's selection for go to main menu from high score function


int main(){

    printf("\n\n\n\t\t***************************************************************\n\n\n");
    printf("\n\t\t");
    get();              //calling get function
  return 0;  
}












//STRUCTURES//

//1.player details//

struct player1
{
    char name[20];              //first round and second round same name//
    int score;                  //first round score//
    int money;                  //first round money//
    int s_score;                //second round score//
    int s_money;                //second round money//
}n1;     //variabale                   









//FUNCTIONS//

// 1.selection//
void selection(){

     printf("\n\t\t ________________________________________ ");
     printf("\n\t\t|                QUIZ GAME               |");
     printf("\n\t\t|________________________________________|");
     printf("\n\t\t|                 WELCOME                |");
     printf("\n\t\t|________________________________________|");
     printf("\n\t\t| > Press 1 to start the game            |");
     printf("\n\t\t| > Press 2 to view the highest score    |");
     printf("\n\t\t| > Press 3 to reset score               |");
     printf("\n\t\t| > press 4 for help                     |");
     printf("\n\t\t| > press 5 to quit                      |");
     printf("\n\t\t|________________________________________|\n\n");


     
     printf("\t\t\tEnter Your Option= ");    //getting the option by user//
     scanf("%d",&sel);                       //asign in to sel variable//

    switch (sel)                            //checking the option//
    {
     case 1:
        game();             //calling game function
     break;

     case 2:
        high_s();           //calling high score function
     break;

     case 3:
        reset();            //calling reset function
     break;

     case 4:
        help();             //calling help function
     break;

     case 5:
        quit();             //calling quit function
     break;

     default:
        printf("\n\t\t\tInvalid Section");
        printf("\n\n\n");
        printf("\t\t");
        selection();     //calling selection function
    
    }

}


//2.getting details//
void get()
{
    printf("ENTER YOUR NAME:  ");                     //gettign the name from user//
    scanf("%s",&n1.name);                         //Assign name into n1.name variable
    n1.score=0;                             
    n1.money=0;

    printf("\n");
    selection();
}



//3.game//
void game()
{
    char questions[][100]={"A.Who create C language?\n",             //First bracket for number of questions(rows) &   
                           "B.When was the 1st Olympic held?\n",     //second bracket says size of per question.
                           "C.Who is the father of science?\n",
                           "D.What is the nearest planet to the sun?\n",
                           "E.What is the smallest country in the world?\n"};

    char options[][100]={"1.Guido van Rossum","2.Dennis Ritchie","3.Anders Hejlsberg","4.James Gosling",
                         "1.825 BC","2.776 BC","3.320 BC","4.80 AD",
                         "1.Galileo Galilei","2.Nicolas Koparnikas","3.Albert Einstein","4.Isaac Newton",
                         "1.Earth","2.Saturn","3.Jupiter","4.mercury",
                         "1.Vatican City","2.Monaco","3.Tuvalu","4.Nauru",};


     int answers[5]={2,3,1,4,1};        //assign answers for each question according to index
     int numberofquestions= sizeof(questions)/ sizeof(questions[0]);            //getting number of questions//
    
     for(int i=0; i<numberofquestions; i++)     //i means questions//
    {
        printf("\n");
        printf("\t\t***************************************************************\n");
        printf("\n");
        printf("\t\t%s\n",questions[i]);
        
        for(int j=(i*4); j<(i*4)+4; j++)        //j means options//
        {
            printf("\t\t%s\n",options[j]);
        }

        printf("\n");
        printf("\t\tYoure choice= \t");
        scanf("%d",&YC);
    
        if(YC==answers[i])
        {
            printf("\n");
            printf("\t\tYOUR ANSWER IS CORRECT\n");
            n1.score++;                              // adding score//
            printf("\t\tYOU WON $100 cash price");
            n1.money=n1.money+100;                  //adding money//
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("\t\tYOUR ANSWER IS WRONG\n");
        }
    }

    printf("\t\t***************************************************************\n");
    printf("\n");

    printf("\n\t\tFIRST ROUND IS OVER\n");
    
    file();

    printf("\n");

    sr();
}



//4.player file//
void file()
{
    FILE *player_1;
            player_1 = fopen("detail.dat","wb");                     //creating and open a file//    // wb=write binary

            fwrite(&n1,sizeof(struct player1),1,player_1);         //writing player name//     //4 arguments, firts one is variable name,second one is size of structure,third one is quantity of variables and poiting file(destination) 

            player_1=fopen("detail.dat","rb");                          //opening file as readable//

            fread(&n1,sizeof(struct player1),1,player_1);               //reading player name//
            printf("\n\t\tPLAYER NAME: %s",n1.name);                      //printing player name//

            fread(&n1,sizeof(struct player1),1,player_1);               //reading player score//
            printf("\n\t\tPLAYER SCORE: %d",n1.score);

            fread(&n1,sizeof(struct player1),1,player_1);
            printf("\n\t\tPLAYER ROUND 1 CASH PRICE IS $%d",n1.money);

            fclose(player_1);
}



//5.second round//
void sr()
{
    if (n1.score>=3)
    {
        printf("\n\t\tCONGTATULATIONS! \n\t\tYOU SELECTED FOR SECOND ROUND");                        //selectted for the 2nd round//
        printf("\n\n\t\tDO YOU LIKE TO PLAY SECOND ROUND ?\n\n\t\tIF YES PRESS 5\n\t\tIF NOT PRESS 6");
        
        printf("\n\n\t\tENTER YOUR SELECTION:  ");
        scanf("%d",&sel_2);


        check_selection:
        switch (sel_2)       //checking the option//
        {
            case 5:
                game2();
            break;

            case 6:
                printf("\n\t\tTHANK YOU FOR PLAYING");
                printf("\n\n\n");
                selection(); 
            break;

            default:
                printf("\n\t\tENTER YOUR SELECTION AGAIN:  ");
                scanf("%d",&sel_2);
                goto check_selection;
        }  
    }
    else
    {
        printf("\n\t\tYOU DIDN'T SELECTED FOR SECOND ROUND\n\n\n");
        selection();
    }
}


//6.game//
void game2()
{
    char questions[][100]={"A.Which country won the first ever Football?\n",
                           "B.Who invented the printing press?\n",
                           "C.Who is the CEO in Google?\n",
                           "D.Who is the first spaceman?\n",
                           "E.What is the largest Ocean?\n"};

    char options[][100]={"1.Uruguay","2.Brazil","3.Argentina","4.France",
                         "1.Charles Babbage","2.Thomas Alva Edison","3.Steve Jobs","4.Johannes Gutenberg",
                         "1.Gopal Vittal","2.Sundar Pichai","3.Satya Nadella","4.Arvind Krishna",
                         "1.Neil Armstrong","2.Michael Collins","3.Yuri Gagarin","4.Buzz Aldrin",
                         "1.Atlantic","2.Pacific","3.Arctic","4.Indian",};


     int answers[5]={1,4,2,3,2};
     int numberofquestions= sizeof(questions)/ sizeof(questions[0]);                //get the size of array//
    
     for(int i=0; i<numberofquestions; i++)
    {
        printf("\n");
        printf("\t\t***************************************************************\n");
        printf("\n");
        printf("\t\t%s\n",questions[i]);
        
        for(int j=(i*4); j<(i*4)+4; j++)
        {
            printf("\t\t%s\n",options[j]);
        }

        printf("\n");
        printf("\t\tYoure choice= \t");
        scanf("%d",&YC);
    
        if(YC==answers[i])
        {
            printf("\n");
            printf("\t\tYOUR ANSWER IS CORRECT\n");
            n1.s_score++;
            printf("\t\tYOU WON $100 cash price");
            n1.s_money=n1.s_money+100;
            printf("\n");
        }
        else
        {
            printf("\n");
            printf("\t\tYOUR ANSWER IS WRONG\n");
        }
    }

    printf("\t\t***************************************************************\n");
    printf("\n");

    printf("\n\t\tSECOND ROUND IS OVER\n");
    
    file2();

    printf("\n\t\t***************************************************************\n");
    printf("\n");

    printf("\n\t\tWOULD YOU LIKE TO PLAY AGAIN ? \n\n");
    printf("\t\tIF YES, PRESS 9\n \t\tIF NOT PRESS 0\n");
    printf("\n");

    printf("\n\t\tENTER YOUR SELECTION:  ");
    scanf("%d",&menue);

    check_input:
    switch (menue)       //checking the option//
        {
            case 9:
                selection(); 
            break;

            case 0:
                printf("\n\t\t********THANK YOU FOR PLAYING COME AGAIN********");
                printf("\n\n\n");
            break;

            default:
                printf("\n\t\tENTER YOUR SELECTION AGAIN:  ");
                scanf("%d",&menue);
                goto check_input;
        }
}


//7.player second round file//
void file2()
{

    FILE *player_1;
            player_1 = fopen("detail.dat","wb");                        //open the file//

            fwrite(&n1,sizeof(struct player1),1,player_1);      

            player_1=fopen("detail.dat","rb");

            fread(&n1,sizeof(struct player1),1,player_1);
            printf("\n\t\tPLAYER NAME: %s",n1.name);

            fread(&n1,sizeof(struct player1),1,player_1);
            printf("\n\t\tPLAYER SCORE: %d",n1.s_score);

            fread(&n1,sizeof(struct player1),1,player_1);
            printf("\n\t\tPLAYER ROUND 2 CASH PRICE IS $%d",n1.s_money);

            fclose(player_1);
}

//8.highest score//
void high_s()
{
    FILE *player_1; 
    player_1 = fopen("detail.dat","rb");

    if(n1.score>n1.s_score){

        fread(&n1,sizeof(struct player1),1,player_1);
        printf("\n\t\tHIGHER SCORE IS %d",n1.score);
    }

    else if(n1.score>0<n1.s_score&&n1.score==n1.s_score){

        fread(&n1,sizeof(struct player1),1,player_1);
        printf("\n\t\tYOU GET SAME SCORE IN BOTH 1 AND 2 ROUND  %d",n1.score);
    }

    else{

        fread(&n1,sizeof(struct player1),1,player_1);
        printf("\n\t\tHIGHER SCORE IS %d",n1.s_score);
    }

    fclose(player_1);

    printf("\n\t\t> PRESS 7 TO GO TO MAIN MENU AGAIN  ");
    scanf("%d",&menue_highs);

    switch (menue_highs)  
        {
            case 7:
                selection(); 
            break;

            default:
                  while(menue_highs!=7)
                    {
                        printf("\n\n\t\t>PRESS 7 TO GO TO MAIN MENU AGAIN  ");
                        scanf("%d",&menue_highs);        
                    }
                selection();
        }
}


//9.Help//
void help()
{
    printf("\n\t\t > There are two rounds in this game");
    printf("\n\t\t > Eache correct Questions awarded $100 cash price");
    printf("\n\t\t > Player must score 3 or more than 3 to qulified for the second round");

    printf("\n\n\t\t> PRESS 7 TO GO TO MAIN MENU AGAIN  ");
    scanf("%d",&menue_help);

    switch (menue_help)  
        {
            case 7:
                selection(); 
            break;

            default:
                while(menue_help!=7)
                    {
                        printf("\n\n\t\t>PRESS 7 TO GO TO MAIN MENU AGAIN  ");
                        scanf("%d",&menue_help);        
                    }
                selection();
        }
} 



//10.Reset score//
void reset()
{
    FILE *player_1; 
    player_1 = fopen("detail.dat","wb");

    n1.score=0;
    n1.s_score=0;
    n1.money=0;
    n1.s_money=0;

    fwrite(&n1,sizeof(struct player1),1,player_1);

    printf("\n\t\tSCORE RESET DONE!");
   
    fclose(player_1);

    printf("\n\t\t> PRESS 7 TO GO TO MAIN MENU AGAIN  ");
    scanf("%d",&menue_reset);

    switch (menue_reset)  
        {
            case 7:
                selection(); 
            break;

            default:
                  while(menue_reset!=7)
                    {
                        printf("\n\n\t\t>PRESS 7 TO GO TO MAIN MENU AGAIN  ");
                        scanf("%d",&menue_reset);        
                    }
                selection();
        }
}

//11.Quit//
void quit()
{
   printf("\n\n\t\t*****THANK YOU FOR BEING WITH OUR GAME*****\n");
   printf("\n\n\n\t\t"); 
}