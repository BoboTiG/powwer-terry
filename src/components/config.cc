
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

Config::Config():
	log_(log_),
	config_(&config_),
	current_section_(current_section_)
{
	config_.SetUnicode(true);
	config_.SetMultiKey(false);
	config_.SetMultiLine(false);
}

Config::~Config() {}

bool Config::load(const std::string &filename) {
	DEBUG(std::string("Loading config file " + filename).c_str());
	bool ret = (config_.LoadFile(filename.c_str()) >= 0);
	if ( ! ret ) {
		ERROR("Error while trying to load the configuration file!");
	}
	return ret;
}

bool Config::save(const std::string &filename) {
	DEBUG(std::string("Saving config file " + filename).c_str());
	bool ret = (config_.SaveFile(filename.c_str()) >= 0);
	if ( ! ret ) {
		ERROR("Error while trying to save the configuration file!");
	}
	return ret;
}

const char *Config::getValue(const std::string &key, const std::string &value) {
	const char *val = config_.GetValue(current_section_.c_str(), key.c_str());
	sprintf(log_.str_, "%s = %s", key.c_str(), val);
	DEBUG(log_.str_);
	if ( val == NULL ) {
		sprintf(log_.str_, "! %s = %s", key.c_str(), value.c_str());
		DEBUG(log_.str_);
		return value.c_str();
	}
	return val;
}

int Config::getValue(const std::string &key, const int value) {
	int val = config_.GetDoubleValue(current_section_.c_str(), key.c_str());
	sprintf(log_.str_, "%s = %d", key.c_str(), val);
	DEBUG(log_.str_);
	if ( val < 0 ) {
		val = value;
		sprintf(log_.str_, "! %s = %d", key.c_str(), val);
		DEBUG(log_.str_);
	}
	return val;
}

int Config::getValue(const std::string &key, const bool state) {
	bool val = config_.GetBoolValue(current_section_.c_str(), key.c_str());
	sprintf(log_.str_, "%s = %d", key.c_str(), val);
	DEBUG(log_.str_);
	if ( val < 0 ) {
		val = state;
		sprintf(log_.str_, "! %s = %d", key.c_str(), val);
		DEBUG(log_.str_);
	}
	return val;
}

void Config::setValue(const char *key, const char *value) {
	config_.SetValue(current_section_.c_str(), key, value);
}

bool Config::setSection(const char *section) {
	current_section_ = section;
	DEBUG(std::string("[" + current_section_ + "]").c_str());
	bool ret = (config_.GetSectionSize(section) > -1);
	if ( ! ret ) {
		ERROR("Section does not exists!");
	}
	return ret;
}

void Config::setLogger(const tectum::Logger &logger) {
	log_ = logger;
}

}
