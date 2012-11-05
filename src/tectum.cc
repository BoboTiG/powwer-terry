
/*!
 * \file tectum.cc
 * \brief Tectum engine.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.05
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#include "./tectum.h"


namespace tectum {

Tectum::Tectum(const char *name) {
	tectum::Core the_one;
	unsigned int step;
	
	the_one.setGame(name);
	for ( step = the_one.INTRO; step <= the_one.MENU; ++step ) {
		the_one.setStep(step);
		the_one.load();
		the_one.update();
		the_one.render();
	}
}

Tectum::~Tectum() {}

}

int main(int argc, char *argv[]) {
	if ( argc > 1 && argv[1] ) {
		printf("Tectum v%s\n", TECTUM_VERSION);
	} else {
		tectum::Tectum game("Powwer Terry");
	}
	return EXIT_SUCCESS;
}
