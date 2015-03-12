#include "MainlineObjectReference.h"

namespace Spriter
{

const std::string MainlineObjectReference::XML_NAME = "object_ref";
const std::string MainlineObjectReference::ID_ATTRIBUTE = "id";
const std::string MainlineObjectReference::KEY_ATTRIBUTE = "key";
const std::string MainlineObjectReference::TIMELINE_ATTRIBUTE = "timeline";
const std::string MainlineObjectReference::PARENT_ATTRIBUTE = "parent";
const std::string MainlineObjectReference::Z_INDEX_ATTRIBUTE = "z_index";

		MainlineObjectReference::MainlineObjectReference()
		{
			InitializeInstanceFields();
			Parent = DEFAULT_PARENT;
		}

		void MainlineObjectReference::InitializeInstanceFields()
		{
			ID = 0;
			Key = 0;
			Timeline_Renamed = 0;
			Parent = 0;
			ZIndex = 0;
		}
}
