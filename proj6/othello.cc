//Implementation file for the othello child class. Derived from the game
//  class.
//Richard Danylo Summer 2019

#include "game.h"
#include "space.h"
#include "othello.h"
#include "colors.h"
#include <iostream>
#include <string>
#include <cctype>

    
void othello::display_board() const {
    int n = 1;
    std::cout << B_GREEN << BLACK << "-----A---B---C---D---E---F---G---H---" << RESET << std::endl;
    for (int i = 0; i < 8; i++) 
    {
        std::cout << B_GREEN << BLACK << " " << n;
        for (int j = 0; j < 8; j++) 
        { 
            std::cout << B_GREEN << BLACK << " | ";
            board[i][j].display(std::cout);
        } 
        std::cout << BLACK << " | " << RESET << std::endl;
        std::cout << B_GREEN << BLACK << "-------------------------------------" << RESET << std::endl;
        ++n;
    }
    std::cout << std::endl;
}

main_savitch_14::game* othello::clone() const {
    return new othello(*this);
}

int othello::evaluate() const {
    int black=0,white=0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board[i][j].get()==1){
                black++;
            } else if (board[i][j].get()==2){
                white++;
            }
        }
    }
    int score = white-black;
    return score;
}

void othello::display_status() const {
    display_board();
}

bool othello::is_legal(const std::string& move) const {
    int op_color, color; //set player
    if (main_savitch_14::game::last_mover() == COMPUTER) {
        color = 1;
    } else {
        color = 2;
    }
    if (color == 1) {
        op_color = 2;
    } else {
        op_color = 1;
    }
    if (move.empty()) { //check if empty
        return false;
    } else if (move == "\u25CF") {
        return true;
    }
    int l = move[0]-'A'; //get move location as int
    int n = move[1]-'0'-1;
    if (board[n][l].get() != 0) {
        return false;
    }
    int up = board[n-1][l].get(); //get spaces around move
    int down = board[n+1][l].get();
    int right = board[n][l+1].get();
    int left = board[n][l-1].get();
    int up_right = board[n-1][l+1].get();
    int up_left = board[n-1][l-1].get();
    int down_right = board[n+1][l+1].get();
    int down_left = board[n+1][l-1].get();
    if (up == op_color) { //test up
        for (int i=n-1; i>=0; i--) {
            if (board[i][l].get() == color) {
                return true;
            }
        }
    }
    if (down == op_color) { //test down
        for (int i=n+1; i<=8; i++) {
            if (board[i][l].get() == color) {
                return true;
            }
        }
    }
    if (right == op_color) { //test right
        for (int i=l+1; i<=8; i++) {
            if (board[n][i].get() == color) {
                return true;
            }
        }
    }
    if (left == op_color) { //test left
        for (int i=l-1; i>=0; i--) {
            if (board[n][i].get() == color) {
                return true;
            }
        }
    }
    if (up_right == op_color) { //test up right
        for (int i=l+1, j=n-1; i<=8 && j>=0; i++, j--) {
            if (board[j][i].get() == color) {
                return true;
            }
        }
    }
    if (up_left == op_color) { //test up left
        for (int i=l-1, j=n-1; i>=0 && j>=0; i--, j--) {
            if (board[j][i].get() == color) {
                return true;
            }
        }
    }
    if (down_right == op_color) { //test down right
        for (int i=l+1, j=n+1; i<=8 && j<=8; i++, j++) {
            if (board[j][i].get() == color) {
                return true;
            }
        }
    }
    if (down_left == op_color) { //test down left
        for (int i=l-1, j=n+1; i>=0 && j<=8; i--, j++) {
            if (board[j][i].get() == color) {
                return true;
            }
        }
    }
    return false;
}

