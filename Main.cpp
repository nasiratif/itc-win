// Islāmic Text Copier Revision 4
// Arabic font used is Jali Arabic
// © ناصر عاطف (Nāṣir ʿAṭif)

// Set current ITC version here:
#define ITC_THIS_VERSION 26

typedef struct IUnknown IUnknown; // To allow the XP toolset to behave

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include "range.h"
#include <UrlMon.h>
#include <Windows.h>
#include <thread>
#include <iostream>

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

// Global declarations
FILE *file;

// Default font
sf::Font font;
// Font colors
sf::Color fontColor = sf::Color(207, 255, 255, 255);
sf::Color fontColor2 = sf::Color(177, 216, 216, 255);
sf::Color fontColor3 = sf::Color(175, 217, 236, 255);

sf::Text update;
bool updateBtnActivated = false;

void Clipboard(const wchar_t* string);
void Update(void);

// Main function
int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	// Get DPI because DPI-aware apps are underrated
	HDC dc = GetDC(NULL);
	float dpiFactor = GetDeviceCaps(dc, LOGPIXELSX) / 96.0f;
	ReleaseDC(NULL, dc);

#if defined(_DEBUG)
	OutputDebugStringA("DPI : ");
	OutputDebugStringA(std::to_string(dpiFactor).c_str());
	OutputDebugStringA("\n");
