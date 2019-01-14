#pragma once

#include <map>

#include "../Maths.h"
#include "../Graphics/Window.h"

#define ALPHA_KEY_UNKNOWN            -1

#define ALPHA_KEY_SPACE              32
#define ALPHA_KEY_APOSTROPHE         39  /* ' */
#define ALPHA_KEY_COMMA              44  /* , */
#define ALPHA_KEY_MINUS              45  /* - */
#define ALPHA_KEY_PERIOD             46  /* . */
#define ALPHA_KEY_SLASH              47  /* / */
#define ALPHA_KEY_0                  48
#define ALPHA_KEY_1                  49
#define ALPHA_KEY_2                  50
#define ALPHA_KEY_3                  51
#define ALPHA_KEY_4                  52
#define ALPHA_KEY_5                  53
#define ALPHA_KEY_6                  54
#define ALPHA_KEY_7                  55
#define ALPHA_KEY_8                  56
#define ALPHA_KEY_9                  57
#define ALPHA_KEY_SEMICOLON          59  /* ; */
#define ALPHA_KEY_EQUAL              61  /* = */
#define ALPHA_KEY_A                  65
#define ALPHA_KEY_B                  66
#define ALPHA_KEY_C                  67
#define ALPHA_KEY_D                  68
#define ALPHA_KEY_E                  69
#define ALPHA_KEY_F                  70
#define ALPHA_KEY_G                  71
#define ALPHA_KEY_H                  72
#define ALPHA_KEY_I                  73
#define ALPHA_KEY_J                  74
#define ALPHA_KEY_K                  75
#define ALPHA_KEY_L                  76
#define ALPHA_KEY_M                  77
#define ALPHA_KEY_N                  78
#define ALPHA_KEY_O                  79
#define ALPHA_KEY_P                  80
#define ALPHA_KEY_Q                  81
#define ALPHA_KEY_R                  82
#define ALPHA_KEY_S                  83
#define ALPHA_KEY_T                  84
#define ALPHA_KEY_U                  85
#define ALPHA_KEY_V                  86
#define ALPHA_KEY_W                  87
#define ALPHA_KEY_X                  88
#define ALPHA_KEY_Y                  89
#define ALPHA_KEY_Z                  90
#define ALPHA_KEY_LEFT_BRACKET       91  /* [ */
#define ALPHA_KEY_BACKSLASH          92  /* \ */
#define ALPHA_KEY_RIGHT_BRACKET      93  /* ] */
#define ALPHA_KEY_GRAVE_ACCENT       96  /* ` */
#define ALPHA_KEY_WORLD_1            161 /* non-US #1 */
#define ALPHA_KEY_WORLD_2            162 /* non-US #2 */

