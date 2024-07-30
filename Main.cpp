#include "Main.h"

#pragma comment (lib, "urlmon.lib")
#pragma comment(lib, "opengl32.lib")

#if defined(_DEBUG)
#pragma comment(lib, "SFML\\sfml-window-d.lib")
#pragma comment(lib, "SFML\\sfml-graphics-d.lib")
#pragma comment(lib, "SFML\\sfml-system-d.lib")
#else
#pragma comment(lib, "SFML\\sfml-window.lib")
#pragma comment(lib, "SFML\\sfml-graphics.lib")
#pragma comment(lib, "SFML\\sfml-system.lib")
#endif

// BUTTON ACTIONS:
// -----
void Website(sf::Window& window)
{
	ShellExecute(NULL, L"open", ITC_STR_WEBSITE, NULL, NULL, SW_SHOWNORMAL);
	ShowWindow(window.getSystemHandle(), SW_MINIMIZE);
}
void Documentation(sf::Window& window)
{
	ShellExecute(NULL, L"open", L"ITC_Documentation.pdf", NULL, NULL, SW_SHOWNORMAL);
	ShowWindow(window.getSystemHandle(), SW_MINIMIZE);
}
// -----

/*

---------- MAIN FUNCTION ----------

*/

int ITC::Main()
{
	// Be aware of screen DPI, very important!
	HDC dc = GetDC(NULL);
	dpiFactor = GetDeviceCaps(dc, LOGPIXELSX) / 96.0f;
	ReleaseDC(NULL, dc);

#if defined(_DEBUG)
	OutputDebugStringA("DPI : ");
	OutputDebugStringA(std::to_string(dpiFactor).c_str());
	OutputDebugStringA("\n");
#endif

	// Create main window
	window.create(sf::VideoMode((uint)(ITC_WIDTH * dpiFactor), (uint)(ITC_HEIGHT * dpiFactor)), ITC_APP_NAME, sf::Style::Titlebar | sf::Style::Close);

	if (!icon.loadFromFile("icons\\icon.png"))
		MessageBox(window.getSystemHandle(), ITC_STR_ERR_MSG(ITC_ICON_FILE).c_str(), L"Error", 0);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Make window top-most
	SetWindowPos(window.getSystemHandle(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

	// Make sure app logic isn't excecuted too fast (and also reduce CPU usage)
	window.setFramerateLimit(60);

	if (!font.loadFromFile(ITC_FONT_FILE))
		MessageBox(window.getSystemHandle(), ITC_STR_ERR_MSG(ITC_FONT_FILE).c_str(), L"Error", 0);

	// Parse all buttons:
	for (TextInfo& info : itcButtons)
	{
		ImportImage(std::string("images\\" + info.image + ".png"), info.image);
		AddCopyableButton(info.text, info.image, info.tooltip, info.key1, info.key2, info.fontShrink);
	}

	sf::Text tip;
	// Set tip font stuffs
	tip.setFont(font);
	tip.setCharacterSize((uint)(ITC_FONT_SIZE * dpiFactor));
	tip.setString(ITC_STR_TOOLTIP);
	tip.setFillColor(fontColor);
	tip.setOutlineColor(fontColor4);
	tip.setOutlineThickness(ITC_OUTLINE_THICKNESS * dpiFactor);
	tip.setPosition(sf::Vector2f(15.f * dpiFactor, 415.f * dpiFactor));

	sf::Text copyNotif;
	// Set copy notification font stuff
	copyNotif.setFont(font);
	copyNotif.setCharacterSize((uint)(ITC_FONT_SIZE * dpiFactor));
	copyNotif.setString(ITC_STR_COPIED);
	copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 0));
	copyNotif.setOutlineColor(sf::Color(fontColor4.r, fontColor4.g, fontColor4.b, 0));
	copyNotif.setOutlineThickness(ITC_OUTLINE_THICKNESS * dpiFactor);
	copyNotif.setPosition(sf::Vector2f(635.f * dpiFactor, 15.f * dpiFactor));

	AddButton(
		"CopyrightText", 
		Website, 
		L"© Nasīr ʿAṭif\nv4.3", 
		sf::Vector2f(16.0f, 16.0f), 
		L"Go to the homepage of Islāmic Text Copier."
	);
	AddButton(
		"DocsButton", 
		Documentation, 
		L"View documentation", 
		sf::Vector2f(116.0f, 16.0f), 
		L"View the documentation of Islāmic Text Copier."
	);

	AddButton(
		"UpdateButton", 
		Website, 
		L"Update Available!", 
		sf::Vector2f(270.0f, 16.0f), 
		L"Go to the homepage of Islāmic Text Copier to update."
	);
	SetButtonState("UpdateButton", false);

	sf::Thread updateThread(&ITC::CheckForUpdates);
	updateThread.launch();

	sf::Event event;
	while (window.isOpen())
	{
		static bool windowShouldClose = false;
		static bool mouseMoved = false;
		static bool spacePressed = false;
		static bool tabPressed = false;

		// Used to select a button using TAB
		static int buttonCursor = -1;

		static uint tipTimer = 520u;

		// Scrolling:
		float screenHeight = (ITC_HEIGHT * dpiFactor);

		static float currentYPos = 0.0f;
		currentYPos = (currentYPos + (scrollYPos - currentYPos) * 0.2f);

		float scrollYOffset = (currentYPos > screenHeight / 2.0f) ?
		std::min(currentYPos - (screenHeight / 2.0f), std::max(frameHeight, screenHeight) - screenHeight) :
			0;
		spacePressed = false;
		tabPressed = false;
		while (window.pollEvent(event))
		{
			// Close window when the user requests to do so
			if (event.type == sf::Event::Closed)
			{
				window.close();
				windowShouldClose = true;
			}
			else if (event.type == sf::Event::MouseMoved)
			{
				mouseMoved = true;
			}
			else if (event.type == sf::Event::MouseWheelMoved)
			{
				scrollYPos = event.mouseWheel.delta >= 0 ?
					scrollYPos = std::clamp(scrollYPos - ITC_HEIGHT * dpiFactor, 0.0f, frameHeight)
					:
					scrollYPos = std::clamp(scrollYPos + ITC_HEIGHT * dpiFactor, 0.0f, frameHeight);
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					scrollYPos = std::clamp(scrollYPos - ITC_HEIGHT * dpiFactor, 0.0f, frameHeight);
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					scrollYPos = std::clamp(scrollYPos + ITC_HEIGHT * dpiFactor, 0.0f, frameHeight);
				}
				else if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
					windowShouldClose = true;
					break;
				}
				else if (event.key.code == sf::Keyboard::Tab)
				{
					tabPressed = true;
					buttonCursor++;
					if (buttonCursor >= (int)(copyButtons.size() + buttons.size()))
						buttonCursor = 0;

					if (buttonCursor < (int)buttons.size() && !buttons[buttonCursor < (int)buttons.size() ? buttonCursor : 0u].enabled && buttonCursor + 1 < (int)(copyButtons.size() + buttons.size()))
						buttonCursor++;
				}
				else if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter)
				{
					spacePressed = true;
				}
				else
				{
					mouseMoved = false;
					spacePressed = false;
					tabPressed = false;
				}
			}
			else
			{
				mouseMoved = false;
			}
		}
		if (windowShouldClose)
			break;

		// Handle buttons:
		for (size_t i = 0; i < buttons.size(); ++i)
		{
			Button& button = buttons[i];

			if (button.enabled)
			{
				if (button.button.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y) && mouseMoved)
				{
					buttonCursor = i;
					mouseMoved = false;
				}
				else if (mouseMoved)
				{
					buttonCursor = -1;
				}

				if (buttonCursor == i)
				{
					tip.setString(button.tooltip);
					tipTimer = 150;

					// Actually copy it
					if (event.type == sf::Event::MouseButtonPressed || spacePressed)
					{
						button.action(window);
						button.button.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, fontColor.a));
					}

					if (button.button.getFillColor().a > 150)
					{
						button.button.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, VALUE_MIN(150, button.button.getFillColor().a - 15)));
					}
				}
				else if (button.button.getFillColor().a < 255)
				{
					button.button.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, VALUE_MAX(button.button.getFillColor().a + 15, 255)));
				}
			}
		}
		for (size_t i = 0; i < copyButtons.size(); ++i)
		{
			size_t actualIndex = buttons.size() + i;
			ImageButton& button = copyButtons[i];

			button.sprite.setPosition(button.sprite.getPosition().x, button.originalY - scrollYOffset);
			if (button.sprite.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y) && mouseMoved)
			{
				buttonCursor = actualIndex;
				mouseMoved = false;
			}
			else if (mouseMoved)
			{
				buttonCursor = -1;	
			}

			if (buttonCursor == actualIndex)
			{
				if (tabPressed)
					scrollYPos = (button.originalY - button.sprite.getOrigin().y) + button.sprite.getGlobalBounds().height;

				tip.setString(button.tooltip);
				tip.setCharacterSize((uint)(ITC_FONT_SIZE * dpiFactor) - button.fontShrink);
				tipTimer = 150;

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed || spacePressed)
				{
					Clipboard(button.text.c_str());
					button.sprite.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
					copyNotif.setOutlineColor(sf::Color(fontColor4.r, fontColor4.g, fontColor4.b, 255));
				}

				if (button.sprite.getColor().a > 150)
				{
					button.sprite.setColor(sf::Color(255, 255, 255, VALUE_MIN(150, button.sprite.getColor().a - 15)));
				}
			}
			else if (button.sprite.getColor().a < 255)
			{
				button.sprite.setColor(sf::Color(255, 255, 255, VALUE_MAX(button.sprite.getColor().a + 15, 255)));
			}

			// Handling hotkeys:
			if (sf::Keyboard::isKeyPressed(button.hotkey[0]) && sf::Keyboard::isKeyPressed(button.hotkey[1]))
			{
				Clipboard(button.text.c_str());
				button.sprite.setColor(sf::Color(255, 255, 255, 255));
				copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				copyNotif.setOutlineColor(sf::Color(fontColor4.r, fontColor4.g, fontColor4.b, 255));
			}
		}

		// EFFECTS:
		// -----
		// Fade-in/out for the tip
		if (!tipTimer)
		{
			tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, VALUE_MIN(0, tip.getFillColor().a - 2)));
			tip.setOutlineColor(sf::Color(fontColor4.r, fontColor4.g, fontColor4.b, VALUE_MIN(0, tip.getOutlineColor().a - 2)));
		}
		else
		{
			tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, VALUE_MAX(tip.getFillColor().a + 45, 255)));
			tip.setOutlineColor(sf::Color(fontColor4.r, fontColor4.g, fontColor4.b, VALUE_MAX(tip.getOutlineColor().a + 45, 255)));
			tipTimer--;
		}

		// Fade out for copy notif text
		if (copyNotif.getFillColor().a > 0)
		{
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, VALUE_MIN(0, copyNotif.getFillColor().a - 3)));
		}
		if (copyNotif.getOutlineColor().a > 0)
		{
			copyNotif.setOutlineColor(sf::Color(fontColor4.r, fontColor4.g, fontColor4.b, VALUE_MIN(0, copyNotif.getOutlineColor().a - 3)));
		}
		// -----

		static sf::Color clearColor = sf::Color(0, 0, 0, 255);
		// Add fade in to the clear color:
		if (clearColor.r < 10)
		{
			clearColor = sf::Color(VALUE_MAX(clearColor.r + 4, 10), clearColor.g, clearColor.b);
		}
		if (clearColor.g < 34)
		{
			clearColor = sf::Color(clearColor.r, VALUE_MAX(clearColor.g + 4, 34), clearColor.b);
		}
		if (clearColor.b < 52)
		{
			clearColor = sf::Color(clearColor.r, clearColor.g, VALUE_MAX(clearColor.b + 4, 52));
		}
		window.clear(clearColor);

		// Draw all texts
		for (ImageButton& button : copyButtons)
		{
			window.draw(button.sprite);
		}
		for (Button& button : buttons)
		{
			if (button.enabled)
				window.draw(button.button);
		}

		window.draw(tip);
		window.draw(copyNotif);

		window.display();
	}

	return 0;
}


