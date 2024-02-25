#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

class UserInterface
{
public:
//Gets updated through an update()
//Call Binder, which then calls relevant controller. May get assigned here instead.
//DeviceHandler is a notifier, which notifies this that the controller is gone.
//Model contains SDL loop
//Gets information by calling relevant controller. Will be assigned here.

	// Informs the UI that the controllers been added or removed
	virtual void controller_change_notify() {} ;
	virtual void main_loop() {} ;
private:

};

#endif // !USER_INTERFACE_H