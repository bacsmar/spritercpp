#pragma once

namespace Spriter
{
		class SpatialInformation
		{
		public:
			float X;
			float Y;
			float Angle;
			float ScaleX;
			float ScaleY;
			float Alpha;
			int Spin;

		private:
			void InitializeInstanceFields();

public:
			SpatialInformation()
			{
				InitializeInstanceFields();
			}
		};
}
