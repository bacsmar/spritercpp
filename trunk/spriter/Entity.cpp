#include "Entity.h"

namespace Spriter
{


const std::string Entity::XML_NAME = "entity";
const std::string Entity::ID_ATTRIBUTE = "id";
const std::string Entity::NAME_ATTRIBUTE = "name";

		void Entity::InitializeInstanceFields()
		{
			ID = 0;
		}

}
