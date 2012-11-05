
/*!
 * \file constants.h
 * \brief Tectum engine - constants headers.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.05
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#ifndef COMPONENTS_CONSTANTS_H_
#define COMPONENTS_CONSTANTS_H_


// Variables
#if ( ! defined(MIN_LOG_LEVEL) )
	#define MIN_LOG_LEVEL NONE  // Minimum log level
#endif

// Functions
#define DEBUG(str)  log_.debug(__FILE__, __LINE__, str);
#define NOTICE(str) log_.notice(__FILE__, __LINE__, str);
#define WARN(str)   log_.warn(__FILE__, __LINE__, str);
#define ERROR(str)  log_.error(__FILE__, __LINE__, str);


#endif  // COMPONENTS_CONSTANTS_H_
