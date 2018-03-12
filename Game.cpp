//
// Created by andresold on 25.11.17.
//
#ifndef COM_3SEM_45LABANDREANDVIKA_Game_H
#define COM_3SEM_45LABANDREANDVIKA_Game_H

#include<ncurses.h>
#include "Game.h"
#include<unistd.h>
#include "time.h"

void Game::launch() {
    initscr();
    cbreak();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    noecho();
    refresh();
    attron(A_BOLD);
    attrset (A_STANDOUT);
    mvprintw(LINES / 2 - 2, COLS / 2 - 10, "Andrey and Victoria welcome you");
    mvprintw(LINES / 2, COLS / 2 - 10, "Click on any button to continue");
    attrset (A_STANDOUT);
    int ch;
    getch();
    getmaxyx(stdscr, max_y, max_x);
    play();
    attroff(A_BOLD);
    endwin();
}

void Game::play() {
    start_color();
    genFood();
    setSnake();
    mvprintw(8, COLS / 2 - 20, "Are You READY??????????????");
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    attron(COLOR_PAIR(1));
    refresh();
    sleep(1);
    int ch = 0;
    timeout(85);
    while ((ch = getch()) != 'q') {
        switch (ch) {
            case KEY_UP:
                direction = Up;
                break;
            case KEY_DOWN:
                direction = Down;
                break;
            case KEY_RIGHT:
                direction = Right;
                break;
            case KEY_LEFT:
                direction = Left;
                break;
        }
        clear();
        map();
        mvprintw(food_y, food_x, " ");
        if (direction + 2 == prev_dir || prev_dir + 2 == direction)
            direction = prev_dir;
        moveSnake(direction);
        refresh();
        if (checkForCollision()) {
            clear();
            mvprintw(max_y / 2 - 2, max_x / 2 - 10, "GAME OVER");
            mvprintw(max_y / 2, max_x / 2 - 10, "YOUR SCORE %d", score);
            refresh();
            sleep(2);
            break;
        }
        prev_dir = direction;
    }
}

void Game::map() {
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    box(stdscr, 0, 0);
    mvprintw(1, 1, "SCORE: ");
    mvprintw(1, 8, "%d", score);
    mvprintw(2, 1, "Press q to quit");
    refresh();
}

void Game::genFood() {
    // srand((time(nullptr)));
    food_y = random() % (max_y - 6) + 4;
    food_x = random() % (max_x - 4) + 2;
}

void Game::setSnake() {
    clear();
    map();
    for (int i = 0; i < 8; i++) {
        CorSnake s((COLS / 2) - 8 + i, LINES / 2);
        l.add(s);
        mvprintw(s.getY(), s.getX(), "%c", s.getCh());
    }
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    attron(COLOR_PAIR(1));
    mvprintw(food_y, food_x, " ");
    refresh();
}

void Game::moveSnake(Direction dir) {
    CorSnake k;
    k = l.get(1);
    int x = k.getX(), y = k.getY();

    switch (dir) {
        case Up:
            y--;
            break;
        case Left:
            x--;
            break;
        case Down:
            y++;
            break;
        case Right:
            x++;
            break;
    }

    mvprintw(7, 1, "Coordinates of snakes x=%d, y= %d", x, y);
    CorSnake s(x, y);
    l.add(s);
    if (x == food_x && y == food_y) {
        score++;
        genFood();

        mvprintw(food_y, food_x, " ");
    } else
        l.remove();
    int len = l.listLength();
    for (int i = 1; i <= len; i++) {
        k = l.get(i);
        mvaddch(k.getY(), k.getX(), k.getCh());
        refresh();
    }
}

bool Game::checkForCollision() {
    bool collided = false;
    CorSnake s = l.get(1);
    int head_x = s.getX();
    int head_y = s.getY();
    if (head_x == max_x - 1 || head_y == 1 || head_x == 1 || head_y == max_y - 1)
        return true;
    else {
        int len = l.listLength();
        for (int i = 4; i < len; i++) {
            s = l.get(i);
            if (head_x == s.getX() && head_y == s.getY()) {
                collided = true;
                break;
            }
        }
        return collided;
    }
}

#endif COM_3SEM_45LABANDREANDVIKA_Game_H