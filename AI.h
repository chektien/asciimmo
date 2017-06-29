/*******************************************************************/
/*!
@file   AI.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the AI class.
*/
/*******************************************************************/

#ifndef AIH
#define AIH

#include "Component.h"
#include <string>
#include <vector>

namespace CS225 {

  ///@addtogroup components Components
  ///@{
  
	///@brief The AI component class 
	///
	///(publicly inheritable: simple virtual)
	class AI: public Component {
	public:
		///The types of actions available
		enum Action {NORTH, SOUTH, EAST, WEST, MELEE, SHOOT, HEAL, NUM_ACTIONS};

		AI(const std::string &name);
    virtual ~AI(void);
		virtual void update(void);

	protected:
		///List of actions
		std::vector<Action> actions_;

    ///Inheritable interface to get action to be performed in current frame.
    ///Method update() calls this and children must provide implementation. No default supplied.
    ///In protected and not private because this method needs to be recursively propagated to children to override.
    ///@return Action to take
		virtual Action getCurrAction(void) = 0;
		
	};

  ///@}
}

#endif
