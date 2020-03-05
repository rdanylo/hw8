//*******************************
//
//	Mitchell Bush
//
//	CS2401
//
//	Dolan 
//
//*******************************

#ifndef OTHELLO_H
#define OTHELLO_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include "game.h"
#include "colors.h"

	class spaces
	{
	public:
		void set_space(int tmp){
			space = tmp;
		}
		
		int get_space()const{
			return space;
		}
		void flip(){
			if(space == 1){
				space = 2;
			}else if(space == 2){
				space = 1; 
			}else{
				cout << "there is a major error somewhere" << endl;
			}
		}

	private:
		//0 = empty
		//1 = red
		//2 = white 
		int space; 
	};


	class Othello : public main_savitch_14::game
	{
	public:
		Othello(){     
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				board[i][j].set_space(0);
			}
		} 
			board[3][3].set_space(2);
			board[3][4].set_space(1);            
			board[4][4].set_space(2);
			board[4][3].set_space(1);
		}

		//stage 1
		void display_status()const;

		void make_move(const string& move);

		bool is_legal(const string& move)const;

		//later stages
		game* clone()const;     
		void compute_moves(queue<string>& moves)const;   
		int evaluate()const;
		bool is_game_over()const;
		who winning()const;
		


	private:

	spaces board[8][8];

	};



#endif