#include <iostream>

using namespace std;

/*
                    Empty template
int Puzzle[9][9] = {{0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0,0}};
*/

// Filled example
int Puzzle[9][9] = {{0,0,0,0,0,4,7,0,8},
                    {0,0,0,0,0,8,0,0,3},
                    {0,0,0,2,1,5,0,0,0},
                    {0,0,7,0,0,0,0,9,6},
                    {8,0,0,0,9,0,0,0,0},
                    {0,0,4,1,0,0,0,0,0},
                    {0,1,0,0,4,0,5,0,0},
                    {0,0,0,0,0,0,2,0,0},
                    {2,5,0,0,0,0,0,8,0}};

// Check if value fits that column
bool isColFit(int val,int col)
{
    for(int i=0; i<9; i++)
    {
        if(Puzzle[i][col] == val)
            return false;
    }
    return true;
}

// Check if value fits that row
bool isRowFit(int val,int row)
{
    for(int i=0; i<9; i++)
    {
        if(Puzzle[row][i] == val)
            return false;
    }
    return true;
}

// Check if value fits into the 3x3 square.
bool isSquFit(int val, int row, int col)
{
    int row_ = (row / 3) * 3;
    int col_ = (col / 3) * 3;

    for(int icol = col_; icol<col_+3; icol++)
    {
        for(int irow = row_; irow<row_+3; irow++)
        {
            if(Puzzle[irow][icol] == val)
                return false;
        }
    }
    return true;
}

// Check if value fits that point
bool isFit(int val,int row,int col)
{
    return isColFit(val,col) && isRowFit(val,row) && isSquFit(val,row,col);
}

void printPuzzle()
{
    cout << endl << endl << endl;
    cout << '\t';

    for(int j=0; j< 9*4 +3; j++)
    {
        cout << "-";
    }
    cout << endl;

    for(int i=0; i<9; i++)
    {
        cout << '\t' << "|";

        for(int j=0; j<9; j++)
        {
            cout << " " << Puzzle[i][j] << " |";
            if(j == 2 || j == 5)
                cout << "|";
        }

        cout << endl << '\t';

        if(i == 2 || i == 5)
        {
            for(int j=0; j< 9*4 +3; j++)
            {
                cout << "=";
            }
        }

        else
        {
            for(int j=0; j< 9*4 +3; j++)
            {
                cout << "-";
            }
       }

       cout << endl;
   }
}

void solve()
{
    for(int row=0; row<9; row++)
    {
        for(int col=0; col<9; col++)
        {
            if(Puzzle[row][col] == 0)
            {
                for(int i=1; i<10; i++)
                {
                    if(isFit(i,row,col))
                    {
                        Puzzle[row][col] = i;
                        solve();
                        Puzzle[row][col] = 0;
                    }
                }
                return;
            }
        }
    }
    printPuzzle();
}

void getValues()
{
    unsigned long int input;
    cout << "Enter each row one by one. " << endl;
    cout << "Example: " << endl;
    cout << '\t';
    cout << "|7|0|0|4|8|0|0|1|0|    ==>     700480010" << endl;

    for(int i=0; i<9; i++)
    {
        cout << i+1 << ". Row: ";
        cin >> input;
        for(int j=0; j<9; j++)
        {
            Puzzle[i][8-j] = input % 10;
            input /= 10;
        }
    }
}

int main()
{
    char selection;
    cout << "Would you like to enter Puzzle manually? (Y/N)" << endl;
    cin >> selection;
    if(selection == 'Y' || selection == 'y')
    {
        getValues();
        solve();
    }
    else if(selection == 'N' || selection == 'n')
        solve();
    else
        cout << "Check your answer and try again." << endl;
    return 0;
}
