
/*!
 * \file logger.cc
 * \brief Tectum engine - logger.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.04
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#include "./logger.h"


namespace tectum {

Logger::Logger():
	level_name_()
{
	level_name_[DEBUG]   = "DEBUG";
	level_name_[NOTICE]  = "NOTICE";
	level_name_[WARNING] = "WARNING";
	level_name_[ERROR]   = "ERROR";
}

Logger::~Logger() {}

void Logger::debug(const char *file, const unsigned int &line, const char *str) {
	this->write(file, line, str, DEBUG);
}

void Logger::notice(const char *file, const unsigned int &line, const char *str) {
	this->write(file, line, str, NOTICE);
}

void Logger::warn(const char *file, const unsigned int &line, const char *str) {
	
	this->write(file, line, str, WARNING);
}
void Logger::error(const char *file, const unsigned int &line, const char *str) {
	this->write(file, line, str, ERROR);
}

void Logger::write(
	const char *file, const unsigned int &line,
	const char *str, const Levels &level
) {
	if ( level > MIN_LOG_LEVEL ) {
		printf("[%s:%d] %s %s\n", file, line, level_name_[level], str);
	}
}

}
