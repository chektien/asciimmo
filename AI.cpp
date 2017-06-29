/*******************************************************************/
/*!
@file   AI.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the AI class.
*/
/*******************************************************************/

#include <iostream>
#include <string>
#include "AI.h"

namespace CS225 {

	/*******************************************************************/
	/*!
		@brief
		Constructor. Initializes with a component name.

		@param name
		The name of the component.
	*/
	/*******************************************************************/
	AI::AI(const std::string &name): Component(name) {}
  
	/*******************************************************************/
	/*!
		@brief
		Destructor.
	*/
	/*******************************************************************/
	AI::~AI(void) {}

	/*******************************************************************/
	/*!
		@brief
		Gets the current action to be performed.
	*/
	/*******************************************************************/
	void AI::update(void)  {
		if (debug_) std::cout << name_ << "::update" << std::endl;

		//Perform each action in the script
		std::cout << "Taking action ";
		switch(getCurrAction()) {
			case NORTH:
				std::cout << "NORTH";
				break;
			case SOUTH:
				std::cout << "SOUTH";
				break;
			case EAST:
				std::cout << "EAST";
				break;
			case WEST:
				std::cout << "WEST";
				break;
			case MELEE:
				std::cout << "MELEE";
				break;
			case SHOOT:
				std::cout << "SHOOT";
				break;
			case HEAL:
				std::cout << "HEAL";
				break;
			default:
				std::cout << "IDLE";
		}
		std::cout << std::endl;
	}
}
