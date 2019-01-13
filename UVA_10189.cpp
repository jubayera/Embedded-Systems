#include <iostream>
using namespace std;

struct bomb_location {
    int row_loc, col_loc;
};

int main ()
{
    int row, col, field = 1;

    while(cin >> row >> col)
    {
        if(row == 0 && col == 0)
            break;

        if(field > 1)
            cout << endl;

        struct bomb_location Bomblocations[row*col];

        int location = 0;
            
        char grid[row][col];
        char result[row][col];
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cin >> grid[i][j];

                if(grid[i][j] == '*')
                {
                    result[i][j] = grid[i][j];
                    Bomblocations[location].row_loc = i;
                    Bomblocations[location].col_loc = j;
                    location++;
                }
                else
                {
                    result[i][j] = '0';
                }
            }
        }

        cout << "Field #" << field << ":" << endl;

        /*for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }

        for(int i = 0; i < location; i++)
            cout << Bomblocations[i].row << " " << Bomblocations[i].col << endl;
        */

        for(int i = 0; i < location; i++)
        {
            //cout << Bomblocations[i].row << " " << Bomblocations[i].col << endl;
            int pos_row = Bomblocations[i].row_loc;
            int pos_col = Bomblocations[i].col_loc;

            for(int row_turn = pos_row - 1; row_turn <= pos_row + 1; row_turn++)
            {
                for(int col_turn = pos_col - 1; col_turn <= pos_col + 1; col_turn++)
                {
                    if(row_turn >= 0 && row_turn < row && col_turn >= 0 && col_turn < col)
                    {
                        if(grid[row_turn][col_turn] != '*')
                        {
                            result[row_turn][col_turn] = ((result[row_turn][col_turn] - '0') + 1) + '0';
                        }
                    }
                }
            }
        }

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cout << result[i][j];
            }
            cout << endl;
        }

        field++;
    }

    return 0;
}
