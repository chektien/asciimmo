/*******************************************************************/
/*!
@file   RandomAI.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the RandomAI class.
*/
/*******************************************************************/

#include <iostream>
#include <cstdlib>
#include "RandomAI.h"

namespace CS225 {

	/*******************************************************************/
  /*!
		@brief
    Constructor. Populates the actions_ list with all the actions.
  */
  /*******************************************************************/
	RandomAI::RandomAI(void): AI("RandomAI") {
    actions_.push_back(AI::NORTH);
    actions_.push_back(AI::SOUTH);
    actions_.push_back(AI::EAST);
    actions_.push_back(AI::WEST);
    actions_.push_back(AI::MELEE);
    actions_.push_back(AI::SHOOT);
    actions_.push_back(AI::HEAL);
    /*for (AI::Action i=AI::NUM_ACTIONS; i>=0; --i)
      actions_.push_back(i);*/

		//To make consistent outputs
		std::srand(1);
	}

  /*******************************************************************/
  /*!
		@brief
    Re-defined from AI base. Gets the curr action. Just keeps getting 
    a random action.

    Students random should be the same output if left at default seed.
	
		@return
    The current action object.

		@todo
    Test the students on correct virtual call.

		@bug
    Students might not have same rand seed.
  */
  /*******************************************************************/
	AI::Action RandomAI::getCurrAction() {
    return actions_[std::rand()%AI::NUM_ACTIONS];			
	}

}
