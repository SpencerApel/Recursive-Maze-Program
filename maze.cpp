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
    matrix = NULL;
}

void find_start(string *matrix, int rows, int &x, int &y)
{
    for (int i = 0; i < rows; ++i)
    {
        string column;
        column = matrix[i];

        for (int j = 0; j < column.length(); ++j)
        {
            if (column[j] == 'N')
            {
                x = i;
                y = j;
            }
        }
    }
}

bool find_exit(string *matrix, int x, int y)
{
}

bool at_end(string *matrix, int x, int y)
{
    //increment through the array, find the index where 'E' is and if
    //x and y are at the index of 'E' then that is where to end?
}

bool valid_move(string *matrix, int x, int y, direction d)
{
}
