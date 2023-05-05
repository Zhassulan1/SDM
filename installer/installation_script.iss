#include "environment.iss"

#define MyAppName "SDM"
#define MyAppVersion "1"
#define MyAppPublisher "https://github.com/Zhassulan1/"
#define MyAppExeName "sdm.exe"


[Setup]
AppId={{A6381385-1F42-4AE9-A49C-EFBA6C7523EE}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName=C:\{#MyAppName}
DisableDirPage=yes
DefaultGroupName={#MyAppName}  
DisableProgramGroupPage=yes   
AllowNoIcons=yes
OutputBaseFilename=SDM setup
Compression=lzma
SolidCompression=yes
WizardStyle=modern
ChangesEnvironment=true


[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"


[Files]
Source: "{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion


[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"


[Tasks]
Name: envPath; Description: "Add to PATH variable" 


[Code] 
procedure CurStepChanged(CurStep: TSetupStep);
begin
    if(CurStep = ssPostInstall) and IsTaskSelected('envPath')
    then EnvAddPath(ExpandConstant('{app}'));
end;
    
procedure CurUninstallStepChanged(CurUninstallStep: TUninstallStep);
begin
    if CurUninstallStep = usPostUninstall
    then EnvRemovePath(ExpandConstant('{app}'));
end;




