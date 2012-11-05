
/*!
 * \file config.cc
 * \brief Tectum engine - configuration management.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.05
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 *
 * This class is a simple wrapper for SimpleIni.
 * See src/lib/SimpleIni.h for more informations.
 */


#include "./config.h"


namespace tectum {

Config::Config() {
	/*ini_.SetUnicode(true);
	ini_.SetMultiKey(false);
	ini_.SetMultiLine(false);*/
}

Config::~Config() {
}

bool Config::load(const std::string &filename) {
	Trace(log_.DEBUG, std::string("Loading config file " + filename).c_str());
	bool ret = (ini_.LoadFile(filename.c_str()) >= 0);
	if ( ! ret ) {
		Trace(log_.ERROR, "Error while trying to load the configuration file!");
	}
	return ret;
}

bool Config::save(const std::string &filename) {
	Trace(log_.DEBUG, std::string("Saving config file " + filename).c_str());
	bool ret = (ini_.SaveFile(filename.c_str()) >= 0);
	if ( ! ret ) {
		Trace(log_.ERROR, "Error while trying to save the configuration file!");
	}
	return ret;
}

const char *Config::getValue(const std::string &key, const std::string &value) {
	const char *val = ini_.GetValue(current_section_.c_str(), key.c_str());
	sprintf(log_.str_, "%s = %s", key.c_str(), val);
	Trace(log_.DEBUG, log_.str_);
	if ( val == NULL ) {
		sprintf(log_.str_, "! %s = %s", key.c_str(), value.c_str());
		Trace(log_.DEBUG, log_.str_);
		return value.c_str();
	}
	return val;
}

int Config::getValue(const std::string &key, const int value) {
	int val = ini_.GetDoubleValue(current_section_.c_str(), key.c_str());
	sprintf(log_.str_, "%s = %d", key.c_str(), val);
	Trace(log_.DEBUG, log_.str_);
	if ( val < 0 ) {
		val = value;
		sprintf(log_.str_, "! %s = %d", key.c_str(), val);
		Trace(log_.DEBUG, log_.str_);
	}
	return val;
}

int Config::getValue(const std::string &key, const bool state) {
	bool val = ini_.GetBoolValue(current_section_.c_str(), key.c_str());
	sprintf(log_.str_, "%s = %d", key.c_str(), val);
	Trace(log_.DEBUG, log_.str_);
	if ( val < 0 ) {
		val = state;
		sprintf(log_.str_, "! %s = %d", key.c_str(), val);
		Trace(log_.DEBUG, log_.str_);
	}
	return val;
}

void Config::setValue(const char *key, const char *value) {
	ini_.SetValue(current_section_.c_str(), key, value);
}

bool Config::setSection(const char *section) {
	current_section_ = section;
	Trace(log_.DEBUG, std::string("[" + current_section_ + "]").c_str());
	bool ret = (ini_.GetSectionSize(section) > -1);
	if ( ! ret ) {
		Trace(log_.ERROR, "Section does not exists!");
	}
	return ret;
}

void Config::setLogger(const tectum::Logger &logger) {
	log_ = logger;
}

}
