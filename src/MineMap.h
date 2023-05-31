#pragma once

class MineMap
{
public:
    MineMap();
    ~MineMap();
    // ��Ϸ״̬
    void Create();                      // Ĭ��
    void Create(int x, int y, int m);     // �û��Զ��崴��
    void Restart();
    bool IsWin();

    // ��Ϸ����
    bool Rclick(int m, int n);
    bool Lclick(int m, int n);
    bool Doubleclick(int m, int n);



private:
    int** Map;          // ��ͼ
    int MineNum;        // ����
    int mx;             // ����
    int my;             // ����
    int gamestate;      // ��Ϸ״̬ 



    int ctnflag(int m, int n);   // ����m,n������Χ�����ӵ����� 
};