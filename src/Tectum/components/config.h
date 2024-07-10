
/*!
 * \file config.h
 * \brief Tectum engine - configuration management headers.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.05 - Initial release
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 *
 * This class is a simple wrapper for SimpleIni.
 * See src/lib/SimpleIni.h for more informations.
 */


#ifndef TECTUM_COMPONENTS_CONFIG_H_
#define TECTUM_COMPONENTS_CONFIG_H_

#define SI_CONVERT_GENERIC

#include <cstdio>
#include <Tectum/components/logger.h>
#include <Tectum/third/SimpleIni.h>


namespace tectum {

class Config {
public:
	Config();
	~Config();
	
	/*!
	 * \brief Load an INI file.
	 * @param INI filename
	 * @return Load success
	 */
	bool load(const std::string &);
	
	/*!
	 * \brief Save an INI file.
	 * @param INI filename
	 * @return Save success
	 */
	bool save(const std::string &);
	
	/*!
	 * \brief Get a value.
	 * @param The key
	 * @param The default value
	 * @return The value of the key
	 */
	const char *getValue(const std::string &, const std::string &);
	
	/*!
	 * \brief Get a value (integer).
	 * @param The key
	 * @param The default value
	 * @return The value of the key
	 */
	int getValue(const std::string &, const int);
	
	/*!
	 * \brief Get a value (double).
	 * @param The key
	 * @param The default value
	 * @return The value of the key
	 */
	double getValue(const std::string &, const double);
	
	/*!
	 * \brief Get a value (bool).
	 * @param The key
	 * @param The default value
	 * @return The value of the key
	 */
	int getValue(const std::string &, const bool);
	
	/*!
	 * \brief Set a value.
	 * @param The key
	 * @param The value
	 * @return void
	 */
	void setValue(const char *, const char *);
	
	/*!
	 * \brief Set the Logger object to manage log entires.
	 * @return void
	 */
	void setLogger(const tectum::Logger &);
	
	/*!
	 * \brief Set the section into the INI file.
	 * @return Selection success
	 */
	bool setSection(const char *);

private:
	/*!
	 * \var log_
	 * \brief Logger object to manage log files.
	 */
	tectum::Logger log_;
	
	/*!
	 * \var config_
	 * \brief INI file handler to manage configurations.
	 */
	CSimpleIniCaseA config_;
	
	/*!
	 * \var current_section_
	 * \brief Current section being traited into the INI file.
	 */
	std::string current_section_;
};

}

#endif  // TECTUM_COMPONENTS_CONFIG_H_
