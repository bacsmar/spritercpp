#include "Timeline.h"

namespace Spriter
{
	
const std::string Timeline::XML_NAME = "timeline";
const std::string Timeline::ID_ATTRIBUTE = "id";
const std::string Timeline::NAME_ATTRIBUTE = "name";

		void Timeline::InitializeInstanceFields()
		{
			ID = 0;
		}
}
