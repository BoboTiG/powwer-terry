Tectum Engine
=============

Directories
-----------

	components/ contains primary classes  
	interfaces/ contains interfaces derived from primary classes  
	lib/        contains third party libraries  


Usage
-----

C++ code snippet:  

	#include <Tectum/components/core.h>
	
	int main(int argc, char *argv[]) {
		tectum::Core game("Powwer Terry");
		game->run();
		return EXIT_SUCCESS;
	}
