#ifndef PTUI_H
#define PTUI_H
#include "UserInterface.h"
#include <string>

class KeyBindController ;

class ptui : public UserInterface
{
public:
	ptui( std::shared_ptr<KeyBindController> _controller ) ;
	void main_loop( std::shared_ptr<KeyBindController> _controller ) ;
	void controller_change_notify() ;

private:
	void assign_key_to_bind( std::shared_ptr<KeyBindController> _controller, std::string _input_key, std::string _bind_key ) ;
	std::shared_ptr<KeyBindController> controller ;
};

#endif // !PTUI_H
