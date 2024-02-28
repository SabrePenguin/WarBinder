#ifndef DEVICE_HANDLER_H
#define DEVICE_HANDLER_H
#include <vector>
#include <SDL.h>
#include <memory>
#include <string>
class Device ;
class UserInterface ;

class DeviceHandler
{
public:
	DeviceHandler() ;
	std::vector<Device> find_devices() ;
	void shutdown() ;
	void add_ui_observer( std::shared_ptr<UserInterface> _ui ) ;
	std::string device_change( SDL_Event* con_event ) ;
	void clear_ui_observers() ;
private:
	void remove_device( SDL_JoystickID _controller ) ;
	std::string add_device( int index ) ;
	SDL_GameController* find_device( SDL_JoystickID _joy_id ) ;
	/*The observer for the ui. Made a vector in case of wierd stuff.*/
	std::vector<std::shared_ptr<UserInterface>> ui_observer ;
	std::vector<SDL_GameController*> game_controllers ;
	int num_controllers ; 
};

#endif // !DEVICE_HANDLER_H