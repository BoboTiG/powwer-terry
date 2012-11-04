
/*!
 * \file core.h
 * \brief Tectum engine - core headers.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.04
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#ifndef COMPONENTS_CORE_H_
#define COMPONENTS_CORE_H_

#include <cstdio>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "./logger.h"


class Core {
public:
	/*!
	 * \var Steps
	 * \brief Possible steps. The Core needs to know which step to run.
	 */
	typedef enum {
		INTRO = 0x01,
		MENU  = 0x02,
		SCENE = 0x03
	} Steps;
	
	/*!
	 * \var current_step
	 * \brief Current running step.
	 */
	unsigned int current_step;
	
	Core();
	~Core();
	
	/*!
	 * \brief Load specific actions for a given step.
	 * @return void
	 */
	void load();
	
	/*!
	 * \brief parametre 2
	 * @return void
	 */
	void update();
	
	/*!
	 * \brief parametre 2
	 * @return void
	 */
	void render();
	
	/*!
	 * \brief parametre 1
	 * @param parametre 2
	 * @return void
	 */
	void setStep(unsigned int);
	
	/*!
	 * \brief parametre 2
	 * @return ce qui est retourné
	 */
	unsigned int getStep();

private:
	/*!
	 * \var Log
	 * \brief Logger object to manage log files.
	 */
	Logger Log;
	
	/*!
	 * \var App
	 * \brief The window to render.
	 */
	sf::RenderWindow App;
	
	/*!
	 * \var Image
	 * \brief The file to load as sprite.
	 */
	sf::Image Image;
	
	/*!
	 * \var Sprite
	 * \brief Table of CRC-32's of all single-byte values.
	 */
	sf::Sprite Sprite;
};

#endif  // COMPONENTS_CORE_H_
