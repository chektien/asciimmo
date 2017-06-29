/*******************************************************************/
/*!
@file   Chaser.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the Chaser class.
*/
/*******************************************************************/

#ifndef CHASERH
#define CHASERH

#include "Component.h"

namespace CS225 {

  ///@addtogroup components Components
  ///@{

	///@brief The Chaser component class 
	///
	///(publicly inheritable: simple virtual)
	class Chaser: public Component {
	public:
		Chaser(GameObject * const target);
		virtual void update(void);

	private:
    ///The target to chase after.
		GameObject *target_;
	};

  ///@}
}

#endif
