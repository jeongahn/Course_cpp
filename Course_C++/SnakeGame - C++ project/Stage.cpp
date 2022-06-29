#include "Stage.h"

Stage::Stage()
{
    srand((unsigned)time(0));
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();

    start_color();
    
    init_pair(EMPTY, COLOR_WHITE, COLOR_BLACK);          //0(게임이 진행되는 공간, 맵의 내부)
    init_pair(WALL, COLOR_BLACK, COLOR_WHITE);           //1(WALL)
    init_pair(IMMUNE_WALL, COLOR_BLACK, COLOR_WHITE);    //2(IMMUNE WALL)
    init_pair(SNAKE_HEAD, COLOR_RED, COLOR_RED);     //3(SNAKE HEAD)
    init_pair(SNAKE_BODY, COLOR_GREEN, COLOR_GREEN);     //4(SNAKE BODY)
    init_pair(GROWTH_ITEM, COLOR_WHITE, COLOR_GREEN);   //5(성장 아이템)
    init_pair(POISON_ITEM, COLOR_WHITE, COLOR_RED);     //6(독 아이템)
    init_pair(GATE, COLOR_CYAN, COLOR_CYAN);             //7(GATE)
    init_pair(10, COLOR_GREEN, COLOR_BLACK);             //10(TITLE/SCROLL/BOARD)
    init_pair(11, COLOR_BLACK, COLOR_WHITE);             //11(FOCUS)
    init_pair(12, COLOR_RED, COLOR_BLACK);               //12(OPTION)

    menuLastFocus = 0,
    speed = 4,
    optLastFocus = speed - 1,
    tcount = 0;
    manualTitle = "< MANUAL >",
    menuTitle = "< MENU >",
    menuTxt[0] = " - PLAY: Start the game",
    menuTxt[1] = " - HELP: Manual of the game",
    menuTxt[2] = " - OPTION: Setting of the game",
    menuTxt[3] = " - EXIT: Exit the game";
    shorTitle = "< HOW TO >";
    shorTxt[0] = " - Press up(^): MOVE UP",
    shorTxt[1] = " - Press down(v): MOVE DOWN",
    shorTxt[2] = " - Press left(<): MOVE LEFT",
    shorTxt[3] = " - Press right(>): MOVE RIGHT",
    shorTxt[4] = " - 'p': GAME PAUSE",
    shorTxt[5] = " - 'r': GAME RESUME",
    shorTxt[6] = " - 'esc': BACK TO THE MAIN MENU";
}

Stage::~Stage()
{
    delwin(scrollBar);
    delwin(description);
    delwin(manual);
    delwin(info);
    delwin(mission);
    delwin(score);
    delwin(game);
    endwin();
}

void Stage::screenLock()
{
    cout << "\e[3;240;120t";
    cout << "\e[8;40;120t";
    system("resize -s 40 120");
    y = 40, x = 120;
    mvprintw(y - 1, 0, "C++ Project SnakeGame");
    sizeY = y / 1.5,
    sizeX = x / 1.5,
    startY = y / 2 - sizeY / 2,
    startX = x / 2 - sizeX / 2,
    desSizeY = sizeY - 6,
    desSizeX = sizeX - 6,
    desStartY = startY + 3,
    desStartX = startX + 3,
    txtLines = 26,
    hidTxtLen = txtLines - desSizeY > 0 ? txtLines - desSizeY : 0,
    scrollBarLen = desSizeY - hidTxtLen;
}

