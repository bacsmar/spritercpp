#pragma once

#include <string>
#include <vector>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace Spriter {   class MainlineObjectReference;  }
namespace Spriter {   class BoneReference;  }


namespace Spriter
{
	class MainlineKey
	{
	public:
		static const std::string XML_NAME;

		static const std::string ID_ATTRIBUTE;
		static const std::string TIME_ATTRIBUTE;

		static const int DEFAULT_TIME = 0;

		int ID;
		int Time;

		std::vector<MainlineObjectReference*> ObjectReferences;
		std::vector<BoneReference*> BoneReferences;

		MainlineKey();

	private:
		void InitializeInstanceFields();
	};
}
