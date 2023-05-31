#pragma once

class MineMap
{
public:
    MineMap();
    ~MineMap();
    // 游戏状态
    void Create();                      // 默认
    void Create(int x, int y, int m);     // 用户自定义创建
    void Restart();
    bool IsWin();

    // 游戏操作
    bool Rclick(int m, int n);
    bool Lclick(int m, int n);
    bool Doubleclick(int m, int n);



private:
    int** Map;          // 地图
    int MineNum;        // 雷数
    int mx;             // 行数
    int my;             // 列数
    int gamestate;      // 游戏状态 



    int ctnflag(int m, int n);   // 返回m,n格子周围的棋子的数量 
};