string Stage::menu()
{
    clear();
    screenLock();
    curs_set(0);
    string txt[5];
    txt[0] = "[ PROJECT : SNAKE  ]";
    int focus = menuLastFocus;
    level = 0;
    while (1)
    {
        if (!focus)
            focus = 300;
        txt[1] = "PLAY";
        txt[2] = "HELP";
        txt[3] = "OPTION";
        txt[4] = "EXIT";
        attron(COLOR_PAIR(10));
        mvprintw(y / 2 - 2, x / 2 - txt[0].length() / 2, txt[0].c_str());
        attroff(COLOR_PAIR(10));
        for (int i = 1; i <= sizeof(txt) / sizeof(txt[0]); i++)
        {
            if (i == abs(focus % 4 + 1))
            {
                attron(COLOR_PAIR(11));
                mvprintw(y / 2 + i, x / 2 - (txt[i].length() / 2), txt[i].c_str());
                attroff(COLOR_PAIR(11));
            }
            else
                mvprintw(y / 2 + i, x / 2 - (txt[i].length() / 2), txt[i].c_str());
        }
        switch (getch())
        {
        case UP:
            focus--;
            break;
        case DOWN:
            focus++;
            break;
        case ENTER:
            menuLastFocus = focus;
            return txt[abs(focus % 4 + 1)];
        }
    }
    return NULL;
}

void Stage::play()
{
    screenLock();
    setMap();
    int n;
    timeoutMs = speedMs[speed - 1];
    for (int i = 0; i < STAGE_NUM; i++)
    {
        msTime = n = 0;
        dir = LEFT;
        copyMap(i);
        setMission();
        makeSnake(); 
        appearGate(); 

        drawMap();
        while (1)
        {
            switch (getch())
            {
            case LEFT:
                if (dir != RIGHT)
                    dir = LEFT;
                else gameOver();
                break;
            case UP:
                if (dir != DOWN)
                    dir = UP;
                else gameOver();
                break;
            case RIGHT:
                if (dir != LEFT)
                    dir = RIGHT;
                else gameOver();
                break;
            case DOWN:
                if (dir != UP)
                    dir = DOWN;
                else gameOver();
                break;
            case PAUSE:
                alert(y / 2 - 4, x / 2 - 34, "Press 'r' to replay!", TRUE);
                while (1)
                {
                    if (getch() == RESUME)
                        break;
                }
                break;
            case ESC:
                endwin();
                return;
            case SKIP:
                for(int i=0;i<4;i++){
                    stat[i] = statMission[i];
                }
            }
            moveSnake();
            if (chkEnter) // 게이트를 통과한 후 행동
            {
                if (++n >= stat[0]) //  뱀의 꼬리까지 게이트를 다 통과했다면, 게이트 재생성
                {
                    disappearGate();
                    appearGate();
                    n = 0;
                    chkEnter = FALSE;
                }
            }
            if (++msTime % (msDiv[speed - 1] * 5) == 0) // 5초마다 아이템 위치 변경
            {
                disappearItem();
                appearItem();
            }
            if (stat[0] < 3) // 뱀의 길이가 3보다 작아지면 게임이 종료된다.
                gameOver();
            if (isMissionClear())
            {
                alert(y / 2 - 4, x / 2 - 27, "Stage Clear!", FALSE);
                break;
            }
            if (checkGameOver())
            {
                alert(y / 2 - 4, x / 2 - 25, "Game Over!", FALSE);
                return;
            }
            drawMap();
            timeout(timeoutMs);
        }
        level++;
    }
    endwin();
}

