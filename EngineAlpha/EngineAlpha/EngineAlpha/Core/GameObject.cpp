#include "GameObject.h"

namespace alpha {
	GameObject::GameObject(glm::vec2 position, float rotation) : Position(position), Rotation(rotation), Transform(glm::rotate(rotation, glm::vec3(0, 0, 1)) * glm::translate(glm::vec3(position, 0))) {
		
	}

	void GameObject::_SetScene(Scene *scene) {
		m_scene = scene;
	}

	void GameObject::AddComponent(Component *component) {
		component->_SetParent(this);
		component->Init();
		m_components.push_back(component);
	}

	void GameObject::Update(float dt) {
		for (size_t i = 0; i < m_components.size(); i++) {
			if (m_components[i])
				m_components[i]->Update(dt);
		}

		Transform = glm::translate(glm::vec3(Position, 0)) * glm::rotate(Rotation, glm::vec3(0, 0, 1));
	}

	void GameObject::Draw(Shader &shader) {
		for (size_t i = 0; i < m_components.size(); i++) {
			if (m_components[i])
				m_components[i]->Draw(shader);
			else
				m_componentRemovalQueue.push_back(m_components[i]);
		}

		while (m_componentRemovalQueue.size() > 0) {
			m_components.erase(std::find(m_components.begin(), m_components.end(), m_componentRemovalQueue[0]));
			m_componentRemovalQueue.erase(m_componentRemovalQueue.begin());
		}
	}
	
	template<class T>
	Component *GameObject::GetComponent() {
		for (size_t i = 0; i < m_components.size(); i++) {
			if (dynamic_cast<T*>(m_components[i])) {
				return m_components[i];
			}
		}
		return nullptr;
	}

	Scene *GameObject::GetScene() {
		return m_scene;
	}

	GameObject::~GameObject() {
		for (size_t i = 0; i < m_components.size(); i++) {
			if (m_components[i]) {
				delete m_components[i];
			}
		}
	}
}