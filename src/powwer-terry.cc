
/*!
 * \file powwer-terry.cc
 * \brief Metal Slug like using the Tectum engine.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.05 - Initial release
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#include <Tectum/components/core.h>
//#include <Tectum/components/logger.h>


int main(int argc, char *argv[]) {
	tectum::Core game("Powwer Terry");
	tectum::Logger logger;
	
	game->setLogger(logger);
	game->run();
	return EXIT_SUCCESS;
}
