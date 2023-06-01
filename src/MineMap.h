#pragma once

#include<stdlib.h>
#include<time.h>

#define SAFEGRID 100
#define MINEGRID 99

#define GAMESUCCESS 2

class MineMap
{
public:
    MineMap();
    ~MineMap();
    // ��Ϸ״̬
    void InitCreate();                              // ��ʼ
    void ModifyDifficulty(int x, int y, int m);      // �û��Զ���
    void Restart();
    bool IsWin();

    // ��Ϸ����
    bool Rclick(int m, int n);
    bool Lclick(int m, int n);
    bool Doubleclick(int m, int n);

private:
    int** Map;          // ��ͼ
    int MineNum;        // ����
    int rMineNum;       // ʣ���������������-���ֵ
    int mx;             // ����
    int my;             // ����
    int gamestate;      // ��Ϸ״̬��0-��ʼ��1-���»��Ƶ�ͼ��2-ʤ����3-ʧ��
    int timer;          // ��ʱ��
    int firstclick;     // �Ƿ�Ϊ��һ�ε��

    int aroundflag(int m, int n);           // ����m,n������Χ�����ӵ����� 
    bool invalidposition(int m, int n);     // �ж�λ���Ƿ�Ϸ���1-�Ƿ���0-�Ϸ�
    bool cleararound(int m, int n);         // ��������Χ8��ĺϷ�λ��
};