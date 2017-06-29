/*******************************************************************/
/*!
@file   RandomAI.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the RandomAI class.
*/
/*******************************************************************/

#ifndef RANDOMH
#define RANDOMH

#include <vector>
#include "AI.h"

namespace CS225 {

	///@addtogroup components Components
	///@{

	///@brief The RandomAI class
	///
	///Inherited from AI class.
	class RandomAI: public AI {
	public:
		RandomAI(void);
		//update() interface+implementation inherited from AI

	private:
		//Inheritable interface (update() calls this and children can override but cannot directly access this)
		virtual Action getCurrAction(void);
	};

	///@}
}

#endif
