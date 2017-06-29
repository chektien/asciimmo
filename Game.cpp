/*******************************************************************/
/*!
@file   Game.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  These are the implementations for the Game class.
*/
/*******************************************************************/

#include <iostream>
#include <list>
#include <algorithm>
#include "Game.h"
#include "GameEngine_.h"

namespace CS225 {

	/*******************************************************************/
	/*!
		@brief
		Constructor. Initializes the total number of frames to run game.
		
		@param totalFrames 
		The total number of frames to run game.
	*/
	/*******************************************************************/
	Game::Game(const unsigned &totalFrames): totalFrames_(totalFrames) {}
	
	/*******************************************************************/
	/*!
		@brief
		Destructor. Need to delete the game objects as these are the only
    dynamic things belonging to the game.
    IRenderables and ICollidables are components which are deleted 
    by gameObjects themselves.
	*/
	/*******************************************************************/
  Game::~Game() {
    std::for_each(gameObjects_.begin(), gameObjects_.end(), Destroy());
  }

  /*******************************************************************/
  /*!
		@brief
    Initialize the game. Setup the game.
  */
  /*******************************************************************/
  void Game::initialize(void) {
    std::cout <<  "\n#######################################################" << 
                  "\n################## Initializing game ##################" << 
                  "\n#######################################################" << std::endl;
  }

  /*******************************************************************/
  /*!
		@brief
    Finalize the game. After the user ends the game.
  */
  /*******************************************************************/
  void Game::finalize(void) {
    std::cout <<  "\n#######################################################" << 
                  "\n################## Finalizing game ####################" << 
                  "\n#######################################################" << std::endl;
  }

	/*******************************************************************/
  /*!
		@brief
    Run the game. (game loop)
		Uses functors Render, Collision and Update whereby the respective
		engine details are implemented.
  */
  /*******************************************************************/
  void Game::run(void) {
		unsigned frameCount = 0;
		while (frameCount < totalFrames_) {
      // Print frame header and increment frameCount at the same time
      std::cout <<  "\n==================================================" << 
                    "\n                   At frame " << frameCount++ << 
                    "\n==================================================" << std::endl;

			// Polymorphic loop to update all gameObjects
      std::cout <<  "\n-----------------------------------" <<
                    "\n|      UPDATING Game Objects      |" <<
                    "\n-----------------------------------" << std::endl;
      std::for_each(gameObjects_.begin(), gameObjects_.end(), Update());
      
      // Polymorphic loop to render all renderables
      std::cout <<  "\n-----------------------------------" <<
                    "\n|       RENDER Renderables        |" <<
                    "\n-----------------------------------" << std::endl;
      std::for_each(renderables_.begin(), renderables_.end(), Render());

      // Polymorphic loop to check all collisions
      std::cout <<  "\n-----------------------------------" <<
                    "\n|   COLLISION check collidables   |" <<
                    "\n-----------------------------------" << std::endl;
      std::cout << "\nResolving collisions for positions ";
      std::for_each(collidables_.begin(), collidables_.end(), Collision());
      std::cout << std::endl;
		}
  }

  /*******************************************************************/
  /*!
		@brief
    Adds a game object to the game.
  
		@param gameObject
    Pointer to the game object to be added.
  */
  /*******************************************************************/
  void Game::addGameObject(GameObject * const gameObject) {
    gameObjects_.push_back(gameObject);
  }

  /*******************************************************************/
  /*!
		@brief
    Adds a ICollidable object to the game.
  
		@param iCollidable
    Pointer to the collidable object to be added.
  */
  /*******************************************************************/
  void Game::addCollidable(ICollidable * const iCollidable) {
    collidables_.push_back(iCollidable);
  }
  
  /*******************************************************************/
  /*!
		@brief
    Adds a IRenderable object to the game.
  
		@param iRenderable
    Pointer to the component object to be added.
  */
  /*******************************************************************/
  void Game::addRenderable(IRenderable * const iRenderable) {
    renderables_.push_back(iRenderable);
  }
}