#define ALPHA_KEY_ESCAPE             256
#define ALPHA_KEY_ENTER              257
#define ALPHA_KEY_TAB                258
#define ALPHA_KEY_BACKSPACE          259
#define ALPHA_KEY_INSERT             260
#define ALPHA_KEY_DELETE             261
#define ALPHA_KEY_RIGHT              262
#define ALPHA_KEY_LEFT               263
#define ALPHA_KEY_DOWN               264
#define ALPHA_KEY_UP                 265
#define ALPHA_KEY_PAGE_UP            266
#define ALPHA_KEY_PAGE_DOWN          267
#define ALPHA_KEY_HOME               268
#define ALPHA_KEY_END                269
#define ALPHA_KEY_CAPS_LOCK          280
#define ALPHA_KEY_SCROLL_LOCK        281
#define ALPHA_KEY_NUM_LOCK           282
#define ALPHA_KEY_PRINT_SCREEN       283
#define ALPHA_KEY_PAUSE              284
#define ALPHA_KEY_F1                 290
#define ALPHA_KEY_F2                 291
#define ALPHA_KEY_F3                 292
#define ALPHA_KEY_F4                 293
#define ALPHA_KEY_F5                 294
#define ALPHA_KEY_F6                 295
#define ALPHA_KEY_F7                 296
#define ALPHA_KEY_F8                 297
#define ALPHA_KEY_F9                 298
#define ALPHA_KEY_F10                299
#define ALPHA_KEY_F11                300
#define ALPHA_KEY_F12                301
#define ALPHA_KEY_F13                302
#define ALPHA_KEY_F14                303
#define ALPHA_KEY_F15                304
#define ALPHA_KEY_F16                305
#define ALPHA_KEY_F17                306
#define ALPHA_KEY_F18                307
#define ALPHA_KEY_F19                308
#define ALPHA_KEY_F20                309
#define ALPHA_KEY_F21                310
#define ALPHA_KEY_F22                311
#define ALPHA_KEY_F23                312
#define ALPHA_KEY_F24                313
#define ALPHA_KEY_F25                314
#define ALPHA_KEY_KP_0               320
#define ALPHA_KEY_KP_1               321
#define ALPHA_KEY_KP_2               322
#define ALPHA_KEY_KP_3               323
#define ALPHA_KEY_KP_4               324
#define ALPHA_KEY_KP_5               325
#define ALPHA_KEY_KP_6               326
#define ALPHA_KEY_KP_7               327
#define ALPHA_KEY_KP_8               328
#define ALPHA_KEY_KP_9               329
#define ALPHA_KEY_KP_DECIMAL         330
#define ALPHA_KEY_KP_DIVIDE          331
#define ALPHA_KEY_KP_MULTIPLY        332
#define ALPHA_KEY_KP_SUBTRACT        333
#define ALPHA_KEY_KP_ADD             334
#define ALPHA_KEY_KP_ENTER           335
#define ALPHA_KEY_KP_EQUAL           336
#define ALPHA_KEY_LEFT_SHIFT         340
#define ALPHA_KEY_LEFT_CONTROL       341
#define ALPHA_KEY_LEFT_ALT           342
#define ALPHA_KEY_LEFT_SUPER         343
#define ALPHA_KEY_RIGHT_SHIFT        344
#define ALPHA_KEY_RIGHT_CONTROL      345
#define ALPHA_KEY_RIGHT_ALT          346
#define ALPHA_KEY_RIGHT_SUPER        347
#define ALPHA_KEY_MENU               348

#define ALPHA_KEY_LAST               ALPHA_KEY_MENU


#define ALPHA_MOD_SHIFT           0x0001

#define ALPHA_MOD_CONTROL         0x0002

#define ALPHA_MOD_ALT             0x0004

#define ALPHA_MOD_SUPER           0x0008

#define ALPHA_MOUSE_BUTTON_1         0
#define ALPHA_MOUSE_BUTTON_2         1
#define ALPHA_MOUSE_BUTTON_3         2
#define ALPHA_MOUSE_BUTTON_4         3
#define ALPHA_MOUSE_BUTTON_5         4
#define ALPHA_MOUSE_BUTTON_6         5
#define ALPHA_MOUSE_BUTTON_7         6
#define ALPHA_MOUSE_BUTTON_8         7
#define ALPHA_MOUSE_BUTTON_LAST      ALPHA_MOUSE_BUTTON_8
#define ALPHA_MOUSE_BUTTON_LEFT      ALPHA_MOUSE_BUTTON_1
#define ALPHA_MOUSE_BUTTON_RIGHT     ALPHA_MOUSE_BUTTON_2
#define ALPHA_MOUSE_BUTTON_MIDDLE    ALPHA_MOUSE_BUTTON_3

#define ALPHA_JOYSTICK_1             0
#define ALPHA_JOYSTICK_2             1
#define ALPHA_JOYSTICK_3             2
#define ALPHA_JOYSTICK_4             3
#define ALPHA_JOYSTICK_5             4
#define ALPHA_JOYSTICK_6             5
#define ALPHA_JOYSTICK_7             6
#define ALPHA_JOYSTICK_8             7
#define ALPHA_JOYSTICK_9             8
#define ALPHA_JOYSTICK_10            9
#define ALPHA_JOYSTICK_11            10
#define ALPHA_JOYSTICK_12            11
#define ALPHA_JOYSTICK_13            12
#define ALPHA_JOYSTICK_14            13
#define ALPHA_JOYSTICK_15            14
#define ALPHA_JOYSTICK_16            15
#define ALPHA_JOYSTICK_LAST          ALPHA_JOYSTICK_16

namespace alpha {
	class InputManager {
	public:
		InputManager();
		InputManager(Window *window);

		glm::vec2 GetMousePosition();
		glm::vec2 GetWindowPosition();
		glm::vec2 GetWindowSize();
		void AddInput(std::string name, int inputPositive, int inputNegative = -2);
		int GetInput(std::string name);

		~InputManager();
	private:
		struct Input {
			int PositiveKey, NegativeKey;
		};

		std::map<std::string, Input> m_inputs;
		Window *m_window;
	};
}