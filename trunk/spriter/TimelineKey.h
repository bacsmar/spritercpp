#pragma once

#include <string>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace Spriter {   class TimelineObject;  }
namespace Spriter {   class TimelineBone;  }


namespace Spriter
{

		class TimelineKey
		{
		public:
			static const std::string XML_NAME;

			static const std::string ID_ATTRIBUTE;
			static const std::string TIME_ATTRIBUTE;
			static const std::string C1_ATTRIBUTE;
			static const std::string C2_ATTRIBUTE;
			static const std::string SPIN_ATTRIBUTE;

			static const int DEFAULT_SPIN = 1;

			int ID;
			int Time;
			float C1;
			float C2;
			int Spin;

			TimelineObject *Object;
			TimelineBone *Bone;

			TimelineKey();

		private:
			void InitializeInstanceFields();
		};
}