void Stage::help()
{
    screenLock();
    int ySize = 0, yScroll = 0;
    while (1)
    {
        manual = newwin(sizeY, sizeX, startY, startX);
        description = newwin(desSizeY, desSizeX, desStartY, desStartX);
        scrollBar = newwin(scrollBarLen, 2, desStartY + yScroll, startX + sizeX - 5);
        wattron(manual, COLOR_PAIR(10));
        box(manual, 0, 0);
        mvwprintw(manual, 0, sizeX / 2 - manualTitle.length() / 2, "%s", manualTitle.c_str());
        wattroff(manual, COLOR_PAIR(10));

        mvwprintw(description, 0 + ySize,
                  sizeX / 2 - menuTitle.length() / 2 - 3, "%s", menuTitle.c_str());
        for (int i = 0; i < sizeof(menuTxt) / sizeof(menuTxt[0]); i++)
            mvwprintw(description, 2 + (i * 2) + ySize, sizeX / 2 - menuTxt[2].length() / 2 - 3, "%s", menuTxt[i].c_str());

        mvwprintw(description, 11 + ySize,
                  sizeX / 2 - shorTitle.length() / 2 - 3, "%s", shorTitle.c_str());
        for (int i = 0; i < sizeof(shorTxt) / sizeof(shorTxt[0]); i++)
            mvwprintw(description, 13 + (i * 2) + ySize, sizeX / 2 - shorTxt[6].length() / 2 - 3, "%s", shorTxt[i].c_str());

        if (txtLines >= desSizeY)
        {
            wattron(scrollBar, COLOR_PAIR(10));
            box(scrollBar, 0, 0);
            wattroff(scrollBar, COLOR_PAIR(10));
        }
        refresh();
        wrefresh(manual);
        wrefresh(description);
        wrefresh(scrollBar);
    RE:
        switch (getch())
        {
        case UP:
            if (yScroll)
                yScroll--;
            else
                goto RE;
            if (ySize)
                ySize++;
            break;
        case DOWN:
            if (yScroll < desSizeY - scrollBarLen)
                yScroll++;
            else
                goto RE;
            if (ySize > desSizeY - txtLines && txtLines > desSizeY)
                ySize--;
            break;
        case ESC:
            return;
        }
    }
}

void Stage::option()
{
    clear();
    screenLock();
    string optTitle = "[ OPTION ]";
    string txt[5];
    string optTxt[2];
    optTxt[0] = "SPEED:";
    optTxt[1] = " SLOW <--> FAST ";
    int focus = optLastFocus;
    level = 0;
    while (1)
    {
        if (!focus)
            focus = 500;
        for (int i = 0; i < sizeof(txt) / sizeof(txt[0]); i++)
            txt[i] = to_string(i + 1);

        attron(COLOR_PAIR(10));
        mvprintw(y / 2 - 2, x / 2 - optTitle.length() / 2, optTitle.c_str());
        attroff(COLOR_PAIR(10));
        for (int i = 0; i < sizeof(txt) / sizeof(txt[0]); i++)
        {
            if (i == abs(focus % 5))
            {
                attron(COLOR_PAIR(12));
                mvprintw(y / 2, x / 2 - sizeof(txt) / sizeof(txt[0]) + i * 3 - 1, txt[i].c_str());
                attroff(COLOR_PAIR(12));
            }
            else
                mvprintw(y / 2, x / 2 - sizeof(txt) / sizeof(txt[0]) + i * 3 - 1, txt[i].c_str());
        }

        mvprintw(y / 2 + 2, x / 2 - optTxt[1].length() / 2 + 1, optTxt[1].c_str());

        optLastFocus = focus;
        speed = atoi(txt[abs(focus % 5)].c_str());
        switch (getch())
        {
        case LEFT:
            focus--;
            break;
        case RIGHT:
            focus++;
            break;
        case ESC:
            return;
        }
    }
}

