/*******************************************************************/
/*!
@file   Position.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  This is the position struct.
*/
/*******************************************************************/
#ifndef POSITIONH
#define POSITIONH

///To encapsulate our game.
namespace CS225 {

	///@brief The Position struct 
	///
	///Captures the (x,y[,z]) of the game object
	struct Position {
		///Ctor
		///
		///@param x_ x-axis position
		///@param y_ y-axis position
		///@param z_ z-axis position
		Position(const int &x_, const int &y_, const int &z_=0): x(x_), y(y_), z(z_) {}
	
		///Copy ctor
		///
		///@param rhs the Position to copy from
		Position(const Position &rhs): x(rhs.x), y(rhs.y), z(rhs.z) {}

		///The (x,y,z) of the game object
		int x, y, z;
	};

}

#endif
