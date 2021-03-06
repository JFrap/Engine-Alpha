#include "Game.h"

#include "Scene.h"
#include "../Graphics/Window.h"
#include "Log.h"

namespace alpha {
	Game::Game()
		: m_deltaTimer(), m_gameWindow(new Window()), m_audioManager()
	{
	}
	
	void Game::SetScene(Scene *newScene) {
		if (m_currentScene) {
			m_currentScene->Finish();
			delete m_currentScene;
		}
		m_currentScene = newScene;
		m_currentScene->_SetGame(this);
		m_currentScene->Init();
	}

	void Game::Start(Scene *startScene) {
		m_inputManager = alpha::InputManager(m_gameWindow);
		SetScene(startScene);
		unsigned int TotalFrames = 0;
		float FrameTimer = 0;
		while (m_gameWindow->IsOpen()) {
			float dt = m_deltaTimer.Restart<float>();

			FrameTimer += dt;
			TotalFrames++;
			if (FrameTimer >= 1) {
				DEBUG("{0} FPS | {1} MS", (float)TotalFrames / FrameTimer, (FrameTimer / (float)TotalFrames) * 1000.0f);

				TotalFrames = 0;
				FrameTimer = 0;
			}

			m_gameWindow->PollEvents();

			m_currentScene->Update(dt);

			m_gameWindow->Clear();

			m_currentScene->Draw();

			m_gameWindow->SwapBuffers();
		}

		if (m_currentScene) {
			m_currentScene->Finish();
			delete m_currentScene;
		}
	}

	InputManager &Game::GetInputManager() {
		return m_inputManager;
	}

	Window *Game::GetWindow() {
		return m_gameWindow;
	}

	AudioManager &Game::GetAudioManager() {
		return m_audioManager;
	}

	Game::~Game() {
		delete m_gameWindow;
	}
}