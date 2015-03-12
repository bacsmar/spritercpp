#include "CharacterMapInstruction.h"

namespace Spriter
{
	
	

const std::string CharacterMapInstruction::XML_NAME = "map";
const std::string CharacterMapInstruction::FOLDER_ATTRIBUTE = "folder";
const std::string CharacterMapInstruction::FILE_ATTRIBUTE = "file";
const std::string CharacterMapInstruction::TARGET_FOLDER_ATTRIBUTE = "target_folder";
const std::string CharacterMapInstruction::TARGET_FILE_ATTRIBUTE = "target_file";

		CharacterMapInstruction::CharacterMapInstruction()
		{
			InitializeInstanceFields();
			TargetFolder = DEFAULT_TARGET_FOLDER;
			TargetFile = DEFAULT_TARGET_FILE;
		}

		void CharacterMapInstruction::InitializeInstanceFields()
		{
			Folder_Renamed = 0;
			File_Renamed = 0;
			TargetFolder = 0;
			TargetFile = 0;
		}
	
}
