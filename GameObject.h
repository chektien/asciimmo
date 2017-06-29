/*******************************************************************/
/*!
@file   GameObject.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the GameObject class.
*/
/*******************************************************************/

#ifndef GAMEOBJECTH
#define GAMEOBJECTH

#include <list>
#include <string>
#include "Component.h"
#include "Position.h"

namespace CS225 {

  ///@addtogroup coreEngine Core Engine
  ///@{

  ///@brief The GameObject class.
	///@todo Ask should anyone inherit from this class?
	class GameObject {
	public:
		GameObject(const std::string &name, const int &x=0, const int &y=0, const float &direction=0.0f);
		~GameObject(void);
		void update(void);
		void addComponent(Component * const component);
		void removeComponent(Component * const component);
    Position& getPosition(void);
		void setPosition(Position& position);
    void toggleDebug(void);

	private:
    ///Debug flag.
    bool debug_;

		///Name of this game object
		std::string name_;

    ///Position(x,y) of the object game object
    Position position_;

    ///Direction that the game object is facing
    float direction_;
		
		///List of polymorphic components
		std::list<Component*> components_;

	};

  ///@}
}

#endif
