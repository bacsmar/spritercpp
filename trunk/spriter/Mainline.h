#pragma once

#include <string>
#include <vector>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace Spriter {   class MainlineKey; }


namespace Spriter
{
	class Mainline : public std::vector<MainlineKey*>
	{
	public:
		static const std::string XML_NAME;
	};
}
