//**********************************************
//
//	Mitchell Bush
//
//	Dolan 
//
//	CS2401
//
//**********************************************


#include "othello.h"
#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include "game.h"
#include "colors.h"
	

using namespace std;

	void Othello::display_status()const{           //prints current state of the board 
			cout << BLUE << " A B C D E F G H" << endl;
			cout << BLUE << "________________" << endl;
			for(int i = 0; i <= 7; i++){
					for(int j = 0; j <= 7; j++){
					
						if(board[i][j].get_space() == 0){
							cout << BLUE << "|" << " "; 
						}
						if(board[i][j].get_space() == 2){
							cout << BLUE << "|" << WHITE << "X"; 
						}
						if(board[i][j].get_space() == 1){
							cout << BLUE << "|" << RED << "O"; 
						}
					}
				cout << "| " << BLUE << i+1;
				cout << WHITE << endl;
			}
	}

	void Othello::make_move(const string& move){
			int attacker, defender; 

				if(main_savitch_14::game::last_mover() == COMPUTER){
					attacker = 1;
					defender = 2;
				}else{
					attacker = 2;
					defender = 1; 
				}
				if(move == "pass"){
					cout << "there are no valid moves: must pass" << endl;
					main_savitch_14::game::make_move(move);	
				}else{
					int column =  move[0]-'A';                      //converts move to an index
					int row = move[1]-49;

					int up_left = board[row-1][column-1].get_space();
					int up = board[row-1][column].get_space(); 
					int up_right = board[row-1][column+1].get_space(); 
					int right = board[row][column+1].get_space(); 
					int down_right = board[row+1][column+1].get_space();  //immediate surroundings 
					int down = board[row+1][column].get_space(); 
					int down_left = board[row+1][column-1].get_space(); 
					int left = board[row][column-1].get_space(); 
					board[row][column].set_space(attacker);


					if(up == defender){
						for(int i = row-1; i >= 0; i--){
							if(board[i][column].get_space() == attacker){  //terrible time performance
								for(int j=i; j<row; j++){
									board[j][column].set_space(attacker);  //flips all sandwiched pebbles
								}
							}
						}
					}
					if(down == defender){
						for(int i = row+1; i <= 8; i++){
							if(board[i][column].get_space() == attacker){
								for(int j=i; j>row; j--){
									board[j][column].set_space(attacker);
								}
							}
						}
					}
					if(right == defender){
						for(int i = column+1; i <= 8; i++){
							if(board[row][i].get_space() == attacker){
								for(int j=i; j>column; j--){
									board[row][j].set_space(attacker);
								}
							}
						}
					}
					if(left == defender){
						for(int i = column-1; i >= 0; i--){
							if(board[row][i].get_space() == attacker){
								for(int j=i; j<column; j++){
									board[row][j].set_space(attacker);
								}
							}
						}
					}
					if(up_left == defender){
						for(int i = row-1, j = column-1; i >= 0 && j >= 0; i--, j--){
							if(board[i][j].get_space() == attacker){
								for(int ii = i, jj = j; ii<row && jj<column; ii++, jj++){
									board[ii][jj].set_space(attacker);
								}
							}
						}
					}
					if(up_right == defender){
						for(int i = row-1, j = column+1; i >= 0 && j <= 8; i--, j++){
							if(board[i][j].get_space() == attacker){
								for(int ii = i, jj = j; ii<row && jj>column; ii++, jj--){
									board[ii][jj].set_space(attacker);
								}
							}
						}
					}
					if(down_left == defender){
						for(int i = row+1, j = column-1; i <= 8 && j >= 0; i++, j--){
							if(board[i][j].get_space() == attacker){
								for(int ii = i, jj = j; ii>row && jj<column; ii--, jj++){
									board[ii][jj].set_space(attacker);
								}
							}
						}
					}
					if(down_right == defender){
						for(int i = row+1, j = column+1; i <= 8 && j <= 8; i++, j++){
							if(board[i][j].get_space() == attacker){
								for(int ii = i, jj = j; ii>row && jj>column; ii--, jj--){
									board[ii][jj].set_space(attacker);
								}
							}
						}
					}
					main_savitch_14::game::make_move(move);


				}
	
	}
	bool Othello::is_legal(const string& move)const{  //check 
				int attacker, defender; 
				if(main_savitch_14::game::last_mover() == COMPUTER){
					attacker = 1;
					defender = 2;
				}else{
					attacker = 2;                       //recognizing who will be flipping who with this move
					defender = 1; 
				}
				if(move.empty()){
					return false;
				}else if(move == "pass"){
					return true;
				}
				int row = (move[1])-49;
				int column = move[0]-'A';
				if(board[row][column].get_space() != 0){
					return false;
				}

					int up_left = board[row-1][column-1].get_space();
					int up = board[row-1][column].get_space(); 
					int up_right = board[row-1][column+1].get_space();       //getting all spaces in the immediate surroundings 
					int right = board[row][column+1].get_space(); 
					int down_right = board[row+1][column+1].get_space(); 
					int down = board[row+1][column].get_space(); 
					int down_left = board[row+1][column-1].get_space(); 
					int left = board[row][column-1].get_space();
					
					if(up == defender){                                   
						for(int i=row-1; i>=0; i--){
							if(board[i][column].get_space() == attacker){
								return true;
							}
						}
					}
					if(down == defender){
						for(int i=row+1; i<=8; i++){
							if(board[i][column].get_space() == attacker){
								return true;
							}
						}
					}
					if(right == defender){
						for(int i=column+1; i<=8; i++){
							if(board[row][i].get_space() == attacker){
								return true;
							}
						}
					}
					if(left == defender){
						for(int i=column-1; i>=0; i--){                     //travels each direction seeing is it sandwiches the opponent
							if(board[row][i].get_space() == attacker){
								return true;
							}
						}
					}
					if(up_right == defender){
						for(int i=column+1, j=row-1; i<=8 && j>=0; i++, j--){
							if(board[j][i].get_space() == attacker){
								return true;
							}
						}
					}
					if(up_left == defender){
						for(int i=column-1, j=row-1; i>=0 && j>=0; i--, j--){
							if(board[j][i].get_space() == attacker){
								return true;
							}
						}
					}
					if(down_right == defender){
						for(int i=column+1, j=row+1; i<=8 && j<=8; i++, j++){
							if(board[j][i].get_space() == attacker){
								return true;
							+}
						}
					}
					if(down_left == defender){
						for(int i=column-1, j=row+1; i>=0 && j<=8; i--, j++){
							if(board[j][i].get_space() == attacker){
								return true;
							}
						}
					}
					return false;

	}			
	

		//later stages
	main_savitch_14::game* Othello::clone()const{   //returns a clone of the board
		return new Othello(*this);
	}
	void Othello::compute_moves(queue<string>& moves)const{  //************************************************************

		string move;
		int moves_added = 0;
		for(char tmp = 'A'; tmp <= 'H'; tmp++){    //loop that test all possible indexes in written form
			for(int i=1; i<=8; i++){
				move+=tmp;
				move+=to_string(i);
				if(is_legal(move)==true){                //if the move is legal it is pushed onto a stack              
					moves.push(move);
					moves_added++;
				}
				move = "";
			}
		}
	}

	int Othello::evaluate()const{
		int white=0, red=0;


		for(int i=0; i<8; i++){           //counts the amount of white and red peices and subtracts them
			for(int j =0; j<8; j++){
				if(board[i][j].get_space()==1){
					red++;
				}else if(board[i][j].get_space()==2){
					white++;
				}
			}
		}


		int final_score = red-white;
		return final_score; 
	}

	bool Othello::is_game_over()const{
		int empty_spaces=0;
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				if(board[i][j].get_space()==0){      //tests if there are no more spaces
					empty_spaces++;
				}
			}
		}
		if(empty_spaces == 0){
			display_message("board is full");
			return true; 
		}
		static int no_moves;
		queue<string> moves;
		compute_moves(moves);
		if(moves.empty()){
			no_moves++;
			if(no_moves == 2){               //tests if there are any valid moves on the stack
				display_message("no valid moves left");
				return true; 
			}
			return false;
		}else{
			no_moves = 0;
			return false; 
		}
	} 
	main_savitch_14::game::who Othello::winning()const{
		
		int score = evaluate();
		if(score > 0){
			cout << "Red Wins!" << endl;              //returns who has the most peices
			return HUMAN; 
		}else if(score < 0){
			cout << "White Wins" << endl;
			return COMPUTER;
		}else{
			cout << "No winner" << endl; 
			return NEUTRAL; 
		}
	}




