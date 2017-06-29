/*******************************************************************/
/*!
@file   UserInput.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the UserInput class.
*/
/*******************************************************************/

#include <iostream>
#include "UserInput.h"

namespace CS225 {

	/*******************************************************************/
	/*!
		@brief
		Constructor.
	*/
	/*******************************************************************/
	UserInput::UserInput(void): Component("UserInput") {}

  /*******************************************************************/
  /*!
		@brief
    The re-defined update() function inherited from Component.
  */
  /*******************************************************************/
  void UserInput::update(void) {
    if (debug_) std::cout << name_ << "::update" << std::endl;
    std::cout << "Checking for user inputs..." << std::endl;
  }
} 