#include "Animation.h"


namespace Spriter
{
	
	

const std::string Animation::XML_NAME = "animation";
const std::string Animation::ID_ATTRIBUTE = "id";
const std::string Animation::NAME_ATTRIBUTE = "name";
const std::string Animation::LENGTH_ATTRIBUTE = "length";
const std::string Animation::LOOPING_ATTRIBUTE = "looping";
const std::string Animation::LOOP_TO_ATTRIBUTE = "loop_to";

		Animation::Animation()
		{
			InitializeInstanceFields();
			Looping = DEFAULT_LOOPING;
		}

		void Animation::InitializeInstanceFields()
		{
			ID = 0;
			Length = 0;
			Looping = false;
			LoopTo = 0;
		}
	
}
