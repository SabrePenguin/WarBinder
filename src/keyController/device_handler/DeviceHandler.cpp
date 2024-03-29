#include <SDL.h>
#include <iostream>
#include <vector>
#include <memory>
#include "DeviceHandler.h"
#include "Device.h"
#include "UserInterface.h"

DeviceHandler::DeviceHandler() :
	num_controllers( 0 )
{
}


std::vector<Device> DeviceHandler::find_devices()
{
	std::vector<Device> device_list ;
	for( int iter = 0 ; iter < SDL_NumJoysticks() ; ++iter )
	{
		if( SDL_IsGameController( iter ) )
		{
			add_device( iter ) ;
		}
	}
	return device_list ;
}


SDL_GameController* DeviceHandler::find_device( SDL_JoystickID _dev_id )
{
	//Loop through devices. Uses vector instead of array.
	for( auto iter = game_controllers.begin() ; iter != game_controllers.end() ; ++iter )
	{
		if( _dev_id == SDL_JoystickInstanceID( SDL_GameControllerGetJoystick( *iter ) ) )
		{
			return *iter ;
		}
	}
	return nullptr ;
}


std::string DeviceHandler::add_device( int device_index )
{
	std::string mapping ;
	SDL_JoystickID controller_id = SDL_JoystickGetDeviceInstanceID( device_index ) ;
	// Check if controller id exists
	if( controller_id < 0 )
		return mapping ;

	//Check if this exists in the list. If it does, quit this function as we don't need it.
	if( find_device( controller_id ) )
		return mapping ;


	SDL_GameController* controller = SDL_GameControllerOpen( device_index ) ;
	// Check if controller was created
	if( !controller )
		return mapping ;

	mapping = SDL_GameControllerMapping( controller ) ;
	game_controllers.push_back( controller ) ;
	return mapping ;
}

void DeviceHandler::remove_device( SDL_JoystickID _controller )
{
	SDL_GameController* control_p = find_device( _controller ) ;

	// Check for nullptr
	if( !control_p )
		return ;

	//Search through vector
	for( auto iter = game_controllers.begin() ; iter != game_controllers.end() ; ++iter )
	{
		//Erase item
		if( *iter == control_p )
		{
			game_controllers.erase( iter ) ;
			return ;
		}
	}
}


void DeviceHandler::shutdown()
{
	for( auto iter = this->game_controllers.begin() ; iter != this->game_controllers.end() ; ++iter )
	{
		SDL_GameControllerClose( ( *iter ) ) ;
	}
	SDL_Quit() ;
}


void DeviceHandler::add_ui_observer( std::shared_ptr<UserInterface> _ui )
{
	this->ui_observer.push_back( _ui ) ;
}


std::string DeviceHandler::device_change( SDL_Event* con_event )
{
	std::string result ;
	if( con_event->type == SDL_CONTROLLERDEVICEADDED || con_event->type == SDL_JOYDEVICEADDED )
	{
		result = this->add_device( con_event->cdevice.which ) ;
	}
	else if( con_event->type == SDL_CONTROLLERDEVICEREMOVED || con_event->type == SDL_JOYDEVICEREMOVED )
	{
		this->remove_device( con_event->cdevice.which ) ;
	}
	for( auto iter = this->ui_observer.begin() ; iter != this->ui_observer.end() ; ++iter )
	{
		iter->get()->controller_change_notify() ;
	}

	return result ;
}


void DeviceHandler::clear_ui_observers()
{
	ui_observer.clear() ;
}