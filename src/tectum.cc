
/*!
 * \file tectum.cc
 * \brief Tectum engine.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.04
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#include "./tectum.h"

int main(int argc, char *argv[]) {
	Core game;
	unsigned int step;
	
	for ( step = game.INTRO; step <= game.MENU; ++step ) {
		game.setStep(step);
		game.load();
		game.update();
		game.render();
	}
	return EXIT_SUCCESS;
}
