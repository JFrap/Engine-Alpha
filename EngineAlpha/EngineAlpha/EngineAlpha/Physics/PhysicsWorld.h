#pragma once

#include <Box2D/Box2D.h>

namespace alpha {
	class PhysicsWorld {
	public:
		PhysicsWorld();

		void Update(float dt);

		~PhysicsWorld();

		static PhysicsWorld MainWorld;

		b2World *GetB2World();
	private:
		const int m_velocityIterations = 6, m_positionIterations = 2;

		b2World m_world;
	};
}