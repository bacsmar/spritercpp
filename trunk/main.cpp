
#pragma once
// temporal includes for testing purposes...
#include <sfml/graphics.hpp>
#include <sfml/window.hpp>
#include <sfml/System/InputStream.hpp>

#include "spriter/ScmlLoader.h"
#include "spriter/SMFLAnimatedSprite.h"
#include "spriter/FileStream.h"


//using namespace Spriter;


	sf::InputStream* ola(const std::string & str)
	{
		FileStream* stream = new FileStream();
		//stream->open("PlatformerPack/"+ str);
		stream->open("skeleton/"+ str);
		return stream;
	}

	int main()
	{
		/////////////////////////////////////////
		// code for testing purposes...
		/////////////////////////////////////////				
		//Create window
		sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "SFML Test");
		renderWindow.setFramerateLimit(60);
		
		// Skeletal Animation;
		Spriter::ScmlLoader scmlLoader;
		Spriter::ScmlObject* scmlobject = scmlLoader.LoadFromFile("skeleton/skeleton.scml");	
		//Spriter::ScmlObject* scmlobject = scmlLoader.LoadFromFile("PlatformerPack/PickUps.scml");	
		//

		Spriter::SMFLAnimatedSprite skeletalAnimation(scmlobject, ola );

		skeletalAnimation.animate(*skeletalAnimation.getAnimations()[1]);
		skeletalAnimation.setPosition(200,300);				

		//Create timer to get frame time
		sf::Clock timer;
		sf::Uint64 lastFrametime = 0;
		
		while(renderWindow.isOpen())
		{					
			renderWindow.clear();				

			skeletalAnimation.update(timer.restart().asMilliseconds());
			renderWindow.draw(skeletalAnimation);

			// Event Loop
			sf::Event ev;
			while(renderWindow.pollEvent(ev))
			{
				if(ev.type == sf::Event::Closed)
				{
					renderWindow.close();
				}
				if(ev.type == sf::Event::KeyPressed)
				{
					switch(ev.key.code)
					{
					case sf::Keyboard::Escape:
						renderWindow.close();
						break;
					case sf::Keyboard::Left:						
						break;
					case sf::Keyboard::Right:						
						break;
					default:
						break;
					}
				}
			}
			renderWindow.display();
		}
		return true;
	}

