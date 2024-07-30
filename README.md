# Islāmic Text Copier
This is a simple text copying program. The goal of this app is simple; give the user easy access to commonly used Arabic texts on their PC, such as Subḥānahu wa Taʾālá and Sallá Allāhu ʿAlayhī wa as-Salam.

The release can be downloaded at it's official home page: https://itc.nasiratif.net.

# Contributions
I decided to open-source this program so that anyone can contribute to it, like fixing bugs, adding more texts and fine-tuning my admittedly sloppy code! It is programmed entirely in C++.

To setup the ITC source, you'll need Visual Studio (2022 preferably), and add an `include` and `lib` folder in the project directory with the SFML files inside (https://www.sfml-dev.org/download.php).

The Inno Setup source is also included (you will need to change the directories inside however).

## Adding texts
Adding new texts is as simple as just adding new members into the `itcButtons` array in **Texts.h** and filling out the TextInfo struct:
1. The `name` member is the Arabic text, ITC will copy this string when the user presses the button
2. The `tooltip` member is the tooltip displayed on the bottom left; this is supposed to display the English transliteration and translation along with it's hotkey
3. `image` is the image filename of the text, ITC will look for it in the **images** directory with the **.png** extension
4. `key1` & `key2` are `sf::Keyboard` keys which register the hotkey for the text
5. `fontShrink` is a number that indicates how much to make the tooltip font smaller if the text is too long

بارك الله فيك
