#pragma once

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <sfml/Graphics/RenderTarget.hpp>

#include "ScmlLoader.h"
#include "ScmlObject.h"
#include "ScmlReference.h"
#include "TimelineObjectReference.h"
#include "Animation.h"
#include "Entity.h"
#include "Folder.h"
#include "File.h"

namespace Spriter 
{
	class SMFLAnimatedSprite : public sf::Transformable, public sf::Drawable
	{
	public:
		enum AnimationOptions
		{
			None = 0,	//0x00000000
			Loop = 1,	//0x00000001
			Reverse = 2,//0x00000010
		};

		SMFLAnimatedSprite(ScmlObject* source,sf::InputStream* (*loader)(const std::string&))
		{
			_runTime = new ScmlReference();
			_runTime->Reference = source;
			_runTime->SetEntity(source->Entities->at(0)->ID);

			//SpriterKeyList<Folder*> *Folders;
			SpriterKeyList<Folder*>::iterator folder = source->Folders->begin();
			SpriterKeyList<Folder*>::iterator folderEnd = source->Folders->end();

			//for (Folder* folder : *source->Folders)
			for ( ; folder != folderEnd; ++folder)
			{
				SpriterKeyList<File*>::iterator fileIt = (*folder)->Files->begin();
				SpriterKeyList<File*>::iterator fileEnd = (*folder)->Files->end();
				//for (File* file : *folder->Files )
				for ( ; fileIt != fileEnd; ++fileIt )
				{
					Spriter::File *file = (*fileIt);
					sf::InputStream* stream = loader(file->Name);
					sf::Texture* texture  = new sf::Texture();

					texture->loadFromStream(*stream);
					texture->setSmooth(true);
					delete stream;

					sf::Sprite* sprite = new sf::Sprite(*texture);

					float originX = file->PivotX * file->Width;
                    float originY = file->Height - file->PivotY * file->Height;

					sprite->setOrigin(originX, originY);
					_sprites[cantorHash( (*folder)->ID, file->ID)] = sprite;
				}
			}

		}

		SpriterKeyList<Animation*>& getAnimations() const
		{
			return *(_runTime->Reference->Entities->at(0)->Animations);
		}

	private:
		static ScmlLoader s_scmlLoader;
		unordered_map<int,sf::Sprite*> _sprites;
		ScmlReference* _runTime;

		static int cantorHash(int a,int b)
		{
			return (a + b) * (a + b + 1) / 2 + a;	//where a, b >= 0
		}
	public:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			states.transform = getTransform() * states.transform.scale( -1,1 );

			//for (auto s : _runTime->GetTimelineObjects())
			std::vector<TimelineObjectReference> objects = _runTime->GetTimelineObjects();
			std::vector<TimelineObjectReference>::const_iterator iter = objects.begin();
			std::vector<TimelineObjectReference>::const_iterator end = objects.end();

			for ( iter; iter != end; ++iter )
			{
				Spriter::TimelineObjectReference s = (*iter);

				unordered_map<int,sf::Sprite*>::const_iterator it = _sprites.find(cantorHash(s.FolderID,s.FileID));

				//sf::Sprite* currentSprite = _sprites.at(cantorHash(s.FolderID,s.FileID));
				sf::Sprite* currentSprite = (*it).second;

				currentSprite->setRotation(360.f - s.Angle);
				currentSprite->setPosition(s.X, -s.Y );
				currentSprite->setScale(s.ScaleX, s.ScaleY);
				//currentSprite->setOrigin( )

				target.draw(*currentSprite, states);
			}
		}

		void update(int delta)
		{
			_runTime->Update(delta);
		}

		void animate(Animation& animation)
		{
			animation.Looping = true;
			_runTime->SetAnimation(animation.ID);

		}

	


	};
}