#include "TimelineObjectBase.h"

namespace Spriter
{
	
const std::string TimelineObjectBase::X_ATTRIBUTE = "x";
const std::string TimelineObjectBase::Y_ATTRIBUTE = "y";
const std::string TimelineObjectBase::ANGLE_ATTRIBUTE = "angle";
const std::string TimelineObjectBase::SCALE_X_ATTRIBUTE = "scale_x";
const std::string TimelineObjectBase::SCALE_Y_ATTRIBUTE = "scale_y";
const std::string TimelineObjectBase::SPIN_ATTRIBUTE = "spin";
const std::string TimelineObjectBase::RED_MASK_ATTRIBUTE = "r";
const std::string TimelineObjectBase::GREEN_MASK_ATTRIBUTE = "g";
const std::string TimelineObjectBase::BLUE_MASK_ATTRIBUTE = "b";
const std::string TimelineObjectBase::ALPHA_MASK_ATTRIBUTE = "a";
const float TimelineObjectBase::DEFAULT_X = 0.0f;
const float TimelineObjectBase::DEFAULT_Y = 0.0f;
const float TimelineObjectBase::DEFAULT_ANGLE = 0.0f;
const float TimelineObjectBase::DEFAULT_SCALE_X = 1.0f;
const float TimelineObjectBase::DEFAULT_SCALE_Y = 1.0f;
const float TimelineObjectBase::DEFAULT_RED_MASK = 1.0f;
const float TimelineObjectBase::DEFAULT_BLUE_MASK = 1.0f;
const float TimelineObjectBase::DEFAULT_GREEN_MASK = 1.0f;
const float TimelineObjectBase::DEFAULT_ALPHA_MASK = 1.0f;

		TimelineObjectBase::TimelineObjectBase()
		{
			InitializeInstanceFields();
			X = DEFAULT_X;
			Y = DEFAULT_Y;
			Angle = DEFAULT_ANGLE;
			ScaleX = DEFAULT_SCALE_X;
			ScaleY = DEFAULT_SCALE_Y;

			RedMask = DEFAULT_RED_MASK;
			BlueMask = DEFAULT_BLUE_MASK;
			GreenMask = DEFAULT_GREEN_MASK;
			AlphaMask = DEFAULT_ALPHA_MASK;
		}

		void TimelineObjectBase::InitializeInstanceFields()
		{
			X = 0;
			Y = 0;
			Angle = 0;
			ScaleX = 0;
			ScaleY = 0;
			RedMask = 0;
			GreenMask = 0;
			BlueMask = 0;
			AlphaMask = 0;
		}
}