void Stage::setMap()
{
    int i, j, k;
    stage = new int **[STAGE_NUM];
    for (i = 0; i < STAGE_NUM; i++)
    {
        stage[i] = new int *[MAP_ROW];
        for (j = 0; j < MAP_ROW; j++)
        {
            stage[i][j] = new int[MAP_COL];
        }
    }

    for (i = 0; i < STAGE_NUM; i++)
    {
        for (j = 0; j < MAP_ROW; j++)
        {
            for (k = 0; k < MAP_COL; k++)
            {
                if (j==0 || k==0 || j == ROW_END || k == COL_END)
                    stage[i][j][k] = WALL;
                else
                    stage[i][j][k] = EMPTY;
            }
        }
        stage[i][0][0] = IMMUNE_WALL;
        stage[i][0][COL_END] = IMMUNE_WALL;
        stage[i][ROW_END][0] = IMMUNE_WALL;
        stage[i][ROW_END][COL_END] = IMMUNE_WALL;
        if (i == 1)
        {
            for (int z = 10; z < 40; z++){
                if(18<=z and z<= 30){ continue; }
                stage[i][7][z] = WALL;
            }
            for (int z = 10; z < 40; z++)
                stage[i][MAP_ROW - 7][z] = WALL;
        }
        if (i == 2)
        {
            for (int z = 5; z < 20; z++)
                stage[i][z][MAP_COL - 15] = WALL;
            for (int z = 5; z < 20; z++)
                stage[i][z][15] = WALL;
            for(int z=30 ; z<35 ; z++)
                stage[i][10][z] = WALL;
            for(int z=15 ; z<20 ; z++)
                stage[i][15][z] = WALL;
        }
        if (i == 3)
        {
            for (int z = 10; z < 40; z++)
            {
                if (z > 22 && z < 27) 
                    continue;
                stage[i][7][z] = WALL; 
            }
            for (int z = 5; z < 10; z++){
                stage[i][z][MAP_COL - 15] = WALL;
                if (stage[i][7][MAP_COL - 15] == WALL)
                    stage[i][7][MAP_COL - 15] = IMMUNE_WALL;
            }
            
            for (int z = 5; z < 10; z++){
                stage[i][z][15] = WALL;
                if (stage[i][7][15] == WALL)
                    stage[i][7][15] = IMMUNE_WALL;
            }
            for (int z = 10; z < 40; z++)
                stage[i][MAP_ROW - 7][z] = WALL;
        }
        if (i == 4)
        {
            for (int z = 10; z < 40; z++)
            {
                if (z > 22 && z < 27)
                    continue;
                stage[i][7][z] = WALL;
            }
            for (int z = 10; z < 40; z++)
            {
                if (z > 22 && z < 27)
                    continue;
                stage[i][MAP_ROW - 7][z] = WALL;
            }
            for (int z = 5; z < 20; z++)
            {
                if (z > 10 && z < 14)
                    continue;
                if (stage[i][z][MAP_COL - 15] == WALL)
                    stage[i][z][MAP_COL - 15] = IMMUNE_WALL;
                else
                    stage[i][z][MAP_COL - 15] = WALL;
            }
            for (int z = 5; z < 20; z++)
            {
                if (z > 10 && z < 14)
                    continue;
                if (stage[i][z][15] == WALL)
                    stage[i][z][15] = IMMUNE_WALL;
                else
                    stage[i][z][15] = WALL;
            }
        }
    }
}

void Stage::copyMap(int nStage)
{
    map = new int *[MAP_ROW];
    for (int i = 0; i < MAP_COL; i++)
        map[i] = new int[MAP_COL];
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
            map[i][j] = stage[nStage][i][j];
    }
}

