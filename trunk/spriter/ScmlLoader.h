#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <functional>
#include <iostream>
#include <fstream>

#include <map>

#include "pugixml.hpp"

#if _MSC_VER < 1600
	using namespace std::tr1;	
	#define nullptr NULL
#endif


namespace Spriter 
{ 
	class ScmlObject;
	class Folder;
	class Entity;
	class File;
	class Animation;
	class Mainline;
	class MainlineKey;
	class MainlineObjectReference;
	class BoneReference;
	class Timeline;
	class TimelineKey;
	class TimelineObject;
	class TimelineBone;
	class CharacterMap;
	class CharacterMapInstruction;
}

namespace Spriter
{
	class ScmlLoader
	{
	public:
		ScmlObject *LoadFromFile(const std::string &pFilename);

		ScmlObject *LoadFromStream(std::ifstream *pStream);

		ScmlObject *LoadFromXml(const std::string &pXml);


	protected:
		virtual void OnException(std::exception &pException);

		virtual void OnScmlObjectLoaded(ScmlObject *pObject);

		virtual void OnFolderLoaded(Folder *pFolder);

		virtual void OnFileLoaded(File *pFile);

		virtual void OnEntityLoaded(Entity *pEntity);

		virtual void OnAnimationLoaded(Animation *pAnimation);

		virtual void OnMainlineLoaded(Mainline *pMainline);

		virtual void OnMainlineKeyLoaded(MainlineKey *pMainlineKey);

		virtual void OnMainlineObjectReferenceLoaded(MainlineObjectReference *pMainlineObjectReference);

		virtual void OnBoneReferenceLoaded(BoneReference *pBoneReference);

		virtual void OnTimelineLoaded(Timeline *pTimeline);

		virtual void OnTimelineKeyLoaded(TimelineKey *pTimelineKey);

		virtual void OnTimelineObjectLoaded(TimelineObject *pTimelineObject);

		virtual void OnTimelineBoneLoaded(TimelineBone *pTimelineBone);

		virtual void OnCharacterMapLoaded(CharacterMap *pCharacterMap);

		virtual void OnCharacterMapInstructionLoaded(CharacterMapInstruction *pCharacterMapInstruction);

	private:

		Folder *LoadFolder(pugi::xml_node *pElement);

		File *LoadFile(pugi::xml_node *pElement);

		Entity *LoadEntity(pugi::xml_node *pElement);

		Animation *LoadAnimation(pugi::xml_node *pElement);

		Mainline *LoadMainline(pugi::xml_node *pElement);

		MainlineKey *LoadMainlineKey(pugi::xml_node *pElement);

		MainlineObjectReference *LoadMainlineObjectReference(pugi::xml_node *pElement);

		BoneReference *LoadBoneReference(pugi::xml_node *pElement);

		Timeline *LoadTimeline(pugi::xml_node *pElement);

		TimelineKey *LoadTimelineKey(pugi::xml_node *pElement);

		TimelineObject *LoadTimelineObject(pugi::xml_node *pElement);

		TimelineBone *LoadTimelineBone(pugi::xml_node *pElement);

		CharacterMap *LoadCharacterMap(pugi::xml_node *pElement);

		CharacterMapInstruction *LoadCharacterMapInstruction(pugi::xml_node *pElement);


	};
}
