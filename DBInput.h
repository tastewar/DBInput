#ifndef DBInput_h
#define DBInput_h

#include <Arduino.h>

typedef enum
{
	DBISLow,
	DBISHigh,
	// add 2 for when "just" flag is set
	DBISJustLow,
	DBISJustHigh,
} DBIState;

class DBInput
{
	public:
	DBInput ( uint8_t pin, uint8_t delay );
	bool Poll ( );
	uint8_t GetCurrentState ( );
	uint8_t GetDBState ( );

	private:
	uint8_t _pin;
	uint8_t _dbdelay;
	uint8_t _curstate;
	uint8_t _dbstate;
	bool _just;
	unsigned long _dbstarttime;


};

#endif