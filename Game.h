
// Created by andresold on 25.11.17.
//

#ifndef COM_3SEM_45LABANDREANDVIKA_GAME_H
#define COM_3SEM_45LABANDREANDVIKA_GAME_H

#include "list.h"

    enum Direction {
        Up, Right, Down, Left
    };

    class Game {
        int score, max_y, max_x, food_x, food_y;// direction, prev_dir;
        Direction direction, prev_dir;
        list l;
    public:
        Game() {
            score = max_y = max_x = food_x = food_y = 0;
            prev_dir = direction = Right;
        }

        void launch();

        void play();

        void map();

        void genFood();

        void setSnake();

        void moveSnake(Direction dir);

        bool checkForCollision();
    };



#endif //COM_3SEM_45LABANDREANDVIKA_GAME_H
