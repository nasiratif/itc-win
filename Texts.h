#pragma once
#include <iostream>
#include "Typedefs.h"

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>

// Describes a copyable text
struct TextInfo
{
	TextInfo(std::wstring text = L"", std::wstring tooltip = L"", std::string image = "", sf::Keyboard::Key key1 = sf::Keyboard::Unknown, sf::Keyboard::Key key2 = sf::Keyboard::Unknown, uint fontShrink = 0u)
	{
		this->text = text;
		this->tooltip = tooltip;
		this->image = image;

		this->key1 = key1;
		this->key2 = key2;

		this->fontShrink = fontShrink;
	}

	std::wstring text;
	std::wstring tooltip;
	std::string image;

	sf::Keyboard::Key key1;
	sf::Keyboard::Key key2;

	uint fontShrink = 0;
};

// Add new texts here::
TextInfo itcButtons[] =
{
	TextInfo(
		L"ﷻ",

		L"Jalla Jalāluhu (Exalted is His Majesty) (ALT + 1)",

		"JAL",

		sf::Keyboard::LAlt, sf::Keyboard::Num1
	),

	TextInfo(
		L"سبحانه و تعالى",

		L"Subḥānahu wa Taʾālá (Glorious and Exalted is He) (ALT + 2)",

		"SWT",

		sf::Keyboard::LAlt, sf::Keyboard::Num2
	),

	TextInfo(
		L"عز و جل",

		L"ʿAzza wa Jal (The Mighty and Majestic) (ALT + 3)",

		"AZW",

		sf::Keyboard::LAlt, sf::Keyboard::Num3
	),

	TextInfo(
		L"ﷺ",

		L"ʿSallá Allāhu ʿAlayhī wa as-Salam (May Allāh's praise & salutations be upon him) (ALT + 4)",

		"SAW",

		sf::Keyboard::LAlt, sf::Keyboard::Num4
	),

	TextInfo(
		L"رضي الله عنه",

		L"Raḍī Allāhu ʿAnhu (May Allāh be pleased with him) (ALT + 5)",

		"RA1",

		sf::Keyboard::LAlt, sf::Keyboard::Num5
	),

	TextInfo(
		L"رضي الله عنها",

		L"Raḍī Allāhu ʿAnhā (May Allāh be pleased with her) (ALT + 6)",

		"RA2",

		sf::Keyboard::LAlt, sf::Keyboard::Num6
	),

	TextInfo(
		L"رحمه الله",

		L"Raḥimahullāh (May Allah have mercy on him) (ALT + 7)",

		"RAH",

		sf::Keyboard::LAlt, sf::Keyboard::Num7
	),

	TextInfo(
		L"حفظه الله",

		L"Ḥafiẓahullāh (May Allah preserve him) (ALT + 8)",

		"HAF",

		sf::Keyboard::LAlt, sf::Keyboard::Num8
	),

	TextInfo(
		L"عليه السلام",

		L"ʿAlayhī as-Salām (Peace be upon him) (ALT + 9)",

		"AS",

		sf::Keyboard::LAlt, sf::Keyboard::Num9
	),

	TextInfo(
		L"الحمد لله",

		L"Alḥamdulillāh (All praises and thanks are due to Allāh) (ALT + 0)",

		"ALH",

		sf::Keyboard::LAlt, sf::Keyboard::Num0
	),

	TextInfo(
		L"جزاك الله خيرا",

		L"Jazāk Allāhu Khairan (May Allāh give you good) (ALT + -)",

		"JZK",

		sf::Keyboard::LAlt, sf::Keyboard::Hyphen
	),

	TextInfo(
		L"بارك الله فيك",

		L"Bārik Allāhu Fīk (May Allāh bless you) (ALT + =)",

		"BRK",

		sf::Keyboard::LAlt, sf::Keyboard::Equal
	),

	TextInfo(
		L"السلام عليكم",

		L"As-Salāmu ‘Alaikum (Peace be upon you) (ALT + [)",

		"ASL",

		sf::Keyboard::LAlt, sf::Keyboard::LBracket
	),

	TextInfo(
		L"وعليكم السلام",

		L"Wa ‘Alaikum As-Salām (And peace be upon you too) (ALT + ])",

		"WASL",

		sf::Keyboard::LAlt, sf::Keyboard::RBracket
	),

	TextInfo(
		L"إن شاء الله",

		L"ʾIn shāʾ Allāh (If Allāh wills) (ALT + \\)",

		"INS",

		sf::Keyboard::LAlt, sf::Keyboard::Backslash
	),

	TextInfo(
		L"رضي الله عنهما",

		L"Raḍī Allāhu ʿAnhumā (May Allāh be pleased with them) (ALT + ;)",

		"RA3",

		sf::Keyboard::LAlt, sf::Keyboard::Semicolon
	),

	TextInfo(
		L"سبحان الله",

		L"Subḥānallāh (Glory be to Allāh) (ALT + ')",

		"SUB",

		sf::Keyboard::LAlt, sf::Keyboard::Quote
	),

	TextInfo(
		L"وإياكم",

		L"Wa Iyyākum (And you) (ALT + /)",

		"WAI",

		sf::Keyboard::LAlt, sf::Keyboard::Slash
	),

	TextInfo(
		L"السلام عليكم ورحمة الله وبركاته",

		L"As-Salāmu ‘Alaikum Wa Rahmatullāhi Wa Barakātuh (Peace, mercy and blessings be upon you) (ALT + ,)",

		"ASL_FULL",

		sf::Keyboard::LAlt, sf::Keyboard::Comma,

		1
	),

	TextInfo(
		L"وعليكم السلام ورحمة الله وبركاته",

		L"Wa ‘Alaikum As-Salām Wa Rahmatullāhi Wa Barakātuh (And peace, mercy and blessings be upon you too) (ALT + .)",

		"WASL_FULL",

		sf::Keyboard::LAlt, sf::Keyboard::Period,

		2
	),

	TextInfo(
		L"اللهم بارك",

		L"Allāhumma Bārik (May Allāh bless you) (ALT + Z)",

		"BARK",

		sf::Keyboard::LAlt, sf::Keyboard::Z
	),

	TextInfo(
		L"اللهم آمين",

		L"Allāhumma Amīn (O Allāh, accept this prayer) (ALT + X)",

		"AMN",

		sf::Keyboard::LAlt, sf::Keyboard::X
	)
};