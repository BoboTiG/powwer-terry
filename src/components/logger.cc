
/*!
 * \file logger.cc
 * \brief Tectum engine - logger.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.04
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#include "./logger.h"

Logger::Logger() {
	level_name[DEBUG]   = "DEBUG";
	level_name[NOTICE]  = "NOTICE";
	level_name[WARNING] = "WARNING";
	level_name[ERROR]   = "ERROR";
}

Logger::~Logger() {}

void Logger::write(
	const char* file, const unsigned int line,
	const Levels level, const char* str
) {
	if ( level > MIN_LOG_LEVEL ) {
		printf("[%s:%d] %s %s\n", file, line, level_name[level], str);
	}
}
