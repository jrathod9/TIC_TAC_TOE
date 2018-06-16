#include<iostream>
using namespace std;

/*Function for taking input from player and manipulating the array accordingly
  It increaments the variable 'turn' if the move is valid */
  
int select(char array[],int position,int turn)
{
    int index=position-1;
   
    if(array[index]!='x' && array[index]!='o')
    {
        if(turn%2==0)
          array[index]='x';
        else
           array[index]='o';
        return turn+1;
    }
    
}

/*Function to print the tictactoe game board on the screen*/

void printBoard(char array[])
{
    
    for(int i=0;i<9;i++)
    {   
        if(i==2 || i==5 || i==8)
          cout<<array[i]<<endl;
        else
          cout<<array[i]<<"|";
    }
    
}

/*Function to check for a sequence of 3 continuous 'x' or 'o' for a win */

int check(char array[],char a)
{
    if((array[0]==a && array[1]==a && array[2]==a)
        || (array[3]==a && array[4]==a && array[5]==a)
        || (array[6]==a && array[7]==a && array[8]==a))
        {
            return 1;
        }
    if((array[0]==a && array[3]==a && array[6]==a)
    ||(array[1]==a && array[4]==a && array[7]==a)
    ||(array[2]==a && array[5]==a && array[8]==a))
    {
        return 1;
    }
    if((array[0]==a && array[4]==a && array[8]==a)
    ||(array[2]==a && array[4]==a && array[6]==a))
    {
        return 1;
    }
    
    return 0;
}

/* Function calls check() and verifies if the game is over */

bool game_over(char array[])
{   
    int x,o;
    char xx='x',oo='o';
    x=check(array,xx);    
    o=check(array,oo);
    
    if(x==1 || o==1)
    return true;
    
    else
    return false;
}

//____MAIN____

int main()
{
    char arr[]={'1','2','3','4','5','6','7','8','9'};  //Initial gameboard array
    int chance=0;                                      //Player chance
    int input;                                         //Input   
    int draw=0;                                        //Flag to check if game draws
    
    while(game_over(arr)==false && draw==0)
    { 
        printBoard(arr);
        cout<<endl;
        cin>>input;
        chance=select(arr,input,chance);
       
       if(chance>=9)
          draw=1;
      
    }
    printBoard(arr);
    cout<<endl;
    
    if(draw==1)
      cout<<"Draw!";
    
    else
    {
    	if(chance%2==0)
   	 	cout<<"P2";
   	 	else
    	cout<<"P1";
	  }
}
