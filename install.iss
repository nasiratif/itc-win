; Islāmic Text Copier Installer
; © Nāṣir ʿAṭif

#define MyAppName "Islāmic Text Copier"
#define MyAppEXEName "itc.exe"
#define MyAppPublisher "Nāṣir ʿAṭif"

[Setup]
AppName={#MyAppName}
AppVersion=2.4
WizardStyle=modern
WizardImageFile="D:\Apps\Islamic Text Copier\Icons\install.bmp"
DefaultDirName={localappdata}\nasiratif\Islamic Text Copier
DefaultGroupName={#MyAppName}
UninstallDisplayIcon={app}\itc.exe
AppPublisher={#MyAppPublisher}
Compression=lzma2
SolidCompression=yes
OutputDir="D:\Apps\Islamic Text Copier\install_output"
OutputBaseFilename=IslamicTextCopierInstall
PrivilegesRequired=lowest
DisableWelcomePage=no
[Messages]
WelcomeLabel1=Welcome to the {#MyAppName} Installer
WelcomeLabel2=Jazākallāhu Khairan, thank you for downloading my software!%n%nThe Islāmic Text Copier is a simple but very useful PC software that allows you to easily copy Arabic islamic texts to your clipboard. This is especially useful when writing articles.
[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; \
   GroupDescription: "{cm:AdditionalIcons}";
[Files]
Source: "D:\Apps\Islamic Text Copier\Code\itc\*"; DestDir: "{app}"; Flags: recursesubdirs

[Icons]
Name: "{group}\Islāmic Text Copier"; Filename: "{app}\itc.exe"
Name: "{userdesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; \
    Tasks: desktopicon