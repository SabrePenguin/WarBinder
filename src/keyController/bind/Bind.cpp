#include <vector>
#include <string>
#include "Bind.h"
#include "KeyBind.h"
#include "../control/Control.h"

/**
 * @brief The constructor
 * @param _internal_id: The internal id of the bind, such as ID_AAM
 * @param _text_id: What will be displayed to the user
 * @param _mode: The gamemode that this belongs to
*/
Bind::Bind(std::string _internal_id, std::string _text_id, char _mode, bool _required) : 
	KeyBind( _mode, false, _required ), internal_id(_internal_id), text_id(_text_id)
{

}

/**
 * @brief Adds a vector of keys to the current Bind.
 * @param _control_combo : vector of implemented Control classes
*/
void Bind::add_control( std::vector<Control*> _control_combo, bool _up )
{
	this->control.push_back( _control_combo );
}