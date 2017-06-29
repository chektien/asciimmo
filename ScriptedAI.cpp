/*******************************************************************/
/*!
@file   ScriptedAI.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the ScriptedAI class.
*/
/*******************************************************************/

#include <iostream>
#include <stdarg.h>
#include "ScriptedAI.h"

namespace CS225 {

	/*******************************************************************/
	/*!
		@brief
		Constructor. Populates the AI script. Initializes current action index.

		@param count
		Number of Action inputs.

		@param ...
		Variable number of MOVEMENT_ACTION inputs.
	*/
	/*******************************************************************/
	ScriptedAI::ScriptedAI(const int &count, ...): AI("ScriptedAI"), currActionIndex(0) {
		va_list script;
		va_start(script, count);
		for (int i=0; i<count; i++)
			actions_.push_back(static_cast<Action>(va_arg(script,/*Action*/int)));	//Using int type cos of the ... (to resolve gnu complaints)
		va_end(script);
	}

  /*******************************************************************/
  /*!
		@brief
     Gets the curr action. Just keeps getting the next one in order. 
		 Wraps back to 0 when reaches the end.
	
		@return
    The current action object.
  */
  /*******************************************************************/
	AI::Action ScriptedAI::getCurrAction() {
		// Wrap around to 1st action when reach the end
		if (currActionIndex == actions_.size())
			currActionIndex = 0;

		return actions_[currActionIndex++];			
	}

}