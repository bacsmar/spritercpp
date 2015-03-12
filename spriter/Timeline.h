#pragma once

#include <string>
#include <vector>
#include "ISpriterKey.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace Spriter {  class TimelineKey;  }

namespace Spriter
{
		class Timeline : public ISpriterKey
		{
		public:
			static const std::string XML_NAME;

			static const std::string ID_ATTRIBUTE;
			static const std::string NAME_ATTRIBUTE;

			std::vector<TimelineKey*> Keys;

		private:
			void InitializeInstanceFields();

public:
			Timeline()
			{
				InitializeInstanceFields();
			}
		};
}
