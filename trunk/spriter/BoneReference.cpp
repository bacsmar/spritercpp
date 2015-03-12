#include "BoneReference.h"

namespace Spriter
{
	
	

const std::string BoneReference::XML_NAME = "bone_ref";
const std::string BoneReference::ID_ATTRIBUTE = "id";
const std::string BoneReference::KEY_ATTRIBUTE = "key";
const std::string BoneReference::TIMELINE_ATTRIBUTE = "timeline";
const std::string BoneReference::PARENT_ATTRIBUTE = "parent";

		BoneReference::BoneReference()
		{
			InitializeInstanceFields();
			Parent = DEFAULT_PARENT;
		}

		void BoneReference::InitializeInstanceFields()
		{
			ID = 0;
			Key = 0;
			Timeline_Renamed = 0;
			Parent = 0;
		}
	
}
