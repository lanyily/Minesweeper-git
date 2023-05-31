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
            if (Map[i][j] == MINEGRID)//对于每个有雷的格子，周围全加1
                for (int m = -1; m <= 1; m++)
                    for (int n = -1; n <= 1; n++)
                    {
                        if (i + m >= mx || i + m < 0)  // 行越界
                            continue;
                        if (j + n >= my || j + n < 0)  // 列越界
                            continue;
                        if (Map[i + m][j + n] == 99)
                            continue;
                        Map[i + m][j + n]++;
                    }
}

bool MineMap::IsWin()
{

}
bool Rclick(int m, int n)
{

}

bool Lclick(int m, int n)
{

}

bool Doubleclick(int m, int n)
{

}
int ctnflag(int m, int n)
{

}
