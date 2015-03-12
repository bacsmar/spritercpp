#pragma once

#include "TimelineObjectBase.h"
#include <string>


namespace Spriter
{
		class TimelineObject : public TimelineObjectBase
		{
		public:
			static const std::string XML_NAME;

			static const std::string FOLDER_ATTRIBUTE;
			static const std::string FILE_ATTRIBUTE;
			static const std::string NAME_ATTRIBUTE;
			static const std::string PIVOT_X_ATTRIBUTE;
			static const std::string PIVOT_Y_ATTRIBUTE;

			static const float DEFAULT_PIVOT_X;
			static const float DEFAULT_PIVOT_Y;


//C# TO C++ CONVERTER NOTE: The variable Folder was renamed since it is named the same as a user-defined type:
			int Folder_Renamed;
//C# TO C++ CONVERTER NOTE: The variable File was renamed since it is named the same as a user-defined type:
			int File_Renamed;
			std::string Name;

			float PivotX;
			float PivotY;


			TimelineObject();

		private:
			void InitializeInstanceFields();
		};
}
