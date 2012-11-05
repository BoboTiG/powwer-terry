
/*!
 * \file tectum.h
 * \brief Tectum engine - headers.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.11.05
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#ifndef TECTUM_H_
#define TECTUM_H_

#include <cstdlib>
#include <cstdio>
#include "./components/core.h"
 
#define TECTUM_VERSION "0.0.1"


namespace tectum {

class Tectum {
	public:
		Tectum(const char *);
		~Tectum();	
};

}

#endif  // TECTUM_H_
