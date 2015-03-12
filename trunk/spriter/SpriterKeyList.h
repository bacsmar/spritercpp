#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#if _MSC_VER < 1600
	using namespace std::tr1;	
#define nullptr NULL
#else
 using namespace std;
#endif


namespace Spriter
{

	
		template<typename T>
		class SpriterKeyList : public std::vector<T>
		{

		private:
			unordered_map<int, T> _collectionByID;
			unordered_map<std::string, T> _collectionByName;


		public:
			void Compile()
			{
				_collectionByID.clear();
				_collectionByName.clear();

				//for (auto Item : this)
				SpriterKeyList::iterator Item = this->begin();
				for ( ; Item != this->end() ;  ++Item)
				{					
					//T item = (*Item);					
					_collectionByID.insert(make_pair( (*Item)->ID, (*Item) ));
					_collectionByName.insert(make_pair( (*Item)->Name, (*Item) ));
				}
			}

			T Lookup(int pID)
			{
				if (_collectionByID.find(pID) != _collectionByID.end())
				{
					return _collectionByID[pID];
				}

				return T();
			}

			T Lookup(const std::string &pName)
			{
				if (_collectionByName.find(pName) != _collectionByName.end())
				{
					return _collectionByName[pName];
				}

				return T();
			}

public:
			SpriterKeyList()
			{
			}
		};
	
}
