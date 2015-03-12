#include "ScmlLoader.h"
#include "SpriterKeyList.h"
#include "ScmlObject.h"
#include "Folder.h"
#include "File.h"
#include "Entity.h"
#include "Animation.h"
#include "CharacterMap.h"
#include "Timeline.h"
#include "MainlineKey.h"
#include "BoneReference.h"
#include "TimelineKey.h"
#include "Mainline.h"
#include "TimelineObject.h"
#include "CharacterMapInstruction.h"
#include "TimelineBone.h"
#include "MainlineObjectReference.h"
#include <algorithm>
#include <map>

using namespace std;
using namespace pugi;


namespace Spriter
{

	ScmlObject *ScmlLoader::LoadFromFile(const std::string &pFilename)
	{
		ifstream file(pFilename.c_str());

		if (file.good())
		{
			return LoadFromStream(&file);
		}		

		return nullptr;
	}

	ScmlObject *ScmlLoader::LoadFromStream(std::ifstream *pStream)
	{
		if (pStream != nullptr)
		{
			try
			{
				string str;
				pStream->seekg(0,std::ios::end);
				str.reserve(pStream->tellg());
				pStream->seekg(0,std::ios::beg);

				str.assign((std::istreambuf_iterator<char>(*pStream)),std::istreambuf_iterator<char>());

				return LoadFromXml(str);
			}
			catch(...) {}
		}

		return nullptr;
	}

	ScmlObject *ScmlLoader::LoadFromXml(const std::string &pXml)
	{
		ScmlObject *result = new ScmlObject();

		result->Folders = new SpriterKeyList<Folder*>();
		result->Entities = new SpriterKeyList<Entity*>();		

		try
		{
			xml_document xml;
			pugi::xml_parse_result resultLoad = xml.load(pXml.c_str());
			//pugi::xml_parse_result resultLoad = xml.load_file(pXml.c_str());

			xml_node firstChild = xml.root().child("spriter_data");
			
			for (pugi::xml_node element = firstChild.first_child(); element; element = element.next_sibling())
			{
				std::string key =  element.name();
				std::transform(key.begin(),key.end(),key.begin(),::tolower);

				if( key == Folder::XML_NAME)
				{
					result->Folders->push_back( LoadFolder(&element));
				}else if ( key == Entity::XML_NAME)
				{
					result->Entities->push_back( LoadEntity(&element));
				}				
			}
		}
		catch (std::exception &ex)
		{
			OnException(ex);
		}

		result->Folders->Compile();
		result->Entities->Compile();

		return result;
	}

	void ScmlLoader::OnException(std::exception &pException)
	{
	}

	void ScmlLoader::OnScmlObjectLoaded(ScmlObject *pObject)
	{
	}

	void ScmlLoader::OnFolderLoaded(Folder *pFolder)
	{
	}

	void ScmlLoader::OnFileLoaded(File *pFile)
	{
	}

	void ScmlLoader::OnEntityLoaded(Entity *pEntity)
	{
	}

	void ScmlLoader::OnAnimationLoaded(Animation *pAnimation)
	{
	}

	void ScmlLoader::OnMainlineLoaded(Mainline *pMainline)
	{
	}

	void ScmlLoader::OnMainlineKeyLoaded(MainlineKey *pMainlineKey)
	{
	}

	void ScmlLoader::OnMainlineObjectReferenceLoaded(MainlineObjectReference *pMainlineObjectReference)
	{
	}

	void ScmlLoader::OnBoneReferenceLoaded(BoneReference *pBoneReference)
	{
	}

	void ScmlLoader::OnTimelineLoaded(Timeline *pTimeline)
	{
	}

	void ScmlLoader::OnTimelineKeyLoaded(TimelineKey *pTimelineKey)
	{
	}

	void ScmlLoader::OnTimelineObjectLoaded(TimelineObject *pTimelineObject)
	{
	}

	void ScmlLoader::OnTimelineBoneLoaded(TimelineBone *pTimelineBone)
	{		
	}

	void ScmlLoader::OnCharacterMapLoaded(CharacterMap *pCharacterMap)
	{
	}

	void ScmlLoader::OnCharacterMapInstructionLoaded(CharacterMapInstruction *pCharacterMapInstruction)
	{
	}	

	Folder *ScmlLoader::LoadFolder(xml_node *pElement)
	{
		Folder *result = new Folder();

		result->Files = new SpriterKeyList<File*>();		

		result->Name = pElement->attribute(Folder::NAME_ATTRIBUTE.c_str() ).value();
		result->ID	= pElement->attribute(Folder::ID_ATTRIBUTE.c_str() ).as_int();

		//for (auto element : *pElement)
		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{
			
			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);

			if(File::XML_NAME == key)
			{
				result->Files->push_back(LoadFile(&element));
			};			
		}

