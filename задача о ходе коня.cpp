// задача о ходе коня.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#define m 8
int board[m][m];


bool Check(int x, int y)//проверка на выход за границу доски
{
    return x >= 1 && y >= 1 && x <= m && y <= m;
}

bool Move(int x, int y)//если не были в этой клетке
{
    return Check(x, y) && board[x][y] == 0;
}
bool FindMoves(int x, int y, int n)
{
    board[x][y] = n; //присваиваем n позиции (x,y)
   
    if (n > m * m - 1)//если обошли уже всю доску
        return true;
    //проверки все 8 ходов коня
    if (Check(x - 1, y - 2) && Move(x - 1, y - 2) && FindMoves(x - 1, y - 2, n + 1)) return true;
    if (Check(x - 2, y - 1) && Move(x - 2, y - 1) && FindMoves(x - 2, y - 1, n + 1)) return true;
    if (Check(x - 2, y + 1) && Move(x - 2, y + 1) && FindMoves(x - 2, y + 1, n + 1)) return true;
    if (Check(x + 1, y - 2) && Move(x + 1, y - 2) && FindMoves(x + 1, y - 2, n + 1)) return true;
    if (Check(x - 1, y + 2) && Move(x - 1, y + 2) && FindMoves(x - 1, y + 2, n + 1)) return true;
    if (Check(x + 2, y - 1) && Move(x + 2, y - 1) && FindMoves(x + 2, y - 1, n + 1)) return true;
    if (Check(x + 1, y + 2) && Move(x + 1, y + 2) && FindMoves(x + 1, y + 2, n + 1)) return true;
    if (Check(x + 2, y + 1) && Move(x + 2, y + 1) && FindMoves(x + 2, y + 1, n + 1)) return true;

    //если не нашлось хода то шаг назад
    board[x][y] = 0; n--; return false;
}

int main()
{
    setlocale(LC_ALL, "rus");
    //////////////////////////////////
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            board[i][j] = 0;
    /////////////////////////////////
    int ii; int  jj;
    cout << "Введите x0  "; cin >> ii; cout << endl;
    cout << "Введите y0  "; cin >> jj;
    if (Check(ii, jj))
    {
        if (FindMoves(ii, jj, 1))
        {
            for (int i = 1; i <= m; i++)
            {
                for (int j = 1; j <= m; j++)
                    cout << board[i][j] <<'\t';
                cout << "\n";
            }
        }
    }
    else cout << "invalid input";
}
