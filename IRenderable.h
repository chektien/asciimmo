/*******************************************************************/
/*!
@file   IRenderable.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the IRenderable class.
*/
/*******************************************************************/

#ifndef IRENDERABLEH
#define IRENDERABLEH

#include <string>

namespace CS225 {

	///@addtogroup engineInterfaces Engine Level Interfaces
	///@{

	///@brief The IRenderable protocol class.
	///
	///Used by components that have displayable components.
	class IRenderable {
	public:
		///@brief  Get a renderable object to display on screen.
		///@return The renderable string.
		virtual const std::string & getRenderable(void) const = 0;
	};

	///@}
}

#endif
