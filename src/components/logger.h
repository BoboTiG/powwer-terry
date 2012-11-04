
/*!
 * \file logger.h
 * \brief Tectum engine - logger headers.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.04
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#ifndef COMPONENTS_LOGGER_H_
#define COMPONENTS_LOGGER_H_

#include <cstdio>
#include <map>
#include "./constants.h"


class Logger {
public:
	/*!
	 * \var Levels
	 * \brief Possible level of information.
	 */
	typedef enum {
		NONE    = 0x01,
		DEBUG   = 0x02,
		NOTICE  = 0x03,
		WARNING = 0x04,
		ERROR   = 0x05
	} Levels;
	
	Logger();
	~Logger();
	
	/*!
	 * \brief write
	 * @param __FILE__
	 * @param __LINE__
	 * @param String to write
	 * @param The level of information
	 * @return void
	 */
	void write(const char*, const unsigned int, const Levels, const char*);

private:
	std::map<unsigned int, const char*>level_name;
};

#endif  // COMPONENTS_LOGGER_H_
