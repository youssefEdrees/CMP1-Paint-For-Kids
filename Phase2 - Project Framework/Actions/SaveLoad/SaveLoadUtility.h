#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "../../Figures/CLine.h"
#include "../../Figures/CRectangle.h"
#include "../../Figures/CTriangle.h"
#include "../../Figures/CRhombus.h"
#include "../../Figures/CCircle.h"
#include "../../Figures/CEllipse.h"

#ifdef __GNUC__
#define DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED(func) __declspec(deprecated) func
#else
#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
#define DEPRECATED(func) func
#endif

// The following inclusions and definitions are from :
/////////////////// https://www.github.com/Microsoft/Windows-classic-samples/blob/master/Samples/Win7Samples/winui/shell/appplatform/commonfiledialog/CommonFileDialogApp.cpp ///////////////////
/////////////////// https://www.github.com/Microsoft/Windows-classic-samples/blob/master/Samples/Win7Samples/winui/shell/appplatform/commonfiledialog/CommonFileDialogApp.cpp ///////////////////

#include <windows.h>      // For common windows data types and function headers
#define STRICT_TYPED_ITEMIDS
#include <shlobj.h>
#include <objbase.h>      // For COM headers
#include <shobjidl.h>     // for IFileDialogEvents and IFileDialogControlEvents
#include <shlwapi.h>
#include <knownfolders.h> // for KnownFolder APIs/datatypes/function headers
#include <propvarutil.h>  // for PROPVAR-related functions
#include <propkey.h>      // for the Property key APIs/datatypes
#include <propidl.h>      // for the Property System APIs
#include <strsafe.h>      // for StringCchPrintfW
#include <shtypes.h>      // for COMDLG_FILTERSPEC
#include <new>

const COMDLG_FILTERSPEC c_rgSaveTypes[] =
{
	//{L"Word Document (*.doc)",       L"*.doc"},
	//{L"Web Page (*.htm; *.html)",    L"*.htm;*.html"},
	{L"Text Document (*.txt)",       L"*.txt"},
	//{L"All Documents (*.*)",         L"*.*"}
};

//// Indices of file types
//#define INDEX_WORDDOC 1
//#define INDEX_WEBPAGE 2
//#define INDEX_TEXTDOC 3
//
//// Controls
//#define CONTROL_GROUP           2000
//#define CONTROL_RADIOBUTTONLIST 2
//#define CONTROL_RADIOBUTTON1    1
//#define CONTROL_RADIOBUTTON2    2       // It is OK for this to have the same ID as CONTROL_RADIOBUTTONLIST,
//										// because it is a child control under CONTROL_RADIOBUTTONLIST
//
//// IDs for the Task Dialog Buttons
//#define IDC_BASICFILEOPEN                       100
//#define IDC_ADDITEMSTOCUSTOMPLACES              101
//#define IDC_ADDCUSTOMCONTROLS                   102
//#define IDC_SETDEFAULTVALUESFORPROPERTIES       103
//#define IDC_WRITEPROPERTIESUSINGHANDLERS        104
//#define IDC_WRITEPROPERTIESWITHOUTUSINGHANDLERS 105

enum ReservedKeywords {
	KEYWORD_RED, 
	KEYWORD_GREEN, 
	KEYWORD_BLUE, 
	KEYWORD_BLACK, 
	KEYWORD_WHITE, 
	KEYWORD_NO_FILL, 
	KEYWORD_LINE, 
	KEYWORD_RECT, 
	KEYWORD_TRI, 
	KEYWORD_RHOMBUS, 
	KEYWORD_CIRCLE, 
	KEYWORD_ELLIPSE
};

enum FileDialogType {
	DIALOG_OPEN, 
	DIALOG_SAVE
};

enum CheckExtensionProbabilities {
	NO_EXTENSION,
	NOT_TXT, 
	TXT
};


///////////////////////////////////////////////////////
enum FileLinesFormat{
	LINE_DRAWCOLOR_FILLCOLOR, 
	LINE_FIGURES_COUNT, 

	LINE_FIG_TYPE_MIN_INDEX,

	LINE_LINE,
	LINE_RECT,
	LINE_TRI,
	LINE_RHOMBUS,
	LINE_CIRCLE,
	LINE_ELLIPSE, 

	LINE_FIG_TYPE_MAX_INDEX
};

enum WordType {
	INTEGER, // FigCount, Position or ID
	COLOR, 
	SHAPE, 
	RESIZE_FACTOR
};
///////////////////////////////////////////////////////

class SaveLoadUtility
{
	SaveLoadUtility(); // Creating an instance of this class makes no sense. (private constructor)

	static const WordType lineDrawColorFillColorDescription[2];
	static const WordType lineFiguresCountDescription[1];
	static const WordType lineLineDescription[8];
	static const WordType lineRectDescription[9];
	static const WordType lineTriDescription[11];
	static const WordType lineRhombusDescription[6];
	static const WordType lineCircleDescription[6];
	static const WordType lineEllipseDescription[6];

	static std::string wstrtostr(const std::wstring &wstr); 

public:
	
	DEPRECATED(static std::string fileDialogOld(FileDialogType type));
	static string fileDialog(FileDialogType type);
	static ReservedKeywords colorIntoKeyword(color c);
	static CheckExtensionProbabilities checkExtension(std::string& path);
};
