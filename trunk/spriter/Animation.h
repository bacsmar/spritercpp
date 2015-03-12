#pragma once

#include <string>
#include "ISpriterKey.h"
#include "SpriterKeyList.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace Spriter {   class Mainline;  }
namespace Spriter {   class Timeline;  }

namespace Spriter
{
	
	
		class Animation : public ISpriterKey
		{
		public:
			static const std::string XML_NAME;

			static const std::string ID_ATTRIBUTE;
			static const std::string NAME_ATTRIBUTE;
			static const std::string LENGTH_ATTRIBUTE;
			static const std::string LOOPING_ATTRIBUTE;
			static const std::string LOOP_TO_ATTRIBUTE;

			static const bool DEFAULT_LOOPING = true;

			int Length;
			bool Looping;
			int LoopTo;

			Mainline *MainlineKeys;
			SpriterKeyList<Timeline*> *Timelines;

			Animation();

		private:
			void InitializeInstanceFields();
		};
	
}