void Stage::drawMap()
{
    game = newwin(MAP_ROW, MAP_COL,
                  y / 2 - MAP_ROW / 2, x / 2 - (MAP_COL / 2 + 16));
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            int index = map[i][j];
            wattron(game, COLOR_PAIR(index));
            mvwaddch(game, i, j, itemIndex[index]);
            wattroff(game, COLOR_PAIR(index));
        }
        printw("\n");
    }

    score = newwin(16, 30, y / 2 - (MAP_ROW / 2 + 4), x / 2 + MAP_COL / 2 - 7.4);
    wattron(score, COLOR_PAIR(10));
    box(score, 0, 0);
    mvwprintw(score, 0, 10, "[ SCORE ]");
    wattroff(score, COLOR_PAIR(10));
    mvwprintw(score, 3, 5, "B: %d / %d", stat[0], SNAKE_MAX_LENGTH);
    mvwprintw(score, 6, 5, "+: %d", stat[1]);
    mvwprintw(score, 9, 5, "-: %d", stat[2]);
    mvwprintw(score, 12, 5, "G: %d", stat[3]);

    mission = newwin(16, 30, y / 2 - (MAP_ROW / 2 + 4) + 17, x / 2 + MAP_COL / 2 - 7.4);
    wattron(mission, COLOR_PAIR(10));
    box(mission, 0, 0);
    mvwprintw(mission, 0, 9, "[ MISSION ]");
    wattroff(mission, COLOR_PAIR(10));
    mvwprintw(mission, 3, 5, "B: %d ( %c )", statMission[0], chkMission[0]);
    mvwprintw(mission, 6, 5, "+: %d ( %c )", statMission[1], chkMission[1]);
    mvwprintw(mission, 9, 5, "-: %d ( %c )", statMission[2], chkMission[2]);
    mvwprintw(mission, 12, 5, "G: %d ( %c )", statMission[3], chkMission[3]);

    info = newwin(4, 15, y / 2 - (MAP_ROW / 2 + 4), x / 2 + MAP_COL / 2 - 47.4);
    mvwprintw(info, 0, 1, "[ STAGE %d/%d ]", level + 1, STAGE_NUM);
    mvwprintw(info, 2, 3, "< %02d:%02d >", msTime / (msDiv[speed - 1] * 60), (msTime / msDiv[speed - 1]) % 60);

    refresh();
    wrefresh(info);
    wrefresh(game);
    wrefresh(score);
    wrefresh(mission);
}

void Stage::appearItem()
{
    int appearNum = rand() % 3 + 1;
    for (int i = 0; i < appearNum; i++)
    {
        int itemType = rand() % 2 + GROWTH_ITEM;
        if (chkMission[2] == 'v')
            itemType = GROWTH_ITEM;
        else if (stat[0] >= SNAKE_MAX_LENGTH)
            itemType = POISON_ITEM;
        while (1)
        {
            int y = rand() % (MAP_ROW - 2) + 1;
            int x = rand() % (MAP_COL - 2) + 1;
            if (map[y][x] == EMPTY &&
                map[y][x - 1] != GATE && map[y][x + 1] != GATE &&
                map[y + 1][x] != GATE && map[y - 1][x] != GATE)
            {
                map[y][x] = itemType;
                itemPos.push_back(make_pair(y, x));
                break;
            }
        }
    }
}

void Stage::appearGate()
{
    int n, y, x;
    for (int i = 0; i < 2; i++)
    {
        while (1)
        {
            n = rand() % (!level ? 4 : 5);
            y = rand() % (MAP_ROW - (i?3:2)) + (i?2:1);
            x = rand() % (MAP_COL - (i?3:2)) + (i?2:1);
            switch (n)
            {
            case 0: // 위쪽 벽
                y = 0;
                break;
            case 1: // 왼쪽 벽
                x = 0;
                break;
            case 2: // 오른쪽 벽
                x = COL_END;
                break;
            case 3: // 아래쪽 벽
                y = ROW_END;
                break;
            case 4: // 맵의 테두리가 아닌 맵 중간에 생기는 벽
                while (1)
                {
                    x = rand() % 30 + 10;
                    y = rand() % 15 + 5;
                    if (map[y][x] == WALL)
                        break;
                }
            }
            if (map[y][x] == WALL)
            {
                map[y][x] = GATE;
                gatePos.push_back(make_pair(y, x));
                break;
            }
        }
        if (i == 0)
            gate1 = new Something(y, x, GATE);
        if (i == 1)
            gate2 = new Something(y, x, GATE);
    }
}

void Stage::disappearItem()
{
    for (auto item : itemPos)
    {
        if (map[item.first][item.second] == GROWTH_ITEM || map[item.first][item.second] == POISON_ITEM)
            map[item.first][item.second] = EMPTY;
    }
    itemPos.clear();
}

void Stage::disappearGate()
{
    for (auto gate : gatePos)
    {
        if(map[gate.first][gate.second] == GATE)
            map[gate.first][gate.second] = WALL;
    }
    gatePos.clear();
}