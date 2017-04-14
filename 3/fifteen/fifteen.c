/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("Got the Game!\nFinish!!!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            //usleep(500000);
			Sleep(500);
        }

        // sleep thread for animation's sake
        //usleep(500000);
		Sleep(500);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
// 跳脫字元 Reference - Win 10才支援
// http://asika.windspeaker.co/post/3496-windows-cmd-ansi
void clear(void)
{
	system("cls");
//    printf("\033[2J");
//    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("\nWELCOME TO GAME OF FIFTEEN\n");
    //usleep(2000000);
	Sleep(2000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
	int i;
	for(i = 0;i<d*d;i++)
	{
		board[i/d][i%d] = d*d-i-1;
	}
	
	if( d%2 == 0 )
	{
		int temp;
		temp = board[d-1][d-2];
		board[d-1][d-2] = board[d-1][d-3];
		board[d-1][d-3] = temp;
		
		printf("%2i,%2i\n",board[d][d-4],board[d][d-3]);
	}
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // TODO
	printf("\n\n");
	int i,j;
	for(i=0;i<d;i++)
	{
		for(j = 0;j<d;j++)
		{
			if( board[i][j] != 0 )
			{
				printf("%2i ",board[i][j]);
			}
			else
			{
				printf(" - ");
			}
			
		}
		printf("\n");
	}
	printf("\n");
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
	int row,col;
	int i;
	for(i = 0;i<d*d;i++)
	{
		if(board[i/d][i%d] == 0)
		{
			row = i/d;
			col = i%d;
		}
	}
	
	if( board[row-1][col] == tile   )
	{
		board[row-1][col] = 0;
		board[row][col] = tile;
		return true;
	}
	else if( board[row][col-1] == tile )
	{
		board[row][col-1] = 0;
		board[row][col] = tile;
		return true;
	}
	else if( board[row+1][col] == tile )
	{
		board[row+1][col] = 0;
		board[row][col] = tile;
		return true;
	}
	else if( board[row][col+1] == tile )
	{
		board[row][col+1] = 0;
		board[row][col] = tile;
		return true;
	}
	
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
	bool checked = true;
	int i;
	for(i=0;i<d*d-1;i++)
	{
		if(board[i/d][i%d] != i+1)
		{
			checked = false;
		}
	}
	
	if(board[i/d][i%d+1] != 0)
	{
		checked = false;
	}
	
    return checked;
}
