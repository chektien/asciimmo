/*******************************************************************/
/*!
@file   Display.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the Display class.
*/
/*******************************************************************/

#include "Display.h"
#include <string>

namespace CS225 {

  /*******************************************************************/
  /*!
		@brief
    Constructor. Defines the looks of the component when rendered.

		@param lookType
    The type of rendered look to give this component.
  */
  /*******************************************************************/
  Display::Display(const Display::LookType &lookType): Component("Display") {
    switch (lookType) {
      case C_BASIC:
        myRenderable_  = "            aaaaaaa                   \n";
        myRenderable_ += "           aaaaaaaa  aaaaaa           \n";
        myRenderable_ += "           aaaaaaa  aaaaaaa           \n";
        myRenderable_ += "           aaa     aaaaaaaa           \n";
        myRenderable_ += "      aaaaaaaaaa   aaa  aaa           \n";
        myRenderable_ += "     a  aaaaaaaaa  aaaaaaaaaaa        \n";
        myRenderable_ += "   aa        aaaaaaaaaaaaaaa  a       \n";
        myRenderable_ += "   a        a aa aaaaaaaaaaa   a      \n";
        myRenderable_ += "   a        aaaa  aaaaaaaaaa   a      \n";
        myRenderable_ += "   a         aa   aaaaaaaaaaa aa      \n";
        myRenderable_ += "   a              aaaaaaaaaaaaa       \n";
        myRenderable_ += "  aaa            aaaaaaaaaaaaaa       \n";
        myRenderable_ += " aaaaaa       aaaaaaaaaaaaaaaaaaa     \n";
        myRenderable_ += " aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa    \n";
        myRenderable_ += " aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa   \n";
        myRenderable_ += "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa  \n";
        myRenderable_ += "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa  \n";
        myRenderable_ += "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa  \n";
        myRenderable_ += "aaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaa  \n";
        myRenderable_ += " aaaaaaaaaaaaaaaa    aaaaaaaaaaaaaa   \n";
        myRenderable_ += "  aaaaaaaaaaaaaaaaa aaaaaaaaaaaaaa    \n";
        myRenderable_ += "    aaaaaaaaaaaaaaaaaaaaaaaaaaa       \n";
        myRenderable_ += "     aaaaaaaaaaaaaaaaaaaaaaa     aa   \n";
        myRenderable_ += "   aa        aaaaaaaaaaaaa         aa \n";
        myRenderable_ += "  a            a   aaaaaaa           a\n";
        myRenderable_ += " a              a  aaaaaaa           a\n";
        myRenderable_ += " aa            aa  aaaaa            aa\n";
        myRenderable_ += " aaaaaaaaaaaaaaaa  aaaaaaaaaaaaaaaaaaa  ";
        break;

      case C_SPIKER:
        myRenderable_  = "                  a                   \n";
        myRenderable_ += "        a         a                   \n";
        myRenderable_ += "         a        a            a      \n";
        myRenderable_ += "         a       aa           a       \n";
        myRenderable_ += "         aa      aaa        aaa       \n";
        myRenderable_ += "   aa    aaa     aaa      aaaa        \n";
        myRenderable_ += "    aa    aaa   aaaa     aaaa         \n";
        myRenderable_ += "     aa   aaaaaaaaaa   aaaaa          \n";
        myRenderable_ += "     aaaaaaaaaaaaaaaaaaaaaa      a    \n";
        myRenderable_ += "     aaaaaaaaaaaaaaaaaaaaa     aa     \n";
        myRenderable_ += "    aaaaaaaaaaaaaaaaaaaaaaaa aaa      \n";
        myRenderable_ += "   aaaaaaaaaaaaaaaaaaaaaaaaaaaa       \n";
        myRenderable_ += "  aaaaa     aaaaaaaaaa     aaaaa      \n";
        myRenderable_ += " aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa     \n";
        myRenderable_ += " aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa    \n";
        myRenderable_ += " aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa    \n";
        myRenderable_ += " aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa    \n";
        myRenderable_ += "  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa    \n";
        myRenderable_ += "   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa     \n";
        myRenderable_ += "   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa     \n";
        myRenderable_ += "   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa  \n";
        myRenderable_ += "  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa \n";
        myRenderable_ += "  aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
        myRenderable_ += " aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";
        myRenderable_ += "aaaaaaaaaaaaaaaa       aaaaaaaaaaaaaaa\n";
        myRenderable_ += " aaaaaaaaaaaaaaa       aaaaaaaaaaaaaaa  ";
        break;

      default:
        myRenderable_  = "  aaa   aaa             aaa   aaa  \n";
        myRenderable_ += " aa    aa aa           aa aa    aa \n";
        myRenderable_ += "aa    aa   aa         aa   aa    aa\n";
        myRenderable_ += "aa                               aa\n";
        myRenderable_ += "aa                               aa\n";
        myRenderable_ += " aa                             aa \n";
        myRenderable_ += "  aaa         aaaaaaa         aaa    ";
    }
    
  }

  /*******************************************************************/
  /*!
		@brief
    Perform changes to renderable.
  */
  /*******************************************************************/
  void Display::update(void) {
    if (debug_) std::cout << name_ << "::update" << std::endl;
    std::cout << "Doing changes to the renderable..." << std::endl;
  }

  /*******************************************************************/
  /*!
		@brief
    Gets an object that is readable by the graphics engine.

		@return
    An object for the graphics engine to render.
  */
  /*******************************************************************/
  const std::string& Display::getRenderable(void) const {
    return myRenderable_;
  }

}