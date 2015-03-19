#include "ScmlReference.h"
#include "ScmlObject.h"
#include "Animation.h"
#include "MainlineKey.h"
#include "Mainline.h"
#include "BoneReference.h"
#include "Entity.h"
#include "Timeline.h"
#include "TimelineKey.h"
#include "TimelineBone.h"
#include "MainlineObjectReference.h"
#include "TimelineObject.h"
#include "TimelineObjectReference.h"
#include "MathHelper.h"

namespace Spriter
{
	
		const int &ScmlReference::getEntityID() const
		{
			return _EntityID;
		}

		void ScmlReference::setEntityID(const int &value)
		{
			_EntityID = value;
		}

		const int &ScmlReference::getAnimationID() const
		{
			return _AnimationID;
		}

		void ScmlReference::setAnimationID(const int &value)
		{
			_AnimationID = value;
		}

		ScmlReference::ScmlReference()
		{
			InitializeInstanceFields();
			Reference = nullptr;
			setEntityID(INVALID);
			setAnimationID(INVALID);
			Milliseconds = 0;
		}

		void ScmlReference::SetEntity(const std::string &pName)
		{
			if (Reference != nullptr)
			{
				SetCurrentEntity(Reference->Entities->Lookup(pName));
			}
		}

		void ScmlReference::SetEntity(int pID)
		{
			if (Reference != nullptr)
			{
				SetCurrentEntity(Reference->Entities->Lookup(pID));
			}
		}

		void ScmlReference::SetAnimation(const std::string &pName)
		{
			if (Reference != nullptr && getEntityID() != INVALID)
			{
				SetCurrentAnimation((Reference->Entities->at(getEntityID())->Animations)->Lookup(pName));
			}
		}

		void ScmlReference::SetAnimation(int pID)
		{
			if (Reference != nullptr && getEntityID() != INVALID)
			{
				SetCurrentAnimation((Reference->Entities->at(getEntityID())->Animations)->Lookup(pID));
			}
		}

		void ScmlReference::Update(int pMilliseconds)
		{
			if (Reference != nullptr && getEntityID() != INVALID && getAnimationID() != INVALID)
			{
				Animation *CurrentAnimation = GetCurrentAnimation();

				Milliseconds += pMilliseconds;

				if (Milliseconds > CurrentAnimation->Length)
				{
					if (CurrentAnimation->Looping)
					{
						Milliseconds %= CurrentAnimation->Length;
					}
					else
					{
						Milliseconds = CurrentAnimation->Length;
					}
				}
				else if (Milliseconds < 0)
				{
					Milliseconds = CurrentAnimation->Looping ? CurrentAnimation->Length : 0;
				}


			}
		}

