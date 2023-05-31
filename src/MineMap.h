#pragma once

#include<stdlib.h>
#include<time.h>

#define SAFEGRID 100
#define MINEGRID 99

class MineMap
{
public:
    MineMap();
    ~MineMap();
    // 游戏状态
    void InitCreate();                              // 初始
    void ModifyDifficulty(int x, int y, int m);      // 用户自定义
    void Restart();
    bool IsWin();

    // 游戏操作
    bool Rclick(int m, int n);
    bool Lclick(int m, int n);
    bool Doubleclick(int m, int n);

private:
    int** Map;          // 地图
    int MineNum;        // 雷数
    int rMineNum;       // 剩余的雷数，即雷数-标记值
    int mx;             // 行数
    int my;             // 列数
    int gamestate;      // 游戏状态，0-开始，1-重新绘制地图，2-胜利，3-失败
    int timer;          // 计时器
    int firstclick;     // 是否为第一次点击

    int ctnflag(int m, int n);   // 返回m,n格子周围的棋子的数量 
};