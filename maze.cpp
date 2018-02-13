#include "maze.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
    string *matrix = new string *[rows]; //allocating memory for the matrix

    return matrix;
}

void fill_matrix(string *matrix, int rows)
{
    ifstream file_in("sample_input.txt");//opening the text file

    if (file_in)//while file is opened and good
    {
        for(int i = 0; i < rows; ++i)//increment through the rows
        {
            getline(file_in, matrix[i]);//get each line and place them in the according row
        }
    }
    file_in.close();//close file
}

void print_matrix(string *matrix, int rows)
{
    for (int i = 0; i < rows; ++i)//increment through the row of the matrix
        cout << matrix[i] << endl;//print eack row
}

void delete_matrix(string *matrix, int rows)
{
    delete[] matrix;//delete the matrix
    matrix = NULL;//set to NULL for no hanging pointers
}

void find_start(string *matrix, int rows, int &x, int &y)
{
    for (int i = 0; i < rows; ++i)//increment through the rows
    {
        string column;
        column = matrix[i];//set the incremented row to string column

        for (int j = 0; j < column.length(); ++j)//increment through the length of column
        {
            if (column[j] == 'N')//if the index of column matches N
            {
                x = i;//x is equal to i because of the 1st for loop
                y = j;//y is eqyal to j because of the 1st for loop
            }
        }
    }
}

bool find_exit(string *matrix, int x, int y)
{
}

bool at_end(string *matrix, int x, int y)
{
    // Returns true if x and y are the final exit location, 
    // and false otherwise.
    int x_sol, y_sol;
    int size = sizeof(matrix)/sizeof(matrix[0]);//to get the size of rows for loop
    
    for (int i = 0; i < size; ++i)//increment through the rows
    {
        string column;
        column = matrix[i];//set the incremented row to string column

        for (int j = 0; j < column.length(); ++j)//increment through the length of column
        {
            if (column[j] == 'E')//if the index of column matches E
            {
                //this sets the variables of the solution
                x_sol = i;//x_sol is equal to i because of the 1st for loop
                y_sol = j;//y_sol is eqyal to j because of the 1st for loop
            }
        }
    }
    if(x == x_sol && y == y_sol)//if x and y are at the solution coords
        return true;
    else
        return false;
}

bool valid_move(string *matrix, int x, int y, direction d)
{
}
