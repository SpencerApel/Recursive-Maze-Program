#include "maze.h"
#include <fstream>
#include <limits>

using std::ifstream;

void get_identity(string my_id[])
{
    my_id[0] = "sra7wb";
    my_id[1] = "16231948";

    //output
    cout << "MST Campus Username: " << my_id[0] << endl;
    cout << "Student ID: " << my_id[1] << endl;
}

string *build_matrix(int rows)
{
    string *matrix = new string[rows]; //allocating memory for the matrix

    return matrix;
}

void fill_matrix(string *matrix, int rows)
{
    ifstream file_in("sample_input.txt");
    int x = 0;
    int y = 0;

    while (file_in)
    {
        file_in >> rows;

        if (rows == 0)
            return;

        matrix = build_matrix(rows);

        file_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Grab line until '\n' then toss it

        for (int i = 0; i < rows; i++)
        {
            getline(file_in, matrix[i]); //filling matrix with file_in from text file
        }

        find_start(matrix, rows, x, y);
        find_exit(matrix, x, y);
        print_matrix(matrix, rows);
        cout << endl;
        delete_matrix(matrix, rows);

        file_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Grab line until '\n' then toss it
    }
}

void print_matrix(string *matrix, int rows)
{
    for (int i = 0; i < rows; i++) //increment through the row of the matrix
    {
        cout << matrix[i] << endl; //print eack row
    }
}

void delete_matrix(string *matrix, int rows)
{
    delete[] matrix; //delete the matrix
    matrix = NULL;   //set equal to null for no hanging pointers
}

void find_start(string *matrix, int rows, int &x, int &y)
{
    for (int i = 0; i < rows; i++) //increment through the rows
    {
        string column;
        column = matrix[i]; //set the incremented row to string column

        for (int j = 0; j < column.length(); j++) //increment through the length of column
        {
            if (column[j] == 'N') //if the index of column matches N
            {
                x = i; //x is equal to i because of the 1st for loop
                y = j; //y is eqyal to j because of the 1st for loop
            }
        }
    }
}

bool find_exit(string *matrix, int x, int y) //first iteration of function passing in coords of N's starting pos
{
    //check if we reached the end of the maze
    if (at_end(matrix, x, y) == true)
        return true;

    //sets the starting position to @
    if(matrix[x][y] == ' ')
        matrix[x][y] = '@';

    //recursive search for our goal
    if (valid_move(matrix, x, y, NORTH) && find_exit(matrix, x - 1, y))
    {
        if(matrix[x][y] == ' ')
            matrix[x][y] = '@';
        return true;
    }
    if (valid_move(matrix, x, y, SOUTH) && find_exit(matrix, x + 1, y))
    {
        if(matrix[x][y] == ' ')
            matrix[x][y] = '@';
        return true;
    }
    if (valid_move(matrix, x, y, WEST) && find_exit(matrix, x, y - 1))
    {
        if(matrix[x][y] == ' ')
            matrix[x][y] = '@';
        return true;
    }
    if (valid_move(matrix, x, y, EAST) && find_exit(matrix, x, y + 1))
    {
        if(matrix[x][y] == ' ')
            matrix[x][y] = '@';
        return true;
    }

    //this line here is meant to print a space when backtracking occurs
    if(matrix[x][y] == '@')
        matrix[x][y] = ' ';
    return false;
}

//this function returns true if you are at the end of the maze
bool at_end(string *matrix, int x, int y)
{
    if (matrix[x][y] == 'E')
    {
        cout << "Solution found:" << endl;
        return true;
    }
    else
    {
        //cout << "Solution not found:" << endl;
        return false;
    }
}

bool valid_move(string *matrix, int x, int y, direction d)
{
    if (d == NORTH)
    {
        //check if north is clear
        if (matrix[x - 1][y] == ' ' || matrix[x - 1][y] == 'E')
            return true;
        else
            return false;
    }
    else if (d == EAST)
    {
        //check if EAST is clear
        if (matrix[x][y + 1] == ' ' || matrix[x][y + 1] == 'E')
            return true;
        else
            return false;
    }
    else if (d == SOUTH)
    {
        //check is south is clear
        if (matrix[x + 1][y] == ' ' || matrix[x + 1][y] == 'E')
            return true;
        else
            return false;
    }
    else if (d == WEST)
    {
        //check if west is clear
        if (matrix[x][y - 1] == ' ' || matrix[x][y - 1] == 'E')
            return true;
        else
            return false;
    }
    else
        return false;
}
