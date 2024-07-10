
/*!
 * \file logger.h
 * \brief Tectum engine - logger headers.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.05 - Initial release
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#ifndef TECTUM_COMPONENTS_LOGGER_H_
#define TECTUM_COMPONENTS_LOGGER_H_

#define DEBUG(str)  log_.debug(__FILE__, __LINE__, str);
#define NOTICE(str) log_.notice(__FILE__, __LINE__, str);
#define WARN(str)   log_.warn(__FILE__, __LINE__, str);
#define ERROR(str)  log_.error(__FILE__, __LINE__, str);

#include <cstdio>
#include <map>
#include <Tectum/constants.h>


namespace tectum {

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
	void write (const char *, const unsigned int &, const char *, const Levels &);
	void debug (const char *, const unsigned int &, const char *);
	void notice(const char *, const unsigned int &, const char *);
	void warn  (const char *, const unsigned int &, const char *);
	void error (const char *, const unsigned int &, const char *);
	
	/*!
	 * \var str_
	 * \brief Where you can store a sentence to send to write().
	 */
	char str_[4096];

private:
	/*!
	 * \var level_name
	 * \brief Map with correspondinf Level number => Level name.
	 */
	std::map<unsigned int, const char*>level_name_;
};

}

#endif  // TECTUM_COMPONENTS_LOGGER_H_
