#pragma once

#include <string>
#include "SpriterKeyList.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace Spriter {  class Folder;  }
namespace Spriter {  class Entity;  }

namespace Spriter
{
	
		class ScmlObject
		{
		public:
			static const std::string XML_NAME;

			SpriterKeyList<Folder*> *Folders;
			SpriterKeyList<Entity*> *Entities;
		};
}
