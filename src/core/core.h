
/*!
 * \file core.h
 * \brief Tectum engine - core headers.
 * \author Mickaël 'Tiger-222' Schoentgen
 * \date 2012.09.15
 *
 * Copyright (C) 2012 Mickaël 'Tiger-222' Schoentgen.
 */


#ifndef SRC_CORE_CORE_H_
#define SRC_CORE_CORE_H_

#define IMG_INTRO_W 600
#define IMG_INTRO_H 200
#define IMG_INTRO_D 16
#define IMG_INTRO_T "Powwer Terry! Intro" 
#define IMG_INTRO_S sf::Style::None

#include <cstdio>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Core {
public:
	/*!
	 * \var pcrc_32_tab
	 * \brief Table of CRC-32's of all single-byte values.
	 */
	typedef enum {
		INTRO = 0x01,
		MENU  = 0x02,
		SCENE = 0x03
	} Steps;
	/*!
	 * \var pcrc_32_tab
	 * \brief Table of CRC-32's of all single-byte values.
	 */
	unsigned int current_step;
	/*!
	 * \brief parametre 2
	 * @return ce qui est retourné
	 */
	Core();
	/*!
	 * \brief parametre 2
	 * @return ce qui est retourné
	 */
	~Core();
	/*!
	 * \brief parametre 2
	 * @return ce qui est retourné
	 */
	void load();
	/*!
	 * \brief parametre 2
	 * @return ce qui est retourné
	 */
	void update();
	/*!
	 * \brief parametre 2
	 * @return ce qui est retourné
	 */
	void render();
	/*!
	 * \brief parametre 1
	 * @param parametre 2
	 * @return ce qui est retourné
	 */
	void setStep(unsigned int);
	/*!
	 * \brief parametre 2
	 * @return ce qui est retourné
	 */
	unsigned int getStep();

private:
	/*!
	 * \var pcrc_32_tab
	 * \brief Table of CRC-32's of all single-byte values.
	 */
	sf::RenderWindow App;
	/*!
	 * \var pcrc_32_tab
	 * \brief Table of CRC-32's of all single-byte values.
	 */
	sf::Image Image;
	/*!
	 * \var pcrc_32_tab
	 * \brief Table of CRC-32's of all single-byte values.
	 */
	sf::Sprite Sprite;
};

#endif  // SRC_CORE_CORE_H_
