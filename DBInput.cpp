#include "DBInput.h"


DBInput::DBInput ( uint8_t pin, uint8_t delay )
{
	_pin = pin;
	_dbdelay = delay;
	_curstate = digitalRead ( pin );
	_dbstate = _curstate;
	_just = true;
	pinMode ( pin, INPUT_PULLUP );
}

bool DBInput::Poll ( )
{
	int reading = digitalRead ( _pin );
	unsigned long ts = millis ( );

	if ( reading != _curstate )
	{
		_dbstarttime = ts;
		_curstate = reading;
	}
	else if ( ts - _dbstarttime > _dbdelay )
	{
		_curstate = reading;
		// stable reading
		if ( reading != _dbstate )
		{
			_dbstate = reading;
			_just = true;
			return true;
		}
	}
	return false;
}

uint8_t DBInput::GetCurrentState ( )
{
	return _curstate;
}

uint8_t DBInput::GetDBState ( )
{
	if ( _just )
	{
		_just = false;
		return _curstate + 2;
	}
	else return _curstate;
}