void othello::make_move(const std::string& move) {
    int op_color, color; //set player
    if (main_savitch_14::game::last_mover() == COMPUTER) {
        color = 1;
    } else {
        color = 2;
    }
    if (color == 1) {
        op_color = 2;
    } else {
        op_color = 1;
    }
    if (move == "\u25CF") {
        std::cout << "User has no valid move. Turn skipped." << std::endl;
        main_savitch_14::game::make_move(move);
    } else {
        int l = move[0]-'A'; //get move location as int
        int n = move[1]-'0'-1;
        int up = board[n-1][l].get(); //get spaces around move
        int down = board[n+1][l].get();
        int right = board[n][l+1].get();
        int left = board[n][l-1].get();
        int up_right = board[n-1][l+1].get();
        int up_left = board[n-1][l-1].get();
        int down_right = board[n+1][l+1].get();
        int down_left = board[n+1][l-1].get();
        board[n][l].set(color);
        if (up == op_color) { //change opposite up
            for (int i=n-1; i>=0; i--) {
                if (board[i][l].get() == color) {
                    for (int j=i; j<n; j++) {
                        board[j][l].set(color);
                    }
                }
            }
        }
        if (down == op_color) { //change opposite down
            for (int i=n+1; i<=8; i++) {
                if (board[i][l].get() == color) {
                    for (int j=i; j>n; j--) {
                        board[j][l].set(color);
                    }
                }
            }
        }
        if (right == op_color) { //change opposite right
            for (int i=l+1; i<=8; i++) {
                if (board[n][i].get() == color) {
                    for (int j=i; j>l; j--) {
                        board[n][j].set(color);
                    }
                }
            }
        }
        if (left == op_color) { //change opposite left
            for (int i=l-1; i>=0; i--) {
                if (board[n][i].get() == color) {
                    for (int j=i; j<l; j++) {
                        board[n][j].set(color);
                    }
                }
            }
        }
        if (up_right == op_color) { //change opposite up right
            for (int i=l+1, j=n-1; i<=8 && j>=0; i++, j--) {
                if (board[j][i].get() == color) {
                    for (int k=i, m=j; m<=n && k>=l; k--, m++) {
                        board[m][k].set(color);
                    }
                }
            }
        }
        if (up_left == op_color) { //change opposite up left
            for (int i=l-1, j=n-1; i>=0 && j>=0; i--, j--) {
                if (board[j][i].get() == color) {
                    for (int k=i, m=j; m<=n && k<=l; k++, m++) {
                        board[m][k].set(color);
                    }
                }
            }
        }
        if (down_right == op_color) { //change opposite down right
            for (int i=l+1, j=n+1; i<=8 && j<=8; i++, j++) {
                if (board[j][i].get() == color) {
                    for (int k=i, m=j; m>=n && k>=l; k--, m--) {
                        board[m][k].set(color);
                    }
                }
            }
        }
        if (down_left == op_color) { //change opposite down right
            for (int i=l-1, j=n+1; i>=0 && j<=8; i--, j++) {
                if (board[j][i].get() == color) {
                    for (int k=i, m=j; m>=n && k<=l; k++, m--) {
                        board[m][k].set(color);
                    }
                }
            }
        }
        main_savitch_14::game::make_move(move);
    }
}

std::string othello::get_user_move() const {
    std::queue<std::string> moves;
    compute_moves(moves);
    std::string answer;
    if (!moves.empty()) {
        display_message("Please enter a board coordinate (ex. A1): ");
        getline(cin, answer);
        answer[0]=toupper(answer[0]); //make upper case
        answer[1]=toupper(answer[1]);
        return answer;
    } else {
        answer = "\u25CF";
    }
    return answer;
}

bool othello::is_game_over() const {
    int blank_space=0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (board[i][j].get()==0) {
                blank_space++;
            }
        }
    }
    if (blank_space == 0) {
        display_message("Board filled. Game Over.\n");
        return true;
    }
    static int out_of_moves;
    std::queue<std::string> moves;
    compute_moves(moves);
    if (moves.empty()) {
        out_of_moves++;
        if (out_of_moves == 2) {
            display_message("No player has any valid moves. Game Over.\n");
            return true;
        }
        return false;
    } else {
        out_of_moves = 0;
        return false;
    }
}

void othello::compute_moves(std::queue<std::string>& moves) const {
    std::string move;
    for (char c = 'A'; c<='H'; c++) {
        for (int i = 1; i<=8; i++) {
            move+=c;
            move+=std::to_string(i);
            if (is_legal(move)) {
                moves.push(move);
            }
            move = "";
        }
    }
}

main_savitch_14::game::who othello::winning( ) const {
    int score = evaluate();
    if (score < 0) {
        std::cout << B_BLUE << BLINK << "BLACK WINS!" << RESET << std::endl;
        return HUMAN;
    } else if (score > 0) {
        std::cout << B_RED << BLINK << "WHITE WINS!" << RESET << std::endl;
        return COMPUTER;
    } else {
        std::cout << B_YELLOW << BLINK << "NO WINNER." << RESET << std::endl;
        return NEUTRAL;
    }
}
