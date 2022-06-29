#ifndef __STAGE__
#define __STAGE__
#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <fstream>
#include <cstring>
#include "Something.h"


// 키보드 입력 정의
#define UP KEY_UP
#define DOWN KEY_DOWN
#define RIGHT KEY_RIGHT
#define LEFT KEY_LEFT
#define ENTER 10
#define ESC 27
#define PAUSE 112
#define RESUME 114
#define SKIP 115

// 아이템 번호 정의
#define EMPTY 0
#define WALL 1
#define IMMUNE_WALL 2
#define SNAKE_HEAD 3
#define SNAKE_BODY 4
#define GROWTH_ITEM 5
#define POISON_ITEM 6
#define GATE 7

using namespace std;

class Stage
{
public:
    // 생성자, 소멸자
    Stage();
    ~Stage();

    // 화면크기 및 위치를 지정해주는 함수
    void screenLock();


//---------------------------------------------------------------------
    // 처음 게임을 시작했을 때, 메뉴에 대한 함수
    string menu();
    void play();
    void help();
    void option();

//------------------------------------------------------------------------

    // 단계별 스테이지를 가져오고, 맵의 크기를 지정하는 함수 
    int getStageNum() const { return STAGE_NUM; }
    int getMapRow() const { return MAP_ROW; }
    int getMapCol() const { return MAP_COL; }

    // 맵에대한 함수
    void setMap();
    void copyMap(int nStage);
    void drawMap();

    // 아이템과 게이트 생성에 대한 함수
    void appearItem();
    void appearGate();
    void disappearItem();
    void disappearGate();


//-------------------------------------------------------------------------------
    // 뱀의 동작에 대한 함수 (생성, 움직임, 게이트로 들어감,나옴 ,아이템 먹기)
    void makeSnake();
    void moveSnake();
    void enterGate(Something *head);
    int findRoot(Something *gate);
    void eatItem(int item);

//-------------------------------------------------------------------------------

    // 게임 진행에 대한 함수
    void setMission();
    bool isMissionClear();
    bool checkGameOver() { return finish; }
    void gameOver();
    void alert(int posY, int posX, const string msg, bool stopFlag);

//-----------------------------------------------------------------------------------

private:
    // 화면(창)에 대한 변수
    WINDOW *game, *score, *mission, *info;
    WINDOW *manual, *description, *scrollBar;

    // 뱀의 상태에 대한 변수
    int stat[5];

    // mission variables
    char chkMission[4];
    int statMission[4];

    // 뱀에 대한 Something.h struct 변수
    const int SNAKE_MAX_LENGTH = 10;
    Something *Bam;
    Something *gate1;
    Something *gate2;

    // const variables about map size & snake character  맵의 크기와 문자를 지정하는  const변수
    const int STAGE_NUM = 5,
              MAP_ROW = 25,
              MAP_COL = 50,
              ROW_END = MAP_ROW - 1,
              COL_END = MAP_COL - 1;
    const string itemIndex = "  X0O+- ";

    // 스테이지, 맵에 대한 변수
    int ***stage, **map;

    // 게임에 대한 변수
    int dir, y, x,
        menuLastFocus, optLastFocus,
        level, speed, tcount,
        timeoutMs, msTime;
    const int speedMs[5] = {500, 250, 200, 100, 50},
              msDiv[5] = {2, 4, 5, 10, 20};

    // 사용 메뉴얼과 설정에 대한 변수
    string manualTitle, menuTitle, shorTitle;
    string menuTxt[4], shorTxt[9];
    int sizeY, sizeX,
        startY, startX;
    int desSizeY, desSizeX,
        desStartY, desStartX;
    int txtLines, hidTxtLen, scrollBarLen;

    vector<string> manualTxt;

    vector<pair<int, int> > itemPos, gatePos;
    bool chkEnter, finish;
};
#endif