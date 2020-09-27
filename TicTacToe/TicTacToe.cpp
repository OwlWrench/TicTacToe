#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>


const std::vector <char> boardbase = { '1','2','3','4','5','6','7','8','9' };
std::vector <char> board = boardbase;

int playerTurn = 1;
int gameover = 0;

int PlayerVsPlayer(int);
int PlayerVsComputer(int);
int VictoryCheck(int player);


int Player1(int);
int Player2(int);
int MrComputer(int);
int getRandomNumber(int max);

int main()
{

    //Main Menu --------------------------------------------------
    std::cout << "Welcome to \n --- TICTACTOE ---" << std::endl;
    
    bool validMenu = 0;

    do
    {
    std::cout << "\nWhat do you choose?" << "\n 1: Player vs. Player" << "\n 2: Play against computer" << "\n 3: How to play" << std::endl;

    int menu;
    std::cin >> menu;

    if (menu == 1)
    {
        std::system("CLS");
        PlayerVsPlayer(0);
        validMenu = 1;
    }
    else if (menu == 2)
    {
        std::system("CLS");
        PlayerVsComputer(0);
        validMenu = 1;
    }
    else if (menu == 3)
    {
        std::system("CLS");
        std::cout << "Place an x (or an o) on one of the tiles, numbered 1-9, by writing the number of the desied tile.\nTake turns doing so and the first to get three of their marks in a row is the victor." << std::endl;
        system("pause");
    }
    else
    {
        std::system("CLS");
        std::cout << "Well, that wasn't one of the options. Try again." << std::endl;
        system("pause");
    }

    } while (validMenu == 0);
    //Main Menu End --------------------------------------------------
   

    std::cout << "That's all, folks!";

    
}


//Player vs player ------------------------------------------------------------------------------------------

int PlayerVsPlayer(int)
{
    //Prints the board ----------------------------
    for (int i = 0; i < board.size(); i++)
    {
        if (i == 0)
        {
            std::cout << " | ";
        }

        if (i % 3 == 0 && i != 0)
        {
            std::cout << "\n" << " | ";
        }

        std::cout << board[i];
        std::cout << " | ";
    }

    //End of board print --------------------------

    bool gameover = 0;

    //Game loop
    do
    {
        if (playerTurn == 1)
        {
            Player1(playerTurn);
            
        }
        else if (playerTurn == 2)
        {
            Player2(playerTurn);
            
        }

        gameover = VictoryCheck(playerTurn);

    } while (gameover == 0);
    //End of game loop

   
    if (playerTurn == 2)
    {
        std::cout << "X GOT THREE IN A ROW! PLAYER 1 IS THE WINNER!" << std::endl;
    }
    else if (playerTurn == 1)
    {
        std::cout << "O GOT THREE IN A ROW! PLAYER 2 IS THE WINNER!" << std::endl;
    }
    else if (playerTurn == 0)
    {
        std::cout << "\nNo more available moves... its a tie" << std::endl;
    }

    system("pause");
    system("CLS");

    return 0;
}
//Player vs Player end -------------------------------------------------------------------------------------------------


int PlayerVsComputer(int)
{
    //Prints the board ----------------------------
    for (int i = 0; i < board.size(); i++)
    {
        if (i == 0)
        {
            std::cout << " | ";
        }

        if (i % 3 == 0 && i != 0)
        {
            std::cout << "\n" << " | ";
        }

        std::cout << board[i];
        std::cout << " | ";
    }

    //End of board print --------------------------

    

    //Game loop
    do
    {
        if (playerTurn == 1)
        {
            Player1(playerTurn);

        }
        else if (playerTurn == 2)
        {
            MrComputer(playerTurn);

        }

        gameover = VictoryCheck(playerTurn);

    } while (gameover == 0);
    //End of game loop


    if (playerTurn == 2)
    {
        std::cout << "X GOT THREE IN A ROW! THE PLAYER IS THE WINNER!" << std::endl;
    }
    else if (playerTurn == 1)
    {
        std::cout << "O GOT THREE IN A ROW! THE COMPUTER WINS!" << std::endl;
    }
    else if (playerTurn == 0)
    {
        std::cout << "\nNo more available moves... its a tie" << std::endl;
    }

    system("pause");
    system("CLS");

    return 0;
}