/*

---------- BACKEND ----------

*/

inline void Clipboard(const wchar_t* string)
{
	const size_t strSize = (wcslen(string) + 1) * sizeof(wchar_t);

	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, strSize);
	memcpy(GlobalLock(hMem), string, strSize);
	GlobalUnlock(hMem);

	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
}

std::wstring ToWStr(std::string str)
{
	std::wostringstream wstm;
	const std::ctype<wchar_t>& ctfacet = std::use_facet<std::ctype<wchar_t>>(wstm.getloc());
	for (size_t i = 0u; i < str.size(); i++)
		wstm << ctfacet.widen(str[i]);
	return wstm.str();
}


void ITC::CheckForUpdates()
{
	// Download latest version file from website
	// If OK, actually start checking if there's an update
	if (SUCCEEDED(URLDownloadToFile(NULL, ITC_STR_VERSIONURL, ITC_VERSION_FILENAME, BINDF_GETNEWESTVERSION, NULL)))
	{
#if defined(_DEBUG)
		OutputDebugStringA("URL download succeeded!");
#endif

		// Do some stuff to get the latest version from the website:
		std::ifstream file(ITC_VERSION_FILENAME, std::ios::binary | std::ios::beg);
		size_t size = (size_t)std::filesystem::file_size(ITC_VERSION_FILENAME);

		if (!file.is_open())
			return;
		char version[5] = { 0 };
		file.read(version, VALUE_MAX(size, sizeof(version) - 1));

		if (!file.good())
		{
			file.close();
			return;
		}

		file.close();

		ushort latestVersion = (ushort)atoi(version);
#if defined(_DEBUG)
		OutputDebugStringA("\nLatest version polled from website: ");
		OutputDebugStringA(version);
		OutputDebugStringA("\n");
#endif

		// If this version is outdated, do some stuff
		if (latestVersion > ITC_THIS_VERSION)
		{
			SetButtonState("UpdateButton", true);
#if defined(_DEBUG)
			OutputDebugStringA("Update available\n");
#endif
		}
	}
#if defined(_DEBUG)
	else
	{
		OutputDebugStringA("Couldn't check for updates..\n");
	}
#endif
}


