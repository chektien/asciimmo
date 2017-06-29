/*******************************************************************/
/*! 
@mainpage The Blank Engine
@author   Chek
@version  0.0000001

@section sec_intro Description
This is a simulated game engine. It is call The Blank Engine because
All of the internals of the various components (graphics, physics, 
and AI) are empty and simulated in text.

@section sec_impldetails Implementation Details
This game demonstrates 
- one way to design the class relationships in a game engine with commonly 
known components. It utilizes a combination of component-based as 
well as inheritance-based architectures.
- a good legitimate use of multiple inheritance
implementing protocol classes along with inheriting a normal base
class.

This code is as stable as a rock (how I wish). Do email 
chtan\@digipen.edu if you find any bugs.

@section sec_about_usage Application Usage
You need to be an absolute geek to be able to use this game engine 
(hint: scrutinize driver.cpp). Basically you would need to:
-# instantiate a GAME from the Game class
-# instantiate a bunch of components (Display, ScriptedAI, UserInput, etc...) from the respective component classes
-# instantiate game objects which are basically a concoction of different components (add them respectively)
-# add these game objects to the GAME
-# initialize() GAME
-# run() GAME
-# finalize() the GAME when you're done
-# let the polymorphism within the classes handle the rest
*/
/*******************************************************************/

/*******************************************************************/
/*!
@file   Game.h
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the interfaces for the Game class.
        This is the main class that controls everything.
*/
/*******************************************************************/

#ifndef GAMEH
#define GAMEH

#include <list>
#include <string>
#include "GameObject.h"
#include "Component.h"
#include "IRenderable.h"
#include "ICollidable.h"

///To encapsulate our game.
namespace CS225 {

  ///@addtogroup coreEngine Core Engine
  ///@{

  ///@brief The Game class.
  ///
  ///Composed of everything.
  class Game {
  public:
	  Game(const unsigned &totalFrames=3);
    ~Game(void);

    void initialize(void);
    void run(void);
    void finalize(void);

    void addGameObject(GameObject * const gameObject);
    void addCollidable(ICollidable * const iCollidable);
    void addRenderable(IRenderable * const iRenderable);

  private:
    ///Number of frames to run game.
	  unsigned totalFrames_;

	  ///List of game objects.
    std::list<GameObject*> gameObjects_;

	  ///List of renderable objects.
    std::list<IRenderable*> renderables_;

	  ///List of collidable objects.
    std::list<ICollidable*> collidables_;
  };

  ///@}

}

#endif
