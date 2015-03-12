#pragma once
#include <string>


namespace Spriter
{
	
	
		class BoneReference
		{
		public:
			static const std::string XML_NAME;

			static const std::string ID_ATTRIBUTE;
			static const std::string KEY_ATTRIBUTE;
			static const std::string TIMELINE_ATTRIBUTE;
			static const std::string PARENT_ATTRIBUTE;

			static const int DEFAULT_PARENT = -1;

			int ID;
			int Key;
//C# TO C++ CONVERTER NOTE: The variable Timeline was renamed since it is named the same as a user-defined type:
			int Timeline_Renamed;
			int Parent;

			BoneReference();

		private:
			void InitializeInstanceFields();
		};
	
}
