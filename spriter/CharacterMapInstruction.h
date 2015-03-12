#pragma once

#include <string>


namespace Spriter
{
	
	
		class CharacterMapInstruction
		{
		public:
			static const std::string XML_NAME;

			static const std::string FOLDER_ATTRIBUTE;
			static const std::string FILE_ATTRIBUTE;
			static const std::string TARGET_FOLDER_ATTRIBUTE;
			static const std::string TARGET_FILE_ATTRIBUTE;

			static const int DEFAULT_TARGET_FOLDER = -1;
			static const int DEFAULT_TARGET_FILE = -1;

//C# TO C++ CONVERTER NOTE: The variable Folder was renamed since it is named the same as a user-defined type:
			int Folder_Renamed;
//C# TO C++ CONVERTER NOTE: The variable File was renamed since it is named the same as a user-defined type:
			int File_Renamed;
			int TargetFolder;
			int TargetFile;

			CharacterMapInstruction();

		private:
			void InitializeInstanceFields();
		};
	
}
