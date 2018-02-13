#include "maze.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;


void get_identity(string my_id[])
{
    my_id[0] = "sra7wb";
    my_id[1] = "16231948";

    //output
    cout << "MST Campus Username: " << my_id[0] << endl;
    cout << "Student ID: " << my_id[1] << endl;
}


string * build_matrix(int rows)
{
    string *matrix = new string *[rows];

    return matrix;
}


void fill_matrix(string *matrix, int rows)
{
    //use getline
}


void print_matrix(string *matrix, int rows)
{
    for(int i = 0; i < rows; ++i)
        cout << matrix[i] << endl;
}


void delete_matrix(string *matrix, int rows)
{
    delete[] matrix;
}


void find_start(string *matrix, int rows, int &x, int &y)
{
}

bool find_exit(string *matrix, int x, int y)
{
}


bool at_end(string *matrix, int x, int y)
{
}

bool valid_move(string *matrix, int x, int y, direction d)
{  
}