int VictoryCheck(int player)
{
    char check = ' ';

    if (playerTurn == 2)
    {
        check = 'x';
    }
    else if (playerTurn == 1)
    {
        check = 'o';
    }



    bool victory = 0;
    //check for three in a row (try make into a switch statement?) ----------
   if (board[0] == check && board[1] == check && board[2] == check)
   {
       std::cout << "\nVictory on 1, 2 and 3" << std::endl;
       victory = 1;
   }
   else if (board[3] == check && board[4] == check && board[5] == check)
   {
       std::cout << "\nVictory on 4, 5 and 6" << std::endl;
       victory = 1;
   }
   else if (board[6] == check && board[7] == check && board[8] == check)
   {
       std::cout << "\nVictory on 7, 8 and 9" << std::endl;
       victory = 1;
   }
   else if (board[0] == check && board[3] == check && board[6] == check)
   {
       std::cout << "\nVictory on 1, 4 and 7" << std::endl;
       victory = 1;
   }
   else if (board[1] == check && board[4] == check && board[7] == check)
   {
       std::cout << "\nVictory on 2, 5 and 8" << std::endl;
       victory = 1;
   }
   else if (board[2] == check && board[5] == check && board[8] == check)
   {
       std::cout << "\nVictory on 3, 6 and 9" << std::endl;
       victory = 1;
   }
   else if (board[0] == check && board[4] == check && board[8] == check)
   {
       std::cout << "\nVictory on 1, 5 and 9" << std::endl;
       victory = 1;
   }
   else if (board[2] == check && board[4] == check && board[6] == check)
   {
       std::cout << "\nVictory on 3, 5 and 7" << std::endl;
       victory = 1;
   }
   //end of three in a row check ------------------------------
   
   if (victory == 0)
   {
       int availableMoves = 0;
       for (int i = 0; i < 9; i++)
       {
           char num = '0' + i + 1;

           if (board[i] == num)
           {
               //Available spots: keep going
               availableMoves++;
           }
           
       }

       if (availableMoves == 0)
       {
           playerTurn = 0;
           victory = 1;
       }
   }

    return victory;
}









int Player1(int)
{
    bool validMove = false;
    
    do
    {
        int p1;

        std::cout << "\nPlayer 1: Choose where to place an X: ";
        std::cin >> p1;

        //Valid move check ----------------------------
        if (board.at(p1 - 1) == 'x')
        {
            std::system("CLS");
            std::cout << "----There's allready an x there!----" << std::endl;
            system("pause");
        }
        else if (board.at(p1 - 1) == 'o')
        {
            std::system("CLS");
            std::cout << "----Your opponents mark is there allredy!----" << std::endl;
            system("pause");
        }
        else
        {
            board[p1 - 1] = 'x';
            validMove = 1;
        }
        //End of Valid move check ---------------------

        //Prints the board ----------------------------
        std::system("CLS");
        for (int i = 0; i < board.size(); i++)
        {
            if (i == 0)
            {
                std::cout << " | ";
            }

            if (i % 3 == 0 && i != 0)
            {
                std::cout << "\n" << " | ";
            }

            std::cout << board[i];
            std::cout << " | ";
        }
        //End of board print --------------------------

    } while (validMove == 0);

   

    playerTurn = 2;
    return playerTurn;
}


int Player2(int)
{
    bool validMove = false;

    do
    {
        int p2;

        std::cout << "\nPlayer 2: Choose where to place an O: ";
        std::cin >> p2;

        //Valid move check ----------------------------
        if (board.at(p2 - 1) == 'o')
        {
            std::system("CLS");
            std::cout << "----There's allready an o there!----" << std::endl;
            system("pause");
        }
        else if (board.at(p2 - 1) == 'x')
        {
            std::system("CLS");
            std::cout << "----Your opponents mark is there allredy!----" << std::endl;
            system("pause");
        }
        else
        {
            board[p2 - 1] = 'o';
            validMove = 1;
        }
        //End of Valid move check ---------------------

        //Prints the board ----------------------------
        std::system("CLS");
        for (int i = 0; i < board.size(); i++)
        {
            if (i == 0)
            {
                std::cout << " | ";
            }

            if (i % 3 == 0 && i != 0)
            {
                std::cout << "\n" << " | ";
            }

            std::cout << board[i];
            std::cout << " | ";
        }
        //End of board print --------------------------

    } while (validMove == 0);

    

    playerTurn = 1;
    return playerTurn;

    
}

int MrComputer(int)
{
    bool validMove = false;
    srand(time(nullptr));

    /*int availableMoves = 0;
    for (int i = 0; i < 9; i++)
    {
        char num = '0' + i + 1;

        if (board[i] == num)
        {
            //Available spots: keep going
            availableMoves++;
        }

    }

    if (availableMoves == 0)
    {
        playerTurn = 0;
        return playerTurn;
    }*/

    do
    {
        int com;

        com = getRandomNumber(8);

        //Computer vilid move check ----------------------------
        if (board[com] == 'o' || board[com] == 'x')
        {
            //try again
            validMove = 0;
        }
        else
        {
            board[com] = 'o';
            validMove = 1;
        }
        //End of computer Valid move check ---------------------

        //Prints the board ----------------------------
        std::system("CLS");
        for (int i = 0; i < board.size(); i++)
        {
            if (i == 0)
            {
                std::cout << " | ";
            }

            if (i % 3 == 0 && i != 0)
            {
                std::cout << "\n" << " | ";
            }

            std::cout << board[i];
            std::cout << " | ";
        }
        //End of board print --------------------------

    } while (validMove == 0);

    gameover = VictoryCheck(playerTurn);

    playerTurn = 1;
    return playerTurn;
}

int getRandomNumber(int max)
{
    int randomNumber = rand() % max + 1;
    return randomNumber;
}