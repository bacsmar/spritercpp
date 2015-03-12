#pragma once

#include "TimelineObjectReference.h"
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace Spriter {   class ScmlObject;  }
namespace Spriter {   class Entity; } 
namespace Spriter {   class Animation;  }
namespace Spriter {   class MainlineKey;  }
namespace Spriter {   class TimelineObjectBase;  }


namespace Spriter
{
	
	
		class ScmlReference
		{
		private:
			int _EntityID;
			int _AnimationID;

		public:
			static const int INVALID = -1;
			ScmlObject *Reference;

				const int &getEntityID() const;
				void setEntityID(const int &value);
				const int &getAnimationID() const;
				void setAnimationID(const int &value);
			int Milliseconds;

			ScmlReference();

			void SetEntity(const std::string &pName);
			void SetEntity(int pID);
			void SetAnimation(const std::string &pName);
			void SetAnimation(int pID);

			void Update(int pMilliseconds);

			std::vector<TimelineObjectReference> GetTimelineObjects();


		private:
			void SetCurrentEntity(Entity *pEntity);

			void SetCurrentAnimation(Animation *pAnimation);

			Animation *GetCurrentAnimation();

			MainlineKey *GetCurrentMainlineKey(Animation *pAnimation);

			TimelineObjectReference GetInterpolatedTimelineObjectReference(TimelineObjectBase *pPrimaryTimelineObject, TimelineObjectBase *pSecondaryTimelineObject, int pSpin, float pProgress);

			TimelineObjectReference GetTimelineObjectReference(TimelineObjectBase *pTimelineObjectBase, int pSpin);

			TimelineObjectReference ApplyTransformations(TimelineObjectReference pParentReference, TimelineObjectReference pChildReference);

			float GetRadians(float pAngle);


		private:
			void InitializeInstanceFields();
		};
}
