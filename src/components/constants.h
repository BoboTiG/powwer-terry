
/*!
 * \file constants.h
 * \brief Tectum engine - constants headers.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.04
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#ifndef COMPONENTS_CONSTANTS_H_
#define COMPONENTS_CONSTANTS_H_


// Functions
#define Trace(a,b) log_.write(__FILE__, __LINE__, a, b);


// Variables
#define GAME_TITLE "Powwer Terry"
#if ( ! defined(MIN_LOG_LEVEL) )
	#define MIN_LOG_LEVEL NONE  // Minimum log level
#endif
 
#define INTRO_IMG_W 600
#define INTRO_IMG_H 200
#define INTRO_IMG_D 16
#define INTRO_IMG_S sf::Style::None


#endif  // COMPONENTS_CONSTANTS_H_
