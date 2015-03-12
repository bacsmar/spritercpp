#pragma once

namespace Spriter
{
	class MathHelper //final
	{
	public:
		static float Linear(float pA, float pB, float pPercentComplete);

		//spin off; on t=15, tk=1 tk2=2, spin is 1.... HOW?!
		static float AngleLinear(float pStartAngle, float pEndAngle, float pPercentComplete, int pSpin);

		static float Quadratic(float pA, float pB, float pC, float pPercentComplete);

		static float Cubic(float pA, float pB, float pC, float pD, float pPercentComplete);
	};
}
