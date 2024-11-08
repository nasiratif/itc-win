/* 

---------- Islāmic Text Copier Revision 4 ----------
---------- Arabic font used is Jali Arabic ----------
---------- © نَصِير عاطف (Nasīr ʿAṭif) ----------

*/

#pragma once
#include "Texts.h"

#include <sstream>
#include <string>
#include <thread>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <map>
#include <vector>
#include <mutex>

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>

#include <Windows.h>
#include <WinInet.h>

// Enable modern visual styles
#if defined _WIN64
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

// FUNCTIONS
// -----
// Copies text to clipboard
inline void Clipboard(const wchar_t* string);
// Converts an ASCII string to a wide one
std::wstring ToWStr(std::string str);
// -----

// DEFINES
// -----
// Set current ITC version here:
#define ITC_THIS_VERSION 28u
#define ITC_VERSION_FILENAME L"version.txt"
#define ITC_APP_NAME L"Islāmic Text Copier"
// Window size:
// ---
#define ITC_WIDTH 720u
#define ITC_HEIGHT 450u
// ---
#define ITC_ICON_FILE "icons\\icon.png"
#define ITC_FONT_FILE "fonts\\calibri.ttf"
#define ITC_FONT_SIZE 16u
#define ITC_OUTLINE_THICKNESS 7.5f
// Button X padding
#define ITC_X_BUTTON_PADDING 20u
// Button Y padding
#define ITC_Y_BUTTON_PADDING 25u
// Sets a maximum value for an integer
#define VALUE_MAX(initial, max) (initial) > (max) ? (max) : (initial)
// Sets a minimum value for an integer
#define VALUE_MIN(min, initial) (initial) < (min) ? (min) : (initial)
// -----

// STRINGS:
// -----
// Error message printed whenever a resource failed to load
#define ITC_STR_ERR_MSG(name) std::wstring(L"Couldn't load resource \"" + ToWStr(name) + L"\". You may need to reinstall ITC.")
#define ITC_STR_WEBSITEURL L"https://itc.nasiratif.net"
#define ITC_STR_VERSIONURL L"https://itc.nasiratif.net/version.txt"
// make sure to update resource files as well
#define ITC_STR_COPYRIGHT L"© Nasīr ʿAṭif\nv4.4"
#define ITC_STR_DOCUMENTATION L"View documentation"
#define ITC_STR_UPDATE L"Update Available!"
#define ITC_STR_TOOLTIP L"Hover over a text to see it's translation in English. Use arrow keys/mouse wheel to scroll."
#define ITC_STR_COPIED L"Copied!"
// -----

// APPLICATION CLASS
class ITC
{
public:
	typedef void (*Action)(sf::Window&);
	// Main function
	int Main();
private:
	struct ImageButton
	{
		ImageButton(std::wstring text = L"", std::string image = "Button", std::wstring tooltip = L"Button", sf::Keyboard::Key key1 = sf::Keyboard::Unknown, sf::Keyboard::Key key2 = sf::Keyboard::Unknown, sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f), uint fontShrink = 0u)
		{
			this->sprite.setTexture(images[image], true);
			this->sprite.setPosition(sf::Vector2f(pos.x, pos.y));
			this->sprite.setOrigin(sf::Vector2f(0.0f, this->sprite.getGlobalBounds().height / 2.0f));
			this->sprite.setScale(sf::Vector2f(dpiFactor, dpiFactor));

			this->text = text;
			this->tooltip = tooltip;

			this->hotkey[0] = key1;
			this->hotkey[1] = key2;

			this->fontShrink = fontShrink;

			this->originalY = pos.y;
		}

		sf::Sprite sprite;

		std::wstring text;
		std::wstring tooltip;

		sf::Keyboard::Key hotkey[2];

		uint fontShrink = 0u;

		float originalY = 0.0f;
	};
	struct Button
	{
		Button(std::string name = "", Action action = nullptr, std::wstring text = L"Button", std::wstring tooltip = L"Button", sf::Vector2f pos = sf::Vector2f(0.0f, 0.0f))
		{
			this->name = name;
			this->text = text;
			this->tooltip = tooltip;

			this->button.setFont(font);
			this->button.setCharacterSize((uint)(ITC_FONT_SIZE * dpiFactor));
			this->button.setString(this->text);
			this->button.setFillColor(fontColor);
			this->button.setOutlineColor(fontColor4);
			this->button.setOutlineThickness(ITC_OUTLINE_THICKNESS * dpiFactor);
			this->button.setPosition(sf::Vector2f(pos.x, pos.y));

			this->action = action;
		}

		sf::Text button;

		std::string name;
		std::wstring text;
		std::wstring tooltip;

		bool enabled = true;
		Action action;
	};

	// Checks for updates (to be done in another thread)
	static void CheckForUpdates();

	static void ImportImage(std::string fileName, std::string name);
	static void ImportImage(void* data, size_t size, std::string name);

	static void AddCopyableButton(std::wstring text = L"", std::string image = "", std::wstring tooltip = L"", sf::Keyboard::Key key1 = sf::Keyboard::Unknown, sf::Keyboard::Key key2 = sf::Keyboard::Unknown, uint fontShrink = 0u);
	static void AddButton(std::string buttonName = "Button", Action action = nullptr, std::wstring text = L"", sf::Vector2f pos = sf::Vector2f(), std::wstring tooltip = L"");

	static void SetButtonState(std::string name, bool state);

	static size_t GetButtonIndex(std::string name);

	static bool IsButtonEnabled(std::string name);

	static sf::RenderWindow window;
	static float dpiFactor;
	static float frameHeight;
	static float scrollYPos;
	// This is here because we check for updating in another thread
	// Seems to work fine without any mutexing, but idk if SFML is officially thread-safe so just in case
	static std::mutex windowMutex;

	// Window icon
	static sf::Image icon;

	// Default font
	static sf::Font font;
	// FONT COLORS:
	// -----
	static sf::Color fontColor;
	static sf::Color fontColor2;
	static sf::Color fontColor3;
	static sf::Color fontColor4;
	// -----

	// Loaded images
	static std::unordered_map<std::string, sf::Texture> images;
	// Copyable buttons
	static std::vector<ImageButton> copyButtons;
	// Regular buttons
	static std::vector<Button> buttons;
};
// -----

// STATIC DEFINITIONS:
// ----- 
sf::RenderWindow ITC::window;
float ITC::dpiFactor = 1.0f;
float ITC::frameHeight = 0.0f;
float ITC::scrollYPos = 0.0f;

std::mutex ITC::windowMutex;

sf::Image ITC::icon;

sf::Font ITC::font;

sf::Color ITC::fontColor = sf::Color(207, 255, 255, 255);
sf::Color ITC::fontColor2 = sf::Color(177, 216, 216, 255);
sf::Color ITC::fontColor3 = sf::Color(175, 217, 236, 255);
sf::Color ITC::fontColor4 = sf::Color(25, 17, 36, 255);

std::unordered_map<std::string, sf::Texture> ITC::images;
std::vector<ITC::ImageButton> ITC::copyButtons;
std::vector<ITC::Button> ITC::buttons;
// -----