//Header file for the othello child class. Derived from the game
//  class.
//Richard Danylo Summer 2019

#ifndef OTHELLO_H
#define OTHELLO_H
#include "game.h"
#include "space.h"
#include <iostream>

class othello : public main_savitch_14::game {
    private:
        space board[8][8];
    
    public:
        othello() {
            board[3][3].set(2);
            board[3][4].set(1);
            board[4][3].set(1);
            board[4][4].set(2);
        };
        void display_board() const;
        game* clone() const;
        void compute_moves(queue<string>& moves) const;
        void display_status() const;
        int evaluate() const;
        bool is_game_over() const;
        bool is_legal(const string& move) const;
        void make_move(const std::string& move);
        string get_user_move() const;
        who winning() const;
};

#endif