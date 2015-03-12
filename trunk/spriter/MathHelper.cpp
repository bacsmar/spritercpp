#include "MathHelper.h"


namespace Spriter
{

	float MathHelper::Linear(float pA, float pB, float pPercentComplete)
	{
		return ((pB - pA) * pPercentComplete) + pA;
	}

	float MathHelper::AngleLinear(float pStartAngle, float pEndAngle, float pPercentComplete, int pSpin)
	{
		if (pSpin == 0)
		{
			return pStartAngle;
		}
		if (pSpin > 0)
		{
			if ((pEndAngle - pStartAngle) < 0)
			{
				pEndAngle += 360;
			}
		}
		else if (pSpin < 0)
		{
			if ((pEndAngle - pStartAngle) > 0)
			{
				pEndAngle -= 360;
			}
		}

		return Linear(pStartAngle, pEndAngle, pPercentComplete);
	}

	float MathHelper::Quadratic(float pA, float pB, float pC, float pPercentComplete)
	{
		return Linear(Linear(pA, pB, pPercentComplete), Linear(pB, pC, pPercentComplete), pPercentComplete);
	}

	float MathHelper::Cubic(float pA, float pB, float pC, float pD, float pPercentComplete)
	{
		return Linear(Quadratic(pA, pB, pC, pPercentComplete), Quadratic(pB, pC, pD, pPercentComplete), pPercentComplete);
	}
}
