/*******************************************************************/
/*!
@file   Component.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the Component class.
*/
/*******************************************************************/

#include <iostream>
#include "Component.h"

namespace CS225 {

	/*******************************************************************/
  /*!
		@brief
    Constructor. Initializes the component with a name.

		@param owner
    The name string of this component.
  */
  /*******************************************************************/
	Component::Component(const std::string &name)
		:debug_(false), name_(name) {}

	/*******************************************************************/
  /*!
		@brief
		Destructor.
  */
  /*******************************************************************/
	Component::~Component(void) {}

  /*******************************************************************/
  /*!
		@brief
    Setting the owner of the component.

		@param owner
    The owner to set.
  */
  /*******************************************************************/
  void Component::setOwner(GameObject * const owner) {
    owner_ = owner;
  }

  /*******************************************************************/
  /*!
		@brief
    Gameobject calls this each frame. It basically polymorphically
    calls the correct update.

    @todo
    Make this a non-virtual class to test students.
  */
  /*******************************************************************/
  void Component::update(void) {
    if (debug_) std::cout << "Component{" << name_ << "}::update" << std::endl;
  }

  /*******************************************************************/
  /*!
		@brief
    Toggles debug on and off.
  */
  /*******************************************************************/
  void Component::toggleDebug(void) {
    if (debug_)
      debug_ = false;
    else
      debug_ = true;
    std::cout << "Debug for component "<< name_ <<" is now " << debug_ << std::endl;
  }
}