/*
 * main.h
 *
 *  Created on: 17-05-2015
 *      Author: lukasz
 */

#ifndef MAIN_H_
#define MAIN_H_

enum  HARDWARE_TYPE {
	DEV_BOARD_STK3800, PRODUCTION_BOARD

};

#define HARDWARE_USED_PRODUCTION_BOARD

#ifndef HARDWARE_USED_PRODUCTION_BOARD

#define HARDWARE_USED_DEV_BOARD_STK3800

#endif
#endif /* MAIN_H_ */
