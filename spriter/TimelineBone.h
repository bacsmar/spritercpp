#pragma once

#include "TimelineObjectBase.h"
#include <string>


namespace Spriter
{
	
		class TimelineBone : public TimelineObjectBase
		{
		public:
			static const std::string XML_NAME;

			TimelineBone();
		};
}
