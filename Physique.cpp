/*******************************************************************/
/*!
@file   Physique.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the Physique class.
*/
/*******************************************************************/

#include "Physique.h"
#include "Position.h"
#include "GameObject.h"

namespace CS225 {

  /*******************************************************************/
  /*!
		@brief
    Constructor. 
		Defines the physics of the component (used in collision checker).
		Position cannot be determined yet.

		@param boundType
    The type of bounding for collision checking.
  */
  /*******************************************************************/
  Physique::Physique(const BoundType &boundType)
		: Component("Physique"), myCollidable_(0,0,0), boundType_(boundType) {}

  /*******************************************************************/
  /*!
		@brief
    The re-defined update() function inherited from Component.
    Inline function.
  */
  /*******************************************************************/
  void Physique::update(void) {
    if (debug_) std::cout << name_ << "::update" << std::endl;
    std::cout << "Doing changes to the physique..." << std::endl;
  }

  /*******************************************************************/
  /*!
		@brief
    Gets a physical object that the physics engine can process.

		@return
    An object for the physics engine to process.
  */
  /*******************************************************************/
  const Position& Physique::getCollidable(void) const {
    myCollidable_ = owner_->getPosition();
    return myCollidable_;
  }
}