#include "TimelineObject.h"

namespace Spriter
{


const std::string TimelineObject::XML_NAME = "object";
const std::string TimelineObject::FOLDER_ATTRIBUTE = "folder";
const std::string TimelineObject::FILE_ATTRIBUTE = "file";
const std::string TimelineObject::NAME_ATTRIBUTE = "name";
const std::string TimelineObject::PIVOT_X_ATTRIBUTE = "pivot_x";
const std::string TimelineObject::PIVOT_Y_ATTRIBUTE = "pivot_y";
const float TimelineObject::DEFAULT_PIVOT_X = 0.0f;
const float TimelineObject::DEFAULT_PIVOT_Y = 1.0f;

		TimelineObject::TimelineObject() : TimelineObjectBase()
		{
			InitializeInstanceFields();
			PivotX = DEFAULT_PIVOT_X;
			PivotY = DEFAULT_PIVOT_Y;
		}

		void TimelineObject::InitializeInstanceFields()
		{
			Folder_Renamed = 0;
			File_Renamed = 0;
			PivotX = 0;
			PivotY = 0;
		}
}
