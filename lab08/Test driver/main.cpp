#include <iostream>
#include "ModulesMalamuzh.h"

using namespace std;

int main()
{
    double mathResult[10][3] = {{2, 4, 3}, {4, 5, 6}, {3, 10, 1}, {1.6, 5, 4.5}, {15, 4, 7}, {7, 6, 1}, {16, 7, 14}, {5, 6, 7}, {6, 1, 7}, {9, 4, 6}};
    double Expected[10] = {58.6453, 155.412, 22032.9, 149.535, 95.0138, 423.184, 1133.15, 412.579, 14.6396, 77.2156};
    for (int i = 0; i < 10; i++)
    {
        cout << "Testcase#" << i + 1 << ": " << calculations_s(mathResult[i][0], mathResult[i][1], mathResult[i][2]);
        if (calculations_s(mathResult[i][0], mathResult[i][1], mathResult[i][2]) == calculations_s(mathResult[i][0], mathResult[i][1], mathResult[i][2]))
        {
            cout << "   PASSED!" << endl;
        }
        else
        {
            cout << "   FAILED!" << endl;
        }
    }
    system("pause");
    return 0;
}
