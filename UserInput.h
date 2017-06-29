/*******************************************************************/
/*!
@file   UserInput.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the UserInput class.
*/
/*******************************************************************/

#ifndef USERINPUTH
#define USERINPUTH

#include "Component.h"

namespace CS225 {

	///@addtogroup components Components
	///@{

	///@brief The UserInput component class 
	class UserInput: public Component {
	public:
		UserInput(void);
		virtual void update(void);
	};

	///@}
}

#endif
