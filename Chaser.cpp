/*******************************************************************/
/*!
@file   Chaser.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the Chaser class.
*/
/*******************************************************************/

#include <iostream>
#include <string>
#include "GameObject.h"
#include "Chaser.h"

namespace CS225 {

	/*******************************************************************/
	/*!
		@brief
		Constructor. Initializes with a target to chase after.

		@param target
		The pointer to the target game object to chase after.
	*/
	/*******************************************************************/
	Chaser::Chaser(GameObject * const target)
		: Component("Chaser"), target_(target) {}

	/*******************************************************************/
	/*!
		@brief
		Here we set the current owner's position to match the target's.
	*/
	/*******************************************************************/
	void Chaser::update(void) {
		if (debug_) std::cout << name_ << "::update" << std::endl;
		std::cout << "Setting new position to target's position: " << "(" << target_->getPosition().x << "," << target_->getPosition().y << ")" << std::endl;
		owner_->setPosition(target_->getPosition());
	}

}
