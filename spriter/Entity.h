#pragma once

#include <string>
#include <vector>

#include "ISpriterKey.h"
#include "SpriterKeyList.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace Spriter {   class CharacterMap; }
namespace Spriter {   class Animation;  }

namespace Spriter
{
		class Entity : public ISpriterKey
		{
		public:
			static const std::string XML_NAME;

			static const std::string ID_ATTRIBUTE;
			static const std::string NAME_ATTRIBUTE;

			std::vector<CharacterMap*> CharacterMaps;
			SpriterKeyList<Animation*> *Animations;

		private:
			void InitializeInstanceFields();

		public:
			Entity()
			{
				InitializeInstanceFields();
			}
		};
}
