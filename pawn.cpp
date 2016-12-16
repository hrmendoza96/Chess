#include "pawn.hpp"
#include "piece.hpp"
#include "position.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

Pawn::Pawn(char color, int x, int y):Piece(color,x,y){//constructor
	firstMove = true;
}
bool Pawn::isValidMove(Piece*** board, Position destiny){
	int diffY = abs(position.getY()-destiny.getY());
	if(color == 'N'){
		int diffX = position.getX()-destiny.getX();
		if((diffY==1&&diffX==0) || (diffY==2&&firstMove&&diffX==0)){ //primer movimiento o movimiento hacia adelante
			if(board[destiny.getY()][destiny.getX()] == NULL){ //agregar braquets
				firstMove=false; // el fisrtmove se declara false porque ya no puede volver a moverse 2 espacios despues de la primera vez
				return true;
			}else{
				return false;
			}

		}
		else if((diffY==1&&diffX==1)){
			if(board[destiny.getY()][destiny.getX()]->getColor() != color){//agregar braquets
				return true;
			}else{
				return false;
			}
		}
		else{
			return false;
		}
	} else if(color == 'B'){
		int diffX = destiny.getX()-position.getX();
		if((diffY==1&&diffX==0) || (diffY==2&&firstMove&&diffX==0)){ //primer movimiento o movimiento hacia adelante
			if(board[destiny.getY()][destiny.getX()] == NULL){
				firstMove=false; // el fisrtmove se declara false porque ya no puede volver a moverse 2 espacios despues de la primera vez
				return true;
			}else{
				return false;
			}
		}
		else if((diffY==1&&diffX==1)){
			if(board[destiny.getY()][destiny.getX()]->getColor() != color){//agregar braquets
				return true;
			}else{
				return false;
			}
		}
		else{
			return false;
		}
	}
}
bool Pawn::moveTo(Piece*** board, Position destiny){
	if(isValidMove(board,destiny)){
		board[position.getY()][position.getX()] = NULL;
		position = destiny;
		board[position.getY()][position.getX()] = this;
		return true;
	}
	else{
		cout << "Invalid move" << endl;
		return false;
	}
}
string Pawn::toString()const{
	stringstream ss;
	if (color == 'N'){
		ss << "P";
	}
	else{
		ss << "p";
	}
	return ss.str();
}
