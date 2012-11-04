
/*!
 * \file core.cc
 * \brief Tectum engine - core.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.09.15
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#include "./core.h"

Core::Core():
	current_step(current_step)
{}

Core::~Core() {
	App.Close();
}

void Core::load() {
	if ( current_step == INTRO ) {
		printf("Step = loading intro\n");
		if ( ! Image.LoadFromFile("./res/intro.jpg")) {
			// error
		}
		App.Create(sf::VideoMode(IMG_INTRO_W, IMG_INTRO_H, IMG_INTRO_D), IMG_INTRO_T, IMG_INTRO_S);
	}
	App.SetFramerateLimit(60);
}

void Core::update() {
	if ( current_step == INTRO ) {
		printf("Step = updating intro\n");
	}
	Sprite.SetImage(Image);
	App.SetPosition(
		(sf::VideoMode::GetDesktopMode().Width / 2.f - App.GetWidth() / 2.f),
		(sf::VideoMode::GetDesktopMode().Height / 2.f - App.GetHeight() / 2.f)
	);
}

void Core::render() {
	if ( current_step == INTRO ) {
		printf("Step = rendering intro\n");
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
