#include "File.h"

namespace Spriter
{
	
const std::string File::XML_NAME = "file";
const std::string File::ID_ATTRIBUTE = "id";
const std::string File::NAME_ATTRIBUTE = "name";
const std::string File::WIDTH_ATTRIBUTE = "width";
const std::string File::HEIGHT_ATTRIBUTE = "height";
const std::string File::PIVOT_X_ATTRIBUTE = "pivot_x";
const std::string File::PIVOT_Y_ATTRIBUTE = "pivot_y";
const float File::DEFAULT_PIVOT_X = 0.0f;
const float File::DEFAULT_PIVOT_Y = 1.0f;

		File::File()
		{
			InitializeInstanceFields();
			PivotX = DEFAULT_PIVOT_X;
			PivotY = DEFAULT_PIVOT_Y;
		}

		void File::InitializeInstanceFields()
		{
			ID = 0;
			Width = 0;
			Height = 0;
			PivotX = 0;
			PivotY = 0;
		}
}
