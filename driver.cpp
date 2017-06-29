/*******************************************************************/
/*!
@file   driver.cpp
@author Chek
@par    email: chtan\@digipen.edu
@par    DigiPen login: chtan
@par    Course: CS225
@par    Assignment #4
@date   28/1/10
@brief  The client program to run the game.
*/
/*******************************************************************/
#include "SDL.h"
#include <iostream>
#include <string>
#include "Game.h"
#include "Physique.h"
#include "Display.h"
#include "AI.h"
#include "ScriptedAI.h"
#include "RandomAI.h"
#include "Chaser.h"
#include "UserInput.h"

namespace CS225 {
 
	/*******************************************************************/
  /*!
		@brief
		Test whether the UserInput component works as it should.
  */
  /*******************************************************************/
  void UserInputTest(void) {
    std::cout <<  "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << 
                  "\n$$$ Running UserInputTest $$$" << 
                  "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;

    // Create test component
    Component *userInput = new UserInput();

    // Turn debugging to on
    userInput->toggleDebug();
    
    // Test update
		userInput->update();

		delete userInput;
	}

	/*******************************************************************/
  /*!
		@brief
		Test whether the AI component works as it should.
  */
  /*******************************************************************/
  void AITest(void) {
    std::cout <<  "\n$$$$$$$$$$$$$$$$$$$$$$" << 
                  "\n$$$ Running AITest $$$" << 
                  "\n$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
		
    // Create some test components
    Component *scriptedAI, *randomAI;
    scriptedAI = new ScriptedAI(5, AI::NORTH, AI::MELEE, AI::WEST, AI::MELEE, AI::WEST);
    randomAI = new RandomAI(); 

    // Turn debugging to on
    scriptedAI->toggleDebug();
    randomAI->toggleDebug();

    // Test updates
    scriptedAI->update();
    scriptedAI->update();
    scriptedAI->update();
    scriptedAI->update();
    scriptedAI->update();
    randomAI->update();
    randomAI->update();
    randomAI->update();
    randomAI->update();
    randomAI->update();

    // The following test should not even compile
    // If your code compiles the following commands, then your design is wrong.
    // Component *pCrashComponent = new Component();
    // AI *pCrashAI = new AI();

		delete randomAI;
		delete scriptedAI;
	}

	/*******************************************************************/
  /*!
		@brief
		Test whether the Display component works as it should.
  */
  /*******************************************************************/
  void DisplayTest(void) {
    std::cout <<  "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$" << 
                  "\n$$$ Running DisplayTest $$$" << 
                  "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
		
    // Create Base and Derived pointers pointing to the same dynamic type
    Display display;
    Component *pComponent = &display;
    Display *pDisplay = &display;
    IRenderable *pIRenderable = &display;

		// Turn debugging to on
    display.toggleDebug();

		// Test updates
    pComponent->update();
    pDisplay->update();
		std::cout << "\n" << pIRenderable->getRenderable() << std::endl;

		// The following test should not even compile
    // If your code compiles the following commands, then your design is wrong.
    // IRenderable *pIRenderable2 = new IRenderable();
	}

	/*******************************************************************/
  /*!
		@brief
		Test whether the Physique component works as it should.
  */
  /*******************************************************************/
  void PhysiqueTest(void) {
    std::cout <<  "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << 
                  "\n$$$ Running PhysiqueTest $$$" << 
                  "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
		
    // Create Base and Derived pointers pointing to the same dynamic type
    Physique *pPhysique = new Physique();
    Component *pComponent = pPhysique;
		ICollidable *pICollidable = pPhysique;
		GameObject *go = new GameObject("GO");
    
		// Physique needs a owner (to get its position)
		go->addComponent(pPhysique);

		// Turn debugging to on
    pPhysique->toggleDebug();

		// Test updates
    pComponent->update();
    pPhysique->update();
		std::cout << "(" << (pICollidable->getCollidable()).x << "," << (pICollidable->getCollidable()).y << ") " ;

		// The following test should not even compile
    // If your code compiles the following commands, then your design is wrong.
    // ICollidable *pICollidable2 = new ICollidable();

		delete go; // which in turn deletes pPhysique
	}

	/*******************************************************************/
  /*!
		@brief
		Test whether the Chaser component works as it should.
  */
  /*******************************************************************/
  void ChaserTest(void) {
    std::cout <<  "\n$$$$$$$$$$$$$$$$$$$$$$$$$$" << 
                  "\n$$$ Running ChaserTest $$$" << 
                  "\n$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;

    // Create test game objects and components
		GameObject *tgo = new GameObject("TargetGO");
		GameObject *cgo = new GameObject("ChaserGO");
    Component *chaser = new Chaser(tgo);

		// Chaser needs a owner (to keep update its position)
		cgo->addComponent(chaser);

    // Turn debugging to on
    chaser->toggleDebug();
    
    // Test update
		chaser->update();

		delete cgo;
		delete tgo;
	}

