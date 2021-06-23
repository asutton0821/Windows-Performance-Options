/* Colson Sutton Copyright 2021 */ 

/* This program will take performance settings and apply them as needed */ 

/* Add the registry key to go to Best Performance and then custom so you see the checkbox in action. After this, you can get the API to apply and actually see the boxes check. */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <WinReg.h>
#include <windows.h>
#pragma comment(lib, "user32.lib")

using namespace std; 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {
		
	//needed variables	
	BOOL fResult; 
	HKEY key; 
	//
	
	
	fResult = SystemParametersInfo(SPI_SETFONTSMOOTHING,1,0,SPIF_SENDCHANGE); //font smoothing
	fResult = SystemParametersInfo(SPI_SETDRAGFULLWINDOWS,0,0,SPIF_SENDCHANGE); //drag full windows
	fResult = SystemParametersInfo(SPI_SETCURSORSHADOW,0,0,SPIF_SENDCHANGE); // cursor shadows
	fResult = SystemParametersInfo(SPI_SETDROPSHADOW,0,0,SPIF_SENDCHANGE); //drop shadows
	fResult = SystemParametersInfo(SPI_SETLISTBOXSMOOTHSCROLLING,0,0,SPIF_SENDCHANGE);//smooth list box scrolling
	fResult = SystemParametersInfo(SPI_SETCOMBOBOXANIMATION,0,0,SPIF_SENDCHANGE);//combo box animation
	fResult = SystemParametersInfo(SPI_SETSELECTIONFADE,0,0,SPIF_SENDCHANGE);//selection fade
	fResult = SystemParametersInfo(SPI_SETTOOLTIPFADE,0,0,SPIF_SENDCHANGE);//tooltip fade
	fResult = SystemParametersInfo(SPI_SETCLIENTAREAANIMATION ,0,0,SPIF_SENDCHANGE);
	fResult = SystemParametersInfo(SPI_SETUIEFFECTS, 0, 0, SPIF_SENDCHANGE);
	fResult = SystemParametersInfo(SPI_SETANIMATION, 0, 0, SPIF_SENDCHANGE);
	
	ANIMATIONINFO animInfo;
	animInfo.iMinAnimate = 0;
	animInfo.cbSize = sizeof( ANIMATIONINFO );
	BOOL result = SystemParametersInfo( SPI_SETANIMATION, animInfo.cbSize,
	&animInfo, 0 );
	
	//DWORD values // 
	DWORD value=0; //default
	DWORD visValue=3; //visualFXSettings DWORD for Custom
	DWORD iconOnlyValue=1;  //iconsonly MUST BE 1 
	//


//opens the key at the VisualEffects
if (RegOpenKey(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\VisualEffects"), &key) != ERROR_SUCCESS)
{
   cout << "Unable to open registry key -> Windows\\DWM";
}
//Sets VisualFXSettings to 3 based on the Value in the variable
if (RegSetValueEx(key, TEXT("VisualFXSetting"), 0, REG_DWORD, (const BYTE*)&visValue, sizeof(visValue)) != ERROR_SUCCESS)
{
   RegCloseKey(key);
   cout <<"Unable to set registry value VisualFXSetting";
}
else
{
   cout << "VisualFXSetting was set" << endl;
}

//Opens Explorer/Advanced

if (RegOpenKey(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced"), &key) != ERROR_SUCCESS)
{
   cout << "Unable to open registry key -> Explorer\\Advanced";
}


//Sets ListViewAlpha to 0
if (RegSetValueEx(key, TEXT("ListViewAlpha"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value)) != ERROR_SUCCESS)
{
   RegCloseKey(key);
   cout <<"Unable to set registry value ListViewAlpha";
}
else
{
   cout << "ListViewAlpha was set" << endl;
}

//Sets ListViewAlpha to 1 based on the variable

if (RegSetValueEx(key, TEXT("IconsOnly"), 0, REG_DWORD, (const BYTE*)&iconOnlyValue, sizeof(iconOnlyValue)) != ERROR_SUCCESS)
{
   RegCloseKey(key);
   cout <<"Unable to set registry value IconsOnly";
}
else
{
   cout << "IconsOnly was set" << endl;
}

//Sets TaskbarAnimations to 0
if (RegSetValueEx(key, TEXT("TaskbarAnimations"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value)) != ERROR_SUCCESS)
{
   RegCloseKey(key);
   cout <<"Unable to set registry value TaskbarAnimations";
}
else
{
   cout << "TaskbarAnimations was set" << endl;
}

//Sets ListviewShadow to 0

if (RegSetValueEx(key, TEXT("ListviewShadow"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value)) != ERROR_SUCCESS)
{
   RegCloseKey(key);
   cout <<"Unable to set registry value ListviewShadow";
}
else
{
   cout << "ListviewShadow was set" << endl;
}

//Sets ListviewAlphaSelect to 0
if (RegSetValueEx(key, TEXT("ListviewAlphaSelect"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value)) != ERROR_SUCCESS)
{
   RegCloseKey(key);
   cout <<"Unable to set registry value ListviewAlphaSelect";
}
else
{
   cout << "ListviewAlphaSelect was set" << endl;
}


//Opens the DWM hive
if (RegOpenKey(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Microsoft\\Windows\\DWM"), &key) != ERROR_SUCCESS)
{
   cout << "Unable to open registry key -> Windows\\DWM";
}

//Sets AlwaysHibernateThumbnails to 0

if (RegSetValueEx(key, TEXT("AlwaysHibernateThumbnails"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value)) != ERROR_SUCCESS)
{
   RegCloseKey(key);
   cout <<"Unable to set registry value AlwaysHibernateThumbnails";
}
else
{
   cout << "AlwaysHibernateThumbnails was set" << endl;
}

//Sets EnableAeroPeek to 0
if (RegSetValueEx(key, TEXT("EnableAeroPeek"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value)) != ERROR_SUCCESS)
{
   RegCloseKey(key);
   cout <<"Unable to set registry value value_name";
}
else
{
   cout << "EnableAeroPeek was set" << endl;
}

	//kills explorer and restarts to take full effect
	system("taskkill /F /IM explorer.exe & start explorer");
	
}



