/*******************************************************************/
/*!
@file   ScriptedAI.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the ScriptedAI class.
*/
/*******************************************************************/

#ifndef SCRIPTEDAIH
#define SCRIPTEDAIH

#include <vector>
#include <stdarg.h>
#include "AI.h"

namespace CS225 {

	///@addtogroup components Components
	///@{

	///@brief The ScriptedAI class
	///
	///Inherited from AI class.
	class ScriptedAI: public AI {
	public:
		ScriptedAI(const int &count, ...);
		//update() interface+implementation inherited from AI

	private:
		///The index of the current action to take.
		unsigned currActionIndex;

		//Inheritable interface (update() calls this and children can override but cannot directly access this)
		virtual Action getCurrAction(void);
	};

	///@}
}

#endif
