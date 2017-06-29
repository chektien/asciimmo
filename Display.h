/*******************************************************************/
/*!
@file   Display.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the Display class.
*/
/*******************************************************************/

#ifndef DISPLAYH
#define DISPLAYH

#include <iostream>
#include <string>
#include "Component.h"
#include "IRenderable.h"

namespace CS225 {

  ///@addtogroup components Components
  ///@{

  ///@brief The Display component class 
  ///
  ///(not meant to be inherited currently, cos no virtual ~)
  class Display: public Component, public IRenderable {
  public:
    ///The type of look to be rendered on screen
    enum LookType {C_BASIC, C_SPIKER, NOIDEA};

    Display(const LookType &lookType=NOIDEA);
    virtual void update(void);                            // Interface from Component
    virtual const std::string& getRenderable(void) const; // Interface from IRenderable

  private:
    ///Stores how this component looks like when displayed on screen
    std::string myRenderable_;
  };

  ///@}
}

#endif
