/*
 * Written by IOXhop : www.ioxhop.com
 * Author : Sonthaya Nongnuch (www.fb.me/maxthai)
 */

#include <Arduino.h>
#include "TimerOne.h"
#include "DigitalTube.h"

DigitalTube::DigitalTube() {
	_DigiTubeConfig.pin_sclk = 4;
	_DigiTubeConfig.pin_rclk = 5;
	_DigiTubeConfig.pin_dio = 6;
}


DigitalTube::DigitalTube(int sclk, int rclk, int dio) {
	_DigiTubeConfig.pin_sclk = sclk;
	_DigiTubeConfig.pin_rclk = rclk;
	_DigiTubeConfig.pin_dio = dio;
}

void DigitalTube::begin() {
	pinMode(_DigiTubeConfig.pin_sclk, OUTPUT);
	pinMode(_DigiTubeConfig.pin_rclk, OUTPUT);
	pinMode(_DigiTubeConfig.pin_dio, OUTPUT);
	
	digitalWrite(_DigiTubeConfig.pin_rclk, HIGH);
	
	Timer1.initialize(2000);
	Timer1.attachInterrupt([]() {
		digitalWrite(_DigiTubeConfig.pin_rclk, LOW);
		shiftOut(_DigiTubeConfig.pin_dio, _DigiTubeConfig.pin_sclk, LSBFIRST, _DigiTubeConfig.characters[_DigiTubeConfig.disp[_DigiTubeConfig.NextDigi]]);
		shiftOut(_DigiTubeConfig.pin_dio, _DigiTubeConfig.pin_sclk, LSBFIRST, 0x80>>_DigiTubeConfig.NextDigi);
		digitalWrite(_DigiTubeConfig.pin_rclk, HIGH);
		_DigiTubeConfig.NextDigi = (_DigiTubeConfig.NextDigi >= 3 ? 0 : _DigiTubeConfig.NextDigi+1);
	});
}

void DigitalTube::show(char digiOne, char digiTwo, char digiTree, char digiFour) {
	_DigiTubeConfig.disp[0] = digiFour;
	_DigiTubeConfig.disp[1] = digiTree;
	_DigiTubeConfig.disp[2] = digiTwo;
	_DigiTubeConfig.disp[3] = digiOne;

	for (int i=0;i<8;i++) {
		char val = _DigiTubeConfig.disp[i];
		if((val >= 32)&&(val <= 47)) val = (val == 45) ? 72 : 73;
		else if((val >= '0')&&(val <= '9')) val -= 48;
		else if((val >= 'A')&&(val <= 'Z')) val -= 45;
		else if((val >= 'a')&&(val <= 'z')) val -= 51;
    
		_DigiTubeConfig.disp[i] = val;
	}
}

void DigitalTube::print(int number) {
	show((number/1000)%10, (number/100)%10, (number/10)%10, number%10);
}
