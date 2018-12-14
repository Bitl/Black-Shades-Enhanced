# Microsoft Developer Studio Project File - Name="blackshades" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=blackshades - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "blackshades.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "blackshades.mak" CFG="blackshades - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "blackshades - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "blackshades - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "blackshades - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "C:\Documents and Settings\BitlDev\Desktop\SDKs\OpenALSDK\Include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "BIG_ENDIAN" /D "FULLSCREEN" /D "NOOGG" /FR /YX /FD /c
# SUBTRACT CPP /X
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib opengl32.lib glu32.lib glaux.lib sdl.lib sdlmain.lib OpenAL32.lib ALut.lib SDL_image.lib /nologo /subsystem:windows /machine:I386 /out:"Release/blackshades_revenge.exe" /libpath:"C:\Documents and Settings\BitlDev\Desktop\SDKs\OpenALSDK\libs\\"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "blackshades - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "C:\Documents and Settings\BitlDev\Desktop\SDKs\OpenALSDK\Include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "BIG_ENDIAN" /D "NOOGG" /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib opengl32.lib glu32.lib glaux.lib sdl.lib sdlmain.lib OpenAL32.lib ALut.lib SDL_image.lib /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/blackshades_revenge.exe" /pdbtype:sept /libpath:"C:\Documents and Settings\BitlDev\Desktop\SDKs\OpenALSDK\libs\\"

!ENDIF 

# Begin Target

# Name "blackshades - Win32 Release"
# Name "blackshades - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\blackshades.rc
# End Source File
# Begin Source File

SOURCE=.\Source\Camera.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Decals.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Files.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Fog.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Frustum.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\GameDraw.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\GameInitDispose.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\GameLoop.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\GameTick.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Globals.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\MacInput.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Maths.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Models.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Person.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Quaternions.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Serialize.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Skeleton.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\SoundFX.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Sprites.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Support.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Text.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\TGALoader.cpp
# End Source File
# Begin Source File

SOURCE=.\Source\Timer.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Source\Camera.h
# End Source File
# Begin Source File

SOURCE=.\Source\Constants.h
# End Source File
# Begin Source File

SOURCE=.\Source\Decals.h
# End Source File
# Begin Source File

SOURCE=.\Source\Files.h
# End Source File
# Begin Source File

SOURCE=.\Source\Fog.h
# End Source File
# Begin Source File

SOURCE=.\Source\Frustum.h
# End Source File
# Begin Source File

SOURCE=.\Source\Game.h
# End Source File
# Begin Source File

SOURCE=.\Source\MacInput.h
# End Source File
# Begin Source File

SOURCE=.\Source\Maths.h
# End Source File
# Begin Source File

SOURCE=.\Source\Models.h
# End Source File
# Begin Source File

SOURCE=.\Source\Person.h
# End Source File
# Begin Source File

SOURCE=.\Source\PhysicsMath.h
# End Source File
# Begin Source File

SOURCE=.\Source\Quaternions.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\Source\Serialize.h
# End Source File
# Begin Source File

SOURCE=.\Source\Skeleton.h
# End Source File
# Begin Source File

SOURCE=.\Source\SoundFX.h
# End Source File
# Begin Source File

SOURCE=.\Source\Sprites.h
# End Source File
# Begin Source File

SOURCE=.\Source\Support.h
# End Source File
# Begin Source File

SOURCE=.\Source\Text.h
# End Source File
# Begin Source File

SOURCE=.\Source\TGALoader.h
# End Source File
# Begin Source File

SOURCE=.\Source\Timer.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\notes.txt
# End Source File
# End Target
# End Project