#endif

	// Initialize window
	uint32_t width = (uint32_t)(720 * dpiFactor);
	uint32_t height = (uint32_t)(450 * dpiFactor);
	sf::RenderWindow window(sf::VideoMode(width, height), L"Islāmic Text Copier", sf::Style::Titlebar | sf::Style::Close);

	// Make window top-most
	SetWindowPos(window.getSystemHandle(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

	// Cap framerate to 60
	window.setFramerateLimit(60);
	
	// Add icon
	sf::Image icon;
	if (!icon.loadFromFile("icons\\icon.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"icon\". You may need to reinstall ITC.", L"Error", 0);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Buttons:

	// Button textures
	sf::Texture texJAL;
	if (!texJAL.loadFromFile("images\\JAL.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"JAL\". You may need to reinstall ITC.", L"Error", 0);
	texJAL.setSmooth(true);

	sf::Texture texSWT;
	if (!texSWT.loadFromFile("images\\SWT.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"SWT\". You may need to reinstall ITC.", L"Error", 0);
	texSWT.setSmooth(true);

	sf::Texture texAZW;
	if (!texAZW.loadFromFile("images\\AZW.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"AZW\". You may need to reinstall ITC.", L"Error", 0);
	texAZW.setSmooth(true);

	sf::Texture texSAW;
	if (!texSAW.loadFromFile("images\\SAW.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"SAW\". You may need to reinstall ITC.", L"Error", 0);
	texSAW.setSmooth(true);

	sf::Texture texRA1;
	if (!texRA1.loadFromFile("images\\RA1.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"RA1\". You may need to reinstall ITC.", L"Error", 0);
	texRA1.setSmooth(true);

	sf::Texture texRA2;
	if (!texRA2.loadFromFile("images\\RA2.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"RA2\". You may need to reinstall ITC.", L"Error", 0);
	texRA2.setSmooth(true);

	sf::Texture texRAH;
	if (!texRAH.loadFromFile("images\\RAH.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"RAH\". You may need to reinstall ITC.", L"Error", 0);
	texRAH.setSmooth(true);

	sf::Texture texHAF;
	if (!texHAF.loadFromFile("images\\HAF.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"HAF\". You may need to reinstall ITC.", L"Error", 0);
	texHAF.setSmooth(true);

	sf::Texture texAS;
	if (!texAS.loadFromFile("images\\AS.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"AS\". You may need to reinstall ITC.", L"Error", 0);
	texAS.setSmooth(true);

	sf::Texture texALH;
	if (!texALH.loadFromFile("images\\ALH.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"ALH\". You may need to reinstall ITC.", L"Error", 0);
	texALH.setSmooth(true);

	sf::Texture texJZK;
	if (!texJZK.loadFromFile("images\\JZK.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"JZK\". You may need to reinstall ITC.", L"Error", 0);
	texJZK.setSmooth(true);

	sf::Texture texBRK;
	if (!texBRK.loadFromFile("images\\BRK.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"BRK\". You may need to reinstall ITC.", L"Error", 0);
	texBRK.setSmooth(true);

	sf::Texture texASL;
	if (!texASL.loadFromFile("images\\ASL.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"ASL\". You may need to reinstall ITC.", L"Error", 0);
	texASL.setSmooth(true);

	sf::Texture texINS;
	if (!texINS.loadFromFile("images\\INS.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"INS\". You may need to reinstall ITC.", L"Error", 0);
	texINS.setSmooth(true);

	sf::Texture texRA3;
	if (!texRA3.loadFromFile("images\\RA3.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"RA3\". You may need to reinstall ITC.", L"Error", 0);
	texRA3.setSmooth(true);

	sf::Texture texSUB;
	if (!texSUB.loadFromFile("images\\SUB.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"SUB\". You may need to reinstall ITC.", L"Error", 0);
	texSUB.setSmooth(true);

	sf::Texture texWAI;
	if (!texWAI.loadFromFile("images\\WAI.png")) MessageBox(window.getSystemHandle(), L"Couldn't load texture \"WAI\". You may need to reinstall ITC.", L"Error", 0);
	texWAI.setSmooth(true);

	// Button sprites
	sf::Sprite JAL;
	JAL.setPosition(sf::Vector2f(60.f * dpiFactor, 90.f * dpiFactor));
	JAL.setTexture(texJAL, true);
	JAL.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite SWT;
	SWT.setPosition(sf::Vector2f(150.f * dpiFactor, 90.f * dpiFactor));
	SWT.setTexture(texSWT, true);
	SWT.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite AZW;
	AZW.setPosition(sf::Vector2f(298.f * dpiFactor, 90.f * dpiFactor));
	AZW.setTexture(texAZW, true);
	AZW.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite SAW;
	SAW.setPosition(sf::Vector2f(447.f * dpiFactor, 90.f * dpiFactor));
	SAW.setTexture(texSAW, true);
	SAW.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite RA1;
	RA1.setPosition(sf::Vector2f(537.f * dpiFactor, 90.f * dpiFactor));
	RA1.setTexture(texRA1, true);
	RA1.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite RA2;
	RA2.setPosition(sf::Vector2f(60.f * dpiFactor, 177.f * dpiFactor));
	RA2.setTexture(texRA2, true);
	RA2.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite RAH;
	RAH.setPosition(sf::Vector2f(209.f * dpiFactor, 177.f * dpiFactor));
	RAH.setTexture(texRAH, true);
	RAH.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite HAF;
	HAF.setPosition(sf::Vector2f(358.f * dpiFactor, 177.f * dpiFactor));
	HAF.setTexture(texHAF, true);
	HAF.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite AS;
	AS.setPosition(sf::Vector2f(508.f * dpiFactor, 177.f * dpiFactor));
	AS.setTexture(texAS, true);
	AS.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite ALH;
	ALH.setPosition(sf::Vector2f(60.f * dpiFactor, 264.f * dpiFactor));
	ALH.setTexture(texALH, true);
	ALH.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite JZK;
	JZK.setPosition(sf::Vector2f(208.f * dpiFactor, 264.f * dpiFactor));
	JZK.setTexture(texJZK, true);
	JZK.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite BRK;
	BRK.setPosition(sf::Vector2f(366.f * dpiFactor, 264.f * dpiFactor));
	BRK.setTexture(texBRK, true);
	BRK.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite ASL;
	ASL.setPosition(sf::Vector2f(522.f * dpiFactor, 264.f * dpiFactor));
	ASL.setTexture(texASL, true);
	ASL.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite INS;
	INS.setPosition(sf::Vector2f(60.f * dpiFactor, 340.f * dpiFactor));
	INS.setTexture(texINS, true);
	INS.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite RA3;
	RA3.setPosition(sf::Vector2f(215.f * dpiFactor, 340.f * dpiFactor));
	RA3.setTexture(texRA3, true);
	RA3.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite SUB;
	SUB.setPosition(sf::Vector2f(370.f * dpiFactor, 340.f * dpiFactor));
	SUB.setTexture(texSUB, true);
	SUB.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	sf::Sprite WAI;
	WAI.setPosition(sf::Vector2f(525.f * dpiFactor, 340.f * dpiFactor));
	WAI.setTexture(texWAI, true);
	WAI.setScale(sf::Vector2f(dpiFactor, dpiFactor));

	// ^^

	// Add font stuffs
	if (!font.loadFromFile("fonts\\calibri.ttf")) MessageBox(window.getSystemHandle(), L"Couldn't load font \"Calibri\". You may need to reinstall ITC.", L"Error", 0);
	
	// Add copyright text
	sf::Text copyright;
	const wchar_t* copyrightString = L"© Nāṣir ʿAṭif\nv4.2";

	// Set copyright font stuffs
	copyright.setFont(font);
	copyright.setCharacterSize((uint32_t)(18 * dpiFactor));
	copyright.setString(copyrightString);
	copyright.setFillColor(fontColor);
	copyright.setPosition(sf::Vector2f(15.f * dpiFactor, 15.f * dpiFactor));

	// Add documentation button text
	sf::Text viewDoc;

	// Set documentation button stuffs
	viewDoc.setFont(font);
	viewDoc.setCharacterSize((uint32_t)(18 * dpiFactor));
	viewDoc.setString("View documentation");
	viewDoc.setFillColor(fontColor2);
	viewDoc.setPosition(sf::Vector2f(125.f * dpiFactor, 15.f * dpiFactor));

	// Set update button stuffs
	update.setFont(font);
	update.setCharacterSize((uint32_t)(18 * dpiFactor));
	update.setString("Update Available!");
	update.setFillColor(fontColor3);
	update.setPosition(sf::Vector2f(295.f * dpiFactor, 15.f * dpiFactor));

	if (!updateBtnActivated) update.setFillColor(sf::Color(fontColor3.r, fontColor3.g, fontColor3.b, 0));

	// Add tip text
	sf::Text tip;
	bool tipDismissed = false;
	bool tipTimeout = false;
	int tipTimer = 0;

	// Set tip font stuffs
	tip.setFont(font);
	tip.setCharacterSize((uint32_t)(18 * dpiFactor));
	tip.setString(L"Hover over a text to see it's translation in English");
	tip.setFillColor(fontColor);
	tip.setPosition(sf::Vector2f(15.f * dpiFactor, 410.f * dpiFactor));

	// Add copy notification text
	sf::Text copyNotif;

	// Set copy notification font stuffs
	copyNotif.setFont(font);
	copyNotif.setCharacterSize((uint32_t)(18 * dpiFactor));
	copyNotif.setString("Copied!");
	copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 0));
	copyNotif.setPosition(sf::Vector2f(635.f * dpiFactor, 15.f * dpiFactor));

	// Set initial clear color
	sf::Color clearColor = sf::Color(0, 0, 0, 255);

	// Attempt updating, and do it in another thread in case it's slow
	std::thread updateThread(Update);

	// Only used for one if statement
	bool doNotExecAgain = false;
	// Main loop
	while (window.isOpen())
	{
		// Rather lazy way of making tip effects
		if (tipTimer < 320)
		{
			tipTimer++;
		}
		if (tipTimer >= 320)
		{
			tipTimeout = true;
		}
		if (tipTimeout == true && doNotExecAgain == false)
		{
			tipDismissed = true;
			doNotExecAgain = true;
		}

		// Hotkeys
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			Clipboard(L"ﷻ");
			JAL.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			Clipboard(L"سبحانه و تعالى");
			SWT.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			Clipboard(L"عز و جل");
			AZW.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			Clipboard(L"ﷺ");
			SAW.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
		{
			Clipboard(L"رضي الله عنه");
			RA1.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
		{
			Clipboard(L"رضي الله عنها");
			RA2.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
		{
			Clipboard(L"رحمه الله");
			RAH.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
		{
			Clipboard(L"حفظه الله");
			HAF.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
		{
			Clipboard(L"عليه السلام");
			AS.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
		{
			Clipboard(L"الحمد لله");
			ALH.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen))
		{
			Clipboard(L"جزاك الله خيرا");
			JZK.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
		{
			Clipboard(L"بارك الله فيك");
			BRK.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket))
		{
			Clipboard(L"السلام عليكم");
			ASL.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket))
		{
			Clipboard(L"إن شاء الله");
			INS.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Semicolon))
		{
			Clipboard(L"رضي الله عنهما");
			RA3.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Quote))
		{
			Clipboard(L"سبحان الله");
			SUB.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) || sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Slash))
		{
			Clipboard(L"و إياك");
			SUB.setColor(sf::Color(255, 255, 255, 255));
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
		}

		// Poll events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Set texts to their defaults when the user isn't hovering over them
			copyright.setString(copyrightString);
			if (tipTimeout == true) tipDismissed = true;

			// Copyright button
			if (copyright.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Go to the homepage of Islāmic Text Copier.");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));

				// When pressed
				if (event.type == sf::Event::MouseButtonPressed)
				{
					ShellExecute(NULL, L"open", L"https://itc.nasiratif.net", NULL, NULL, SW_SHOWNORMAL);
					ShowWindow(window.getSystemHandle(), SW_MINIMIZE);
					copyright.setFillColor(fontColor);
				}

				if (copyright.getFillColor().a > 150)
				{
					copyright.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Min(150, copyright.getFillColor().a - 15)));
				}
			}
			else
			{
				if (copyright.getFillColor().a < 255)
				{
					copyright.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(copyright.getFillColor().a + 15, 255)));
				}
			}

			// Documentation button
			if (viewDoc.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"View the documentation of Islāmic Text Copier.");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));

				// When pressed
				if (event.type == sf::Event::MouseButtonPressed)
				{
					ShellExecute(NULL, L"open", L"ITC_Documentation.pdf", NULL, NULL, SW_SHOWNORMAL);
					ShowWindow(window.getSystemHandle(), SW_MINIMIZE);
					viewDoc.setFillColor(fontColor2);
				}

				if (viewDoc.getFillColor().a > 150)
				{
					viewDoc.setFillColor(sf::Color(fontColor2.r, fontColor2.g, fontColor2.b, Min(150, viewDoc.getFillColor().a - 15)));
				}
			}
			else
			{
				if (viewDoc.getFillColor().a < 255)
				{
					viewDoc.setFillColor(sf::Color(fontColor2.r, fontColor2.g, fontColor2.b, Max(viewDoc.getFillColor().a + 15, 255)));
				}
			}

			// Update button
			if (update.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y) && updateBtnActivated)
			{
				tip.setString(L"Go to the Islāmic Text Copier homepage to download the latest update.");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));

				// When pressed
				if (event.type == sf::Event::MouseButtonPressed)
				{
					ShellExecute(NULL, L"open", L"https://itc.nasiratif.net", NULL, NULL, SW_SHOWNORMAL);
					update.setFillColor(fontColor3);
					window.close();
					break;
				}

				if (update.getFillColor().a > 150)
				{
					update.setFillColor(sf::Color(fontColor3.r, fontColor3.g, fontColor3.b, Min(150, update.getFillColor().a - 15)));
				}
			}
			else
			{
				if (update.getFillColor().a < 255 && updateBtnActivated)
				{
					update.setFillColor(sf::Color(fontColor3.r, fontColor3.g, fontColor3.b, Max(update.getFillColor().a + 15, 255)));
				}
			}

			// JAL button
			if (JAL.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Jalla Jalāluhu (Exalted is His Majesty) (ALT + 1)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"ﷻ");
					JAL.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (JAL.getColor().a > 150)
				{
					JAL.setColor(sf::Color(255, 255, 255, Min(150, JAL.getColor().a - 15)));
				}
			}
			else
			{
				if (JAL.getColor().a < 255)
				{
					JAL.setColor(sf::Color(255, 255, 255, Max(JAL.getColor().a + 15, 255)));
				}
			}

			// SWT button
			if (SWT.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Subḥānahu wa Taʾālá (Glorious and Exalted is He) (ALT + 2)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"سبحانه و تعالى");
					SWT.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (SWT.getColor().a > 150)
				{
					SWT.setColor(sf::Color(255, 255, 255, Min(150, SWT.getColor().a - 15)));
				}
			}
			else
			{
				if (SWT.getColor().a < 255)
				{
					SWT.setColor(sf::Color(255, 255, 255, Max(SWT.getColor().a + 15, 255)));
				}
			}

			// AZW button
			if (AZW.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"ʿAzza wa Jal (The Mighty and Majestic) (ALT + 3)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"عز و جل");
					AZW.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (AZW.getColor().a > 150)
				{
					AZW.setColor(sf::Color(255, 255, 255, Min(150, AZW.getColor().a - 15)));
				}
			}
			else
			{
				if (AZW.getColor().a < 255)
				{
					AZW.setColor(sf::Color(255, 255, 255, Max(AZW.getColor().a + 15, 255)));
				}
			}

			// SAW button
			if (SAW.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"ʿSallá Allāhu ʿAlayhī wa as-Salam (May Allāh's praise & salutations be upon him) (ALT + 4)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"ﷺ");
					SAW.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (SAW.getColor().a > 150)
				{
					SAW.setColor(sf::Color(255, 255, 255, Min(150, SAW.getColor().a - 15)));
				}
			}
			else
			{
				if (SAW.getColor().a < 255)
				{
					SAW.setColor(sf::Color(255, 255, 255, Max(SAW.getColor().a + 15, 255)));
				}
			}

			// RA1 button
			if (RA1.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Raḍī Allāhu ʿAnhu (May Allāh be pleased with him) (ALT + 5)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"رضي الله عنه");
					RA1.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (RA1.getColor().a > 150)
				{
					RA1.setColor(sf::Color(255, 255, 255, Min(150, RA1.getColor().a - 15)));
				}
			}
			else
			{
				if (RA1.getColor().a < 255)
				{
					RA1.setColor(sf::Color(255, 255, 255, Max(RA1.getColor().a + 15, 255)));
				}
			}

			// RA2 button
			if (RA2.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Raḍī Allāhu ʿAnhā (May Allāh be pleased with her) (ALT + 6)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"رضي الله عنها");
					RA2.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (RA2.getColor().a > 150)
				{
					RA2.setColor(sf::Color(255, 255, 255, Min(150, RA2.getColor().a - 15)));
				}
			}
			else
			{
				if (RA2.getColor().a < 255)
				{
					RA2.setColor(sf::Color(255, 255, 255, Max(RA2.getColor().a + 15, 255)));
				}
			}

			// RAH button
			if (RAH.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Raḥimahullāh (May Allah have mercy on him) (ALT + 7)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"رحمه الله");
					RAH.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (RAH.getColor().a > 150)
				{
					RAH.setColor(sf::Color(255, 255, 255, Min(150, RAH.getColor().a - 15)));
				}
			}
			else
			{
				if (RAH.getColor().a < 255)
				{
					RAH.setColor(sf::Color(255, 255, 255, Max(RAH.getColor().a + 15, 255)));
				}
			}

			// HAF button
			if (HAF.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Ḥafiẓahullāh (May Allah preserve him) (ALT + 8)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"حفظه الله");
					HAF.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (HAF.getColor().a > 150)
				{
					HAF.setColor(sf::Color(255, 255, 255, Min(150, HAF.getColor().a - 15)));
				}
			}
			else
			{
				if (HAF.getColor().a < 255)
				{
					HAF.setColor(sf::Color(255, 255, 255, Max(HAF.getColor().a + 15, 255)));
				}
			}

			// AS button
			if (AS.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"ʿAlayhī as-Salām (Peace be upon him) (ALT + 9)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"عليه السلام");
					AS.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (AS.getColor().a > 150)
				{
					AS.setColor(sf::Color(255, 255, 255, Min(150, AS.getColor().a - 15)));
				}
			}
			else
			{
				if (AS.getColor().a < 255)
				{
					AS.setColor(sf::Color(255, 255, 255, Max(AS.getColor().a + 15, 255)));
				}
			}

			// ALH button
			if (ALH.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Alḥamdulillāh (All praises and thanks are due to Allāh) (ALT + 0)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"الحمد لله");
					ALH.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (ALH.getColor().a > 150)
				{
					ALH.setColor(sf::Color(255, 255, 255, Min(150, ALH.getColor().a - 15)));
				}
			}
			else
			{
				if (ALH.getColor().a < 255)
				{
					ALH.setColor(sf::Color(255, 255, 255, Max(ALH.getColor().a + 15, 255)));
				}
			}

			// JZK button
			if (JZK.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Jazāk Allāhu Khairan (May Allāh give you good) (ALT + -)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"جزاك الله خيرا");
					JZK.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (JZK.getColor().a > 150)
				{
					JZK.setColor(sf::Color(255, 255, 255, Min(150, JZK.getColor().a - 15)));
				}
			}
			else
			{
				if (JZK.getColor().a < 255)
				{
					JZK.setColor(sf::Color(255, 255, 255, Max(JZK.getColor().a + 15, 255)));
				}
			}

			// BRK button
			if (BRK.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Bārik Allāhu Fīk (May Allāh bless you) (ALT + =)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"بارك الله فيك");
					BRK.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (BRK.getColor().a > 150)
				{
					BRK.setColor(sf::Color(255, 255, 255, Min(150, BRK.getColor().a - 15)));
				}
			}
			else
			{
				if (BRK.getColor().a < 255)
				{
					BRK.setColor(sf::Color(255, 255, 255, Max(BRK.getColor().a + 15, 255)));
				}
			}

			// ASL button
			if (ASL.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"As Salāmu ‘Alaikum (Peace be upon you) (ALT + [)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"السلام عليكم");
					ASL.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (ASL.getColor().a > 150)
				{
					ASL.setColor(sf::Color(255, 255, 255, Min(150, ASL.getColor().a - 15)));
				}
			}
			else
			{
				if (ASL.getColor().a < 255)
				{
					ASL.setColor(sf::Color(255, 255, 255, Max(ASL.getColor().a + 15, 255)));
				}
			}

			// INS button
			if (INS.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"ʾIn shāʾ Allāh (If Allāh wills) (ALT + ])");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"إن شاء الله");
					INS.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (INS.getColor().a > 150)
				{
					INS.setColor(sf::Color(255, 255, 255, Min(150, INS.getColor().a - 15)));
				}
			}
			else
			{
				if (INS.getColor().a < 255)
				{
					INS.setColor(sf::Color(255, 255, 255, Max(INS.getColor().a + 15, 255)));
				}
			}

			// RA3 button
			if (RA3.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Raḍī Allāhu ʿAnhumā (May Allāh be pleased with them) (ALT + ;)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"رضي الله عنهما");
					RA3.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (RA3.getColor().a > 150)
				{
					RA3.setColor(sf::Color(255, 255, 255, Min(150, RA3.getColor().a - 15)));
				}
			}
			else
			{
				if (RA3.getColor().a < 255)
				{
					RA3.setColor(sf::Color(255, 255, 255, Max(RA3.getColor().a + 15, 255)));
				}
			}

			// SUB button
			if (SUB.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Subḥānallāh (Glory be to Allāh) (ALT + ')");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"سبحان الله");
					SUB.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (SUB.getColor().a > 150)
				{
					SUB.setColor(sf::Color(255, 255, 255, Min(150, SUB.getColor().a - 15)));
				}
			}
			else
			{
				if (SUB.getColor().a < 255)
				{
					SUB.setColor(sf::Color(255, 255, 255, Max(SUB.getColor().a + 15, 255)));
				}
			}

			// WAI button
			if (WAI.getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
			{
				tip.setString(L"Wa Iyyākum (And you) (ALT + /)");
				tipTimeout = true;
				tipDismissed = false;
				tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 35, 255)));

				// Actually copy it
				if (event.type == sf::Event::MouseButtonPressed)
				{
					Clipboard(L"وإياكم");
					WAI.setColor(sf::Color(255, 255, 255, 255));
					copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, 255));
				}

				if (WAI.getColor().a > 150)
				{
					WAI.setColor(sf::Color(255, 255, 255, Min(150, WAI.getColor().a - 15)));
				}
			}
			else
			{
				if (WAI.getColor().a < 255)
				{
					WAI.setColor(sf::Color(255, 255, 255, Max(WAI.getColor().a + 15, 255)));
				}
			}

			// Close window when the user requests to do so
			if (event.type == sf::Event::Closed)
				window.close();
			// Or, if the user simply presses Escape
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape) window.close();
		}

		// Fade-in/out for the tip
		if (tipDismissed == true)
		{
			tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Min(0, tip.getFillColor().a - 2)));
		}
		else if (tipDismissed == false)
		{
			tip.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Max(tip.getFillColor().a + 2, 255)));
		}

		// Fade out for copy notif text
		if (copyNotif.getFillColor().a > 0)
		{
			copyNotif.setFillColor(sf::Color(fontColor.r, fontColor.g, fontColor.b, Min(0, copyNotif.getFillColor().a - 3)));
		}
		
		// Add fade in to the clear color, I suppose
		if (clearColor.r < 10)
		{
			clearColor = sf::Color(Max(clearColor.r + 4, 10), clearColor.g, clearColor.b);
		}
		if (clearColor.g < 34)
		{
			clearColor = sf::Color(clearColor.r, Max(clearColor.g + 4, 34), clearColor.b);
		}
		if (clearColor.b < 52)
		{
			clearColor = sf::Color(clearColor.r, clearColor.g, Max(clearColor.b + 4, 52));
		}
		window.clear(clearColor);

		// Render objects
		window.draw(JAL);
		window.draw(SWT);
		window.draw(AZW);
		window.draw(SAW);
		window.draw(RA1);
		window.draw(RA2);
		window.draw(RAH);
		window.draw(HAF);
		window.draw(AS);
		window.draw(ALH);
		window.draw(JZK);
		window.draw(BRK);
		window.draw(ASL);
		window.draw(INS);
		window.draw(RA3);
		window.draw(SUB);
		window.draw(WAI);
		window.draw(viewDoc);
		window.draw(update);
		window.draw(copyright);
		window.draw(tip);
		window.draw(copyNotif);

		// Present the entire frame
		window.display();
		
	}

	// Obligatory clean upping
	updateThread.detach();
	
	return 0;
}

