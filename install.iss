; Islāmic Text Copier Installer
; © Nasīr ʿAṭif

#define MyAppName "Islāmic Text Copier"
#define MyAppEXEName "itc.exe"
#define MyAppPublisher "ناصر عاطف (Nasīr ʿAṭif)"

[Setup]
AppName={#MyAppName}
AppVersion=4.3
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
WelcomeLabel2=Jazākallāhu Khairan, thank you for your interest in downloading my software!%n%nIslāmic Text Copier is a simple but very useful computer software that allows you to easily copy Arabic islāmic texts to your clipboard. This is especially useful when writing islāmic media that makes heavy use of Arabic texts whenever one is not fluent with Arabic.
[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; \
   GroupDescription: "{cm:AdditionalIcons}";
[InstallDelete]
Type: filesandordirs; Name: "{localappdata}\nasiratif\Islamic Text Copier\*"
[Files]
Source: "D:\Apps\Islamic Text Copier\Code\itc\Release Build\*"; DestDir: "{app}"; Excludes: "version.txt"; Flags: recursesubdirs

[Icons]
Name: "{group}\Islāmic Text Copier"; Filename: "{app}\itc.exe"
Name: "{userdesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; \
    Tasks: desktopicon