
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
#include <csignal>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "./logger.h"
#include "./config.h"


namespace tectum {

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
	
	Core();
	~Core();
	
	/*!
	 * \brief Load specific actions for a given step.
	 * @return void
	 */
	void load();
	
	/*!
	 * \brief Process update for a given step.
	 * @return void
	 */
	void update();
	
	/*!
	 * \brief Process render for a given step.
	 * @return void
	 */
	void render();
	
	/*!
	 * \brief Set the game's name.
	 * @param Name of the game
	 * @return void
	 */
	void setGame(const char *name);
	
	/*!
	 * \brief Set current step.
	 * @param Step number
	 * @return void
	 */
	void setStep(const unsigned int);
	
	/*!
	 * \brief Get current step.
	 * @return Step number
	 */
	unsigned int getStep();
	
	/*!
	 * \var current_step_
	 * \brief Current step.
	 */
	unsigned int current_step_;

private:
	int pad__;
	 
	/*!
	 * \var log_
	 * \brief Logger object to manage log files.
	 */
	 tectum::Logger log_;
	
	/*!
	 * \var config_
	 * \brief Configuration handler.
	 */
	tectum::Config config_;
	
	/*!
	 * \var app_
	 * \brief The window to render.
	 */
	sf::RenderWindow app_;
	
	/*!
	 * \var image_
	 * \brief The file to load as sprite.
	 */
	sf::Image image_;
	
	/*!
	 * \var sprite_
	 * \brief Table of CRC-32's of all single-byte values.
	 */
	sf::Sprite sprite_;
	
	/*!
	 * \var step_name_
	 * \brief Map with correspondinf Step number => Step name.
	 */
	std::map<unsigned int, std::string>step_name_;
	
	/*!
	 * \var game_name_
	 * \brief The name of the game.
	 */
	std::string game_name_;
	
};

}

#endif  // COMPONENTS_CORE_H_
