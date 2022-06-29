#include <iostream>
#include "Stage.h"
using namespace std;

void Stage::makeSnake()
{
    stat[0] = 3;
    int row = 13;
    int col = 26;
    Bam = new Something(row, col--, SNAKE_BODY);
    Something *p = new Something(row, col--, SNAKE_BODY);
    Bam->link = p;
    p = new Something(row, col--, SNAKE_HEAD);
    Bam->link->link = p;
    map[Bam->y][Bam->x] = Bam->who;
    p = Bam->link;
    map[p->y][p->x] = p->who;
    p = p->link;
    map[p->y][p->x] = p->who;
}

void Stage::moveSnake()
{
    if (map[Bam->y][Bam->x] != WALL)
        map[Bam->y][Bam->x] = EMPTY;
    Something *q = Bam;
    Something *p = q->link;
    while (p->link != NULL)
    {
        q->x = p->x;
        q->y = p->y;
        q = p;
        p = p->link;
    }
    if (dir == LEFT)
    {
        map[p->y][p->x] = q->who;
        q->x = p->x;
        q->y = p->y;
        p->x--;
    }
    else if (dir == UP)
    {
        map[p->y][p->x] = q->who;
        q->x = p->x;
        q->y = p->y;
        p->y--;
    }
    else if (dir == RIGHT)
    {
        map[p->y][p->x] = q->who;
        q->x = p->x;
        q->y = p->y;
        p->x++;
    }
    else if (dir == DOWN)
    {
        map[p->y][p->x] = q->who;
        q->x = p->x;
        q->y = p->y;
        p->y++;
    }
    if (map[p->y][p->x] == WALL || map[p->y][p->x] == SNAKE_BODY)
    {
        map[p->y][p->x] = IMMUNE_WALL;
        gameOver();
    }
    if (map[p->y][p->x] == GATE)
    {
        enterGate(p);
    }
    if (map[p->y][p->x] == GROWTH_ITEM || map[p->y][p->x] == POISON_ITEM)
    {
        eatItem(map[p->y][p->x]);
    }
    map[p->y][p->x] = p->who;
}

void Stage::enterGate(Something *head)
{
    chkEnter = TRUE;
    if (gate1->x == head->x && gate1->y == head->y)
    {
        if (gate2->x == 0)
        {
            head->x = 1;
            head->y = gate2->y;
            dir = RIGHT;
        }
        else if (gate2->x == COL_END)
        {
            head->x = COL_END - 1;
            head->y = gate2->y;
            dir = LEFT;
        }
        else if (gate2->y == 0)
        {
            head->x = gate2->x;
            head->y = 1;
            dir = DOWN;
        }
        else if (gate2->y == ROW_END)
        {
            head->x = gate2->x;
            head->y = ROW_END - 1;
            dir = UP;
        }
        findRoot(gate2); // 게이트로 들어오는 방향에 따라서 나가는 방향 지정 
        if (dir == LEFT)
        {
            head->x = gate2->x - 1;
            head->y = gate2->y;
        }
        else if (dir == UP)
        {
            head->x = gate2->x;
            head->y = gate2->y - 1;
        }
        else if (dir == RIGHT)
        {
            head->x = gate2->x + 1;
            head->y = gate2->y;
        }
        else if (dir == DOWN)
        {
            head->x = gate2->x;
            head->y = gate2->y + 1;
        }
    }
    else if (gate2->x == head->x && gate2->y == head->y)
    {
        if (gate1->x == 0)
        {
            head->x = 1;
            head->y = gate1->y;
            dir = RIGHT;
        }
        else if (gate1->x == COL_END)
        {
            head->x = COL_END - 1;
            head->y = gate1->y;
            dir = LEFT;
        }
        else if (gate1->y == 0)
        {
            head->x = gate1->x;
            head->y = 1;
            dir = DOWN;
        }
        else if (gate1->y == ROW_END)
        {
            head->x = gate1->x;
            head->y = ROW_END - 1;
            dir = UP;
        }
        findRoot(gate1); // 게이트로 들어오는 방향에 따라서 나가는 방향 지정 
        if (dir == LEFT)
        {
            head->x = gate1->x - 1;
            head->y = gate1->y;
        }
        else if (dir == UP)
        {
            head->x = gate1->x;
            head->y = gate1->y - 1;
        }
        else if (dir == RIGHT)
        {
            head->x = gate1->x + 1;
            head->y = gate1->y;
        }
        else if (dir == DOWN)
        {
            head->x = gate1->x;
            head->y = gate1->y + 1;
        }
    }
    stat[3]++;
}

int Stage::findRoot(Something *gate)
{
    for (int i = 0; i < 4; i++)
    {
        if (dir == LEFT)
        {
            if (map[gate->y][gate->x - 1] == EMPTY)
                return dir;
            else
                dir = KEY_UP;
        }
        else if (dir == KEY_UP)
        {
            if (map[gate->y - 1][gate->x] == EMPTY)
                return dir;
            else
                dir = RIGHT;
        }
        else if (dir == RIGHT)
        {
            if (map[gate->y][gate->x + 1] == EMPTY)
                return dir;
            else
                dir = DOWN;
        }
        else if (dir == DOWN)
        {
            if (map[gate->y + 1][gate->x] == EMPTY)
                return dir;
            else
                dir = LEFT;
        }
    }
    return dir;
}

void Stage::eatItem(int item)
{
    if (item == GROWTH_ITEM)
    {
        if (stat[0] == 10)
            return;
        Something *p = new Something(Bam->y, Bam->x, SNAKE_BODY);
        if (Bam->x - Bam->link->x == 1)
            p->x++;
        else if (Bam->y - Bam->link->y == 1)
            p->y++;
        else if (Bam->x - Bam->link->x == -1)
            p->x--;
        else if (Bam->y - Bam->link->y == -1)
            p->y--;
        p->link = Bam;
        Bam = p;
        if (map[Bam->y][Bam->x] != WALL)
            map[Bam->y][Bam->x] = Bam->who;
        stat[0]++;
        stat[1]++;
    }
    else if (item == POISON_ITEM)
    {
        map[Bam->y][Bam->x] = EMPTY;
        Bam = Bam->link;
        stat[0]--;
        stat[2]++;
    }
}