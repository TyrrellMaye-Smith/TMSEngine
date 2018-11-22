#include "Exception.h"

namespace tmsengine
{
	Exception::Exception(std::string _message)
	{
		message = _message;
	}

	Exception::~Exception() throw()
	{

	}

	const char* Exception::what()
	{
		return "Exception";
	}
}