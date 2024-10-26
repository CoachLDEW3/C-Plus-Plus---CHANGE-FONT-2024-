/**************************************************************************************************************************************************
 Name:		CoachLDEW
 Date:		10.24.2024
 Purpose:	This program allows the user to change the font in the console window. The function takes one parameter: The font name.  
            Example: ChangeFont("Courier New"); changes the font to Courier New.
**************************************************************************************************************************************************/
#include <iostream>			//This library contains standard input and output processes
#include <Windows.h>		//This library provides access to the Windows API, allowing you to interact with the operating system's functionalities
#include <string>           //This library provides a collection of functions for efficient string manipulation and memory operations


using namespace std;

void ChangeFont(string font)
{
    //Output Handle to the console
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX CFontInfo;
    CFontInfo.cbSize = sizeof(CFontInfo);

    //Get the current font information
    if (!GetCurrentConsoleFontEx(hOut, FALSE, &CFontInfo)) {
        cerr << "Error getting console font info: " << GetLastError() << endl;
    }

    //Change the font
    if (font == "Consolas") {
        wcscpy_s(CFontInfo.FaceName, L"Consolas"); // Set the font name to "Consolas"
    }
    else if (font == "Times New Roman") {
        wcscpy_s(CFontInfo.FaceName, L"Times New Roman"); // Set the font name to "Consolas"
    }
    else if (font == "Arial") {
        wcscpy_s(CFontInfo.FaceName, L"Arial"); // Set the font name to "Consolas"
    }
    else if (font == "Lucida Console") {
        wcscpy_s(CFontInfo.FaceName, L"Lucida Console"); // Set the font name to "Consolas"
    }
    else if (font == "Liberation Mono") {
        wcscpy_s(CFontInfo.FaceName, L"Liberation Mono"); // Set the font name to "Consolas"
    }
    else if (font == "Courier New") {
        wcscpy_s(CFontInfo.FaceName, L"Courier New"); // Set the font name to "Consolas"
    }
    else {
        cout << "Invalid choice.\n";
    }

    //Set the new font
    if (!SetCurrentConsoleFontEx(hOut, FALSE, &CFontInfo)) {
        cerr << "Error setting console font: " << GetLastError() << endl;
    }
}

int main() 
{
    ChangeFont("Courier New");

    cout << "Hello, World!" << endl;
    return 0;
}