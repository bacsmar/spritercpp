#pragma once

#include <string>


namespace Spriter
{
	
		class TimelineObjectBase
		{
		public:
			static const std::string X_ATTRIBUTE;
			static const std::string Y_ATTRIBUTE;
			static const std::string ANGLE_ATTRIBUTE;
			static const std::string SCALE_X_ATTRIBUTE;
			static const std::string SCALE_Y_ATTRIBUTE;
			static const std::string SPIN_ATTRIBUTE;
			static const std::string RED_MASK_ATTRIBUTE;
			static const std::string GREEN_MASK_ATTRIBUTE;
			static const std::string BLUE_MASK_ATTRIBUTE;
			static const std::string ALPHA_MASK_ATTRIBUTE;

			static const float DEFAULT_X;
			static const float DEFAULT_Y;
			static const float DEFAULT_ANGLE;
			static const float DEFAULT_SCALE_X;
			static const float DEFAULT_SCALE_Y;
			static const float DEFAULT_RED_MASK;
			static const float DEFAULT_BLUE_MASK;
			static const float DEFAULT_GREEN_MASK;
			static const float DEFAULT_ALPHA_MASK;

			float X;
			float Y;
			float Angle;
			float ScaleX;
			float ScaleY;
			float RedMask;
			float GreenMask;
			float BlueMask;
			float AlphaMask;

			TimelineObjectBase();

		private:
			void InitializeInstanceFields();
		};
}