	/*******************************************************************/
  /*!
		@brief
		Test whether some of the casts works as it should.
  */
  /*******************************************************************/
  void castTest(void) {
    std::cout <<  "\n$$$$$$$$$$$$$$$$$$$$$$$$" << 
                  "\n$$$ Running castTest $$$" << 
                  "\n$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;

		// Create some components
		Display display;
		Component *pComponent = &display;

		// Casting from base to derived and vice versa
    std::cout << "                 Derived castable to Base? ANS = " << (dynamic_cast<Component*>(&display) != 0) << std::endl;
		std::cout << "         Derived castable to another Base? ANS = " << (dynamic_cast<GameObject*>(&display) != 0) << std::endl;
		std::cout << "        Derived castable to Protocol Base? ANS = " << (dynamic_cast<IRenderable*>(&display) != 0) << std::endl;
		std::cout << "Derived castable to another Protocol Base? ANS = " << (dynamic_cast<ICollidable*>(&display) != 0) << std::endl;
    std::cout << "      Derived castable to another Derived? ANS = " << (dynamic_cast<ScriptedAI*>(pComponent) != 0)  << std::endl;
	}

	/*******************************************************************/
  /*!
		@brief
		Initializing a basic level with 1 PC, 2 NPCs and 1 camera.
		Destruction of gameObjects are handled by the Game class, and
		destruction of components are handled by the Components class.

		@bug
		This is potentially disastrous in terms of memory management... 
		Think about how you would prevent this? 
		(not required to solve in this assignment though)
  */
  /*******************************************************************/
  void gameTest(void) {
    std::cout <<  "\n$$$$$$$$$$$$$$$$$$$$$$$$$" << 
                  "\n$$$ Running basicTest $$$" << 
                  "\n$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;

    // Initialize the game and some component pointers to be reused
    Game game;
    GameObject *gameObject;
	  AI *scriptedAI, *randomAI; 
    Display *display;
    Physique *physique;
	  Chaser *chaser;
    UserInput *userInput;

    ////////
    // PC //
    ////////
    // Player Character.
    // Has physique, display and user inputs checking (no AI since its controlled by player)
	  gameObject = new GameObject("Player");
	  physique = new Physique();
    display = new Display(Display::C_BASIC);
    userInput = new UserInput();

	  gameObject->addComponent(physique);
	  gameObject->addComponent(display);
    gameObject->addComponent(userInput);
    
    game.addCollidable(physique);
    game.addRenderable(display);
    game.addGameObject(gameObject);

	  //////////////
    // Chasecam //
    //////////////
    // A third person camera that follows the PC around.
    // Has a chasing component, no display or anything else
	  chaser = new Chaser(gameObject);						// use the old go as the target pointer
	  gameObject = new GameObject("Chasecam");
	  gameObject->addComponent(chaser);
    game.addGameObject(gameObject);

    ////////////////
	  // NPC Spiker //
    ////////////////
    // Non-player character - spiker.
    // Has physique, display and a melee type scripted AI.
    gameObject = new GameObject("NPC Spiker", 5, 5, 20);
	  physique = new Physique();
    display = new Display(Display::C_SPIKER);
	  scriptedAI = new ScriptedAI(5, AI::NORTH, AI::MELEE, AI::WEST, AI::MELEE, AI::WEST);

	  gameObject->addComponent(physique);
	  gameObject->addComponent(display);
	  gameObject->addComponent(scriptedAI);

    game.addCollidable(physique);
    game.addRenderable(display);
    game.addGameObject(gameObject);

    ///////////////
    // NPC Ghost //
    ///////////////
    // Non-player character - ghost.
    // Has physique, display, and a random AI.
    gameObject = new GameObject("NPC Ghost", 10, 10, 10);
	  physique = new Physique();
    display = new Display();
	  randomAI = new RandomAI();

	  gameObject->addComponent(physique);
	  gameObject->addComponent(display);
	  gameObject->addComponent(randomAI);

    game.addCollidable(physique);
    game.addRenderable(display);
    game.addGameObject(gameObject);

		//////////////////
    // Run the game //
		//////////////////
    game.initialize();
    game.run();
    game.finalize();
  }
} //namespace CS225

/*******************************************************************/
/*!
	@brief
	The usual starting place.

	@return
  The standard return.
*/
/*******************************************************************/
int main(int argc, char **arg) {
	/*CS225::UserInputTest();
	std::cout << std::endl;

	CS225::AITest();
	std::cout << std::endl;

	CS225::DisplayTest();
	std::cout << std::endl;

	CS225::PhysiqueTest();
	std::cout << std::endl;

	CS225::ChaserTest();
	std::cout << std::endl;

	CS225::castTest();
	std::cout << std::endl;

  CS225::gameTest();
	std::cout << std::endl;*/

	//Make 2 surface pointers
	SDL_Surface *hello = 0;
	SDL_Surface *screen = 0;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//Set up screen
	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

	//Load image
	hello = SDL_LoadBMP("hello.bmp");

	//Apply image to screen
	SDL_BlitSurface(hello, NULL, screen, NULL);

	//Update Screen
	SDL_Flip(screen);

	//Pause;
	SDL_Delay(2000);

	//Destroy the image
	SDL_FreeSurface(hello);

	//Quit SDL (destroys screen)
	SDL_Quit();

  return 0;
}