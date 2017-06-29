/*******************************************************************/
/*!
@file   GameEngine_.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  This is the heart of the engine represented by functors.
				Each functor is a part of a core engine implementation.
				Changes to each core algorithm need to be only performed here.
*/
/*******************************************************************/

#ifndef GAMEENGINEH
#define GAMEENGINEH

#include <iostream>
#include "Component.h"
#include "GameObject.h"
#include "IRenderable.h"
#include "ICollidable.h"

namespace CS225 {

	///@addtogroup engineFunctors Engine Functors
  ///@{

  ///@brief Functor to handle clean up in general.
	class Destroy {
	public:
		///Delete each component.
		///Simply delete each component.
		///@param component Pointer to the component to be deleted.
		void operator()(Component* component) {
			delete component;
		}

		///Delete each gameobject.
		///Simply delete each gameobject.
		///@param gameObject Pointer to the gameobject to be deleted.
		void operator()(GameObject* go) {
			delete go;
		}
	};

	///@brief Functor to update an object in general.
	class Update {
	public:
		///Update each gameobject.
		///Simply calls the update() method of each.
		///@param gameObject Pointer to the gameobject to be updated.
		void operator()(GameObject * const gameObject) {
			std::cout << std::endl;
			gameObject->update();
		}

		///Update each component.
		///Simply calls the update() method of each.
		///@param gameObject Pointer to the gameobject to be updated.
		void operator()(Component * const component) {
			component->update();
		}
	};

	///@brief Functor to implement rendering to screen.
	class Render {
	public:
		///Render each IRenderable object. 
		///Gets the renderable object and renders it on the screen.
		///@param iRenderable Pointer to the component object to be rendered.
		void operator()(const IRenderable * const iRenderable) {
			std::cout << std::endl;
			std::cout << iRenderable->getRenderable() << std::endl;
		}
	};

	///@brief Functor to implement collision detection.
	class Collision {
	public:
		///Resolve collisions between each collidable.
		///Gets the collision data from each object and perform collision resolution.
		///@param iCollidable Pointer to the collideable component to be checked.
		void operator()(const ICollidable * const iCollidable) {
			std::cout << "(" << (iCollidable->getCollidable()).x << "," << (iCollidable->getCollidable()).y << ") " ;
		}
	};

	///@}
}

#endif
