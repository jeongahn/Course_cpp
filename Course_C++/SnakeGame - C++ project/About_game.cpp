#include <iostream>
#include "Stage.h"
using namespace std;

void Stage::setMission()
{
    finish = chkEnter = FALSE;
    memset(stat, 0, sizeof(stat));
    memset(statMission, 0, sizeof(statMission));
    memset(chkMission, ' ', sizeof(chkMission));

    // 미션 할당 및 미션숫자 범위 
    statMission[0] = rand() % 5 + 6; // SNAKE LENGTH: 6~10
    statMission[1] = rand() % 5 + 4; // INCREASE ITEM: 4~8
    statMission[2] = rand() % 4 + 3; // DECREASE ITEM: 3~6
    statMission[3] = rand() % 5 + 1; // GATE : 1~5
}

bool Stage::isMissionClear()
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (stat[i] >= statMission[i])
        {
            chkMission[i] = 'v';
            count++;
        }
        else if (!i)
            chkMission[i] = ' ';
    }
    if (count == 4)
        return TRUE;
    return FALSE;
}

void Stage::gameOver()
{
    finish = true;
}

void Stage::alert(int posY, int posX, const string msg, bool stopFlag)
{
    WINDOW *alert = newwin(7, msg.length() * 2, posY, posX);
    box(alert, 0, 0);
    wattron(alert, COLOR_PAIR(0));
    wbkgd(alert, COLOR_PAIR(2));
    mvwprintw(alert, 3, msg.length() / 2, msg.c_str());
    wrefresh(alert);
    if (!stopFlag)
        usleep(1750000);
}