		void ScmlReference::GetTimelineObjects(std::vector<TimelineObjectReference> &results)
		{			
			if (Reference != nullptr && getEntityID() != INVALID && getAnimationID() != INVALID)
			{
				Animation *CurrentAnimation = GetCurrentAnimation();

				MainlineKey *CurrentMainlineKey = GetCurrentMainlineKey(CurrentAnimation);

				std::vector<TimelineObjectReference> BoneReferences;
				BoneReferences.reserve(30);
#if 1
				for (size_t i = 0; i < CurrentMainlineKey->BoneReferences.size(); i++)
				{
					BoneReference *CurrentBoneReference = CurrentMainlineKey->BoneReferences[i];

					int TimelineIndex = CurrentBoneReference->Timeline_Renamed;
					int TimelineKeyIndex = CurrentBoneReference->Key;
					int NextTimelineKeyIndex = TimelineKeyIndex;

					//if (NextTimelineKeyIndex < CurrentAnimation->Timelines->at(TimelineIndex)->Keys.size() - 1)
					if (NextTimelineKeyIndex < CurrentAnimation->Timelines->operator[](TimelineIndex)->Keys.size() - 1)
					{
						NextTimelineKeyIndex++;
					}

					//TimelineKey *PrimaryTimelineKey = CurrentAnimation->Timelines->at(TimelineIndex)->Keys[TimelineKeyIndex];
					//TimelineKey *SecondaryTimelineKey = CurrentAnimation->Timelines->at(TimelineIndex)->Keys[NextTimelineKeyIndex];
					TimelineKey *PrimaryTimelineKey = CurrentAnimation->Timelines->operator[](TimelineIndex)->Keys[TimelineKeyIndex];
					TimelineKey *SecondaryTimelineKey = CurrentAnimation->Timelines->operator[](TimelineIndex)->Keys[NextTimelineKeyIndex];

					bool ConnectToFirstFrame = false;

					if (CurrentMainlineKey->ID == CurrentAnimation->MainlineKeys->size() - 1 && CurrentAnimation->Looping && PrimaryTimelineKey->ID > 0)
					{
						//SecondaryTimelineKey = CurrentAnimation->Timelines->at(TimelineIndex)->Keys[(CurrentAnimation->MainlineKeys->at(0)->BoneReferences[i])->Key];
						SecondaryTimelineKey = CurrentAnimation->Timelines->operator[](TimelineIndex)->Keys[(CurrentAnimation->MainlineKeys->operator[](0)->BoneReferences[i])->Key];
						ConnectToFirstFrame = true;
					}

					TimelineObjectReference Bone;

					if (PrimaryTimelineKey == SecondaryTimelineKey)
					{
						Bone = GetTimelineObjectReference(PrimaryTimelineKey->Bone, PrimaryTimelineKey->Spin);
					}
					else
					{
						float Progress = (static_cast<float>(Milliseconds - PrimaryTimelineKey->Time)) / ((ConnectToFirstFrame ? CurrentAnimation->Length : SecondaryTimelineKey->Time) - PrimaryTimelineKey->Time);

						Bone = GetInterpolatedTimelineObjectReference(PrimaryTimelineKey->Bone, SecondaryTimelineKey->Bone, PrimaryTimelineKey->Spin, Progress);
					}

					if (CurrentMainlineKey->BoneReferences[i]->Parent != BoneReference::DEFAULT_PARENT)
					{
						Bone = ApplyTransformations(BoneReferences[CurrentBoneReference->Parent], Bone);
					}

					BoneReferences.push_back(Bone);
				}
#endif
#if 1
				size_t currentMainlineKeySize = CurrentMainlineKey->ObjectReferences.size();
				for (size_t i = 0; i < currentMainlineKeySize; i++)
				{
					MainlineObjectReference *CurrentObjectReference = CurrentMainlineKey->ObjectReferences[i];

					int TimelineIndex = CurrentObjectReference->Timeline_Renamed;
					int TimelineKeyIndex = CurrentObjectReference->Key;
					int NextTimelineKeyIndex = TimelineKeyIndex;

					//if (NextTimelineKeyIndex < (CurrentAnimation->Timelines->at(TimelineIndex)->Keys).size() - 1)					
					if (NextTimelineKeyIndex < (CurrentAnimation->Timelines->operator[](TimelineIndex)->Keys).size() - 1)
					{
						NextTimelineKeyIndex++;
					}

					//TimelineKey *PrimaryTimelineKey = CurrentAnimation->Timelines->at(TimelineIndex)->Keys[TimelineKeyIndex];
					//TimelineKey *SecondaryTimelineKey = CurrentAnimation->Timelines->at(TimelineIndex)->Keys[NextTimelineKeyIndex];
					TimelineKey *PrimaryTimelineKey = CurrentAnimation->Timelines->operator[](TimelineIndex)->Keys[TimelineKeyIndex];
					TimelineKey *SecondaryTimelineKey = CurrentAnimation->Timelines->operator[](TimelineIndex)->Keys[NextTimelineKeyIndex];

					bool ConnectToFirstFrame = false;

					if (CurrentMainlineKey->ID == CurrentAnimation->MainlineKeys->size() - 1 && CurrentAnimation->Looping && PrimaryTimelineKey->ID > 0)
					{
						//SecondaryTimelineKey = CurrentAnimation->Timelines->at(TimelineIndex)->Keys[(CurrentAnimation->MainlineKeys->at(0)->ObjectReferences[i])->Key];
						SecondaryTimelineKey = CurrentAnimation->Timelines->operator[](TimelineIndex)->Keys[(CurrentAnimation->MainlineKeys->operator[](0)->ObjectReferences[i])->Key];
						ConnectToFirstFrame = true;
					}

					TimelineObject *PrimaryTimelineObject = PrimaryTimelineKey->Object;
					TimelineObjectReference Object;
					
					if (PrimaryTimelineKey == SecondaryTimelineKey)
					{
						Object = GetTimelineObjectReference(PrimaryTimelineObject, PrimaryTimelineKey->Spin);
					}
					else
					{
						float Progress = (static_cast<float>(Milliseconds - PrimaryTimelineKey->Time)) / (float)((ConnectToFirstFrame ? CurrentAnimation->Length : SecondaryTimelineKey->Time) - PrimaryTimelineKey->Time);

						TimelineObject *SecondaryTimelineObject = SecondaryTimelineKey->Object;

						Object = GetInterpolatedTimelineObjectReference(PrimaryTimelineObject, SecondaryTimelineObject, PrimaryTimelineKey->Spin, Progress);
					}					
					if (CurrentObjectReference->Parent != MainlineObjectReference::DEFAULT_PARENT)
					{
						Object = ApplyTransformations(BoneReferences[CurrentObjectReference->Parent], Object);
					}

					Object.FileID = PrimaryTimelineObject->File_Renamed;
					Object.FolderID = PrimaryTimelineObject->Folder_Renamed;

					results.push_back(Object);
					
				}
#endif
			}			
		}

		void ScmlReference::SetCurrentEntity(Entity *pEntity)
		{
			if (pEntity != nullptr)
			{
				setEntityID(pEntity->ID);
			}
			else
			{
				setEntityID(INVALID);
			}

			setAnimationID(INVALID);
			Milliseconds = 0;
		}

