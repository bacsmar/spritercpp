#include "MainlineKey.h"

namespace Spriter
{
	
const std::string MainlineKey::XML_NAME = "key";
const std::string MainlineKey::ID_ATTRIBUTE = "id";
const std::string MainlineKey::TIME_ATTRIBUTE = "time";

		MainlineKey::MainlineKey()
		{
			InitializeInstanceFields();
			Time = DEFAULT_TIME;
		}

		void MainlineKey::InitializeInstanceFields()
		{
			ID = 0;
			Time = 0;
		}
}
