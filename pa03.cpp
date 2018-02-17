#include "maze.h"

int main()
{
    string *matrix = NULL;
    int rows = 0;
    int cols = 0;
    int x = 0;
    int y = 0;
    bool run = true;

    ifstream file_in("sample_input.txt"); //opening the text file

    while (run == true)
    {
        file_in >> rows; //get the first number
        file_in >> cols;

        if (rows == 0)
            run = false;
        else if(rows > 0)
        {
            matrix = build_matrix(rows);
            fill_matrix(matrix, rows, file_in);
            find_start(matrix, rows, x, y);
            
            print_matrix(matrix, rows);
            delete_matrix(matrix, rows);
            cout << endl;
        }
    }
    file_in.close();//close file
    return 0;
}
