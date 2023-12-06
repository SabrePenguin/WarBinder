#ifndef BIND_H
#define BIND_H
#include <vector>
#include <string>
#include "../control/Control.h"

class Bind
{
	public:
		Bind();
		void add_control(Control* _control);
	private:
		int id;
		std::string text_id;
		std::vector<std::vector<Control*>> control;
};


#endif