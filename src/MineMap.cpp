#include "MineMap.h"

MineMap::MineMap() : MineNum(50),
gamestate(0),
rMineNum(0),
mx(20),
my(15)
{
    Map = NULL;
}

MineMap::~MineMap() {}

void MineMap::InitCreate()
{
    if (Map != NULL)
    {
        for (int i = 0; i < mx; i++)
            delete Map[i];
        delete Map;
        Map = NULL;
    }
    Map = new int* [mx];
    for (int i = 0; i < mx; i++)
        Map[i] = new int[my];
    Restart();
}

void MineMap::ModifyDifficulty(int x, int y, int m)
{
    InitCreate();
    mx = x;
    my = y;
    MineNum = m;
}

void MineMap::Restart()
{
    srand(time(NULL));

    for (int i = 0; i < mx; i++)
        for (int j = 0; j < my; j++)
            Map[i][j] = SAFEGRID;
    for (int i = 0; i < MineNum;)
    {
        int m = rand() % mx, n = rand() % my;
        if (Map[m][n] == SAFEGRID)
        {
            Map[m][n] == MINEGRID;
            i++;
        }
    }
    for (int i = 0; i < mx; i++)
        for (int j = 0; j < my; j++)
            if (Map[i][j] == MINEGRID) // 对于每个有雷的格子，周围全加1
                for (int m = -1; m <= 1; m++)
                    for (int n = -1; n <= 1; n++)
                    {
                        if (i + m >= mx || i + m < 0) // 行越界
                            continue;
                        if (j + n >= my || j + n < 0) // 列越界
                            continue;
                        if (Map[i + m][j + n] == 99)
                            continue;
                        Map[i + m][j + n]++;
                    }

    gamestate = 1;
    rMineNum = MineNum;
    firstclick = 1;
    timer = 0;
}

bool MineMap::IsWin()
{
    for (int i = 0; i < mx; i++)
        for (int j = 0; j < my; j++)
        {
            if (Map[i][j] > 99)
                return false;
            if (Map[i][j] > 49 && Map[i][j] < 59)
                return false;
        }
    gamestate = GAMESUCCESS;
    return true;
}

bool MineMap::Lclick(int m, int n)
{
    if (gamestate == 0 || gamestate == GAMESUCCESS)
        return false;
    if (invalidposition(m, n))
        return false;

    if (Map[m][n] <= 90)
        return false;
    else if (Map[m][n] >= 101 && Map[m][n] <= 108)
    {
        Map[m][n] -= 100;
        firstclick = 0;
        IsWin();
    }
    else if (Map[m][n] == SAFEGRID)
    {
        Map[m][n] = 0;
        cleararound(m, n);
    }
    else if (Map[m][n] == MINEGRID && firstclick)
    {
    }
    else if (Map[m][n] == MINEGRID && (!firstclick))
    {
        for (int i = 0; i < mx; i++)
        {
            for (int j = 0; j < my; j++)
            {
                if (Map[i][j] == MINEGRID)
                    Map[i][j] = -1;
                else if (Map[i][j] > 49 && Map[i][j] < 60)
                    Map[i][j] = -2;
            }
        }
        gamestate = 0;
    }
    return true;
}

bool MineMap::Rclick(int m, int n)
{
    if (gamestate == 0 || gamestate == GAMESUCCESS)
        return false;
    if (invalidposition(m, n))
        return false;
    if (Map[m][n] > 90)//可交互暗格
    {
        Map[m][n] -= 50;
        rMineNum--;
    }
    else if (Map[m][n] > 40 && Map[m][n] < 60)
    {
        rMineNum++;
        Map[m][n] += 50;
    }
    return true;
}

bool MineMap::Doubleclick(int m, int n)
{
    if (invalidposition(m, n))
        return false;
    if (Map[m][n] > 40)
        return false;
    if (Map[m][n] == aroundflag(m, n))
        cleararound(m, n);
    return true;
}

int MineMap::aroundflag(int m, int n)
{
    int t = 0;
    if (invalidposition(m, n))
        return -1;
    for (int a = -1; a <= 1; a++)
        for (int b = -1; b <= 1; b++)
        {
            if ((m + a >= mx) || (n + b >= my) || (m + a < 0) || (n + b < 0) || (Map[m + a][n + b] > 60) || (Map[m + a][n + b] < 40))
                continue;
            t++;
        }
    return t;
}

bool MineMap::invalidposition(int m, int n)
{
    return (m >= mx || n >= my || m < 0 || n < 0);
}

bool MineMap::cleararound(int m, int n)
{
    Lclick(m - 1, n);
    Lclick(m + 1, n);
    Lclick(m, n - 1);
    Lclick(m, n + 1);
    Lclick(m - 1, n + 1);
    Lclick(m - 1, n - 1);
    Lclick(m + 1, n - 1);
    Lclick(m - 1, n + 1);
    return true;
}