// Functions

// Copies text to clipboard
inline void Clipboard(const wchar_t* string)
{
	const wchar_t* output = string;
	const size_t len = (wcslen(output) + 1) * sizeof(wchar_t);

	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
	memcpy(GlobalLock(hMem), output, len);
	GlobalUnlock(hMem);

	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_UNICODETEXT, hMem);
	CloseClipboard();
}

// Function to check for updates
void Update()
{
	// Download latest version file from website
	// If OK, actually start checking if there's an update
	if (SUCCEEDED(URLDownloadToFile(NULL, L"https://itc.nasiratif.net/version.txt", L"version.txt", BINDF_GETNEWESTVERSION, NULL)))
	{
#if defined(_DEBUG)
		OutputDebugStringA("URL download succeeded!");
#endif
		
		// Do some stuff to get the latest version from the website
		file = fopen("version.txt", "r");
		const unsigned MAX_LENGTH = 256;
		char buffer[MAX_LENGTH];
		const char* sLatestVersion = fgets(buffer, MAX_LENGTH, file);
		uint32_t latestVersion = atoi(sLatestVersion);

#if defined(_DEBUG)
		OutputDebugStringA("\nLatest version polled from website: ");
		OutputDebugStringA(sLatestVersion);
		OutputDebugStringA("\n");
#endif

		// If this version is outdated, do some stuff
		if (latestVersion > ITC_THIS_VERSION)
		{
			updateBtnActivated = true;
			if (updateBtnActivated) update.setFillColor(sf::Color(fontColor3.r, fontColor3.g, fontColor3.b, 255));
#if defined(_DEBUG)
			OutputDebugStringA("Update available\n");
#endif
		}

		fclose(file);
	}
#if defined(_DEBUG)
	else
	{
		OutputDebugStringA("Couldn't check for updates..\n");
	}
#endif
}