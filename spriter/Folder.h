#pragma once

#include <string>

#include "ISpriterKey.h"
#include "SpriterKeyList.h"

//C# TO C++ CONVERTER NOTE: Forward class declarations:
namespace Spriter {   class File;  }


namespace Spriter
{
	
	
		class Folder : public ISpriterKey
		{
		public:
			static const std::string XML_NAME;

			static const std::string ID_ATTRIBUTE;
			static const std::string NAME_ATTRIBUTE;

			SpriterKeyList<File*> *Files;

		private:
			void InitializeInstanceFields();

		public:
			Folder()
			{
				InitializeInstanceFields();
			}
		};
}
