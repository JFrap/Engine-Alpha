#pragma once

#include "Maths.h"

#include "Core/Game.h"
#include "Core/GameObject.h"
#include "Core/InputManager.h"
#include "Core/Log.h"
#include "Core/Scene.h"
#include "Core/Signal.h"
#include "Core/ResourceManager.h"

#include "Graphics/BaseMesh.h"
#include "Graphics/Shader.h"
#include "Graphics/Window.h"
#include "Graphics/Camera.h"
#include "Graphics/Image.h"
#include "Graphics/Texture.h"
#include "Graphics/Color.h"

#include "Components/AudioPlayerComponent.h"
#include "Components/QuadComponent.h"
#include "Components/QuadColliderComponent.h"
#include "Components/CircleColliderComponent.h"
#include "Components/PolygonColliderComponent.h"
#include "Components/TransformComponent.h"

#include "Physics/PhysicsWorld.h"
#include "Physics/RayCaster.h"

// ---- Entry Point ----
#ifdef ALPHA_ENTRY_POINT
#include "EntryPoint.h"
#endif // !NO_ENTRY_POINT
// ---------------------