		result->Files->Compile();

		OnFolderLoaded(result);

		return result;
	}

	File *ScmlLoader::LoadFile(xml_node *pElement)
	{
		File *result = new File();

		result->Name = pElement->attribute( File::NAME_ATTRIBUTE.c_str() ).value();
		result->ID = pElement->attribute( File::ID_ATTRIBUTE.c_str() ).as_int();
		result->Width = pElement->attribute( File::WIDTH_ATTRIBUTE.c_str() ).as_int();
		result->Height = pElement->attribute( File::HEIGHT_ATTRIBUTE.c_str() ).as_int();
		result->PivotX = pElement->attribute( File::PIVOT_X_ATTRIBUTE.c_str() ).as_float();
		result->PivotY = pElement->attribute( File::PIVOT_Y_ATTRIBUTE.c_str() ).as_float();

		OnFileLoaded(result);

		return result;
	}

	Entity *ScmlLoader::LoadEntity(xml_node *pElement)
	{
		Entity *result = new Entity();

		result->Animations = new SpriterKeyList<Animation*>();
		//result->CharacterMaps = std::vector<CharacterMap*>();

		result->Name = pElement->attribute( Entity::NAME_ATTRIBUTE.c_str() ).value();
		result->ID = pElement->attribute( Entity::ID_ATTRIBUTE.c_str() ).as_int();


		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{

			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);

			if(Animation::XML_NAME == key)
			{
				result->Animations->push_back(LoadAnimation(&element));
			};			
			if(CharacterMap::XML_NAME == key)
			{
				//result->CharacterMaps->push_back(LoadCharacterMap(&element));
				result->CharacterMaps.push_back(LoadCharacterMap(&element));
			};			
		}

		result->Animations->Compile();

		OnEntityLoaded(result);

		return result;
	}

	Animation *ScmlLoader::LoadAnimation(xml_node *pElement)
	{
		Animation *result = new Animation();

		//result->MainlineKeys = new Mainline();
		result->MainlineKeys = 0;	//it will be filled later
		result->Timelines = new SpriterKeyList<Timeline*>();

		result->Name	= pElement->attribute(Animation::NAME_ATTRIBUTE.c_str() ).value();
		result->ID		= pElement->attribute(Animation::ID_ATTRIBUTE.c_str()).as_int();
		result->Length	= pElement->attribute(Animation::LENGTH_ATTRIBUTE.c_str()).as_int();
		result->Looping = pElement->attribute(Animation::LOOPING_ATTRIBUTE.c_str()).as_bool();
		result->LoopTo	= pElement->attribute(Animation::LOOP_TO_ATTRIBUTE.c_str()).as_int();

		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{

			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);

			if(Mainline::XML_NAME == key)
			{
				//result->MainlineKeys->push_back(LoadAnimation(&element));
				result->MainlineKeys = LoadMainline(&element);
			};			
			if(Timeline::XML_NAME == key)
			{				
				result->Timelines->push_back(LoadTimeline(&element));
			};			
		}
		
		result->Timelines->Compile();

		OnAnimationLoaded(result);

		return result;
	}

	Mainline *ScmlLoader::LoadMainline(xml_node *pElement)
	{
		Mainline *result = new Mainline();

		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{

			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);
			
			if(MainlineKey::XML_NAME == key)
			{				
				result->push_back(LoadMainlineKey(&element));
			};			
		}


		OnMainlineLoaded(result);

		return result;
	}

	MainlineKey *ScmlLoader::LoadMainlineKey(xml_node *pElement)
	{
		MainlineKey *result = new MainlineKey();

		//result->ObjectReferences = std::vector<MainlineObjectReference*>();
		//result->BoneReferences = std::vector<BoneReference*>();

		result->ID		= pElement->attribute(MainlineKey::ID_ATTRIBUTE.c_str() ).as_int();
		result->Time	= pElement->attribute(MainlineKey::TIME_ATTRIBUTE.c_str()).as_int(MainlineKey::DEFAULT_TIME);

		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{

			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);

			if ( MainlineObjectReference::XML_NAME == key)
			{				
				result->ObjectReferences.push_back(LoadMainlineObjectReference(&element));
			};	
			if ( BoneReference::XML_NAME == key)
			{
				result->BoneReferences.push_back(LoadBoneReference(&element));
			};
		}
		OnMainlineKeyLoaded(result);

		return result;
	}

	MainlineObjectReference *ScmlLoader::LoadMainlineObjectReference(xml_node *pElement)
	{
		MainlineObjectReference *result = new MainlineObjectReference();

		result->ID		= pElement->attribute(MainlineObjectReference::ID_ATTRIBUTE.c_str() ).as_int();
		result->Key		= pElement->attribute(MainlineObjectReference::KEY_ATTRIBUTE.c_str()).as_int();
		result->Timeline_Renamed	= pElement->attribute(MainlineObjectReference::TIMELINE_ATTRIBUTE.c_str()).as_int();
		result->Parent	= pElement->attribute(MainlineObjectReference::PARENT_ATTRIBUTE.c_str()).as_int( MainlineObjectReference::DEFAULT_PARENT);
		result->ZIndex	= pElement->attribute(MainlineObjectReference::Z_INDEX_ATTRIBUTE.c_str()).as_int();

		OnMainlineObjectReferenceLoaded(result);

		return result;
	}

	BoneReference *ScmlLoader::LoadBoneReference(xml_node *pElement)
	{
		BoneReference *result = new BoneReference();

		result->ID		= pElement->attribute(BoneReference::ID_ATTRIBUTE.c_str() ).as_int();
		result->Key		= pElement->attribute(BoneReference::KEY_ATTRIBUTE.c_str()).as_int();
		result->Timeline_Renamed	= pElement->attribute(BoneReference::TIMELINE_ATTRIBUTE.c_str()).as_int();		
		result->Parent	= pElement->attribute(BoneReference::PARENT_ATTRIBUTE.c_str()).as_int(BoneReference::DEFAULT_PARENT);

		OnBoneReferenceLoaded(result);

		return result;
	}

	Timeline *ScmlLoader::LoadTimeline(xml_node *pElement)
	{
		Timeline *result = new Timeline();

		//result->Keys = std::vector<TimelineKey*>();
		result->Name		= pElement->attribute(Timeline::NAME_ATTRIBUTE.c_str()).value();
		result->ID		= pElement->attribute(Timeline::ID_ATTRIBUTE.c_str() ).as_int();

		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{

			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);

			if ( TimelineKey::XML_NAME == key)
			{				
				result->Keys.push_back(LoadTimelineKey(&element));					
			};				
		}

		OnTimelineLoaded(result);

		return result;
	}

	TimelineKey *ScmlLoader::LoadTimelineKey(xml_node *pElement)
	{
		TimelineKey *result = new TimelineKey();
		
		result->ID		= pElement->attribute(TimelineKey::ID_ATTRIBUTE.c_str() ).as_int();
		result->Time	= pElement->attribute(TimelineKey::TIME_ATTRIBUTE.c_str() ).as_int();
		result->C1		= pElement->attribute(TimelineKey::C1_ATTRIBUTE.c_str() ).as_float();
		result->C2		= pElement->attribute(TimelineKey::C2_ATTRIBUTE.c_str() ).as_float();
		result->Spin	= pElement->attribute(TimelineKey::SPIN_ATTRIBUTE.c_str() ).as_int( TimelineKey::DEFAULT_SPIN);

		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{

			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);

			if ( TimelineBone::XML_NAME == key)
			{				
				result->Bone = LoadTimelineBone(&element);					
			};				
			if ( TimelineObject::XML_NAME == key)
			{				
				result->Object = LoadTimelineObject(&element);					
			};
		}

		OnTimelineKeyLoaded(result);

		return result;
	}

	TimelineObject *ScmlLoader::LoadTimelineObject(xml_node *pElement)
	{
		TimelineObject *result = new TimelineObject();

		result->X		= pElement->attribute(TimelineObject::X_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_X);
		result->Y		= pElement->attribute(TimelineObject::Y_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_Y);
		result->Angle	= pElement->attribute(TimelineObject::ANGLE_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_ANGLE);
		result->ScaleX	= pElement->attribute(TimelineObject::SCALE_X_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_SCALE_X);
		result->ScaleY	= pElement->attribute(TimelineObject::SCALE_Y_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_SCALE_Y);

		result->RedMask		= pElement->attribute(TimelineObject::RED_MASK_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_RED_MASK);
		result->GreenMask	= pElement->attribute(TimelineObject::GREEN_MASK_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_GREEN_MASK);
		result->BlueMask	= pElement->attribute(TimelineObject::BLUE_MASK_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_BLUE_MASK);
		result->AlphaMask	= pElement->attribute(TimelineObject::ALPHA_MASK_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_ALPHA_MASK);

		result->Folder_Renamed	= pElement->attribute(TimelineObject::FOLDER_ATTRIBUTE.c_str() ).as_int( );
		result->File_Renamed	= pElement->attribute(TimelineObject::FILE_ATTRIBUTE.c_str() ).as_int();
		result->Name			= pElement->attribute(TimelineObject::NAME_ATTRIBUTE.c_str() ).value();
		result->PivotX			= pElement->attribute(TimelineObject::PIVOT_X_ATTRIBUTE.c_str() ).as_float( TimelineObject::DEFAULT_PIVOT_X);
		result->PivotY			= pElement->attribute(TimelineObject::PIVOT_Y_ATTRIBUTE.c_str() ).as_float(	TimelineObject::DEFAULT_PIVOT_Y);

		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{
			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);

			// wasn't supported in c# also
			if ( TimelineObject::XML_NAME == key)
			{					
			//	result->MainlineObjectReferences.push_back(LoadMainlineObjectReference(&element));					
			};				
		}

		OnTimelineObjectLoaded(result);

		return result;
	}
	
	TimelineBone *ScmlLoader::LoadTimelineBone(xml_node *pElement)
	{
		TimelineBone *result = new TimelineBone();

		result->X		= pElement->attribute(TimelineBone::X_ATTRIBUTE.c_str() ).as_float( TimelineBone::DEFAULT_X);
		result->Y		= pElement->attribute(TimelineBone::Y_ATTRIBUTE.c_str() ).as_float( TimelineBone::DEFAULT_Y);
		result->Angle	= pElement->attribute(TimelineBone::ANGLE_ATTRIBUTE.c_str() ).as_float( TimelineBone::DEFAULT_ANGLE);
		result->ScaleX	= pElement->attribute(TimelineBone::SCALE_X_ATTRIBUTE.c_str() ).as_float( TimelineBone::DEFAULT_SCALE_X);
		result->ScaleY	= pElement->attribute(TimelineBone::SCALE_Y_ATTRIBUTE.c_str() ).as_float( TimelineBone::DEFAULT_SCALE_Y);

		result->RedMask		= pElement->attribute(TimelineBone::RED_MASK_ATTRIBUTE.c_str() ).as_float( TimelineBone::DEFAULT_RED_MASK);
		result->GreenMask	= pElement->attribute(TimelineBone::GREEN_MASK_ATTRIBUTE.c_str() ).as_float( TimelineBone::DEFAULT_GREEN_MASK);
		result->BlueMask	= pElement->attribute(TimelineBone::BLUE_MASK_ATTRIBUTE.c_str() ).as_float( TimelineBone::DEFAULT_BLUE_MASK);
		result->AlphaMask	= pElement->attribute(TimelineBone::ALPHA_MASK_ATTRIBUTE.c_str() ).as_float( TimelineBone::DEFAULT_ALPHA_MASK);

		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{

			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);

			// wasn't supported in c# also
			if ( TimelineBone::XML_NAME == key)
			{				
				//result->TimelineBone .push_back(LoadMainlineObjectReference(&element));					
			};				
		}

		OnTimelineBoneLoaded(result);

		return result;
	}

	CharacterMap *ScmlLoader::LoadCharacterMap(xml_node *pElement)
	{
		CharacterMap *result = new CharacterMap();
		//result->Maps = std::vector<CharacterMapInstruction*>();

		result->ID		= pElement->attribute(CharacterMap::ID_ATTRIBUTE.c_str() ).as_int();
		result->Name		= pElement->attribute(CharacterMap::NAME_ATTRIBUTE.c_str() ).value();

		for (pugi::xml_node element = pElement->first_child(); element; element = element.next_sibling() )
		{

			std::string key = element.name();
			std::transform(key.begin(),key.end(),key.begin(),::tolower);
			
			if ( CharacterMapInstruction::XML_NAME == key )
			{				
				result->Maps.push_back(LoadCharacterMapInstruction(&element));					
			};				
		}		

		OnCharacterMapLoaded(result);

		return result;
	}

	CharacterMapInstruction *ScmlLoader::LoadCharacterMapInstruction(xml_node *pElement)
	{
		CharacterMapInstruction *result = new CharacterMapInstruction();

		result->Folder_Renamed	= pElement->attribute(CharacterMapInstruction::FOLDER_ATTRIBUTE.c_str() ).as_int();
		result->File_Renamed		= pElement->attribute(CharacterMapInstruction::FILE_ATTRIBUTE.c_str() ).as_int();
		result->TargetFolder		= pElement->attribute(CharacterMapInstruction::TARGET_FOLDER_ATTRIBUTE.c_str() ).as_int( CharacterMapInstruction::DEFAULT_TARGET_FOLDER);
		result->TargetFile		= pElement->attribute(CharacterMapInstruction::TARGET_FILE_ATTRIBUTE.c_str() ).as_int(CharacterMapInstruction::DEFAULT_TARGET_FILE);		

		OnCharacterMapInstructionLoaded(result);

		return result;
	}	
}
