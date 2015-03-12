#pragma once

#include <string>
#include "ISpriterKey.h"

namespace Spriter
{
	
	
		class File : public ISpriterKey
		{
		public:
			static const std::string XML_NAME;

			static const std::string ID_ATTRIBUTE;
			static const std::string NAME_ATTRIBUTE;
			static const std::string WIDTH_ATTRIBUTE;
			static const std::string HEIGHT_ATTRIBUTE;
			static const std::string PIVOT_X_ATTRIBUTE;
			static const std::string PIVOT_Y_ATTRIBUTE;

			static const float DEFAULT_PIVOT_X;
			static const float DEFAULT_PIVOT_Y;

			int Width;
			int Height;

			float PivotX;
			float PivotY;

			File();

		private:
			void InitializeInstanceFields();
		};
}
