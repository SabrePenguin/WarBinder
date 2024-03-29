#ifndef JOYSTICK_H
#define JOYSTICK_H
#include "Control.h"
class Keybind ;
class Joystick : public Control
{
public:
	Joystick( std::string _joystick_id, std::string _local_name, bool _is_axis ) ;
	~Joystick() ;
	void add_bind( KeyBind* _bind ) ;
	std::string get_local_name() ;
private:
	//The internal joystick button/axis id
	std::string joystick_id;
	//The local joystick name
	std::string local_joy;
	//Indicates if the given id is an axis or not
	bool is_axis ;
};
#endif // !JOYSTICK_H