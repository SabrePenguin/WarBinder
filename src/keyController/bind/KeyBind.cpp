#include "KeyBind.h"

KeyBind::KeyBind( char _mode, bool _axis, bool _required) :
	mode( _mode ), axis( _axis ), required( true )
{

}

char KeyBind::get_mode() {
	return this->mode ;
}