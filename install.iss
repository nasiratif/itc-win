; Islāmic Text Copier Installer
; © Nasīr ʿAṭif

#define MyAppName "Islāmic Text Copier"
#define MyAppEXEName "itc.exe"
#define MyAppPublisher "نَصِير عاطف (Nasīr ʿAṭif)"

#define public Dependency_Path_NetCoreCheck "dependencies\"

#include "CodeDependencies.iss"

[Setup]
AppName={#MyAppName}
AppVersion=4.4
WizardStyle=modern
WizardImageFile="D:\Projects\Islamic Text Copier\Icons\install.bmp"
DefaultDirName={localappdata}\nasiratif\Islamic Text Copier
DefaultGroupName={#MyAppName}
UninstallDisplayIcon={app}\itc.exe
AppPublisher={#MyAppPublisher}
Compression=lzma2
SolidCompression=yes
OutputDir="D:\Projects\Islamic Text Copier\install_output"
OutputBaseFilename=IslamicTextCopierInstall
PrivilegesRequired=lowest
DisableWelcomePage=no
[Messages]
WelcomeLabel1=Welcome to the {#MyAppName} Installer
WelcomeLabel2=Jazākallāhu Khairan, thank you for your interest in downloading my software!%n%nIslāmic Text Copier is a simple but very useful computer software that allows you to easily copy Arabic islāmic texts to your clipboard. This is especially useful when writing islāmic media that makes heavy use of Arabic texts whenever one is not fluent with Arabic.%n%nUpon installing, the Visual C++ 2015 redistributable (x86) will also be installed. This is required for the software to function properly.
[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; \
   GroupDescription: "{cm:AdditionalIcons}";
[InstallDelete]
Type: filesandordirs; Name: "{localappdata}\nasiratif\Islamic Text Copier\*"
[Files]
Source: "D:\Projects\Islamic Text Copier\Code\itc\Build\Win32\Release\*"; DestDir: "{app}"; Flags: recursesubdirs
Source: "vcredist2022.exe"; Flags: dontcopy noencryption

[Icons]
Name: "{group}\Islāmic Text Copier"; Filename: "{app}\itc.exe"
Name: "{userdesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; \
    Tasks: desktopicon
    
[Code]
function InitializeSetup: Boolean;
begin
  Dependency_ForceX86 := True; // force 32-bit install of next dependencies
  
  ExtractTemporaryFile('vcredist2022.exe');
  Dependency_AddVC2015To2022;

  Result := True;
end;