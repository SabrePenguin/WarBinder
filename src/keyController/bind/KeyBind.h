#ifndef KEYBIND_H
#define KEYBIND_H
#include <vector>
#include <string>

class Control ;
enum class controller ;
struct Imported_Axis ;
class KeyBind
{
	public:
		KeyBind(char _mode, bool _axis, bool _required) ;
		virtual void add_control( std::vector<Control*> _control_combo, controller _up ) { return ; };
		virtual void add_second_bind( std::string _text_id, controller _up ) { return ; } ;
		virtual void add_axis( Control* _axis ) { return ; } ;
		virtual void add_data( Imported_Axis* _imported ) { return ; };
		char get_mode() ;
		bool is_axis() ;
	protected:
		//Unfortunate type check
		bool axis ;
		//The gamemode character representation
		char mode ;
		//Whether the given control is required to play the game (ie. Fire guns)
		bool required ;
};

#endif // !KEYBIND_H