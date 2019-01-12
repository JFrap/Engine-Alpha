#include "BaseColliderComponent.h"

namespace alpha {
	BaseColliderComponent::BaseColliderComponent() {

	}

	glm::vec2 BaseColliderComponent::GetPosition() { return glm::vec2(Body->GetPosition().x, Body->GetPosition().y); }
	float BaseColliderComponent::GetRotation() { return Body->GetAngle(); }

	glm::vec2 BaseColliderComponent::GetVelocity() { return glm::vec2(Body->GetLinearVelocity().x, Body->GetLinearVelocity().y); }
	float BaseColliderComponent::GetAngularVelocity() { return Body->GetAngularVelocity(); }

	void BaseColliderComponent::SetPosition(glm::vec2 pos) { Body->SetTransform(b2Vec2(pos.x, pos.y), Body->GetAngle()); }
	void BaseColliderComponent::SetRotation(float rotation) { Body->SetTransform(Body->GetPosition(), rotation); }

	void BaseColliderComponent::SetVelocity(glm::vec2 vel) { Body->SetLinearVelocity(b2Vec2(vel.x, vel.y)); }
	void BaseColliderComponent::SetAngularVelocity(float angVel) { Body->SetAngularVelocity(angVel); }


	void BaseColliderComponent::Update(float dt) {
		Body->SetLinearDamping(Friction);
		Body->SetAngularDamping(Friction);
		Parent->Position = GetPosition();
		Parent->Rotation = GetRotation();
	}
	
	BaseColliderComponent::~BaseColliderComponent() {

	}

	void BaseColliderComponent::CreateBody(glm::vec2 Position, float rotation) {
		BodyDef.type = b2BodyType(ColliderBodyType::Dynamic);
		BodyDef.position.Set(Position.x, Position.y);
		BodyDef.angle = rotation;
		Body = PhysicsWorld::MainWorld.GetB2World()->CreateBody(&BodyDef);
	}

	void BaseColliderComponent::DefineFixture(float density, float friction) {
		FixtureDef.shape = Shape;
		FixtureDef.density = density;
		FixtureDef.friction = friction;
		Body->CreateFixture(&FixtureDef);
	}
}