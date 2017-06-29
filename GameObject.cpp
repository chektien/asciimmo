/*******************************************************************/
/*!
@file   GameObject.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the GameObject class.
*/
/*******************************************************************/

#include <iostream>
#include <algorithm>
#include "GameObject.h"
#include "GameEngine_.h"

namespace CS225 {

	/*******************************************************************/
	/*!
		@brief
		Constructor. Simply initializes the id and name fields.

		@param name
	  The name of this object.
	
		@param x
		x position of the object.

		@param y
		y position of the object.

		@param direction
		Angle the object is facing.
	*/
	/*******************************************************************/
	GameObject::GameObject(const std::string &name, const int &x, const int &y, const float &direction)
		:debug_(false), name_(name), position_(x,y), direction_(direction) {}

  /*******************************************************************/
	/*!
		@brief
		Destructor. Need to delete the components as they only belong
    to this game object (composition). Note that however they are
    created (new) by the main Game class initialize() method.
	*/
	/*******************************************************************/
	GameObject::~GameObject(void) {
		std::for_each(components_.begin(), components_.end(), Destroy());
  }

	/*******************************************************************/
	/*!
		@brief
		Main gameloop calls this each frame. It basically calls updates 
		polymorphically on all the components.
	*/
	/*******************************************************************/
	void GameObject::update(void) {
	  if (debug_) std::cout << "GameObject{" << name_ << "}::update" << std::endl;
    std::cout << ">>> Updating " << name_ << " <<<" <<std::endl;

		std::for_each(components_.begin(), components_.end(), Update());
	}

	/*******************************************************************/
	/*!
		@brief
		Adds a component to the components_ list

		@param component
		The pointer to the component to be added.
	*/
	/*******************************************************************/
	void GameObject::addComponent(Component * const component) {
		components_.push_back(component);
    component->setOwner(this);
	}
	
	/*******************************************************************/
	/*!
		@brief
		Adds a component to the components_ list

		@param component
		The pointer to the component to be deleted.
	*/
	/*******************************************************************/
	void GameObject::removeComponent(Component * const component) {
		components_.remove(component);
	}

  /*******************************************************************/
	/*!
		@brief
		Gets the position of the game object.

		@return
		The position of the game object.
	*/
	/*******************************************************************/
  Position& GameObject::getPosition(void) {
    return position_;
  }

	/*******************************************************************/
	/*!
		@brief
		Sets the position of the game object.

		@param position
		The new position to set.
	*/
	/*******************************************************************/
  void GameObject::setPosition(Position& position) {
    position_ = position;
  }

  /*******************************************************************/
  /*!
		@brief
    Toggles debug on and off.
  */
  /*******************************************************************/
  void GameObject::toggleDebug(void) {
    if (debug_)
      debug_ = false;
    else
      debug_ = true;
    std::cout << "Debug for game object "<< name_ <<" is now " << debug_ << std::endl;
  }
}