void ITC::ImportImage(std::string fileName, std::string name)
{
	sf::Texture& tex = images[name];
	if (!tex.loadFromFile(fileName))
		MessageBox(window.getSystemHandle(), ITC_STR_ERR_MSG(name).c_str(), L"Error", MB_ICONINFORMATION);
	tex.setSmooth(true);
}

void ITC::ImportImage(void* data, size_t size, std::string name)
{
	sf::Texture& tex = images[name];
	if (!tex.loadFromMemory(data, size))
		MessageBox(window.getSystemHandle(), ITC_STR_ERR_MSG(name).c_str(), L"Error", MB_ICONINFORMATION);
	tex.setSmooth(true);
}


void ITC::AddCopyableButton(std::wstring text, std::string image, std::wstring tooltip, sf::Keyboard::Key key1, sf::Keyboard::Key key2, uint fontShrink)
{
	sf::Vector2f defaultPos = sf::Vector2f(60.0f, 130.0f);
	sf::Vector2f pos = defaultPos;
	bool buttonsExist = !copyButtons.empty();

	static float lineHeight = 0u;

	ImageButton copyButton = ImageButton(text, image, tooltip, key1, key2, sf::Vector2f(pos.x * dpiFactor, pos.y * dpiFactor), fontShrink);

	float rectHeight = copyButton.sprite.getGlobalBounds().height;
	if (rectHeight > lineHeight)
		lineHeight = rectHeight;

	if (buttonsExist)
	{
		sf::Sprite& lastButton = copyButtons[copyButtons.size() - 1].sprite;
		pos = sf::Vector2f(
			lastButton.getPosition().x + lastButton.getGlobalBounds().width,
			lastButton.getPosition().y
		);

		copyButton.sprite.setPosition(sf::Vector2f(pos.x + ITC_X_BUTTON_PADDING * dpiFactor, pos.y));
		if (copyButton.sprite.getPosition().x + copyButton.sprite.getGlobalBounds().width > (float)(ITC_WIDTH * dpiFactor) - ITC_X_BUTTON_PADDING)
		{
			copyButton.sprite.setPosition(defaultPos.x * dpiFactor, copyButton.sprite.getPosition().y + ((float)rectHeight + (ITC_Y_BUTTON_PADDING * dpiFactor)));
			rectHeight = 0.0f;
		}
	}
	float newFrameHeight = ((copyButton.sprite.getPosition().y - copyButton.sprite.getOrigin().y * dpiFactor) + copyButton.sprite.getGlobalBounds().height) + (ITC_Y_BUTTON_PADDING + 50) * dpiFactor;

	if (newFrameHeight > frameHeight)
		frameHeight = newFrameHeight;

	copyButton.originalY = copyButton.sprite.getPosition().y;
	copyButtons.emplace_back(copyButton);
}

void ITC::AddButton(std::string name, Action action, std::wstring text, sf::Vector2f pos, std::wstring tooltip)
{
	Button& button = buttons.emplace_back(Button(name, action, text, tooltip, sf::Vector2f(pos.x * dpiFactor, pos.y * dpiFactor)));
}

void ITC::SetButtonState(std::string name, bool state)
{
	for (Button& button : buttons)
	{
		if (button.name != name)
			continue;
		button.enabled = state;
	}
}

size_t ITC::GetButtonIndex(std::string name)
{
	for (size_t i = 0; i < buttons.size(); ++i)
	{
		if (buttons[i].name == name)
			return i;
	}

	return size_t(-1);
}

bool ITC::IsButtonEnabled(std::string name)
{
	for (size_t i = 0; i < buttons.size(); ++i)
	{
		if (buttons[i].name == name)
			return buttons[i].enabled;
	}

	return false;
}


// Entry point
int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{	
	ITC itc;
	return itc.Main();
}
