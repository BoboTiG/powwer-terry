
/*!
 * \file core.cc
 * \brief Tectum engine - core.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.04
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#include "./core.h"

Core::Core():
	current_step(current_step)
{
	Trace(Log.NOTICE, "Starting the game.");
}

Core::~Core() {
	Trace(Log.NOTICE, "Closing game.");
	if ( App.IsOpened() ) {
		App.Close();
	}
}

void Core::load() {
	if ( current_step == INTRO ) {
		Trace(Log.DEBUG, "Loading Introduction");
		if ( ! Image.LoadFromFile("./res/intro.jpg") ) {
			Trace(Log.WARNING, "Cannot load from file ./res/intro.jpg");
		}
		App.Create(sf::VideoMode(IMG_INTRO_W, IMG_INTRO_H, IMG_INTRO_D), GAME_TITLE, IMG_INTRO_S);
	}
	App.SetFramerateLimit(60);
	App.SetPosition(
		(sf::VideoMode::GetDesktopMode().Width / 2.f - App.GetWidth() / 2.f),
		(sf::VideoMode::GetDesktopMode().Height / 2.f - App.GetHeight() / 2.f)
	);
	Sprite.SetImage(Image);
}

void Core::update() {
	if ( current_step == INTRO ) {
		Trace(Log.DEBUG, "Updating Introduction");
	}
}

void Core::render() {
	if ( current_step == INTRO ) {
		Trace(Log.DEBUG, "Rendering Introduction");
	}
	while ( App.IsOpened() ) {
		App.Clear();
		App.Draw(Sprite);
		App.Display();
	}
}

void Core::setStep(unsigned int step) {
	current_step = step;
}

unsigned int Core::getStep() {
	return current_step;
}
