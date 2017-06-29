/*******************************************************************/
/*!
@file   Physique.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the Physique class.
*/
/*******************************************************************/

#ifndef PHYSIQUEH
#define PHYSIQUEH

#include <iostream>
#include <string>
#include "Component.h"
#include "ICollidable.h"
#include "Position.h"

namespace CS225 {

  ///@addtogroup components Components
  ///@{

  ///@brief The Physique component class 
  class Physique: public Component, public ICollidable {
  public:
    ///The types of bounding for collision checking
    enum BoundType {BOX, SPHERE, MESH};

    /*///Encapsulates the information needed for collision
    struct CollisionInfo {
      Position position;
      BoundType boundType;
    };*/

    Physique(const BoundType &boundType=BOX);
    virtual void update(void);                          // Interface from Component
    virtual const Position& getCollidable(void) const;  // Interface from ICollidable

  private:
    ///Stores the physics information about this object
    mutable Position myCollidable_;

		///Stores the type of bounding volume used
		BoundType boundType_;
  };

  ///@}

}

#endif
