#pragma once

#include "../Maths.h"
#include "../Core/Scene.h"
#include "../Components/Component.h"
#include "../Components/TransformComponent.h"

namespace alpha {
	class Component;
	class Scene;

	class GameObject {
	public:
		GameObject();

		void _SetScene(Scene *scene);
		void AddComponent(Component *component);

		void Update(float dt);

		void Draw(Shader &shader);

		template<typename T, typename... Args>
		void AddComponent(Args&&... args) {
			static_assert(std::is_base_of<Component, T>(), "T is not a component.");

			auto component = static_cast<T*>(new T(std::forward<Args>(args)...));

			AddComponent(component);
		}

		template<class T>
		bool HasComponent() {
			static_assert(std::is_base_of<Component, T>(), "T is not a component.");

			return GetComponent<T>() != nullptr;
		}

		template<class T>
		T* GetComponent() {
			static_assert(std::is_base_of<Component, T>(), "T is not a component");

			for (size_t i = 0; i < m_components.size(); i++) {
				if (dynamic_cast<T*>(m_components[i])) {
					return dynamic_cast<T*>(m_components[i]);
				}
			}

			return nullptr;
		}

		Scene *GetScene();

		glm::mat4 GetTransform();
		TransformComponent& GetTransformComponent();

		~GameObject();

	private:
		Scene *m_scene;
		std::vector<Component*> m_components;
		std::vector<Component*> m_componentRemovalQueue;
	};
}