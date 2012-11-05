
/*!
 * \file core.cc
 * \brief Tectum engine - core.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.05
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#include "./core.h"


namespace tectum {

Core::Core():
	current_step_(current_step_)
{
	Trace(log_.NOTICE, "Starting the game \\o/");
	step_name_[INTRO] = "the introduction";
	step_name_[MENU]  = "the menu";
	step_name_[SCENE] = "a scene";
	config_.setLogger(log_);
}

Core::~Core() {
	Trace(log_.NOTICE, "Closing the game /o\\  Tcho !");
	if ( app_.IsOpened() ) {
		app_.Close();
	}
}

void Core::load() {
	Trace(log_.DEBUG, std::string("Loading " + step_name_[current_step_]).c_str());
	if ( current_step_ == INTRO ) {
		if ( ! config_.load("./config/game.ini") ) {
			return;
		}
		if ( ! config_.setSection("introduction") ) {
			return;
		}
		if ( ! config_.getValue("show", true) ) {
			Trace(log_.NOTICE, "Player do not want to display the intro ... :(");
			return;
		}
		if ( ! image_.LoadFromFile("./res/intro.jpg") ) {
			Trace(log_.WARNING, "Cannot load from file ./res/intro.jpg");
			return;
		}
		app_.Create(
			sf::VideoMode(
				config_.getValue("width", 600),
				config_.getValue("height", 200),
				INTRO_IMG_D),
			GAME_TITLE, INTRO_IMG_S
		);
	}
	app_.SetFramerateLimit(60);
	app_.SetPosition(
		(sf::VideoMode::GetDesktopMode().Width / 2.f - app_.GetWidth() / 2.f),
		(sf::VideoMode::GetDesktopMode().Height / 2.f - app_.GetHeight() / 2.f)
	);
	sprite_.SetImage(image_);
}

void Core::update() {
	Trace(log_.DEBUG, std::string("Updating " + step_name_[current_step_]).c_str());
}

void Core::render() {
	Trace(log_.DEBUG, std::string("Rendering " + step_name_[current_step_]).c_str());
	if ( current_step_ == INTRO ) {
		while ( app_.IsOpened() ) {
			sf::Event event;
			while ( app_.GetEvent(event) ) {
				if ( (event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape) ) {
					return;
				}
			}
			app_.Clear();
			app_.Draw(sprite_);
			app_.Display();
		}
	}
}

void Core::setStep(const unsigned int step) {
	current_step_ = step;
	Trace(log_.NOTICE, std::string("Let's go with " + step_name_[current_step_]).c_str());
}

unsigned int Core::getStep() {
	return current_step_;
}

}
