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
    int x, y;

    while (file_in)
    {
        file_in >> rows;

        if(rows == 0)
            return;

        matrix = build_matrix(rows);

        file_in.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Grab line until '\n' then toss it

        for (int i = 0; i < rows; i++)
        {
            getline(file_in, matrix[i]);
        }
        find_start(matrix, rows, x, y);
        print_matrix(matrix, rows);
        cout << endl;
        delete_matrix(matrix, rows);
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
    cout << "(" << x << ", " << y << ")" << endl;
}

bool find_exit(string *matrix, int x, int y) //first iteration of function passing in coords of N's starting pos
{
    if (valid_move(matrix, x, y, NORTH) == true) //need to add breaks in all of the if/if else statement to help with multiple ways to go, do the 1st
    {
        --x; //moving up; a row index
        return true;
    }
    else if (valid_move(matrix, x, y, EAST) == true) //NEED TO CHANGE OUTPUT FUNCTION to add @
    {
        ++y; //moving right a column index
        return true;
    }
    else if (valid_move(matrix, x, y, SOUTH) == true)
    {
        ++x; //moving down a row index
        return true;
    }
    else if (valid_move(matrix, x, y, WEST) == true)
    {
        --y; //moving left a column index
        return true;
    }
    //else if()//backtracking
    else
        return false;
}

bool at_end(string *matrix, int x, int y)
{
    int x_sol, y_sol;
    int size = sizeof(matrix) / sizeof(matrix[0]); //to get the size of rows for loop

    for (int i = 0; i < size; i++) //increment through the rows
    {
        string column;
        column = matrix[i]; //set the incremented row to string column

        for (int j = 0; j < column.length(); j++) //increment through the length of column
        {
            if (column[j] == 'E') //if the index of column matches E
            {
                //this sets the variables of the solution
                x_sol = i; //x_sol is equal to i because of the 1st for loop
                y_sol = j; //y_sol is eqyal to j because of the 2nd for loop
            }
        }
    }
    if (x == x_sol && y == y_sol) //if x and y are at the solution coords
        return true;
    else
        return false;
}

bool valid_move(string *matrix, int x, int y, direction d)
{
    //check for |, @, and ' '

    if (d == NORTH)
    {
        //check if north is clear
        string column;
        column = matrix[--x];

        if (column[y] == '|')
            return false;
        else if (column[y] == ' ')
            return true;
    }
    else if (d == EAST)
    {
        //check if EAST is clear
        string column;
        column = matrix[x];

        if (column[++y] == '|')
            return false;
        else if (column[++y] == ' ')
            return true;
    }
    else if (d == SOUTH)
    {
        string column;
        column = matrix[++x];

        if (column[y] == '|')
            return false;
        else if (column[y] == ' ')
            return true;
    }
    else if (d == WEST)
    {
        string column;
        column = matrix[x];

        if (column[--y] == '|')
            return false;
        else if (column[--y] == ' ')
            return true;
    }
    else
        return false;
}
