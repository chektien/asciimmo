/*******************************************************************/
/*!
@file   ICollidable.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the ICollidable class.
*/
/*******************************************************************/

#ifndef ICOLLIDABLEH
#define ICOLLIDABLEH

#include <string>
#include "Position.h"

namespace CS225 {

  ///@addtogroup engineInterfaces Engine Level Interfaces
  ///@{

  ///@brief The ICollidable protocol class.
	///
  ///Used by components that have collidable components.
  class ICollidable {
  public:
    ///Get a collidable object to let the collision engine process.
    ///
		///@return The collidable position.
    virtual const Position & getCollidable(void) const = 0;
  };

  ///@}

}

#endif
