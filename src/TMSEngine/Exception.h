#ifndef TMSENGINE_EXCEPTION_H_
#define TMSENGINE_EXCEPTION_H_

#include <exception>
#include <string>

namespace tmsengine
{

	class Exception : public std::exception
	{
	public:
		Exception(std::string _message);
		~Exception() throw();

		const char *what();
	private:
		std::string message;
	};
}
#endif