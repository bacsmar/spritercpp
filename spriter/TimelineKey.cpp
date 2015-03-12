#include "TimelineKey.h"


namespace Spriter
{
	
const std::string TimelineKey::XML_NAME = "key";
const std::string TimelineKey::ID_ATTRIBUTE = "id";
const std::string TimelineKey::TIME_ATTRIBUTE = "time";
const std::string TimelineKey::C1_ATTRIBUTE = "c1";
const std::string TimelineKey::C2_ATTRIBUTE = "c2";
const std::string TimelineKey::SPIN_ATTRIBUTE = "spin";

		TimelineKey::TimelineKey()
		{
			InitializeInstanceFields();
			Spin = DEFAULT_SPIN;
		}

		void TimelineKey::InitializeInstanceFields()
		{			
			ID = 0;
			Time = 0;
			C1 = 0;
			C2 = 0;
			Spin = DEFAULT_SPIN;
		}
}