		void ScmlReference::SetCurrentAnimation(Animation *pAnimation)
		{
			if (Reference != nullptr && pAnimation != nullptr)
			{
				setAnimationID(pAnimation->ID);
			}
			else
			{
				setAnimationID(INVALID);
			}

			Milliseconds = 0;
		}

		Animation *ScmlReference::GetCurrentAnimation()
		{
			return (Reference->Entities->at(getEntityID())->Animations)->at(getAnimationID());
		}

		Spriter::MainlineKey *ScmlReference::GetCurrentMainlineKey(Animation *pAnimation)
		{
			int KeyID = 0;

			for (size_t i = KeyID; i < pAnimation->MainlineKeys->size(); i++)
			{
				if (pAnimation->MainlineKeys->at(i)->Time <= Milliseconds)
				{
					KeyID = i;
				}
				else
				{
					break;
				}
			}

			return pAnimation->MainlineKeys->at(KeyID);
		}

		Spriter::TimelineObjectReference ScmlReference::GetInterpolatedTimelineObjectReference(TimelineObjectBase *pPrimaryTimelineObject, TimelineObjectBase *pSecondaryTimelineObject, int pSpin, float pProgress)
		{
			TimelineObjectReference objref;

			objref.AlphaMask = MathHelper::Linear(pPrimaryTimelineObject->AlphaMask, pSecondaryTimelineObject->AlphaMask, pProgress);
			objref.Angle = MathHelper::AngleLinear(pPrimaryTimelineObject->Angle, pSecondaryTimelineObject->Angle, pProgress, pSpin); 
			objref.BlueMask = MathHelper::Linear(pPrimaryTimelineObject->BlueMask, pSecondaryTimelineObject->BlueMask, pProgress);
			objref.GreenMask = MathHelper::Linear(pPrimaryTimelineObject->GreenMask, pSecondaryTimelineObject->GreenMask, pProgress);
			objref.RedMask = MathHelper::Linear(pPrimaryTimelineObject->RedMask, pSecondaryTimelineObject->RedMask, pProgress);
			objref.ScaleX = MathHelper::Linear(pPrimaryTimelineObject->ScaleX, pSecondaryTimelineObject->ScaleX, pProgress);
			objref.ScaleY = MathHelper::Linear(pPrimaryTimelineObject->ScaleY, pSecondaryTimelineObject->ScaleY, pProgress);
			objref.Spin = pSpin;
			objref.X = MathHelper::Linear(pPrimaryTimelineObject->X, pSecondaryTimelineObject->X, pProgress);
			objref.Y = MathHelper::Linear(pPrimaryTimelineObject->Y, pSecondaryTimelineObject->Y, pProgress);

			return objref;
		}

		Spriter::TimelineObjectReference ScmlReference::GetTimelineObjectReference(TimelineObjectBase *pTimelineObjectBase, int pSpin)
		{
			TimelineObjectReference objref;

			objref.AlphaMask = pTimelineObjectBase->AlphaMask;
			objref.Angle = pTimelineObjectBase->Angle;
			objref.BlueMask = pTimelineObjectBase->BlueMask;
			objref.GreenMask = pTimelineObjectBase->GreenMask;
			objref.RedMask = pTimelineObjectBase->RedMask;
			objref.ScaleX = pTimelineObjectBase->ScaleX;
			objref.ScaleY = pTimelineObjectBase->ScaleY;
			objref.Spin = pSpin; 
			objref.X = pTimelineObjectBase->X;
			objref.Y = pTimelineObjectBase->Y;

			return objref;
		}

		Spriter::TimelineObjectReference ScmlReference::ApplyTransformations(TimelineObjectReference pParentReference, TimelineObjectReference pChildReference)
		{
			pChildReference.Angle += pParentReference.Angle;
			pChildReference.ScaleX *= pParentReference.ScaleX;
			pChildReference.ScaleY *= pParentReference.ScaleY;
			pChildReference.AlphaMask *= pParentReference.AlphaMask;

			if (pChildReference.X != 0 || pChildReference.Y != 0)
			{
				float X = pChildReference.X * pParentReference.ScaleX;
				float Y = pChildReference.Y * pParentReference.ScaleY;

				double Sin = sin(GetRadians(pParentReference.Angle));
				double Cos = cos(GetRadians(pParentReference.Angle));

				pChildReference.X = static_cast<float>((X * Cos) - (Y * Sin));
				pChildReference.Y = static_cast<float>((X * Sin) - (Y * Cos));

				pChildReference.X += pParentReference.X;
				pChildReference.Y += pParentReference.Y;

			}
			else
			{
				pChildReference.X = pParentReference.X;
				pChildReference.Y = pParentReference.Y;
			}

			return pChildReference;
		}

		float ScmlReference::GetRadians(float pAngle)
		{
			return static_cast<float>((pAngle / 360.0f) * 2.0f * 3.141592654f);
		}

		void ScmlReference::InitializeInstanceFields()
		{
			Milliseconds = 0;
		}
}
