#include "Folder.h"

namespace Spriter
{
	

const std::string Folder::XML_NAME = "folder";
const std::string Folder::ID_ATTRIBUTE = "id";
const std::string Folder::NAME_ATTRIBUTE = "name";

		void Folder::InitializeInstanceFields()
		{
			ID = 0;
		}
	
}
