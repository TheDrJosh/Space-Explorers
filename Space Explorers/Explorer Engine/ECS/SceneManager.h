#pragma once
#include "Scene.h"

namespace ExplorerEngine
{
	namespace ECS
	{
		class SceneManager
		{
		public:
			SceneManager()
			{
				for (SceneID scene = 0; scene < MAX_SCENES; scene++)
				{
					availableSceneIDs.push(scene);
				}
			}

			SceneID AddScene()
			{
				SceneID scene = availableSceneIDs.front();
				scenes.insert(std::pair<SceneID, Scene>(scene, Scene()));
				availableSceneIDs.pop();
				return scene;
			}
			void RemoveScene(SceneID scene)
			{
				scenes.erase(scene);
			}
			void ReloadScene()
			{
				activeScene = scenes[sequence[sequenceLocation]];
			}
			void NextScene()
			{
				if (sequenceLocation < sequence.size())
				{
					sequenceLocation++;
					ReloadScene();
				}
			}
			void PreviousScene()
			{
				if (sequenceLocation > 0)
				{
					sequenceLocation--;
					ReloadScene();
				}
			}
			void SetSequence(std::vector<SceneID> sequence)
			{
				this->sequence = sequence;
			}
			void AddToSequence(SceneID scene)
			{
				sequence.push_back(scene);
			}
			void SaveScene()
			{

			}


		private:
			Scene activeScene;
			std::unordered_map<SceneID, Scene> scenes;
			std::vector<SceneID> sequence;
			int sequenceLocation = 0;
			std::queue<SceneID> availableSceneIDs;
		};
	}
}