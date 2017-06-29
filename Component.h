/*******************************************************************/
/*!
@file   Component.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the Component class.
*/
/*******************************************************************/

#ifndef COMPONENTH
#define COMPONENTH

#include <string>
//#include "GameObject.h"

namespace CS225 {

	///@addtogroup components Components
	///@{

	class GameObject;

	///@brief The Component 
	///
	///(is an ABC, no direct instantiation)
	///@todo Test the students on this instantiation.
	///@bug Doxygen BUG: you cannot add the word "class" after Component
	class Component {
	public:
		Component(const std::string &name);
		virtual ~Component(void); 
		//virtual void update(std::string str) {std::cout << "Component::update(str) " << str <<std::endl;}; // Purposely added to check overloaded inheriting
		virtual void update(void) = 0 /*{std::cout << "WOOHOO" <<std::endl;}*/ ; // TODO: Can make this non virtual non pure in SKELETON
		void setOwner(GameObject * const owner);
		void toggleDebug(void);

	protected:
		/// Debug flag.
		bool debug_;

		/// Name of component
		std::string name_;

		/// Pointer to owner (GameObject) of component
		GameObject* owner_;
	};

	///@}
}

#endif
