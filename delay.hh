/*
 * delay.hh
 *
 *  Created on: Aug 23, 2020
 *      Author: anujshah
 */

#ifndef DELAY_HH_
#define DELAY_HH_


uint32_t t;

void delay(uint32_t cycles){
//	for(t=1000000; t>0; t--);
	for(t=0; t<cycles; t++);
}



#endif /* DELAY_HH_ */
